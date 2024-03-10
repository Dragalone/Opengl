#include "assetmanager.h"

AssetManager::AssetManager()
{
    // Добавляем дженерики в список, которые всегда должны быть
    this->addTexture("__generic__", "generic/generic.png");
    this->addTexture("__generic_specular__", "generic/generic.spec.png");
}

AssetManager::~AssetManager()
{

}

void AssetManager::addModel(std::string name, std::string folder, std::string modelFileName)
{
    models[name] = Model(folder + "/" + modelFileName, folder);
    // models.push_back(Model(folder + "/" + modelFileName, folder));
    // return models.size() - 1;
}

void AssetManager::addTexture(std::string name, std::string texturePath)
{
    textures[name] = Texture(texturePath);
}

Model & AssetManager::getModel(std::string name)
{
    ModelsMap::iterator pos = models.find(name);
    if (pos == models.end()) {
        return genericModel;
    } else {
        return pos->second;
    }
}

Texture & AssetManager::getTexture(std::string name)
{
    TexturesMap::iterator pos = textures.find(name);
    if (pos == textures.end()) {
        return genericTexture;
    } else {
        return pos->second;
    }
}



// void AssetManager::addTexture(std::string name, std::string textureFile)
// {
//     textures[name] = Texture(textureFile);
// }

/*
Model& AssetManager::getModel(std::string name)
{
    ModelsMap::iterator pos = models.find(name);
    if (pos == models.end()) {
        return sampleModel;
    } else {
        // std::cout << "TEST: " << name << "; " << pos->second.getModelPath() << " " << pos->second.getMTLPath() << "\n";
        return pos->second;
    }
}

void AssetManager::importModel(std::string name)
{
    ModelsMap::iterator pos = models.find(name);
    if (pos != models.end()) {
        // auto& asd = pos->second;
        pos->second.importModel();
    }
}
*/

// Texture& AssetManager::getTexture(std::string name)
// {
//     TexturesMap::const_iterator pos = textures.find(name);
//     if (pos == textures.end()) {
//         return Texture();
//     } else {
//         return textures[name];
//     }
// }


