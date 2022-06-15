#include <iostream>
#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <iomanip>

void setColor(Sculptor* S, unsigned char r, unsigned char g, unsigned char b) {
    (*S).setColor(((float)r)/255, ((float)g)/255, ((float)b)/255, 1);
}

void body(Sculptor* S, int x, int y, int z) {
    setColor(S, 159,159,159);
    (*S).putEllipsoid(75 + x, 16 + y, 75 + z, 75, 15, 75);
    (*S).cutEllipsoid(75 + x, 16 + y, 75 + z, 73, 13, 73);
    (*S).putCylinder(75 + x, 18.5 + y, 75 + z, 75 + x, 19.5 + y, 75 + z, 75);
    (*S).cutBox(x, 150 + x, y, 18 + y, z, 75 + z);
    (*S).putCylinder(75 + x, 10.5 + y, 75 + z, 75 + x, 11.5 + y, 75 + z, 75);
    (*S).cutCylinder(75 + x, 10.5 + y, 75 + z, 75 + x, 11.5 + y, 75 + z, 72);
    (*S).cutBox(x, 150 + x, y, 30 + y, 70 + z, 150 + z);
    (*S).cutBox(127 + x, 128 + x, 11 + y, 19 + y, 21 + z, 23 + z);
    (*S).cutBox(22 + x, 23 + x, 11 + y, 19 + y, 21 + z, 23 + z);
    for (int i = 0; i <= 70; i++) {
        (*S).cutBox(x - 1, i - 1 + x, 11 + y, 30 + y, i + z, i + z);
        (*S).cutBox(151 - i + x, 151 + x, 11 + y, 30 + y, i + z, i + z);
    }

    (*S).putEllipsoid(75 + x, 15 + y, 75 + z, 75, 15, 75);
    (*S).cutEllipsoid(75 + x, 15 + y, 75 + z, 73, 13, 73);
    (*S).cutCylinder(75 + x, 12 + y, 75 + z, 75 + x, 18 + y, 75 + z, 75);
    setColor(S, 120,120,120);
    (*S).putCylinder(75 + x, 12 + y, 75 + z, 75 + x, 18 + y, 75 + z, 70);
    (*S).cutCylinder(75 + x, 12 + y, 75 + z, 75 + x, 18 + y, 75 + z, 68);

    setColor(S, 159,159,159);
    (*S).putCylinder(75 + x, 29.5 + y, 75 + z, 75 + x, 30.5 + y, 75 + z, 17);
    (*S).putCylinder(75 + x, 30.5 + y, 75 + z, 75 + x, 31.5 + y, 75 + z, 16);

    int X, Z;
    float a, b;
    setColor(S, 134, 1, 2);
    for (int i = 0; i <= 10; i++) {
        a = sin((67.56 + 22.44/10*i)*(M_PI/180));
        b = cos((67.56 + 22.44/10*i)*(M_PI/180));
        (*S).putCylinder(18*a + 75 + x, 29 + y, 18*b + 75 + z, 26.95*a + 75 + x, 29 + y, 26.95*b + 75 + z, 0.5);
    }
    for (int i = 0; i <= 15; i++) {
        a = sin((67.56 + 22.44/15*i)*(M_PI/180));
        b = cos((67.56 + 22.44/15*i)*(M_PI/180));
        (*S).putCylinder(26.5*a + 75 + x, 28 + y, 26.5*b + 75 + z, 30.52*a + 75 + x, 28 + y, 30.52*b + 75 + z, 0.5);
    }
    for (int i = 0; i <= 17; i++) {
        a = sin((-20 + ((double)40)/17*i)*(M_PI/180));
        b = cos((-20 + ((double)40)/17*i)*(M_PI/180));
        (*S).putCylinder(18*a + 75 + x, 31 + y, 18*b + 68 + z, 23*a + 75 + x, 31 + y, 23*b + 68 + z, 0.5);
    }
    for (int i = 0; i <= 16; i++) {
        a = sin((-114.41 + 24.41/16*i)*(M_PI/180));
        b = cos((-114.41 + 24.41/16*i)*(M_PI/180));
        (*S).putCylinder(29.41*a + 75 + x, 28 + y, 29.41*b + 75 + z, 36.93*a + 75 + x, 28 + y, 36.93*b + 75 + z, 0.5);
    }
    for (int i = 0; i <= 12; i++) {
        a = sin((-45 + 12.95/12*i)*(M_PI/180));
        b = cos((-45 + 12.95/12*i)*(M_PI/180));
        (*S).putCylinder(49.3*a + 75 + x, 26 + y, 49.3*b + 75 + z, 45.95*a + 75 + x, 26 + y, 45.95*b + 75 + z, 0.5);
    }
    for (int i = 0; i <= 13; i++) {
        a = sin((-45 + 12.95/13*i)*(M_PI/180));
        b = cos((-45 + 12.95/13*i)*(M_PI/180));
        (*S).putCylinder(49.72*a + 75 + x, 26 + y, 49.72*b + 75 + z, 50.95*a + 75 + x, 26 + y, 50.95*b + 75 + z, 0.5);
    }
    for (int i = 0; i <= 13; i++) {
        a = sin((-45 + 12.95/13*i)*(M_PI/180));
        b = cos((-45 + 12.95/13*i)*(M_PI/180));
        (*S).putCylinder(50*a + 75 + x, 25 + y, 50*b + 75 + z, 53.13*a + 75 + x, 25 + y, 53.13*b + 75 + z, 0.5);
    }

    (*S).cutCylinder(75 + x, 30.5 + y, 82 + z, 75 + x, 31.5 + y, 82 + z, 6);
    setColor(S, 50,50,50);
    (*S).putBox(69 + x, 81 + x, 30 + y, 30 + y, 76 + z, 88 + z);
    setColor(S, 159,159,159);
    (*S).putCylinder(75 + x, 29.5 + y, 82 + z, 75 + x, 30.5 + y, 82 + z, 3.5);
    (*S).cutCylinder(75 + x, 29.5 + y, 82 + z, 75 + x, 30.5 + y, 82 + z, 2.5);
    setColor(S, 50,50,50);
    (*S).putBox(72 + x, 78 + x, 29 + y, 29 + y, 79 + z, 85 + z);
    setColor(S, 159,159,159);
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

    for (int i = 75; i <= 108; i++) {
        for (int j = 18; j <= 61; j++) {
            if (-3*(i - 94) + 19*(j - 21) >= 0 && -8*(i - 108) + 14*(j - 29) >= 0 && -3*(i - 103) - 5*(j - 61) >= 0) {
                (*S).putBox(i + x, i + x, y, 6 + y, j + z, j + z);
                (*S).putBox(150 - i + x, 150 - i + x, y, 6 + y, j + z, j + z);
            }
        }
    }

    for (int i = 88; i <= 109; i++) {
        for (int j = 90; j <= 125; j++) {
            if ((i - 90) + (j - 93) >= 0 && 16*(i - 88) + (j - 125) >= 0 && -(i - 96) - 4*(j - 123) >= 0 && -7*(i - 109) - 13*(j - 116) >= 0) {
                (*S).putBox(i + x, i + x, y, 6 + y, j + z, j + z);
                (*S).putBox(150 - i + x, 150 - i + x, y, 6 + y, j + z, j + z);
            }
        }
    }

    (*S).putBox(69 + x, 80 + x, y, 6 + y, 108 + z, 136 + z);
    (*S).cutCylinder(75 + x, 0.5 + y, 75 + z, 75 + x, -0.5 + y, 75 + z, 23.79);
    (*S).putCylinder(75 + x, 0.5 + y, 75 + z, 75 + x, -0.5 + y, 75 + z, 17);
    (*S).putCylinder(75 + x, -0.5 + y, 75 + z, 75 + x, -1.5 + y, 75 + z, 16);
    (*S).cutCylinder(75 + x, -0.5 + y, 82 + z, 75 + x, -1.5 + y, 82 + z, 6);
    setColor(S, 50,50,50);
    (*S).putBox(69 + x, 81 + x, y, y, 76 + z, 88 + z);
    setColor(S, 159,159,159);
    (*S).putCylinder(75 + x, 0.5 + y, 82 + z, 75 + x, -0.5 + y, 82 + z, 3.5);
    (*S).cutCylinder(75 + x, 0.5 + y, 82 + z, 75 + x, -0.5 + y, 82 + z, 2.5);
    setColor(S, 50,50,50);
    (*S).putBox(72 + x, 78 + x, 1 + y, 1 + y, 79 + z, 85 + z);
    setColor(S, 159,159,159);
    (*S).putVoxel(77 + x, 0 + y, 86 + z);
    (*S).putVoxel(78 + x, 0 + y, 87 + z);
    (*S).putVoxel(73 + x, 0 + y, 86 + z);
    (*S).putVoxel(72 + x, 0 + y, 87 + z);
    (*S).putVoxel(71 + x, 0 + y, 84 + z);
    (*S).putVoxel(70 + x, 0 + y, 85 + z);
    (*S).putVoxel(71 + x, 0 + y, 80 + z);
    (*S).putVoxel(70 + x, 0 + y, 79 + z);
    (*S).putVoxel(73 + x, 0 + y, 78 + z);
    (*S).putVoxel(72 + x, 0 + y, 77 + z);
    (*S).putVoxel(77 + x, 0 + y, 78 + z);
    (*S).putVoxel(78 + x, 0 + y, 77 + z);
    (*S).putVoxel(79 + x, 0 + y, 80 + z);
    (*S).putVoxel(80 + x, 0 + y, 79 + z);
    (*S).putVoxel(79 + x, 0 + y, 84 + z);
    (*S).putVoxel(80 + x, 0 + y, 85 + z);

    for (int i = 0; i <= 3; i++) {
        X = (int)((70 + i)*sin(150*(M_PI/180))) + 75;
        Z = (int)((70 + i)*cos(150*(M_PI/180))) + 75;
        (*S).putBox(X + x, X + x, 20 + y, 25 + y - i, Z, Z);
        (*S).putBox(X + x, X + x, 5 + y + i, 10 + y, Z, Z);
    }
    for (int i = 0; i <= 3; i++) {
        X = (int)((70 + i)*sin(170*(M_PI/180))) + 75;
        Z = (int)((70 + i)*cos(170*(M_PI/180))) + 75;
        (*S).putBox(X + x, X + x, 20 + y, 25 + y - i, Z, Z);
        (*S).putBox(X + x, X + x, 5 + y + i, 10 + y, Z, Z);
    }
    for (int i = 0; i <= 3; i++) {
        X = (int)((70 + i)*sin(190*(M_PI/180))) + 75;
        Z = (int)((70 + i)*cos(190*(M_PI/180))) + 75;
        (*S).putBox(X + x, X + x, 20 + y, 25 + y - i, Z, Z);
        (*S).putBox(X + x, X + x, 5 + y + i, 10 + y, Z, Z);
    }
    for (int i = 0; i <= 3; i++) {
        X = (int)((70 + i)*sin(210*(M_PI/180))) + 75;
        Z = (int)((70 + i)*cos(210*(M_PI/180))) + 75;
        (*S).putBox(X + x, X + x, 20 + y, 25 + y - i, Z, Z);
        (*S).putBox(X + x, X + x, 5 + y + i, 10 + y, Z, Z);
    }

    setColor(S, 94, 186, 255);
    for (int i = 0; i <= 120; i++) {
        X = (int)(70.3*sin((135 + ((double)90)/120*i)*(M_PI/180))) + 75;
        Z = (int)(70.3*cos((135 + ((double)90)/120*i)*(M_PI/180))) + 75;
        (*S).putBox(X + x, X + x, 12 + y, 18 + y, Z, Z);
    }
    setColor(S, 50,50,50);
    for (int i = 0; i <= 32; i++) {
        X = (int)(70.5*sin((135 + ((double)90)/32*i)*(M_PI/180))) + 75;
        Z = (int)(70.5*cos((135 + ((double)90)/32*i)*(M_PI/180))) + 75;
        (*S).putBox(X + x, X + x, 12 + y, 18 + y, Z, Z);
    }
}

