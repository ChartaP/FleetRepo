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

}

VOID GameScene::Exit()
{

}