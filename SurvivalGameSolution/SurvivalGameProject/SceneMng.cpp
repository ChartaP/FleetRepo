#include "main.h"

SceneMng::SceneMng()
{
	curScene = NULL;
	PrevScene = NULL;
	gameScene = new GameScene();
}

VOID SceneMng::ChangeScene(TCHAR*name)
{
	if (curScene != NULL)
	{
		curScene->Exit();
		PrevScene = curScene;
	}
	if (_tcscmp(name, TEXT("GameScene")) == 0)
	{
		curScene = gameScene;
	}
	if (curScene != NULL)
	{
		curScene->Enter();
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

VOID SceneMng::ScenePaint(HDC hdc, HRGN *hRgn, HBITMAP hShipBit, HBITMAP hWeaponBit, HBITMAP hUIBit, HBITMAP hMapBit)
{
	curScene->ScenePaint(  hdc, hRgn, hShipBit, hWeaponBit, hUIBit, hMapBit);
}