void upperNose(Sculptor* S, int x, int y, int z) {
    setColor(S, 159,159,159);
    for (int i = 0; i < 66; i++) {
        (*S).putBox((6*i)/66 + x, -(6*i)/66 + 24 + x, y, -(13*i)/74 + 12 + y, i + z, i + z);
        if (i == 0) {
            continue;
        }
        (*S).cutBox((6*i)/66 + 1 + x, -(6*i)/66 + 23 + x, 1 + y, -(13*i)/74 + 11 + y, i + z, i + z);
    }
}

void lowerNose(Sculptor* S, int x, int y, int z) {
    setColor(S, 159,159,159);
    for (int i = 0; i < 66; i++) {
        (*S).putBox((6*i)/66 + x, -(6*i)/66 + 24 + x, (13*i)/74 + y, 12 + y, i + z, i + z);
        if (i == 0) {
            continue;
        }
        (*S).cutBox((6*i)/66 + 1 + x, -(6*i)/66 + 23 + x, (13*i)/74 + 1 + y, 11 + y, i + z, i + z);
    }
}

void leftHorn(Sculptor* S, int x, int y, int z) {
    for (int i = -6; i <= 78; i++) {
        setColor(S, 159,159,159);
        (*S).putBox(x, -(36*i)/79 + 43 + x, 5 + y, 5 + y, i + z, i + z);
        (*S).putBox(x, -(36*i)/79 + 43 + x, -1 + y, -1 + y, i + z, i + z);
        setColor(S, 120,120,120);
        (*S).putBox(x, -(36*i)/79 + 43 + x, 0 + y, 4 + y, i + z, i + z);
        if (i == 78) {
            continue;
        }
        (*S).cutBox(1 + x, -(36*i)/79 + 42 + x, y, 4 + y, i + z, i + z);
    }
}

