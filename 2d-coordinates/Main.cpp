#include <stdio.h>
#include "Utility.cpp"

int main()
{
    //Allocate memory on the heap
    Vector2* a = new Vector2(1, 1);
    Vector2* b = new Vector2(2, 2);

    Vector2* addVectorResults = AddVector(*a, *b);
    printf(" Vector Add Coordinates (%.2lf, %.2lf)\n\n", addVectorResults->x, addVectorResults->y);
    free(addVectorResults);

    Vector2* medianVectorResult = CoordinatesMedianPoint(*a, *b);
    printf(" Vector Median Coordinates (%.2lf, %.2lf)\n\n", medianVectorResult->x, medianVectorResult->y);
    free(medianVectorResult);

    Vector2* swapedVector = SwapCoordinates(*a, *b);
    printf(" Swaped Vector\n");
    printf(" Vector a (%.2lf, %.2lf)\n", swapedVector[0].x, swapedVector[0].y);
    printf(" Vector b (%.2lf, %.2lf)\n\n", swapedVector[1].x, swapedVector[1].y);
    free(swapedVector);

    Vector2 distanceBetweenPoints = Distance(*a , *b);
    printf(" Distance between VectorA(%.2lf, %.2lf) and VectorB(%.2lf, %.2lf) is VectorC(%.2lf, %.2lf)\n\n", a->x, a->y, b->x, b->y, distanceBetweenPoints.x, distanceBetweenPoints.y);

    Circle* testCircle = new Circle(new Vector2(0, 0), 1);
    Vector2* testPoint = new Vector2(1, 0);
    int result = InsideCircle(*testCircle, *testPoint);

    printf(" The point at coordinates (%.2lf, %.2lf) %s at coordinates (%.2lf, %.2lf)\n\n", testPoint->x, testPoint->y, result ? "is inside the circle" : "is inside the circle", testCircle->origin->x, testCircle->origin->y);

    delete testCircle;
    delete testPoint;

    //Free mem taken by the vectors
    delete a;
    delete b;

    return 0;
}





