#include <iostream>
#include "sculptor.h"

void putCylinder(Sculptor* S, float xa, float ya, float za, float xb, float yb, float zb, float rad) {
    int xi, yi, zi, xf, yf, zf;
    xi = (int)(xa - rad); yi = (int)(ya - rad); zi = (int)(za - rad); xf = (int)(xb + rad) + 1; yf = (int)(yb + rad) + 1; zf = (int)(zb + rad) + 1;
    if (za > zb) {
        zi = (int)(zb - rad); zf = (int)(za + rad) + 1;
    }
    if (ya > yb) {
        yi = (int)(yb - rad); yf = (int)(ya + rad) + 1;
    }
    if (xa > xb) {
        xi = (int)(xb - rad); xf = (int)(xa + rad) + 1;
    }

    for (int i = xi; i <= xf; i++) {
        for (int j = yi; j <= yf; j++) {
            for (int k = zi; k <= zf; k++) {
                float t0 = ((xb - xa)*(i - xa) + (yb - ya)*(j - ya) + (zb - za)*(k - za))/((xb - xa)*(xb - xa) + (yb - ya)*(yb - ya) + (zb - za)*(zb - za));
                if (0 <= t0 && t0 <= 1) {
                    if ((i - xa - (xb - xa)*t0)*(i - xa - (xb - xa)*t0) + (j - ya - (yb - ya)*t0)*(j - ya - (yb - ya)*t0) + (k - za - (zb - za)*t0)*(k - za - (zb - za)*t0) <= rad*rad) {
                        (*S).putVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

void cutCylinder(Sculptor* S, float xa, float ya, float za, float xb, float yb, float zb, float rad) {
    int xi, yi, zi, xf, yf, zf;
    xi = (int)(xa - rad); yi = (int)(ya - rad); zi = (int)(za - rad); xf = (int)(xb + rad) + 1; yf = (int)(yb + rad) + 1; zf = (int)(zb + rad) + 1;
    if (za > zb) {
        zi = (int)(zb - rad); zf = (int)(za + rad) + 1;
    }
    if (ya > yb) {
        yi = (int)(yb - rad); yf = (int)(ya + rad) + 1;
    }
    if (xa > xb) {
        xi = (int)(xb - rad); xf = (int)(xa + rad) + 1;
    }

    for (int i = xi; i <= xf; i++) {
        for (int j = yi; j <= yf; j++) {
            for (int k = zi; k <= zf; k++) {
                float t0 = ((xb - xa)*(i - xa) + (yb - ya)*(j - ya) + (zb - za)*(k - za))/((xb - xa)*(xb - xa) + (yb - ya)*(yb - ya) + (zb - za)*(zb - za));
                if (0 <= t0 && t0 <= 1) {
                    if ((i - xa - (xb - xa)*t0)*(i - xa - (xb - xa)*t0) + (j - ya - (yb - ya)*t0)*(j - ya - (yb - ya)*t0) + (k - za - (zb - za)*t0)*(k - za - (zb - za)*t0) <= rad*rad) {
                        (*S).cutVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

void body(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    (*S).putEllipsoid(75 + x, 15 + y, 75 + z, 75, 15, 75);
    (*S).cutEllipsoid(75 + x, 15 + y, 75 + z, 73, 13, 73);
    cutCylinder(S, 75 + x, 12 + y, 75 + z, 75 + x, 18 + y, 75 + z, 75);
    putCylinder(S, 75 + x, 12 + y, 75 + z, 75 + x, 18 + y, 75 + z, 73);
    cutCylinder(S, 75 + x, 12 + y, 75 + z, 75 + x, 18 + y, 75 + z, 71);
    putCylinder(S, 75 + x, 29.5 + y, 75 + z, 75 + x, 30.5 + y, 75 + z, 17);
    putCylinder(S, 75 + x, 30.5 + y, 75 + z, 75 + x, 31.5 + y, 75 + z, 16);
    cutCylinder(S, 75 + x, 30.5 + y, 82 + z, 75 + x, 31.5 + y, 82 + z, 6);
    (*S).setColor(50,50,50);
    (*S).putBox(69 + x, 81 + x, 30 + y, 30 + y, 76 + z, 88 + z);
    (*S).setColor(232,221,187);
    putCylinder(S, 75 + x, 29.5 + y, 82 + z, 75 + x, 30.5 + y, 82 + z, 3.5);
    cutCylinder(S, 75 + x, 29.5 + y, 82 + z, 75 + x, 30.5 + y, 82 + z, 2.5);
    (*S).setColor(50,50,50);
    (*S).putBox(72 + x, 78 + x, 29 + y, 29 + y, 79 + z, 85 + z);
    (*S).setColor(232,221,187);
    (*S).putVoxel(77 + x, 30 + y, 86 + z);
    (*S).putVoxel(78 + x, 30 + y, 87 + z);
    (*S).putVoxel(73 + x, 30 + y, 86 + z);
    (*S).putVoxel(72 + x, 30 + y, 87 + z);
    (*S).putVoxel(71 + x, 30 + y, 84 + z);
    (*S).putVoxel(70 + x, 30 + y, 85 + z);
    (*S).putVoxel(71 + x, 30 + y, 80 + z);
    (*S).putVoxel(70 + x, 30 + y, 79 + z);
    (*S).putVoxel(73 + x, 30 + y, 78 + z);
    (*S).putVoxel(72 + x, 30 + y, 77 + z);
    (*S).putVoxel(77 + x, 30 + y, 78 + z);
    (*S).putVoxel(78 + x, 30 + y, 77 + z);
    (*S).putVoxel(79 + x, 30 + y, 80 + z);
    (*S).putVoxel(80 + x, 30 + y, 79 + z);
    (*S).putVoxel(79 + x, 30 + y, 84 + z);
    (*S).putVoxel(80 + x, 30 + y, 85 + z);
}

void upperNose(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    for (int i = 0; i < 66; i++) {
        (*S).putBox((6*i)/66 + x, -(6*i)/66 + 24 + x, y, -(13*i)/74 + 12 + y, i + z, i + z);
        (*S).cutBox((6*i)/66 + 1 + x, -(6*i)/66 + 23 + x, 1 + y, -(13*i)/74 + 11 + y, i + z, i + z);
    }
}

void lowerNose(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    for (int i = 0; i < 66; i++) {
        (*S).putBox((6*i)/66 + x, -(6*i)/66 + 24 + x, (13*i)/74 + y, 12 + y, i + z, i + z);
        (*S).cutBox((6*i)/66 + 1 + x, -(6*i)/66 + 23 + x, (13*i)/74 + 1 + y, 11 + y, i + z, i + z);
    }
}

void leftHorn(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    for (int i = 0; i <= 78; i++) {
        (*S).putBox(x, -(36*i)/79 + 43 + x, y, 4 + y, i + z, i + z);
        if (i == 78) {
            continue;
        }
        (*S).cutBox(1 + x, -(36*i)/79 + 42 + x, 1 + y, 3 + y, i + z, i + z);
    }
}

void rightHorn(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    for (int i = 0; i <= 78; i++) {
        (*S).putBox((36*i)/79 + x, 43 + x, y, 4 + y, i + z, i + z);
        if (i == 78) {
            continue;
        }
        (*S).cutBox((36*i)/79 + 1 + x, 42 + x, 1 + y, 3 + y, i + z, i + z);
    }
}

void cabinTube(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    (*S).putSphere(18 + x, 18 + y, 44 + z, 9);
    (*S).cutSphere(18 + x, 18 + y, 44 + z, 8);
    putCylinder(S, 18 + x, 18 + y, 44 + z, 62.16 + x, 19.27 + y, 18.59 + z, 9);
    cutCylinder(S, 18 + x, 18 + y, 44 + z, 62.16 + x, 19.27 + y, 18.59 + z, 8);
    putCylinder(S, 18 + x, 18 + y, 44 + z, 18 + x, 18 + y, 60 + z, 9);
    cutCylinder(S, 18 + x, 18 + y, 44 + z, 18 + x, 18 + y, 60 + z, 8);
    for (int i = 0; i <= 10; i++) {
        putCylinder(S, 18 + x, 18 + y, 60.5 + i + z, 18 + x, 18 + y, 61.5 + i + z, -(4*i)/11 + 8.5);
        cutCylinder(S, 18 + x, 18 + y, 60.5 + i + z, 18 + x, 18 + y, 61.5 + i + z, -(4*i)/11 + 7.5);
    }
    putCylinder(S, 18 + x, 18 + y, 71.5 + z, 18 + x, 18 + y, 72.5 + z, 4.5);
    cutCylinder(S, 18 + x, 18 + y, 71.5 + z, 18 + x, 18 + y, 72.5 + z, 2.5);
    putCylinder(S, 18 + x, 18 + y, 72.5 + z, 18 + x, 18 + y, 73.5 + z, 2.5);
}

int main() {
    Sculptor falcon(400,400,250);

    body(&falcon, 0, 10, 0);
    upperNose(&falcon, 63, 29, 93);
    lowerNose(&falcon, 63, 9, 93);
    leftHorn(&falcon, 83, 23, 127);
    rightHorn(&falcon, 24, 23, 127);
    cabinTube(&falcon,-8,12,73);

    falcon.writeOFF("falcon.off");

    return 0;
}