#include "main.h"

GameScene::GameScene()
{
	name[0] = NULL;
	lstrcpyn(name, TEXT("GameScene"), 16);

}

VOID GameScene::Enter()
{
	MyFleet = new FleetClass(&(myGameMng->myFlagShipData));
	MyFleet->setFleetPostion(800,400);
}

VOID GameScene::Update()
{
	MyFleet->Update();
}

VOID GameScene::Exit()
{

}

VOID GameScene::ScenePaint(HDC hMainDc, HDC hdc, HRGN *hRgn ,  HBITMAP hShipBit, HBITMAP hWeaponBit, HBITMAP hUIBit, HBITMAP hMapBit)
{
	DrawBitmap(hdc, crt.left, crt.top, crt.right, crt.bottom, IMG_UI_BACK01_INDEX, hUIBit);
	
	//클리핑 영역
	*hRgn = CreateEllipticRgn(GameScreen.left, GameScreen.top, GameScreen.right, GameScreen.bottom);
	SelectClipRgn(hMainDc, *hRgn);
	//월드맵
	DrawWorldMap(hdc, hMapBit);

	MyFleet->FleetPaint(hdc, hShipBit);
}