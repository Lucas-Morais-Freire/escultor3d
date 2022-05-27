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

void foot(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    putCylinder(S, 14 + x, 7.5 + y, 12 + z, 14 + x, 8.5 + y, 12 + z, 14); // coloca disco (raio 14)
    cutCylinder(S, 14 + x, 7.5 + y, 12 + z, 14 + x, 8.5 + y, 12 + z, 13); // tira disco (raio 13)
    (*S).putBox(7 + x, 21 + x, 14 + y, 16 + y, 7 + z, 17 + z); // suporte das 3 pernas
    (*S).putBox(11 + x, 17 + x, 17 + y, 17 + y, 7 + z, 17 + z); // detalhe do suporte
    (*S).cutBox(13 + x, 15 + x, 15 + y, 16 + y, 7 + z, 17 + z); // detalhe do suporte
    (*S).cutBox(14 + x, 14 + x, 14 + y, 17 + y, 7 + z, 17 + z); // detalhe do suporte
    putCylinder(S, 6 + x, 14 + y, 12 + z, 6 + x, 16 + y, 12 + z, 5); // parte arredondada do suporte
    putCylinder(S, 22 + x, 14 + y, 12 + z, 22 + x, 16 + y, 12 + z, 5); // parte arredondada do suporte
    (*S).putBox(9 + x, 19 + x, 19 + y, 23 + y, 7 + z, 17 + z); // caixa superior

    (*S).setColor(93,93,93);
    putCylinder(S, 0 + x, 4 + y, 12 + z, 10 + x, 8 + y, 12 + z, 1.5); // suporte dianteiro
    putCylinder(S, 27 + x, 1 + y, 12 + z, 18 + x, 8 + y, 12 + z, 1.5); //suporte traseiro
    putCylinder(S, 14 + x, 11 + y, 12 + z, 14 + x, 43 + y, 12 + z, 4); // perna principal
    putCylinder(S, 5 + x, 17 + y, 12 + z, 5 + x, 25 + y, 12 + z, 2); // perna dianteira inf
    putCylinder(S, 5 + x, 26 + y, 12 + z, 5 + x, 43 + y, 12 + z, 3); // perna dianteira sup
    putCylinder(S, 23 + x, 17 + y, 12 + z, 23 + x, 25 + y, 12 + z, 2); // perna traseira inf
    putCylinder(S, 23 + x, 26 + y, 12 + z, 23 + x, 43 + y, 12 + z, 3); // perna traseira sup

    (*S).setColor(232,221,187);
    (*S).putBox(1 + x, 17 + x, y, y, 1 + z, 23 + z); //base eixo z inf
    (*S).putBox(x, 18 + x, 1 + y, 1 + y, z, 24 + z); //base eixo z sup
    (*S).putBox(18 + x, 30 + x, y, 1 + y, 6 + z, 18 + z); // base eixo x
    (*S).cutBox(30 + x, 30 + x, 1 + y, 1 + y, 6 + z, 18 + z); // detalhe base eixo x
    (*S).putBox(x, 19 + x, 2 + y, 3 + y, 6 + z, 18 + z); // tampa da base
    (*S).cutBox(17 + x, 19 + x, 3 + y, 3 + y, 6 + z, 18 + z); // detalhe tampa da base
    putCylinder(S, 14 + x, 2 + y, 12 + z, 14 + x, 9 + y, 12 + z, 5); // tronco
    putCylinder(S, 14 + x, 9.5 + y, 12 + z, 14 + x, 10.5 + y, 12 + z, 13); // disco maior
    (*S).putBox(-1 + x, 1 + x, 2 + y, 4 + y, 6 + z, 18 + z); // "rabinho" dos pés
    (*S).putBox(-2 + x, x, 3 + y, 5 + y, 6 + z, 18 + z); //
    (*S).putBox(-3 + x, -2 + x, 5 + y, 6 + y, 6 + z, 18 + z); //
}

void RF_FootHolder(Sculptor* S, int x, int y, int z) {
    (*S).setColor(232,221,187);
    (*S).putBox(x, 77 + x, y, 10 + y, z, 58 + z);
    (*S).putBox(34 + x, 67 + x, -3 + y, -1 + y, 30 + z, 30 + z);
    (*S).putBox(34 + x, 67 + x, -6 + y, -4 + y, 31 + z, 31 + z);
    (*S).putBox(34 + x, 67 + x, -9 + y, -7 + y, 32 + z, 32 + z);
    (*S).putBox(34 + x, 67 + x, -3 + y, -1 + y, 2 + z, 2 + z);
    (*S).putBox(34 + x, 67 + x, -6 + y, -4 + y, 1 + z, 1 + z);
    (*S).putBox(34 + x, 67 + x, -9 + y, -7 + y, z, z);

    (*S).setColor(0,0,0);
    for (int i = 0; i <= 77; i++) {
        (*S).cutBox(i + x, i + x, y, 10 + y, (3655 - i)/63 + 1 + z, 59 + z);
    }
    for (int i = 64; i <= 77; i++) {
        (*S).cutBox(i + x, i + x, y, 10 + y, 121 - i + z, 57 + z);
    }
    for (int i = 0; i <= 5; i++) {
        (*S).cutBox(i + x, i + x, y, 10 + y, z, (-29*i + 290)/5 - 2 + z);
    }
    for (int i = 6; i <= 16; i++) {
        (*S).cutBox(i + x, i + x, y, 10 + y, z, (-26*i + 432)/10 - 1 + z);
    }
    (*S).cutBox(34 + x, 67 + x, y, 5 + y, 2 + z, 30 + z);

}

void RF_foot(Sculptor *S, int x, int y, int z) {
    RF_FootHolder(S, x, y + 48, z);
    foot(S, x + 38, y + 10, z + 4);
}

int main() {
    Sculptor falcon(300,300,200);

    falcon.setColor(232,221,187);
    falcon.putEllipsoid(75, 15, 75, 75, 15, 75);
    falcon.cutEllipsoid(75, 15, 75, 73, 13, 73);
    for (int i = 0; i <= 150; i++) {
        for (int j = 0; j <= 30; j++) {
            for (int k = 0; k <= 150; k++) {
                if ((i - 75)*(i - 75) + (k - 75)*(k - 75) >= 73*73) {
                    falcon.cutVoxel(i, j, k);
                }
            }
        }
    }
    putCylinder(&falcon, 75, 12, 75, 75, 18, 75, 73);
    cutCylinder(&falcon, 75, 12, 75, 75, 18, 75, 71);

    falcon.writeOFF("falcon.off");

    return 0;
}
