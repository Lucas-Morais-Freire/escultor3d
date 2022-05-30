#include "sculptor.h"
#include <iostream>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx; ny = _ny; nz = _nz;
    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    for (int i = 1; i < nx; i++) {
        v[i] = v[i - 1] + ny;
    }
    v[0][0] = new Voxel[nx*ny*nz];
    for (int i = 1; i < nx*ny; i++) {
        v[0][i] = v[0][i - 1] + nz;
    }
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].isOn = false;
            }
        }
    }
    r = g = b = a = 0;
}

Sculptor::~Sculptor() {
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

void Sculptor::setColor(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) {
    r = _r; g = _g; b = _b; a = _a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if (0 <= x && x < nx && 0 <= y && y < ny && 0 <= z && z < nz) {
        v[x][y][z].isOn = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    if (0 <= x && x < nx && 0 <= y && y < ny && 0 <= z && z < nz) {
        v[x][y][z].isOn = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                if (0 <= i && i < nx && 0 <= j && j < ny && 0 <= k && k < nz) {
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                if (0 <= i && i < nx && 0 <= j && j < ny && 0 <= k && k < nz) {
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for (int i = xcenter - radius; i <= xcenter + radius; i++) {
        for (int j = ycenter - radius; j <= ycenter + radius; j++) {
            for (int k = zcenter - radius; k <= zcenter + radius; k++) {
                if (0 <= i && i < nx && 0 <= j && j < ny && 0 <= k && k < nz) {
                    if ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter) <= radius*radius) {
                        v[i][j][k].isOn = true;
                        v[i][j][k].r = r;
                        v[i][j][k].g = g;
                        v[i][j][k].b = b;
                        v[i][j][k].a = a;
                    }
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for (int i = xcenter - radius; i <= xcenter + radius; i++) {
        for (int j = ycenter - radius; j <= ycenter + radius; j++) {
            for (int k = zcenter - radius; k <= zcenter + radius; k++) {
                if (0 <= i && i < nx && 0 <= j && j < ny && 0 <= k && k < nz) {
                    if ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter) <= radius*radius) {
                        v[i][j][k].isOn = false;
                    }
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    long long xc = (long long)xcenter;
    long long yc = (long long)ycenter;
    long long zc = (long long)zcenter;
    unsigned long long Rx = (unsigned long long)rx;
    unsigned long long Ry = (unsigned long long)ry;
    unsigned long long Rz = (unsigned long long)rz;
    for (long long i = xc - (long long)Rx; i <= xc + (long long)Rx; i++) {
        for (long long j = yc - (long long)Ry; j <= yc + (long long)Ry; j++) {
            for (long long k = zc - (long long)Rz; k <= zc + (long long)Rz; k++) {
                if (0 <= i && i < nx && 0 <= j && j < ny && 0 <= k && k < nz) {
                    if (((unsigned long long)((i - xc)*(i - xc)))*Ry*Ry*Rz*Rz + ((unsigned long long)((j - yc)*(j - yc)))*Rx*Rx*Rz*Rz + ((unsigned long long)((k - zc)*(k - zc)))*Ry*Ry*Rx*Rx <= Rx*Rx*Ry*Ry*Rz*Rz) {
                        v[i][j][k].isOn = true;
                        v[i][j][k].r = r;
                        v[i][j][k].g = g;
                        v[i][j][k].b = b;
                        v[i][j][k].a = a;
                    }
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    long long xc = (long long)xcenter;
    long long yc = (long long)ycenter;
    long long zc = (long long)zcenter;
    unsigned long long Rx = (unsigned long long)rx;
    unsigned long long Ry = (unsigned long long)ry;
    unsigned long long Rz = (unsigned long long)rz;
    for (long long i = xc - (long long)Rx; i <= xc + (long long)Rx; i++) {
        for (long long j = yc - (long long)Ry; j <= yc + (long long)Ry; j++) {
            for (long long k = zc - (long long)Rz; k <= zc + (long long)Rz; k++) {
                if (0 <= i && i < nx && 0 <= j && j < ny && 0 <= k && k < nz) {
                    if (((unsigned long long)((i - xc)*(i - xc)))*Ry*Ry*Rz*Rz + ((unsigned long long)((j - yc)*(j - yc)))*Rx*Rx*Rz*Rz + ((unsigned long long)((k - zc)*(k - zc)))*Ry*Ry*Rx*Rx <= Rx*Rx*Ry*Ry*Rz*Rz) {
                        v[i][j][k].isOn = false;
                    }
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename) {
    std::fstream fout;
    fout.open(filename, std::fstream::out);
    if (!fout.is_open()) {
        exit(1);
    }
    unsigned int vcount = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].isOn) {
                    vcount++;
                }
            }
        }
    }
    fout << "OFF\n" << vcount*8 << " " << vcount*6 << " 0\n";
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].isOn) {
                    fout << -0.5 + i << " " << 0.5 + j << " " << -0.5 + k << "\n" << -0.5 + i << " " << -0.5 + j << " " << -0.5 + k << "\n" << 0.5 + i << " " << -0.5 + j << " " << -0.5 + k << "\n" << 0.5 + i << " " << 0.5 + j << " " << -0.5 + k << "\n" << -0.5 + i << " " << 0.5 + j << " " << 0.5 + k << "\n" << -0.5 + i << " " << -0.5 + j << " " << 0.5 + k << "\n" << 0.5 + i << " " << -0.5 + j << " " << 0.5 + k << "\n" << 0.5 + i << " " << 0.5 + j << " " << 0.5 + k << "\n";
                }
            }
        }
    }
    unsigned int count = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].isOn) {
                    fout << "4 " << count << " " << 3 + count << " " << 2 + count << " " << 1 + count << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n" << "4 " << 4 + count << " " << 5 + count << " " << 6 + count << " " << 7 + count << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n" << "4 " << count << " " << 1 + count << " " << 5 + count << " " << 4 + count << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n" << "4 " << count << " " << 4 + count << " " << 7 + count << " " << 3 + count << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n" << "4 " << 3 + count << " " << 7 + count << " " << 6 + count << " " << 2 + count << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n" << "4 " << 1 + count << " " << 2 + count << " " << 6 + count << " " << 5 + count << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    count += 8;
                }
            }
        }
    }
    fout.close();
}
