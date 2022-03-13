#ifndef MESH_H
#define MESH_H

#include "glew.h"
#include "glfw3.h"

class Mesh
{
private:
    GLuint VBO, EBO;

public:
    GLuint ID;
    Mesh(GLfloat *vertices, int verticesSize, GLuint *indices, int indicesSize);
    ~Mesh();
};

#endif