#pragma once

#define FORMATION_RING 0
#define FORMATION_LINE 1

class FleetClass
{
private:

	INT xPos;
	INT yPos;

	INT fleetScale;
	INT fleetFormation;
	ShipClass* flagShip;
	ShipClass* childShip[8];

public:
	FleetClass(ShipData*);

	ShipClass* getFlagShip();
	ShipClass* getChildShip(INT);
	INT getFleetScale();

	VOID addChildShip(ShipData*);
	VOID setFleetPostion(INT, INT);
	VOID setChildPostion();
	VOID moveToPath();

	VOID Update();

	VOID FleetDraw(HDC, HBITMAP);
};
