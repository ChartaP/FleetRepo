#pragma once
class SceneMng
{
public :

	VOID ChangeScene(CHAR*name);
	CHAR* GetCurrentScene();

	VOID Update();

private :

	SceneClass *curScene;
	SceneClass *PrevScene;

	GameScene *gameScene;

};