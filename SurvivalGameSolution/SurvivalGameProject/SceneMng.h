#pragma once

class SceneMng
{
private:
	SceneClass* curScene = NULL;
	SceneClass* PrevScene = NULL;
	SceneClass* gameScene = NULL;

public:
	SceneMng();
	VOID ChangeScene(TCHAR*);
	TCHAR* GetCurrentScene();
	VOID Update();
};