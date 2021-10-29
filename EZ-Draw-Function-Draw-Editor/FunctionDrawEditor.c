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
#define CurvePrecision 0.01
#define StoredCurveArraySize (int)(200 * (1 / CurvePrecision) * 2)

typedef struct 
{
    int unitInPixelsX, unitInPixelsY, graphOffsetX, graphOffsetY, lastPosX, lastPosY;
} NavigationValues;

typedef struct 
{
    double curveValuesX[StoredCurveArraySize];
    double curveValuesY[StoredCurveArraySize];
    unsigned short valueExists[StoredCurveArraySize];
    int storedCurveSize;
} StoredCurve;

typedef struct 
{
    int width, height;
    int mouseX, mouseY;
} WindowInfos;

StoredCurve storedCurve;
NavigationValues navigationValues;
WindowInfos windowInfos;

void drawCaretAtPosition(Ez_window win, int x, int y, int onHorizontalAxis)
{
    int caretSize = 3;

    if (onHorizontalAxis)
        ez_draw_line(win, x, y - caretSize, x, y + caretSize);
    else
        ez_draw_line(win, x - caretSize, y, x + caretSize, y);
}

double getFunctionImage(double x, int* outTestCasePassed)
{
    /*
    //Check if the sqrt content is always > 0 to prevent any error
    double testCase = 1 + ((x / 2) * (x + sqrt(pow(x, 2) + 8)));
    if (testCase > 0)
    {
        *outTestCasePassed = 1;
        return sqrt(testCase);
    }
    else
    {
        *outTestCasePassed = 0;
        return 0;
    }
    */

    double testCase = (2+sin(x));
    if (testCase > 0)
    {
        *outTestCasePassed = 1;
        return pow(asin(x), 2) / testCase;
    }
    else
    {
        *outTestCasePassed = 0;
        return 0;
    }
}

//Calculate and store curve data
void getFunctionData(int width, int unitInPixelsX)
{
    int curveSizeCounter = 0;
    for (double i = -200; i <= 200; i += CurvePrecision)
    {
        int testCaseResult; //Store the test case result to prevent rendering a point that doesn't exist, for example when dividing by 0

        //Store results
        storedCurve.curveValuesY[curveSizeCounter] = getFunctionImage(i, &testCaseResult);
        storedCurve.valueExists[curveSizeCounter] = (testCaseResult > 0);
        storedCurve.curveValuesX[curveSizeCounter] = i;

        curveSizeCounter++;
    }

    //After the loop, we have the final stored values count of the array
    storedCurve.storedCurveSize = curveSizeCounter;
}

