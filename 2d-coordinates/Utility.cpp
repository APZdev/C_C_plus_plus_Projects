#include <stdlib.h>
#include <math.h>
#include "Utility.h"

class Vector2
{
public:
    double x, y;
    Vector2()
    {
        x = 0;
        y = 0;
    }
    Vector2(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};

class Circle
{
public:
    Vector2* origin;
    double radius;
    Circle()
    {
        origin = new Vector2(0, 0);
        radius = 1;
    }
    Circle(Vector2* _origin, double _radius)
    {
        origin = _origin;
        radius = _radius;
    }

    ~Circle() //Deconstructor
    {
        //Clear memory in case the default constructor is called
        //delete origin;
    }
};

static Vector2* AddVector(const Vector2 a, const Vector2 b)
{
    Vector2* result = (Vector2*)calloc(2, sizeof(Vector2));

    if (result)
    {
        result->x = a.x + b.x;
        result->y = a.y + b.y;
    }

    return result;
}

static Vector2* CoordinatesMedianPoint(const Vector2 a, const Vector2 b)
{
    Vector2* result = (Vector2*)calloc(2, sizeof(Vector2));

    if (result) //Prevent NULL pointer dereferencing error
    {
        result->x = (a.x + b.x) / 2;
        result->y = (a.y + b.y) / 2;
    }

    return result;
}

//Can only return an array if we store it's pointer on the heap
//Return array of struct/class explained -> https://stackoverflow.com/questions/47028165/how-do-i-return-an-array-of-struct-from-a-function/47028268s
static Vector2* SwapCoordinates(const Vector2 a, const Vector2 b)
{
    Vector2 coordinatesBuffer = a;
    Vector2* swapedCoordinates = (Vector2*)calloc(2, sizeof(Vector2));

    if (swapedCoordinates)
    {
        swapedCoordinates[0] = b;
        swapedCoordinates[1] = coordinatesBuffer;
    }

    return swapedCoordinates;
}

static Vector2 Distance(const Vector2 a, const Vector2 b)
{
    Vector2 finalVector;

    finalVector.x = b.x - a.x;
    finalVector.y = b.y - a.y;

    return finalVector;
}

static int InsideCircle(Circle circle, Vector2 point)
{
    return pow(point.x - circle.origin->x, 2) + pow(point.y - circle.origin->y, 2) < pow(circle.radius, 2);
}