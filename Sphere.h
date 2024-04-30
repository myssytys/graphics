#ifndef SPHERE_H
#define SPHERE_H

class Sphere {

public:

    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> colors;
    std::vector<float> texCoords;
    std::vector<int> indices;
    float phi;
    float dphi;
    float theta;
    float dtheta;
    int hseg;
    int vseg;
    float radius;
    float centerX;
    float centerY;
    float centerZ;

    Sphere(float centerX, float centerY, float centerZ, float radius, int hseg, int vseg);
    void UVSphere();
    void generateIcosahedron(float size);
    int getSize(const std::vector<float>&);
    float getRadius();
    void setRadius(float r);
    ~Sphere();


};

#endif