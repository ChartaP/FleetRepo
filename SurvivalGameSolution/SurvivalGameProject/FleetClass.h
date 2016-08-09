#pragma once

#define FORMATION_RING 0
#define FORMATION_LINE 1

class FleetClass
{
private:

	INT fleetScale;
	INT fleetFormation;
	ShipClass* flagShip;
	ShipClass childShip[8];

public:
	FleetClass();
	FleetClass(ShipData*, INT);
	ShipClass* getFlagShip();
	ShipClass* getChildShip(INT);
	INT getFleetScale();
	VOID Update();

};
