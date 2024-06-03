#pragma once
#include "point.h"

class Cube
{
public:
    Settings st;
    Point pt;

    Cube();
    void Update();
    void Draw();
    float Remap(float point, int p);

private:
    vector<Vector3> matrixA = {
        Vector3{-1, 1, -3},
        Vector3{1, 1, -3},
        Vector3{-1, -1, -3},
        Vector3{1, -1, -3},

        Vector3{-1, 1, -5},
        Vector3{1, 1, -5},
        Vector3{-1, -1, -5},
        Vector3{1, -1, -5} };
};
