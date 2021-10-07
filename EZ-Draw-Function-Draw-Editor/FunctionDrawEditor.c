/* FunctionDrawEditor.c
 *
 * Edouard.Thiel@lif.univ-mrs.fr - 02/07/2008 - version 1.2
 *
 * Compilation on Windows (On cmd -> Go to the files path):
 *     gcc -Wall FunctionDrawEditor.c ez-draw.c -o FunctionDrawEditor.exe -lgdi32
 * 
 *
 * This program is free software under the terms of the
 * GNU Lesser General Public License (LGPL) version 2.1.
*/

//Geogebra website -> https://www.geogebra.org/calculator
//Geogebra equation -> f(x)=sqrt(1+((x)/(2)) (x+sqrt(x^(2)+8)))

#include "ez-draw.h"
#include <math.h>

typedef struct {
    int unitInPixelsX, unitInPixelsY, graphOffsetX, graphOffsetY, lastPosX, lastPosY;
} NavigationValues;

NavigationValues navigationValues;

void drawCaretAtPosition(Ez_window win, int x, int y, int onHorizontalAxis)
{
    int caretSize = 3;

    if (onHorizontalAxis)
        ez_draw_line(win, x, y - caretSize, x, y + caretSize);
    else
        ez_draw_line(win, x - caretSize, y, x + caretSize, y);
}

double getFunctionImage(double x, int* testCasePassed)
{
    //Check if the sqrt content is always > 0 to prevent any error
    double testCase = 1 + ((x / 2) * (x + sqrt(pow(x, 2) + 8)));
    if (testCase > 0)
    {
        *testCasePassed = 1;
        return sqrt(testCase);
    }
    else
    {
        *testCasePassed = 0;
        return 0;
    }
}

//TODO : Store the array values instead of calculating the cruve every render
void drawFunction(Ez_window win, int width, int height, int unitInPixelsX, int unitInPixelsY, int windowOriginOffsetX, int windowOriginOffsetY)
{
    //Draw the function representative curve
    ez_set_thick(3.5);
    ez_set_color(ez_red);

    double horizontalPrecision = 0.001;

    int sectionAmountX = (int)(width / unitInPixelsX);
    for (double i = -(int)(sectionAmountX / 2); i <= (int)(sectionAmountX / 2); i += horizontalPrecision)
    {

        int testCaseResult, testCaseNextResult; //Store the test case result to prevent rendering a point that doesn't exist

        //Get result of current point and next to draw a line
        double result = getFunctionImage(i, &testCaseResult);
        double nextResult = getFunctionImage(i + horizontalPrecision, &testCaseNextResult);

        if (testCaseResult > 0 && testCaseNextResult > 0) //Draw line only if both test case passed
        {
            ez_draw_line(win, (int)((width / 2 ) + windowOriginOffsetX + (i * unitInPixelsX)), (int)((height / 2) + windowOriginOffsetY - (result * unitInPixelsY)),
                (int)((width / 2) + windowOriginOffsetX + ((i + horizontalPrecision) * unitInPixelsX)), (int)((height / 2) + windowOriginOffsetY - (nextResult * unitInPixelsY)));
        }
    }
}

void drawAxisLines(Ez_window win, int width, int height, int unitInPixelsX, int unitInPixelsY, int windowOriginOffsetX, int windowOriginOffsetY)
{
    //Draw axis
    ez_set_thick(1);
    ez_set_color(ez_black);
    ez_draw_line(win, 0, (int)((height / 2) + windowOriginOffsetY), width, (int)((height / 2) + windowOriginOffsetY)); //Horizontal
    ez_draw_line(win, (int)((width / 2) + windowOriginOffsetX), 0, (int)((width / 2) + windowOriginOffsetX), height); //Vertical


    //Draw carets
    int caretAmountX = (int)((width + windowOriginOffsetX) / unitInPixelsX);
    for (int i = -caretAmountX; i <= caretAmountX; i++)
    {
        drawCaretAtPosition(win, (int)(width / 2) + windowOriginOffsetX + (i * unitInPixelsX), windowOriginOffsetY + (int)(height / 2), 1);

        if (i != 0) //Don't display 0 coordinate
        {
            char numStr[5];
            snprintf(numStr, 50, "%d", i);
            ez_draw_text(win, EZ_BC, (int)(width / 2) + windowOriginOffsetX + (i * unitInPixelsX), windowOriginOffsetY + (int)(height / 2) + 20, numStr);
        }
    }

    int caretAmountY = (int)((height + windowOriginOffsetY) / unitInPixelsY);
    for (int i = -caretAmountY; i <= caretAmountY; i++)
    {
        drawCaretAtPosition(win, (int)(width / 2) + windowOriginOffsetX, windowOriginOffsetY + (i * unitInPixelsY) + (int)(height / 2), 0);

        if (i != 0) //Don't display 0 coordinate
        {
            char numStr[5];
            snprintf(numStr, 50, "%d", -i);
            ez_draw_text(win, EZ_BC, windowOriginOffsetX + (int)(width / 2) - 20, windowOriginOffsetY + (i * unitInPixelsY) + (int)(height / 2) + 5, numStr);
        }
    }
}

