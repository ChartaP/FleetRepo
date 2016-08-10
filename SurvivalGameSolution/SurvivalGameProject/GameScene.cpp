#include "main.h"

GameScene::GameScene()
{
	name[0] = NULL;
	lstrcpyn(name, TEXT("GameScene"), 16);

}

VOID GameScene::Enter()
{
	MyFleet = new FleetClass(&(myGameMng->myFlagShipData));
}

VOID GameScene::Update()
{
	MyFleet->Update();
}

VOID GameScene::Exit()
{

}

VOID GameScene::ScenePaint(HDC hdc,  HBITMAP hBit)
{
	MyFleet->FleetPaint(hdc, hBit);
}