//Draw the function representative curve
void drawFunction(Ez_window win, int width, int height, int unitInPixelsX, int unitInPixelsY, int windowOriginOffsetX, int windowOriginOffsetY)
{
    //Set curve color and thickness
    ez_set_thick(2.5);
    ez_set_color(ez_red);

    int isFirstDraw = 1;
    int caretAmountX = (int)(width / unitInPixelsX) + abs((int)(windowOriginOffsetX / unitInPixelsX));
    for (int i = (int)((storedCurve.storedCurveSize / 2) - (caretAmountX * (1 / CurvePrecision))); i < ((storedCurve.storedCurveSize / 2) + (caretAmountX * (1 / CurvePrecision))) - 2; i++)
    {
        //Get the point coordinates from the stored curve values
        double x = storedCurve.curveValuesX[i];
        double y = storedCurve.curveValuesY[i];
        double yNext = storedCurve.curveValuesY[i + 1];

        //Draw the lines
        if (storedCurve.valueExists[i] == 1)
        {
            ez_draw_line(win, (int)((width / 2 ) + windowOriginOffsetX + (x * unitInPixelsX)), (int)((height / 2) + windowOriginOffsetY - (y * unitInPixelsY)),
                    (int)((width / 2) + windowOriginOffsetX + ((x + CurvePrecision) * unitInPixelsX)), (int)((height / 2) + windowOriginOffsetY - (yNext * unitInPixelsY)));
        }
        else if (storedCurve.valueExists[i] == 0 && storedCurve.valueExists[i + 1] == 1 && isFirstDraw == 1) //First draw check to prevent failed testCases not rendering the first line
        {
            isFirstDraw = 0;

            ez_draw_line(win, (int)((width / 2) + windowOriginOffsetX + (x * unitInPixelsX)), (int)((height / 2) + windowOriginOffsetY - (0 * unitInPixelsY)),
                (int)((width / 2) + windowOriginOffsetX + ((x + CurvePrecision) * unitInPixelsX)), (int)((height / 2) + windowOriginOffsetY - (yNext * unitInPixelsY)));
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


    //Draw carets + numbers
    int offsetCountX = (int)(windowOriginOffsetX / unitInPixelsX);
    int caretAmountX = (int)(width / unitInPixelsX) + abs(offsetCountX);
    for (int i = -caretAmountX; i <= caretAmountX; i++)
    {
        drawCaretAtPosition(win, (int)(width / 2) + windowOriginOffsetX + (i * unitInPixelsX), windowOriginOffsetY + (int)(height / 2), 1);

        //Dislay axis numbers
        if (i != 0) //Don't display 0 coordinate
        {
            char numStr[5];
            snprintf(numStr, 50, "%d", i);
            ez_draw_text(win, EZ_BC, (int)(width / 2) + windowOriginOffsetX + (i * unitInPixelsX), windowOriginOffsetY + (int)(height / 2) + 20, numStr);
        }
    }

    int offsetCountY = (int)(windowOriginOffsetY / unitInPixelsY);
    int caretAmountY = (int)(height / unitInPixelsY) + abs(offsetCountY);
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

void drawCurveHoverPoint(Ez_window win)
{
    ez_set_color(ez_blue);
    ez_set_thick(7);

    char numStr[25];
    int testCaseResult;
    double relativeMouseX = (windowInfos.mouseX - (windowInfos.width / 2));
    double curveImage = getFunctionImage((relativeMouseX - navigationValues.graphOffsetX) / navigationValues.unitInPixelsX, &testCaseResult);
    if (testCaseResult == 1)
    {
        snprintf(numStr, 50, "f(%.3lf) = %lf", (relativeMouseX - navigationValues.graphOffsetX) / navigationValues.unitInPixelsX, curveImage);
        ez_draw_point(win, (windowInfos.width / 2) + relativeMouseX, (windowInfos.height / 2) - ((curveImage * navigationValues.unitInPixelsY) - navigationValues.graphOffsetY));

    }
    else
        snprintf(numStr, 50, "f(%.3lf) = ERROR", (relativeMouseX - navigationValues.graphOffsetX) / navigationValues.unitInPixelsX, curveImage);

    ez_set_nfont(1);
    ez_draw_text(win, EZ_TL, 30, 30, numStr);
}

void win1_on_expose(Ez_event* ev)
{
    ez_window_get_size(ev->win, &windowInfos.width, &windowInfos.height);

    drawAxisLines(ev->win, windowInfos.width, windowInfos.height, navigationValues.unitInPixelsX, navigationValues.unitInPixelsY, navigationValues.graphOffsetX, navigationValues.graphOffsetY);
    drawFunction(ev->win, windowInfos.width, windowInfos.height, navigationValues.unitInPixelsX, navigationValues.unitInPixelsY, navigationValues.graphOffsetX, navigationValues.graphOffsetY);
    drawCurveHoverPoint(ev->win);
}

void increaseGraphScale(Ez_window win)
{
    navigationValues.unitInPixelsX += 10;
    navigationValues.unitInPixelsY += 10;

    ez_send_expose(win);
}

void decreaseGraphScale(Ez_window win)
{
    if (!(navigationValues.unitInPixelsX - 10 <= 0)) //Check zoom limit before apply
    {
        navigationValues.unitInPixelsX -= 10;
        navigationValues.unitInPixelsY -= 10;

        ez_send_expose(win);
    }
}

void win1_on_motion_notify(Ez_event* ev) /* Mouse moved */
{
    //Update mouse window coordinates
    windowInfos.mouseX = ev->mx;
    windowInfos.mouseY = ev->my;

    //Move graph on click drag
    if (ev->mb >= 1)
    {
        //Clamp the view translation
        if (navigationValues.graphOffsetX + ev->mx - navigationValues.lastPosX <= -5000 || navigationValues.graphOffsetX + ev->mx - navigationValues.lastPosX >= 5000 ||
            navigationValues.graphOffsetY + ev->my - navigationValues.lastPosY <= -5000 || navigationValues.graphOffsetY + ev->my - navigationValues.lastPosY >= 5000) return;

        //Get the delta mouse movements
        navigationValues.graphOffsetX += ev->mx - navigationValues.lastPosX;
        navigationValues.graphOffsetY += ev->my - navigationValues.lastPosY;
    }

    //To get the delta we need the previous pos, so we save it
    navigationValues.lastPosX = ev->mx;
    navigationValues.lastPosY = ev->my;

    ez_send_expose(ev->win);
}


void win1_on_key_press(Ez_event* ev)
{
    switch (ev->key_sym) {
    case XK_Escape: ez_quit(); break;
    case XK_p: increaseGraphScale(ev->win); break;
    case XK_m: decreaseGraphScale(ev->win); break;
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

    ez_window_get_size(window, &windowInfos.width, &windowInfos.height);

    navigationValues.unitInPixelsX = 90;
    navigationValues.unitInPixelsY= 90;
    navigationValues.graphOffsetX = 0;
    navigationValues.graphOffsetY = 0;

    //TODO : Try to somehow lock window size

    ez_window_dbuf(window, 1); //If screen buffer is On, don't resize window every frame

    getFunctionData(windowInfos.width, navigationValues.unitInPixelsX); //Calculate function data once

    ez_main_loop ();
    exit(0);
}


