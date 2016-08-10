#include "main.h"

FleetClass::FleetClass(ShipData* flagShipData)
{
	fleetScale = 1;
	fleetFormation = FORMATION_RING;

	childShip[0]= new ShipClass();
	childShip[0]->setShip(flagShipData);

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

VOID FleetClass::setFleetPostion(INT x,INT y)
{

}

VOID FleetClass::setChildPostion()
{
	INT i;
	INT x, y;
	INT distance = 100;
	INT angle;
	for (i=0;i<fleetScale;i++)
	{
		if (i==0)
		{
			childShip[0]->setPosition(xPos,yPos);
		}
		else
		{
			angle = 360 / i;

			x = cos(angle) * distance;
			y = sin(angle) * distance;

			childShip[0]->setPosition(xPos+x, yPos+y);
		}
	}
}

VOID FleetClass::moveToPath()
{

}

VOID FleetClass::Update()//�Դ� ���� ������Ʈ
{

}

VOID FleetClass::FleetPaint(HDC hdc, HBITMAP hBit)
{
	INT i;
	for (i=0;i<fleetScale;i++)
	{

	}
}