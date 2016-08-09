#pragma once

#define SHIPTYPE_BATTLESHIP		0;
#define SHIPTYPE_CORVETT		1;
#define SHIPTYPE_CRUISER		2;
#define SHIPTYPE_DESTROYER		3;
#define SHIPTYPE_FRIGATE		4;
#define SHIPTYPE_PATROLKILLER	5;

#define SHIPZONE_NORMAL		0;
#define SHIPZONE_MINOR		1;
#define SHIPZONE_MIDDLE		2;
#define SHIPZONE_SERIOUS	3;

typedef struct
{
	INT HP;
	INT ARMOR;
	INT STATE;
}ShipZone;

typedef struct
{
	INT xScale;
	INT yScale;
	INT ShipType;
	INT ShipImg;
	INT ShipSpeed;

	ShipZone Bow;
	ShipZone Body;
	ShipZone Stern;
	ShipZone Bridge;
	ShipZone Chimney;
	ShipZone Hangar;
}ShipData;

#define SHIP_TEST_TEST_INDEX 0
#define SHIP_TEST_TEST_DATA {22,166,2,1000,30,{1000,200,0},{2000,200,0},{1500,200,0},{500,50,0},{500,100,0},{500,25,0}}

extern ShipData ShipDataDir[128];