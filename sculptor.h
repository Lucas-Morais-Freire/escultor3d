#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
  float r,g,b; // Colors
  float a;
// Transparency
  bool isOn; // Included or not
};

class Sculptor {
private:
    Voxel ***v;
    // 3D matrix
    int nx,ny,nz; // Dimensions
    float r, g, b, a; // Current drawing color
public:
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void setColor(float _r, float _g, float _b, float _a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void putCylinder(float xa, float ya, float za, float xb, float yb, float zb, float rad);
    void cutCylinder(float xa, float ya, float za, float xb, float yb, float zb, float rad);
    void writeOFF(const char* filename);
};

#endif
