#pragma once

typedef struct
{
	INT xPos;
	INT yPos;
	INT xScale;
	INT yScale;
}ImgData;

//Ship


//Weapon


//UI
#define UI_IMG_BACK01_INDEX 3000
#define UI_IMG_BACK01_DATA {177,1,126,126}

//Map
#define MAP_IMG_SEA01_INDEX 4000
#define MAP_IMG_SEA01_DATA {1,1,64,64}

extern ImgData ShipImgDir[128];
extern ImgData WeaponImgDir[128];
extern ImgData UIImgDir[128];
extern ImgData MapImgDir[128];
