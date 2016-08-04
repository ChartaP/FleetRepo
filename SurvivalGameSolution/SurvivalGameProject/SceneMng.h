#pragma once

class SceneMng
{
private :

	SceneClass* curScene;
	SceneClass* PrevScene;

	GameScene* gameScene;

public:

	SceneMng();

	VOID ChangeScene(TCHAR*);
	TCHAR* GetCurrentScene();

	VOID Update();

};