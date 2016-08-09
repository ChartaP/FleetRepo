#pragma once

class ShipClass
{
private:
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
	VOID setShip();
	VOID setPosition();
	VOID Update();
};