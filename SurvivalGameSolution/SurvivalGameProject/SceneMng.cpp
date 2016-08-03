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
		curScene = gameScene;
	}
}

TCHAR* SceneMng::GetCurrentScene() 
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