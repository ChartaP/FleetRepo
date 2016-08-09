#include "main.h"

ShipClass* FleetClass::getFlagShip()
{
	return flagShip;
}

ShipClass* FleetClass::getChildShip(INT num)
{
	return &(childShip[num]);
}

INT FleetClass::getFleetScale()
{
	return fleetScale;
}

VOID FleetClass::Update()
{

}