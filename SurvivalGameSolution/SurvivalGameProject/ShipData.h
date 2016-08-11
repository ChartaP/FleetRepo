#pragma once

#define SHIPTYPE_BATTLESHIP		0	//전함
#define SHIPTYPE_CORVETT		1	//초계함
#define SHIPTYPE_CRUISER		2	//순양함
#define SHIPTYPE_DESTROYER		3	//구축함
#define SHIPTYPE_FRIGATE		4	//호위함
#define SHIPTYPE_PATROLKILLER	5	//고속정

#define SHIPZONE_NORMAL		0	//멀정
#define SHIPZONE_MINOR		1	//소규모 피해
#define SHIPZONE_MIDDLE		2	//중간 피해
#define SHIPZONE_SERIOUS	3	//대규모 피해

typedef struct
{
	INT HP;				//체력	
	INT ARMOR;			//장갑
	INT STATE;			//상태
}ShipZone;

typedef struct
{
	INT xScale;			//x축 크기
	INT yScale;			//y축 크기
	INT ShipType;		//함종
	INT ShipImg;		//이미지 번호
	INT ShipSpeed;		//함 속도

	ShipZone Bow;		//선수
	ShipZone Body;		//선체
	ShipZone Stern;		//선미
	ShipZone Bridge;	//함교
	ShipZone Chimney;	//연돌
	ShipZone Hangar;	//격납고
}ShipData;

#define SHIP_TEST_TEST_INDEX 0
#define SHIP_TEST_TEST_DATA {22,166,SHIPTYPE_CRUISER,1000,30,{1000,200,SHIPZONE_NORMAL},{2000,200,SHIPZONE_NORMAL},{1500,200,SHIPZONE_NORMAL},{500,50,SHIPZONE_NORMAL},{500,100,SHIPZONE_NORMAL},{500,25,SHIPZONE_NORMAL}}

extern ShipData ShipDataDir[128];