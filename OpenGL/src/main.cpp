#include "window.h"
#include "scene.h"
#include "logger.h"

int main()
{

	// Сначала создаем окно, чтобы у нас был OpenGL-контекст
	Window window;
	window.setSize(1280, 720);
	window.setTitle("OpenGL_scene");

	if(window.init() != 0)
		return 1;

	// Добавляем модели для загрузки перед отображением сцены
	window.assetManager.addModel("grass", "grass", "grass.obj"); 
	window.assetManager.addModel("ufo", "ufo", "ufo.obj");
	window.assetManager.addModel("house", "house", "Barn_001.obj");
	window.assetManager.addModel("cow", "cow", "cow.obj");
	window.assetManager.addModel("sheep", "sheep", "sheep.obj");
	// window.assetManager.addModel("b", "butterfly", "butterfly.obj");


	// Добавляем текстуры для загрузки перед отображением сцены
    window.assetManager.addTexture("grass", "grass/grass.png");
	window.assetManager.addTexture("ufo", "ufo/ufo2.png");
	window.assetManager.addTexture("house", "house/Barn_None_color.png");
	window.assetManager.addTexture("cow", "cow/cow.png");
	window.assetManager.addTexture("sheep", "sheep/sheep.png");
	// window.assetManager.addTexture("b", "butterfly/butterfly.png");

	// Инициализируем сцену
	Scene scene;

	// Располагаем объекты на сцене
	SceneObject grass;
	grass.material.requiredTextureName = "grass";
	grass.requireModel("grass");
	grass.position = glm::vec3(4, 4, 0);
	grass.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	scene.addSceneObject(grass);
	SceneObject cow;
	cow.material.requiredTextureName = "cow";
	cow.requireModel("cow");
	cow.position = glm::vec3(16.0, 5.2, 5.0);
//	cow.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	scene.addSceneObject(cow);
	SceneObject cow2;
	cow2.material.requiredTextureName = "cow";
	cow2.requireModel("cow");
	cow2.position = glm::vec3(8.0, 5.2, 0.0);
	cow2.angle = glm::radians(-70.f);
	//	cow.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	scene.addSceneObject(cow2);
	SceneObject house;
	house.material.requiredTextureName = "house";
	house.requireModel("house");
	house.position = glm::vec3(18.0, 4.9, -8.5);
	//house.scale = glm::vec3(1.0f, 25.0f, 25.0f);
	house.simpleAnimation = false;	scene.addSceneObject(house);

	SceneObject ufo;
	ufo.material.requiredTextureName = "ufo";
	ufo.requireModel("ufo");
	ufo.simpleAnimation = true;
	ufo.position = glm::vec3(-9.0, 15.2, 4);
	ufo.scale = glm::vec3(9.0f, 9.0f, 9.0f);
	scene.addSceneObject(ufo);

	SceneObject sheep;
	sheep.material.requiredTextureName = "sheep";

	sheep.requireModel("sheep");
	sheep.position = glm::vec3(1.0, 6.8, 5.0);
	sheep.scale = glm::vec3(1.5f, 1.5f, 1.5f);
	sheep.angle = glm::radians(-50.f);
	scene.addSceneObject(sheep);

	// Устанавливаем текущую сцену
	window.setScene(scene);
	window.requestPrepareCurrentScene();

	// Отрисовываем загрузку, затем сцену
	window.render();

	return 0;
}