void rightHorn(Sculptor* S, int x, int y, int z) {
    for (int i = -6; i <= 78; i++) {
        setColor(S, 159,159,159);
        (*S).putBox((36*i)/79 + x, 43 + x, -1 + y, -1 + y, i + z, i + z);
        (*S).putBox((36*i)/79 + x, 43 + x, 5 + y, 5 + y, i + z, i + z);
        setColor(S, 120,120,120);
        (*S).putBox((36*i)/79 + x, 43 + x, y, 4 + y, i + z, i + z);
        if (i == 78) {
            continue;
        }
        (*S).cutBox((36*i)/79 + 1 + x, 42 + x, y, 4 + y, i + z, i + z);
    }
    setColor(S, 120, 120, 120);
    (*S).putCylinder(21 + x, 3.5 + y, 25 + z, 21 + x, 5.5 + y, 25 + z, 6);
    (*S).cutCylinder(21 + x, 4.5 + y, 25 + z, 21 + x, 5.5 + y, 25 + z, 5);
    (*S).putCylinder(31+ x, 3.5 + y, 48 + z, 31 + x, 5.5 + y, 48 + z, 6);
    (*S).cutCylinder(31+ x, 4.5 + y, 48 + z, 31 + x, 5.5 + y, 48 + z, 5);
    (*S).putCylinder(150 - 21 - x, 3.5 + y, 25 + z, 150 - 21 - x, 5.5 + y, 25 + z, 6);
    (*S).cutCylinder(150 - 21 - x, 4.5 + y, 25 + z, 150 - 21 - x, 5.5 + y, 25 + z, 5);
    (*S).putCylinder(150 - 31 - x, 3.5 + y, 48 + z, 150 - 31 - x, 5.5 + y, 48 + z, 6);
    (*S).cutCylinder(150 - 31 - x, 4.5 + y, 48 + z, 150 - 31 - x, 5.5 + y, 48 + z, 5);
}

