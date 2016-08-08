#include "main.h"

SceneMng::SceneMng()
{
	curScene = NULL;
	PrevScene = NULL;
	gameScene = new GameScene();
}

VOID SceneMng::ChangeScene(TCHAR*name)
{
	if (_tcscmp(name, TEXT("GameScene")) == 0)
	{
		if (curScene != NULL)
			PrevScene = curScene;
		curScene = gameScene;
	}
}

TCHAR* SceneMng::GetCurrentScene() 
{
	if (curScene != NULL)
		return curScene->name;
	else
		return NULL;
}

VOID SceneMng::Update()
{
	if (curScene!=NULL)
	{
		curScene->Update();
	}
}
