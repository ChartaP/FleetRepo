#include "main.h"

FleetClass::FleetClass(ShipData* flagShipData)
{
	fleetScale = 1;
	fleetFormation = FORMATION_RING;

	childShip[0]= new ShipClass();
	flagShip = childShip[0];
}

ShipClass* FleetClass::getFlagShip()//���� ��ȯ
{
	return flagShip;
}

ShipClass* FleetClass::getChildShip(INT num)//�Ҽ��� ��ȯ
{
	return childShip[num];
}

INT FleetClass::getFleetScale()//�Դ� �Ը� ��ȯ
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

VOID FleetClass::Update()//�Դ� ���� ������Ʈ
{

}

VOID FleetClass::FleetDraw(HDC hdc, HBITMAP hBit)
{

}