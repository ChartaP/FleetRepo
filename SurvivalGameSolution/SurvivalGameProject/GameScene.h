#pragma once

class GameScene : public SceneClass
{
public :
	GameScene();

	VOID Enter();
	VOID Update();
	VOID Exit();
	VOID ScenePaint(HDC, HDC, HRGN*, HBITMAP, HBITMAP, HBITMAP, HBITMAP);
protected:

private:
	FleetClass* MyFleet;

};