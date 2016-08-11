#pragma once
#pragma comment(lib, "Msimg32.lib")
#include <Windows.h>
#include <tchar.h>

#include <list>

#include "ImgData.h"
#include "ShipData.h"

#include "GameMng.h"

#include "ShipClass.h"

#include "FleetClass.h"

//Scene Header

#include "SceneClass.h"
#include "GameScene.h"
#include "SceneMng.h"

//Projectile Header

//#include "ProjectileClass.h"

#define ALPHA RGB(255, 0, 255)
#define PLAYERCOLOR RGB(255, 255, 0)

HBITMAP* LoadBitmap(TCHAR*);
VOID setImgDir();
VOID DrawLocalBitmap(HDC, INT, INT, INT, INT, INT, HBITMAP);
VOID DrawWorldBitmap(HDC, INT, INT, INT, INT, INT, HBITMAP);
VOID DrawWorldMap(HDC, HBITMAP);

extern GameMng* myGameMng;
extern RECT crt;
extern RECT GameScreen; //월드맵 클립영역