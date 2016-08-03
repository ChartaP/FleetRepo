#pragma once

class SceneMng
{
private :

	SceneClass* curScene;
	SceneClass* PrevScene;

	GameScene* gameScene;

public:

	VOID ChangeScene(CHAR*);
	CHAR* GetCurrentScene();

	VOID Update();

};