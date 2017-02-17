#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "Scene.h"
#include <map>
#include "PlayerBase.h"
#include "MapBase.h"
#include "RenderingBase.h"

using std::map;

class SceneManager
{
private:
	SceneManager()
	{
		currSceneID = nextSceneID = 0;
	}

	map<unsigned, Scene*> SceneDataBase;
	int currSceneID, nextSceneID;
	static SceneManager *s_instance;
	bool quit;

public:

	unsigned frameRate = 0;
	void addScene(Scene * scene);
	void setNextScene(int sceneID);
	int getCurrentScene();
	int go();
	void initAllScene();
	void quitAllScene();
	void update();
	bool isQuit();
	void setQuit();
	int sceneat = 0;
	static SceneManager* getSceneManger()
	{
		if (!s_instance)
		{
			s_instance = new SceneManager;
		}
		return s_instance;
	}

};


#endif