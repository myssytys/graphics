#ifndef CUBE_H
#define CUBE_H

#include <glm/glm.hpp>
#include <vector>

class Cube {
    
    public:

    struct Vertex {
        glm::vec3 pos;
        glm::vec4 colors;
        glm::vec2 texCoords;
    };
    
    //glm::vec3 vertices;
    std::vector<int> indices;
    std::vector<Vertex> Data;
    //glm::vec4 colors;
    //glm::vec2 texCoords;
    Cube();
    ~Cube();
    
};
#endif