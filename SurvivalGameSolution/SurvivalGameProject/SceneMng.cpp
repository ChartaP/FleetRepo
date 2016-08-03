#include "main.h"

VOID SceneMng::ChangeScene(CHAR*name)
{
	if (strcmp(name, "GameScene") == 0)
	{
		curScene = gameScene;
	}
}

CHAR* SceneMng::GetCurrentScene() 
{
	return curScene->name;
}

VOID SceneMng::Update()
{
	if (curScene!=NULL)
	{
		curScene->Update();
	}
}