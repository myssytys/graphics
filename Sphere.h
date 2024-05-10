#ifndef SPHERE_H
#define SPHERE_H

#include <vector>
#include <glm/glm.hpp>

class Sphere {

public:
    struct Vertex {
        glm::vec3 pos;
        glm::vec4 colors;
        glm::vec2 texCoords;
        glm::vec3 normals;
    };
    
    std::vector<Vertex> Data;
    std::vector<uint16_t> indices;
    float phi;
    float dphi;
    float theta;
    float dtheta;
    int lon;
    int lat;
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