void cabinTube(Sculptor* S, int x, int y, int z) {
    setColor(S, 159,159,159);
    (*S).putSphere(18 + x, 18 + y, 44 + z, 9);
    (*S).cutSphere(18 + x, 18 + y, 44 + z, 8);
    (*S).putCylinder(18 + x, 18 + y, 44 + z, 62.16 + x, 19.27 + y, 18.59 + z, 9);
    (*S).cutCylinder(18 + x, 18 + y, 44 + z, 62.16 + x, 19.27 + y, 18.59 + z, 8);
    (*S).putCylinder(18 + x, 18 + y, 44 + z, 18 + x, 18 + y, 60 + z, 9);
    (*S).cutCylinder(18 + x, 18 + y, 44 + z, 18 + x, 18 + y, 60 + z, 8);
    for (int i = 0; i <= 10; i++) {
        (*S).putCylinder(18 + x, 18 + y, 60.5 + i + z, 18 + x, 18 + y, 61.5 + i + z, -(4*i)/11 + 8.5);
        (*S).cutCylinder(18 + x, 18 + y, 60.5 + i + z, 18 + x, 18 + y, 61.5 + i + z, -(4*i)/11 + 7.5);
    }
    (*S).putCylinder(18 + x, 18 + y, 71.5 + z, 18 + x, 18 + y, 72.5 + z, 4.5);
    (*S).cutCylinder(18 + x, 18 + y, 71.5 + z, 18 + x, 18 + y, 72.5 + z, 2.5);
    (*S).putCylinder(18 + x, 18 + y, 72.5 + z, 18 + x, 18 + y, 73.5 + z, 2.5);

    setColor(S, 50, 50, 50);
    (*S).putBox(17 + x, 19 + x, 26 + y, 26 + y, 63 + z, 63 + z);
    (*S).putBox(17 + x, 19 + x, 25 + y, 25 + y, 64 + z, 66 + z);
    (*S).putBox(17 + x, 19 + x, 24 + y, 24 + y, 67 + z, 69 + z);
    (*S).putBox(17 + x, 19 + x, 23 + y, 23 + y, 70 + z, 70 + z);

    (*S).putBox(22+ x, 22 + x, 25 + y, 25 + y, 61 + z, 63 + z);
    (*S).putBox(21 + x, 21 + x, 25 + y, 25 + y, 62 + z, 63 + z);
    (*S).putBox(21 + x, 22 + x, 24 + y, 24 + y, 64 + z, 66 + z);
    (*S).putBox(21 + x, 22 + x, 23 + y, 23 + y, 67 + z, 69 + z);

    (*S).putBox(36 - 22 + x, 36 - 22 + x, 25 + y, 25 + y, 61 + z, 63 + z);
    (*S).putBox(36 - 21 + x, 36 - 21 + x, 25 + y, 25 + y, 62 + z, 63 + z);
    (*S).putBox(36 - 22 + x, 36 - 21 + x, 24 + y, 24 + y, 64 + z, 66 + z);
    (*S).putBox(36 - 22 + x, 36 - 21 + x, 23 + y, 23 + y, 67 + z, 69 + z);

    (*S).putBox(24 + x, 24 + x, 23 + y, 24 + y, 61 + z, 63 + z);
    (*S).putBox(25 + x, 25 + x, 21 + y, 22 + y, 61 + z, 63 + z);
    (*S).putBox(24 + x, 24 + x, 21 + y, 22 + y, 64 + z, 66 + z);
    (*S).putBox(23 + x, 23 + x, 21 + y, 21 + y, 67 + z, 69 + z);

    (*S).putBox(36 - 24 + x, 36 - 24 + x, 23 + y, 24 + y, 61 + z, 63 + z);
    (*S).putBox(36 - 25 + x, 36 - 25 + x, 21 + y, 22 + y, 61 + z, 63 + z);
    (*S).putBox(36 - 24 + x, 36 - 24 + x, 21 + y, 22 + y, 64 + z, 66 + z);
    (*S).putBox(36 - 23 + x, 36 - 23 + x, 21 + y, 21 + y, 67 + z, 69 + z);

    (*S).putBox(16 + x, 17 + x, 20 + y, 21 + y, 72 + z, 72 + z);
    (*S).putBox(36 - 17 + x, 36 - 16 + x, 20 + y, 21 + y, 72 + z, 72 + z);

    (*S).putBox(15 + x, 15 + x, 18 + y, 19 + y, 72 + z, 72 + z);
    (*S).putBox(36 - 15 + x, 36 - 15 + x, 18 + y, 19 + y, 72 + z, 72 + z);

    (*S).putBox(17 + x, 19 + x, 17 + y, 19 + y, 73 + z, 73 + z);
}

