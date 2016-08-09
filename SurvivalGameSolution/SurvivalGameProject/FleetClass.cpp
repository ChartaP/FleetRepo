#include "main.h"

FleetClass::FleetClass(ShipData* flagShipData)
{
	fleetScale = 1;
	fleetFormation = FORMATION_RING;

	childShip[0]= new ShipClass();
	flagShip = childShip[0];
}

ShipClass* FleetClass::getFlagShip()//기함 반환
{
	return flagShip;
}

ShipClass* FleetClass::getChildShip(INT num)//소속함 반환
{
	return childShip[num];
}

INT FleetClass::getFleetScale()//함대 규모 반환
{
	return fleetScale;
}

VOID FleetClass::addChildShip(ShipData*)
{

}

VOID FleetClass::setPostion(INT x,INT y)
{

}

VOID FleetClass::moveToPath()
{

}

VOID FleetClass::Update()//함대 상태 업데이트
{

}

VOID FleetClass::FleetDraw(HDC hdc, HBITMAP hBit)
{

}