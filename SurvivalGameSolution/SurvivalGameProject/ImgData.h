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
#define UI_BACK01_INDEX 3000
#define UI_BACK01_DATA {177,1,126,126}

//Map
#define MAP_SEA01_INDEX 4000
#define MAP_SEA01_DATA {1,1,64,64}

extern ImgData ShipDir[128];
extern ImgData WeaponDir[128];
extern ImgData UIDir[128];
extern ImgData MapDir[128];