void sideTube(Sculptor* S, int x, int y, int z) {
    setColor(S, 159,159,159);
    for (int i = 0; i <= 4; i++) {
        (*S).putBox(x, 41 + x, -(9*i)/5 + 8 + y, (9*i)/5 + 22 + y, i + z, i + z);
        if (i == 0) {
            continue;
        }
        (*S).cutBox(1 + x, 40 + x, -(9*i)/5 + 10 + y, (9*i)/5 + 20 + y, i + z, i + z);
    }
    for (int i = 5; i <= 15; i++) {
        (*S).putBox(x, 41 + x, y, 30 + y, i + z, i + z);
        (*S).cutBox(1 + x, 40 + x, 1 + y, 29 + y, i + z, i + z);
    }
    for (int i = 16; i <= 20; i++) {
        (*S).putBox(x, 41 + x, (90*i - 9)/50 - 27 + y, -(90*i - 9)/50 + 57 + y, i + z, i + z);
        if (i == 20) {
            continue;
        }
        (*S).cutBox(1 + x, 40 + x, (90*i - 9)/50 - 25 + y, -(90*i - 9)/50 + 55 + y, i + z, i + z);
    }
}

void leftTruncCone(Sculptor* S, int x, int y, int z) {
    setColor(S, 159,159,159);
    for (int i = 0; i <= 12; i++) {
        (*S).cutBox(i + x, i + x, y, 17 + y, -(3*i)/12 + z, (3*i)/12 + 20 + z);
    }
    (*S).putBox(8 + x, 8 + x, 5 + y, 11 + y, 23 + z, 23 + z);
    (*S).putBox(4 + x, 7 + x, 3 + y, 13 + y, 22 + z, 22 + z);
    (*S).putBox(x, 3 + x, 2 + y, 14 + y, 21 + z, 21 + z);
    (*S).putBox(8 + x, 8 + x, 5 + y, 11 + y, -3 + z, -3 + z);
    (*S).putBox(4 + x, 7 + x, 3 + y, 13 + y, -2 + z, -2 + z);
    (*S).putBox(x, 3 + x, 2 + y, 14 + y, -1 + z, -1 + z);
    for (int i = 0; i <= 7; i++) {
        (*S).putCylinder(-0.5 + i + x, 8 + y, 10 + z, 0.5 + i + x, 8 + y, 10 + z,-((float)(2.5*i))/7 + 10.5);
        if (i == 6) {
            setColor(S, 120,120,120);
            (*S).putCylinder(-0.5 + i + x, 8 + y, 10 + z, 0.5 + i + x, 8 + y, 10 + z,-((float)(2.5*i))/7 + 9.5);
            setColor(S, 159,159,159);
            continue;
        }
        (*S).cutCylinder(-0.5 + i + x, 8 + y, 10 + z, 0.5 + i + x, 8 + y, 10 + z,-((float)(2.5*i))/7 + 9.5);
    }
}

