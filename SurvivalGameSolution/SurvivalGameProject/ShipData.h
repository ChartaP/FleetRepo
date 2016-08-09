#pragma once



typedef struct
{
	INT xScale;
	INT yScale;
	INT ShipType;
	INT ShipImg;
	INT ShipSpeed;


}ShipData;

#define SHIP_TEST_TEST_INDEX 0
#define SHIP_TEST_TEST_DATA {1,1,1,1}

extern ShipData ShipDataDir[128];