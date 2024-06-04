#include "cube.h"

Cube::Cube() {
    pt.radius = 5;
}

void Cube::Update() {
}

void Cube::Draw() {
    for (int i = 0; i < matrixA.size(); i++) {
        Scale();
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

void Cube::Scale() {
    for (int i = 0; i < matrixA.size(); i++) {
        int x = matrixA[i].x;
        int y = matrixA[i].y;
        int z = matrixA[i].z;

        matrixA[i].x = x * mI[0].x + y * mI[1].x + z * mI[2].x;
        matrixA[i].y = x * mI[0].y + y * mI[1].y + z * mI[2].y;
        matrixA[i].z = x * mI[0].z + y * mI[1].z + z * mI[2].z;
    }
}


//Remap Func:
// Goal; Normalize, then remap.
// Range [-1, 1] to [0, 1]
// Why?; although og always -z then conv to z, if -x/-y, will be [-1, 0]
// Then; Increase with wid, hei as a factor.