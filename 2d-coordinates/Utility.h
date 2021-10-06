#pragma once

class Vector2;
class Circle;
static Vector2* AddVector(const Vector2 a, const Vector2 b);
static Vector2* CoordinatesMedianPoint(const Vector2 a, const Vector2 b);
static class Vector2* SwapCoordinates(const Vector2 a, const Vector2 b);
static Vector2 Distance(const Vector2 a, const Vector2 b);
static int InsideCircle(Circle circle, Vector2 point);