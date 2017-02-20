#include "SceneManager.h"
#include "Application.h"

void SceneManager::addScene(Scene * scene)
{
	SceneDataBase[SceneDataBase.size()] = scene;
}

void SceneManager::initAllScene()
{
	for (int i = 0; i < SceneDataBase.size(); i++)
	{
		SceneDataBase[i]->Init();
	}
	quit = false;
}

void SceneManager::quitAllScene()
{
	for (int i = 0; i < SceneDataBase.size(); i++)
	{
		SceneDataBase[i]->Exit();
		delete SceneDataBase[i];
	}
}

void SceneManager::setNextScene(int sceneID)
{
	if (sceneID >= SceneDataBase.size())
		currSceneID = SceneDataBase.size() - 1;

	currSceneID = sceneID;
}
int SceneManager::getCurrentScene()
{
	sceneat = currSceneID;
	return currSceneID;
}
int SceneManager::go()
{
	return sceneat;
}
void SceneManager::update()
{
	SceneManager::getSceneManger()->SceneDataBase[currSceneID]->Update(Application::m_timer.getElapsedTime());
	SceneManager::getSceneManger()->SceneDataBase[currSceneID]->Render();
	//Swap buffers
	glfwSwapBuffers(Application::m_window);
	//Get and organize events, like keyboard and mouse input, window resizing, etc...
	glfwPollEvents();
	Application::m_timer.waitUntil(Application::frameTime);       // Frame rate limiter. Limits each frame to a specified time in ms.   

}
//void SceneManager::cmpls()
//{
//	glfwGetWindowSize(Application::m_window, &wx, &wy);
//	glfwGetCursorPos(Application::m_window, &cx, &cy);
//}
bool SceneManager::isQuit()
{
	return quit;
}

void SceneManager::setQuit()
{
	quit = true;
}