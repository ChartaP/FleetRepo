#pragma once

typedef struct
{
	INT xPos;
	INT yPos;
	INT xScale;
	INT yScale;
}ImgData;

//Ship
#define IMG_UI_TEST01_INDEX 1000
#define IMG_UI_TEST02_DATA {1,1,22,166}

//Weapon


//UI
#define IMG_UI_BACK01_INDEX 3000
#define IMG_UI_BACK01_DATA {177,1,126,126}

//Map
#define IMG_MAP_SEA01_INDEX 4000
#define IMG_MAP_SEA01_DATA {1,1,64,64}

extern ImgData ShipImgDir[128];
extern ImgData WeaponImgDir[128];
extern ImgData UIImgDir[128];
extern ImgData MapImgDir[128];
