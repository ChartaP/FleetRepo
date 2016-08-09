#pragma once

class FleetClass
{
private:

	INT fleetScale;
	ShipClass* flagShip;
	ShipClass childShip[8];

public:

	ShipClass* getFlagShip();
	ShipClass* getChildShip(INT);
	INT getFleetScale();
	VOID Update();

};
