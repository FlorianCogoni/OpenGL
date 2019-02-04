#ifndef MODEL_HPP
#define MODEL_HPP

#include "Shader.hpp"
#include "Mesh.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


GLuint TextureFromFile(const char *path, const string &directory, bool gamma = false);

class Model {
public:
    Model(std::string path);
    void Draw(Shader shader);
private:
    vector<Texture> textures_loaded;
    vector<Mesh> meshes;
    string directory;
    void loadModel(string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};




#endif
