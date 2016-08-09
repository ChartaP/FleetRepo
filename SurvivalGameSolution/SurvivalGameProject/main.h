#pragma once
#pragma comment(lib, "Msimg32.lib")
#include <Windows.h>
#include <tchar.h>

#include <list>

#include "GameMng.h"

#include "ImgData.h"
#include "ShipData.h"

#include "ShipClass.h"

#include "FleetClass.h"

//Scene Header

#include "SceneClass.h"
#include "GameScene.h"
#include "SceneMng.h"

//Projectile Header

//#include "ProjectileClass.h"

HBITMAP* LoadBitmap(TCHAR*);
VOID setImgDir();
VOID DrawBitmap(HDC, INT, INT, INT, INT, INT, HBITMAP);
VOID DrawWorldMap(HDC, HBITMAP);