#include "cube.h"

Cube::Cube() {
    pt.radius = 5;
}

void Cube::Update() {
}

void Cube::Draw() {
    for (int i = 0; i < matrixA.size(); i++) {
        float x = matrixA[i].x / -matrixA[i].z;
        float y = matrixA[i].y / -matrixA[i].z;
        x = Remap(x, 0);
        y = Remap(y, 1);

        DrawCircle(x, y, pt.radius, RED);
    }
}

float Cube::Remap(float point, int p) {
    point = (1 + point) / 2;
    if (p == 0) point *= st.scrWid;
    if (p == 1) point *= st.scrHei;
    return point;
}
