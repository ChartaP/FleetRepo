#pragma once

class SceneMng
{

private:

	SceneClass* curScene = NULL;
	SceneClass* PrevScene = NULL;

	GameScene* gameScene = NULL;


public:
	SceneMng();
	VOID ChangeScene(TCHAR*);
	TCHAR* GetCurrentScene();
	VOID Update();

};