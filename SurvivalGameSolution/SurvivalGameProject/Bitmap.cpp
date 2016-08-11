#include "main.h"

HBITMAP LoadBitmap(INT num) //비트맵 불러오기
{
	static HBITMAP shipBmp;
	static HBITMAP weaponBmp;
	static HBITMAP mapBmp;
	static HBITMAP UIBmp;

	switch (num)
	{
	case 1:
		shipBmp = (HBITMAP)LoadImage(NULL, TEXT("ShipImg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		return shipBmp;
	case 2:
		weaponBmp = (HBITMAP)LoadImage(NULL, TEXT("WeaponImg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		return weaponBmp;
	case 3:
		UIBmp = (HBITMAP)LoadImage(NULL, TEXT("UI.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		return UIBmp;
	case 4:
		mapBmp = (HBITMAP)LoadImage(NULL, TEXT("MapImg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		return mapBmp;
	}
	return NULL;
}

VOID DrawLocalBitmap(HDC hdc, INT PosX, INT PosY, INT ScaleX, INT ScaleY, INT ImgNum, HBITMAP hBit)//로컬 좌표에 그리는 비트맵
{
	HDC MemDC;
	HBITMAP OldBitmap;
	BITMAP bit;
	ImgData tempData;

	switch (ImgNum / 1000)
	{
	case 1:
		tempData = ShipImgDir[ImgNum - 1000];
		break;
	case 2:
		tempData = WeaponImgDir[ImgNum - 2000];
		break;
	case 3:
		tempData = UIImgDir[ImgNum - 3000];
		break;
	case 4:
		tempData = MapImgDir[ImgNum - 4000];
		break;
	}

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);

	TransparentBlt(hdc, PosX, PosY, ScaleX, ScaleY, MemDC, tempData.xPos, tempData.yPos, tempData.xScale, tempData.yScale, ALPHA);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

VOID DrawWorldBitmap(HDC hdc, INT PosX, INT PosY, INT ScaleX, INT ScaleY, INT ImgNum, HBITMAP hBit)//월드 좌표에 그리는 비트맵
{
	HDC MemDC;
	HBITMAP OldBitmap;
	BITMAP bit;
	ImgData tempData;

	switch (ImgNum / 1000)
	{
	case 1:
		tempData = ShipImgDir[ImgNum - 1000];
		break;
	case 2:
		tempData = WeaponImgDir[ImgNum - 2000];
		break;
	case 3:
		tempData = UIImgDir[ImgNum - 3000];
		break;
	case 4:
		tempData = MapImgDir[ImgNum - 4000];
		break;
	}

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);

	TransparentBlt(hdc, PosX + w_xPos, PosY + w_yPos, ScaleX, ScaleY, MemDC, tempData.xPos, tempData.yPos, tempData.xScale, tempData.yScale, ALPHA);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}