void rightTruncCone(Sculptor* S, int x, int y, int z) {
    setColor(S, 159,159,159);
    for (int i = 12; i >= 0; i--) {
        (*S).cutBox(12 - i + x, 12 - i + x, y, 17 + y, -(3*i)/12 + z, (3*i)/12 + 20 + z);
    }
    (*S).putBox(4 + x, 4 + x, 5 + y, 11 + y, 23 + z, 23 + z);
    (*S).putBox(5 + x, 8 + x, 3 + y, 13 + y, 22 + z, 22 + z);
    (*S).putBox(9 + x, 12 + x, 2 + y, 14 + y, 21 + z, 21 + z);
    (*S).putBox(4 + x, 4 + x, 5 + y, 11 + y, -3 + z, -3 + z);
    (*S).putBox(5 + x, 8 + x, 3 + y, 13 + y, -2 + z, -2 + z);
    (*S).putBox(9 + x, 12 + x, 2 + y, 14 + y, -1 + z, -1 + z);
    for (int i = 7; i >= 0; i--) {
        (*S).putCylinder(12.5 - i + x, 8 + y, 10 + z, 11.5 - i + x, 8 + y, 10 + z,-((float)(2.5*i))/7 + 10.5);
        if (i == 6) {
            setColor(S, 120,120,120);
            (*S).putCylinder(12.5 - i + x, 8 + y, 10 + z, 11.5 - i + x, 8 + y, 10 + z,-((float)(2.5*i))/7 + 9.5);
            setColor(S, 159,159,159);
            continue;
        }
        (*S).cutCylinder(12.5 - i + x, 8 + y, 10 + z, 11.5 - i + x, 8 + y, 10 + z,-((float)(2.5*i))/7 + 9.5);
    }
}

void windows(Sculptor* S, int x, int y, int z) {
    setColor(S, 50,50,50);
    (*S).putCylinder(75 + x, 30.94 + y, 45.59 + z, 75 + x, 28.95 + y, 45.83 + z, 5.6);
    (*S).putCylinder(86.51 + x, 28.96 + y, 48.23 + z, 86.61 + x, 30.94 + y, 48.02 + z, 5.6);
    (*S).putCylinder(63.49 + x, 28.96 + y, 48.23 + z, 63.33 + x, 30.94 + y, 48.02 + z, 5.6);
    (*S).putCylinder(75 + x, 26.69 + y, 31.26 + z, 75 + x, 29.02 + y, 30.82 + z, 5.6);
    (*S).putCylinder(92.21 + x, 26.7 + y, 34.83 + z, 92.36 + x, 28.96 + y, 34.45 + z, 5.6);
    (*S).putCylinder(57.79 + x, 26.7 + y, 34.83 + z, 57.64 + x, 28.96 + y, 34.45 + z, 5.6);
}

