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

ShipClass* FleetClass::getFlagShip()//���� ��ȯ
{
	return flagShip;
}

ShipClass* FleetClass::getChildShip(INT num)//�Ҽ��� ��ȯ
{
	return &(childShip[num]);
}

INT FleetClass::getFleetScale()//�Դ� �Ը� ��ȯ
{
	return fleetScale;
}

VOID FleetClass::Update()//�Դ� ���� ������Ʈ
{

}