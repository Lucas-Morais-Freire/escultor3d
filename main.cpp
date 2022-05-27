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

void corpo(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    (*S).putEllipsoid(75 + x, 15 + y, 75 + z, 75, 15, 75);
    (*S).cutEllipsoid(75 + x, 15 + y, 75 + z, 73, 13, 73);
    for (int i = 0; i <= 150; i++) {
        for (int j = 0; j <= 30; j++) {
            for (int k = 0; k <= 150; k++) {
                if ((i - 75)*(i - 75) + (k - 75)*(k - 75) >= 73*73) {
                    (*S).cutVoxel(i + x, j + y, k + z);
                }
            }
        }
    }
    putCylinder(S, 75 + x, 12 + y, 75 + z, 75 + x, 18 + y, 75 + z, 73);
    cutCylinder(S, 75 + x, 12 + y, 75 + z, 75 + x, 18 + y, 75 + z, 71);
}

int main() {
    Sculptor falcon(400,400,250);

    corpo(&falcon, 0, 10, 0);

    falcon.writeOFF("falcon.off");

    return 0;
}
