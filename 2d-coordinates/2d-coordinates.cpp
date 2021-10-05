#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Vector2;
struct Circle;
double* AddTwoCoordinates(const Vector2 point[]);
double* CoordinatesMedianPoint(const Vector2 point[]);
struct Vector2* SwapCoordinates(Vector2 point[]);
Vector2 Distance(Vector2 a, Vector2 b);
bool InsideCircle(Circle circle, Vector2 point);

class Vector2
{
public:
    double x, y;
    Vector2(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};

struct Circle
{
    Vector2 origin;
    double radius;
};

int main()
{
    Vector2 coordinates[2];

    coordinates[0].x = 1;
    coordinates[0].y = 1;

    coordinates[1].x = 2;
    coordinates[1].y = 2;

    double* addResults = AddTwoCoordinates(coordinates);
    printf("Vector Add Coordinates (%lf, %lf)\n", addResults[0], addResults[1]);
    free(addResults);

    double* medianCoordinatesResults = CoordinatesMedianPoint(coordinates);
    printf("Vector Median Coordinates (%lf, %lf)\n", medianCoordinatesResults[0], medianCoordinatesResults[1]);
    free(medianCoordinatesResults);

    struct Vector2* tradedCoordinates = SwapCoordinates(coordinates);
    printf("Vector a (%lf, %lf)\n", tradedCoordinates[0].x, tradedCoordinates[0].y);
    printf("Vector b (%lf, %lf)\n", tradedCoordinates[1].x, tradedCoordinates[1].y);
    free(tradedCoordinates);

    Vector2 distanceBetweenPoints = Distance(coordinates[0], coordinates[1]);
    printf("Vector 2 Distance (%lf, %lf)", distanceBetweenPoints.x, distanceBetweenPoints.y);

    Circle testCircle;
    testCircle.origin = new Vector2(0, 1)
    InsideCircle();
}

double* AddTwoCoordinates(const Vector2 point[])
{
    double* results = (double*)calloc(2, sizeof(double));

    if (results)
    {
        results[0] = point[0].x + point[1].x;
        results[1] = point[0].y + point[1].y;
    }

    return results;
}

double* CoordinatesMedianPoint(const Vector2 point[])
{
    double* results = (double*)calloc(2, sizeof(double));

    if (results)
    {
        results[0] = (point[0].x + point[1].x) / 2;
        results[1] = (point[0].y + point[1].y) / 2;
    }

    return results;
}

//Can only return an array if we store it's pointer on the heap
//Return array of struct explained -> https://stackoverflow.com/questions/47028165/how-do-i-return-an-array-of-struct-from-a-function/47028268s
struct Vector2* SwapCoordinates(Vector2 point[])
{
    Vector2 coordinatesBuffer = point[0];
    struct Vector2* swapedCoordinates = (Vector2*)calloc(2, sizeof(struct Vector2));

    if (swapedCoordinates)
    {
        swapedCoordinates[0] = point[1];
        swapedCoordinates[1] = coordinatesBuffer;
    }

    return swapedCoordinates;
}

Vector2 Distance(Vector2 a, Vector2 b)
{
    Vector2 finalVector;

    finalVector.x = b.x - a.x;
    finalVector.y = b.y - a.y;

    return finalVector;
}

bool InsideCircle(Circle circle, Vector2 point)
{
    //(x - center_x) ^ 2 + (y - center_y) ^ 2 < radius ^ 2

    int yes = pow(point.x - circle.origin.x, 2) + pow(point.y - circle.origin.y, 2) < pow(circle.radius, 2);
  
    printf("%d", yes);

    return true;
}




