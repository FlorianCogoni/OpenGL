#ifndef MESH_HPP
#define MESH_HPP

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <string>
#include <vector>
#include "Shader.hpp"

using namespace std;


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
};


struct Texture {
    GLuint id;
    string type;
    string path;
};


class Mesh {
private:
    vector<Vertex> vertices;
    vector<GLuint> indices;
    vector<Texture> textures;
    GLuint VAO, VBO, EBO;
    void setupMesh();
public:
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    void Draw(Shader shader);

    const vector<Vertex> &getVertices() const;

    void setVertices(const vector<Vertex> &vertices);

    const vector<GLuint> &getIndices() const;

    void setIndices(const vector<GLuint> &indices);

    const vector<Texture> &getTextures() const;

    void setTextures(const vector<Texture> &textures);

    GLuint getVAO() const;

    void setVAO(GLuint VAO);

    GLuint getVBO() const;

    void setVBO(GLuint VBO);

    GLuint getEBO() const;

    void setEBO(GLuint EBO);
};



#endif
