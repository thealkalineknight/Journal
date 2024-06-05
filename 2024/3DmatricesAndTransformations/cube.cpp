#include "cube.h"

Cube::Cube() {
    pt.radius = 5;

    //Transform('t', 0);
    //Transform('s', 1);
    //Transform('r', 2); 
    // everything works normal except multiple rotations (look into it later) maybe its the trig..?
}

void Cube::Update() {
    //Transform('r', 0);
    //th += 0.01;
}

void Cube::Draw() {
    for (int i = 0; i < matrixA.size(); i++) {
        float x = matrixA[i].x / -matrixA[i].z;
        float y = matrixA[i].y / -matrixA[i].z;
        x = Remap(x, 0);
        y = Remap(y, 1);

        DrawCircle(x, y, pt.radius, RED);
        matrixAt[i].x = x; matrixAt[i].y = y;

        if (i + 1 < matrixA.size()) {
            DrawLine(matrixAt[i].x, matrixAt[i].y, matrixAt[i + 1].x, matrixAt[i + 1].y, ORANGE);
        }
        for (int j = 0; j < 3; j++) {
            DrawLine(matrixAt[j].x, matrixAt[j].y, matrixAt[7 - j].x, matrixAt[7 - j].y, ORANGE);
        }
    }
    DrawLine(matrixAt[0].x, matrixAt[0].y, matrixAt[3].x, matrixAt[3].y, ORANGE);
    DrawLine(matrixAt[4].x, matrixAt[4].y, matrixAt[7].x, matrixAt[7].y, ORANGE);
}

float Cube::Remap(float point, int p) {
    point = (1 + point) / 2;
    if (p == 0) point *= st.scrWid;
    if (p == 1) point *= st.scrHei;
    return point;
}

void Cube::Transform(char mode, int coor) {

    for (int i = 0; i < matrixA.size(); i++) {
        int x = matrixA[i].x;
        int y = matrixA[i].y;
        int z = matrixA[i].z;

        if (mode == 't') {
            if (coor == 0) matrixA[i].x += Tf;
            if (coor == 1) matrixA[i].y += Tf;
            if (coor == 2) matrixA[i].z += Tf;
        }

        else {
            vector<Vector3> M{};
            if (mode == 's') {
                M = mS;
                if (coor == 0) M[0].x = Sf;
                if (coor == 1) M[1].y = Sf;
                if (coor == 2) M[2].z = Sf;
            }
            else if (mode == 'r') {

                if (coor == 0) M = mRx;
                if (coor == 1) M = mRy;
                if (coor == 2) M = mRz;
            }

            matrixA[i].x = x * M[0].x + y * M[1].x + z * M[2].x;
            matrixA[i].y = x * M[0].y + y * M[1].y + z * M[2].y;
            matrixA[i].z = x * M[0].z + y * M[1].z + z * M[2].z;
        }
    }
}


//Remap Func:
// Goal; Normalize, then remap.
// Range [-1, 1] to [0, 1]
// Why?; although og always -z then conv to z, if -x/-y, will be [-1, 0]
// Then; Increase with wid, hei as a factor.
