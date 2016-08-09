#pragma once

class ShipClass
{
private:
	INT xPos;
	INT yPos;
	INT xScale;
	INT yScale;
	INT ShipType;
	INT ShipImg;
	INT ShipSpeed;

	ShipZone Bow;
	ShipZone Body;
	ShipZone Stern;
	ShipZone Bridge;
	ShipZone Chimney;
	ShipZone Hangar;

public:
	ShipClass();
	VOID setShip(ShipData*);
	VOID setPosition(INT,INT);
	VOID Update();
};