void win1_on_expose(Ez_event* ev)
{
    //Rescale the window every frame to prevent resizing -> until i find how to lock resize
    ez_window_set_size(ev->win, 1280, 720);

    int width = 0, height = 0;
    ez_window_get_size(ev->win, &width, &height);

    int windowOriginOffsetX = navigationValues.graphOffsetX;
    int windowOriginOffsetY = navigationValues.graphOffsetY;

    drawAxisLines(ev->win, width, height, navigationValues.unitInPixelsX, navigationValues.unitInPixelsY, windowOriginOffsetX, windowOriginOffsetY);
    drawFunction(ev->win, width, height, navigationValues.unitInPixelsX, navigationValues.unitInPixelsY, windowOriginOffsetX, windowOriginOffsetY);
}

void moveGraphOriginPos(Ez_window win, int x, int y)
{
    if (x > 0)
        navigationValues.graphOffsetX += 10;
    else if(x < 0)
        navigationValues.graphOffsetX -= 10;

    if (y > 0)
        navigationValues.graphOffsetY += 10;
    else if(y < 0)
        navigationValues.graphOffsetY -= 10;

    ez_send_expose(win);
}

void increaseGraphScale(Ez_window win)
{
    navigationValues.unitInPixelsX += 10;
    navigationValues.unitInPixelsY += 10;

    ez_send_expose(win);
}

void decreaseGraphScale(Ez_window win)
{
    if (!(navigationValues.unitInPixelsX - 10 <= 0))
    {
        navigationValues.unitInPixelsX -= 10;
        navigationValues.unitInPixelsY -= 10;

        ez_send_expose(win);
    }
}

void win1_on_motion_notify(Ez_event* ev) /* Mouse moved */
{
    /*
    char numStr[25];
    snprintf(numStr, 50, "x : %d, y : %d", ev->mx, ev->my);
    ez_draw_text(ev->win, EZ_BC, 70, 30, numStr);
    */

    //TODO : Move graph on click

    if (ev->mb >= 1)
    {
        abs(ev->mx - navigationValues.lastPosX);
        abs(ev->my - navigationValues.lastPosY);

        navigationValues.graphOffsetX += ev->mx - navigationValues.lastPos);

        navigationValues.lastPosX = ev->mx;
        navigationValues.lastPosY = ev->my;
    }

    ez_send_expose(ev->win);

    //ez_send_expose(ev->win);
}


void win1_on_key_press(Ez_event* ev)
{
    switch (ev->key_sym) {
    case XK_q: ez_quit(); break;
    case XK_p: increaseGraphScale(ev->win); break;
    case XK_m: decreaseGraphScale(ev->win); break;
    case XK_Left: moveGraphOriginPos(ev->win, -1, 0); break;
    case XK_Right: moveGraphOriginPos(ev->win, 1, 0); break;
    case XK_Up: moveGraphOriginPos(ev->win, 0, -1); break;
    case XK_Down: moveGraphOriginPos(ev->win, 0, 1); break;
    }
}


void win1_on_event(Ez_event* ev)                /* Called by ez_main_loop() */
{                                                /* for each event on win1   */
    switch (ev->type) {
    case Expose: win1_on_expose(ev); break;
    case KeyPress: win1_on_key_press(ev); break;
    case MotionNotify: win1_on_motion_notify(ev); break;
    }
}

int main ()
{
    if (ez_init() < 0) exit(1);

    Ez_window window;
    window = ez_window_create (1280, 720, "FunctionDrawEditor", win1_on_event);

    navigationValues.unitInPixelsX = 90;
    navigationValues.unitInPixelsY= 90;
    navigationValues.graphOffsetX = 0;
    navigationValues.graphOffsetY = 0;

    //FIX : Try to enable the buffer and figure out why the screen is white
    ez_window_dbuf(window, 0);

    ez_main_loop ();
    exit(0);
}


