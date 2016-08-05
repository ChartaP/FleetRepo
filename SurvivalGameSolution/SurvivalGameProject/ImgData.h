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


//Map
#define MAP_SEA01_INDEX 4000
#define MAP_SEA01_DATA {1,1,64,64}

extern ImgData ShipDir[128];
extern ImgData WeaponDir[128];
extern ImgData UIDir[128];
extern ImgData MapDir[128];
