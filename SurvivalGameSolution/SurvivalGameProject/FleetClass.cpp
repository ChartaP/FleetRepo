#include "main.h"

FleetClass::FleetClass()
{
	fleetScale = 0;
	fleetFormation = FORMATION_RING;
	flagShip = NULL;
	memset(childShip, NULL, sizeof(ShipClass) * 8);
}

FleetClass::FleetClass(ShipData* shipData, INT scale)
{
	INT i;
	fleetScale = scale;
	fleetFormation = FORMATION_RING;

	

}

ShipClass* FleetClass::getFlagShip()//기함 반환
{
	return flagShip;
}

ShipClass* FleetClass::getChildShip(INT num)//소속함 반환
{
	return &(childShip[num]);
}

INT FleetClass::getFleetScale()//함대 규모 반환
{
	return fleetScale;
}

VOID FleetClass::Update()//함대 상태 업데이트
{

}