void topGun(Sculptor* S, int x, int y, int z) {
    setColor(S, 180, 180, 180);
    (*S).putBox(x, 4 + x, y, y, z, 5 + z);
    (*S).cutBox(x, x, y, y, z, 1 + z);
    (*S).cutBox(4 + x, 4 + x, y, y, z, 1 + z);
    (*S).putBox(1 + x, 3 + x, 1 + y, 1 + y, 2 + z, 5 + z);
    (*S).putVoxel(2 + x, 1 + y, 6 + z);
    (*S).putBox(x, 4 + x, 1 + y, 1 + y, 7 + z, 7 + z);
    (*S).putBox(4 + x, 4 + x, 1 + y, 1 + y, 8 + z, 10 + z);
    (*S).putBox(x, x, 1 + y, 1 + y, 8 + z, 10 + z);
    (*S).putBox(1 + x, 3 + x, y, 2 + y, 8 + z, 10 + z);
    (*S).putBox(1 + x, 1 + x, y, y, 11 + z, 18 + z);
    (*S).putBox(3 + x, 3 + x, y, y, 11 + z, 18 + z);
    (*S).putBox(1 + x, 1 + x, 2 + y, 2 + y, 11 + z, 18 + z);
    (*S).putBox(3 + x, 3 + x, 2 + y, 2 + y, 11 + z, 18 + z);
}

void bottomGun(Sculptor* S, int x, int y, int z) {
    setColor(S, 180, 180, 180);
    (*S).putBox(x, 4 + x, 2 + y, 2 + y, z, 5 + z);
    (*S).cutBox(x, x, 2 + y, 2 + y, z, 1 + z);
    (*S).cutBox(4 + x, 4 + x, 2 + y, 2 + y, z, 1 + z);
    (*S).putBox(1 + x, 3 + x, 1 + y, 1 + y, 2 + z, 5 + z);
    (*S).putVoxel(2 + x, 1 + y, 6 + z);
    (*S).putBox(x, 4 + x, 1 + y, 1 + y, 7 + z, 7 + z);
    (*S).putBox(4 + x, 4 + x, 1 + y, 1 + y, 8 + z, 10 + z);
    (*S).putBox(x, x, 1 + y, 1 + y, 8 + z, 10 + z);
    (*S).putBox(1 + x, 3 + x, y, 2 + y, 8 + z, 10 + z);
    (*S).putBox(1 + x, 1 + x, y, y, 11 + z, 18 + z);
    (*S).putBox(3 + x, 3 + x, y, y, 11 + z, 18 + z);
    (*S).putBox(1 + x, 1 + x, 2 + y, 2 + y, 11 + z, 18 + z);
    (*S).putBox(3 + x, 3 + x, 2 + y, 2 + y, 11 + z, 18 + z);
}

