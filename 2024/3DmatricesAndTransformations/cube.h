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
    void Scale();

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

    vector<Vector3> mI = {    // TRY changing me!
        Vector3{1, 0, 0},
        Vector3{0, 1, 0},
        Vector3{0, 0, 1} };
};  