#include "main.h"


ShipClass::ShipClass()
{

}

VOID ShipClass::setShip(ShipData* data)
{
	xScale = data->xScale;
	yScale = data->yScale;
	ShipType = data->ShipType;
	ShipImg = data->ShipImg;
	ShipSpeed = data->ShipSpeed;

	Bow = data->Bow;
	Body = data->Body;
	Stern = data->Stern;
	Bridge = data->Bridge;
	Chimney = data->Chimney;
	Hangar = data->Hangar;
}

VOID ShipClass::setPosition(INT x,INT y)
{
	xPos = x;
	yPos = y;
}

VOID ShipClass::Update()
{

}

VOID ShipClass::ShipPaint(HDC hdc, HBITMAP hBit)
{

}