void antenna(Sculptor* S, int x, int y, int z) {
    setColor(S, 159,159,159);
    (*S).putCylinder(106.15 + x, 41.17 + y, 116.74 + z, 106.15 + x, 41.44 + y, 117.7 + z, 5);
    (*S).putCylinder(106.15 + x, 41.44 + y, 117.7 + z, 106.15 + x, 41.71 + y, 118.66 + z, 7);
    (*S).cutCylinder(106.15 + x, 41.44 + y, 117.7 + z, 106.15 + x, 41.71 + y, 118.66 + z, 4.5);
    (*S).putCylinder(106.15 + x, 41.71 + y, 118.66 + z, 106.15 + x, 41.97 + y, 119.63 + z, 8);
    (*S).cutCylinder(106.15 + x, 41.71 + y, 118.66 + z, 106.15 + x, 41.97 + y, 119.63 + z, 6.2);
    (*S).putVoxel(104 + x, 45 + y, 115 + z);
    (*S).putVoxel(104 + x, 44 + y, 114 + z);
    (*S).putVoxel(104 + x, 43 + y, 113 + z);
    (*S).putVoxel(104 + x, 42 + y, 114 + z);
    (*S).putVoxel(104 + x, 41 + y, 115 + z);
    (*S).putVoxel(104 + x, 40 + y, 116 + z);
    (*S).putVoxel(104 + x, 39 + y, 117 + z);

    (*S).putVoxel(108 + x, 45 + y, 115 + z);
    (*S).putVoxel(108 + x, 44 + y, 114 + z);
    (*S).putVoxel(108 + x, 43 + y, 113 + z);
    (*S).putVoxel(108 + x, 42 + y, 114 + z);
    (*S).putVoxel(108 + x, 41 + y, 115 + z);
    (*S).putVoxel(108 + x, 40 + y, 116 + z);
    (*S).putVoxel(108 + x, 39 + y, 117 + z);

    (*S).putBox(105 + x, 107 + x, 43 + y, 43 + y, 113 + z, 113 + z);
    (*S).putBox(103 + x, 103 + x, 43 + y, 43 + y, 112 + z, 114 + z);
    (*S).putBox(109 + x, 109 + x, 43 + y, 43 + y, 112 + z, 114 + z);

    (*S).putVoxel(103 + x, 42 + y, 112 + z);
    (*S).putVoxel(103 + x, 41 + y, 112 + z);
    (*S).putVoxel(103 + x, 40 + y, 111 + z);
    (*S).putVoxel(103 + x, 39 + y, 111 + z);
    (*S).putVoxel(103 + x, 38 + y, 111 + z);
    (*S).putVoxel(103 + x, 37 + y, 111 + z);

    (*S).putVoxel(109 + x, 42 + y, 112 + z);
    (*S).putVoxel(109 + x, 41 + y, 112 + z);
    (*S).putVoxel(109 + x, 40 + y, 111 + z);
    (*S).putVoxel(109 + x, 39 + y, 111 + z);
    (*S).putVoxel(109 + x, 38 + y, 111 + z);
    (*S).putVoxel(109 + x, 37 + y, 111 + z);

    (*S).putVoxel(103 + x, 42 + y, 114 + z);
    (*S).putVoxel(103 + x, 41 + y, 114 + z);
    (*S).putVoxel(103 + x, 40 + y, 115 + z);
    (*S).putVoxel(103 + x, 39 + y, 115 + z);
    (*S).putVoxel(103 + x, 38 + y, 115 + z);
    (*S).putVoxel(103 + x, 37 + y, 115 + z);
    (*S).putVoxel(103 + x, 36 + y, 115 + z);

    (*S).putVoxel(109 + x, 42 + y, 114 + z);
    (*S).putVoxel(109 + x, 41 + y, 114 + z);
    (*S).putVoxel(109 + x, 40 + y, 115 + z);
    (*S).putVoxel(109 + x, 39 + y, 115 + z);
    (*S).putVoxel(109 + x, 38 + y, 115 + z);
    (*S).putVoxel(109 + x, 37 + y, 115 + z);
    (*S).putVoxel(109 + x, 36 + y, 115 + z);
}

void cleanInside(Sculptor* S, int x, int y, int z) {
    (*S).cutEllipsoid(75 + x, 15 + y, 75 + z, 62, 13, 62);
}

void line(Sculptor* S, int* A, int* B) {

}

int main() {
    Sculptor falcon(400,400,250);

    body(&falcon, 0, 10, 0);
    /*upperNose(&falcon, 63, 29, 93);
    lowerNose(&falcon, 63, 9, 93);
    leftHorn(&falcon, 83, 23, 127);
    rightHorn(&falcon, 24, 23, 127);
    cabinTube(&falcon,-8,12,73);
    sideTube(&falcon, 15, 10, 65);
    sideTube(&falcon, 94, 10, 65);
    leftTruncCone(&falcon, 136, 17, 65);
    rightTruncCone(&falcon, 2, 17, 65);
    cleanInside(&falcon, 0, 10, 0);
    windows(&falcon, 0, 10, 0);
    topGun(&falcon, 73, 42, 70);
    bottomGun(&falcon, 73, 6, 70);
    antenna(&falcon, 0, 0, 0);
    setColor(&falcon, 134, 1, 2);
    falcon.putBox(83, 87, 28, 28, 147, 155);*/

    falcon.writeOFF("falcon.off");

    return 0;
}
