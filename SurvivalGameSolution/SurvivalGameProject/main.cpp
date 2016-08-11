#include "main.h"

VOID CALLBACK TimerProc(HWND, UINT, UINT_PTR, DWORD);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("SurvivalGame");

GameMng* myGameMng = NULL;
SceneMng* mySceneMng = NULL;
RECT crt;
RECT GameScreen; //월드맵 클립영역

ShipData ShipDataDir[128];

ImgData ShipImgDir[128];
ImgData WeaponImgDir[128];
ImgData UIImgDir[128];
ImgData MapImgDir[128];

INT w_xPos=0;
INT w_yPos=0;

INT APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, INT nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (INT)Message.wParam;
}

VOID setImgDir()
{
	memset(ShipImgDir, NULL, sizeof(ImgData) * 128);
	memset(WeaponImgDir, NULL, sizeof(ImgData) * 128);
	memset(UIImgDir, NULL, sizeof(ImgData) * 128);
	memset(MapImgDir, NULL, sizeof(ImgData) * 128);

	ShipImgDir[IMG_SHIP_TEST01_INDEX - 1000] = IMG_SHIP_TEST02_DATA;
	UIImgDir[IMG_UI_BACK01_INDEX - 3000] = IMG_UI_BACK01_DATA;
	MapImgDir[IMG_MAP_SEA01_INDEX - 4000] = IMG_MAP_SEA01_DATA;
}

VOID setShipDir()
{
	memset(ShipDataDir, NULL, sizeof(ShipData) * 128);
	ShipDataDir[SHIP_TEST_TEST_INDEX] = SHIP_TEST_TEST_DATA;
}

HBITMAP LoadBitmap(INT num) //비트맵 불러오기
{
	static HBITMAP shipBmp ;
	static HBITMAP weaponBmp ;
	static HBITMAP mapBmp ;
	static HBITMAP UIBmp ;

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

VOID DrawWorldBitmap(HDC hdc, INT PosX, INT PosY, INT ScaleX,INT ScaleY,INT ImgNum, HBITMAP hBit)//월드 좌표에 그리는 비트맵
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
	
	TransparentBlt(hdc, PosX+w_xPos, PosY+w_yPos, ScaleX, ScaleY, MemDC, tempData.xPos, tempData.yPos, tempData.xScale, tempData.yScale, ALPHA);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

VOID DrawWorldMap(HDC hdc, HBITMAP hBit)
{
	int i, j;
	for (i = 0; i < 64; i++)
	{
		for (j = 0; j < 64; j++)
		{
			DrawWorldBitmap(hdc,i*64,j*64,64,64, IMG_MAP_SEA01_INDEX,hBit);
		}
	}
}

VOID CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	HDC hdc;
	hdc = GetDC(hWnd);

	mySceneMng->Update();

	TextOut(hdc, 8, 8, mySceneMng->GetCurrentScene(),sizeof(TCHAR)*	_tcslen(mySceneMng->GetCurrentScene()));

	InvalidateRect(hWnd,NULL,FALSE);

	ReleaseDC(hWnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;//메인 DC
	HDC backMemDC;//임시 DC
	static HBITMAP backBitmap = NULL;//도화지 비트맵
	HBITMAP hOldBitmap;//임시 비트맵
	PAINTSTRUCT ps;
	static HBITMAP MyBitmapShip; //캐릭터 이미지 모아둔 비트맵
	static HBITMAP MyBitmapWeapon; //캐릭터 이미지 모아둔 비트맵
	static HBITMAP MyBitmapMap; //캐릭터 이미지 모아둔 비트맵
	static HBITMAP MyBitmapUI; //캐릭터 이미지 모아둔 비트맵
	HRGN hRgn;

	switch (iMessage)
	{
	case WM_CREATE:
		GetClientRect(hWnd, &crt);
		GameScreen.top = crt.top + 32;
		GameScreen.bottom = crt.bottom - 32;
		GameScreen.left = (crt.right/2) - ((crt.bottom/2)-32);
		GameScreen.right = (crt.right / 2) + ((crt.bottom / 2) - 32);

		myGameMng = new GameMng();

		setShipDir();
		myGameMng->myFlagShipData = ShipDataDir[SHIP_TEST_TEST_INDEX];

		mySceneMng = new SceneMng();

		setImgDir();
		MyBitmapShip = LoadBitmap(1);
		MyBitmapWeapon = LoadBitmap(2);
		MyBitmapUI = LoadBitmap(3);
		MyBitmapMap = LoadBitmap(4);

		mySceneMng->ChangeScene(TEXT("GameScene"));

		SetTimer(hWnd, 1, 1000/60, TimerProc);
		return 0;
	case WM_SIZE:
		GetClientRect(hWnd, &crt);
		GameScreen.top = crt.top + 32;
		GameScreen.bottom = crt.bottom - 32;
		GameScreen.left = (crt.right / 2) - ((crt.bottom / 2) - 32);
		GameScreen.right = (crt.right / 2) + ((crt.bottom / 2) - 32);

		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		backMemDC = CreateCompatibleDC(hdc);

		backBitmap = CreateCompatibleBitmap(hdc, crt.right, crt.bottom); //도화지 준비!
		hOldBitmap = (HBITMAP)SelectObject(backMemDC, backBitmap); //도화지 세팅
		FillRect(backMemDC, &crt, (HBRUSH)GetStockObject(LTGRAY_BRUSH)); //도화지 색 변경

		//그리는 곳 시작
		{
			mySceneMng->ScenePaint(backMemDC, &hRgn, MyBitmapShip, MyBitmapWeapon, MyBitmapUI, MyBitmapMap);
		}
		//그리는 곳 끝

		BitBlt(hdc, 0, 0, crt.right, crt.bottom, backMemDC, 0, 0, SRCCOPY);


		DeleteObject(SelectObject(backMemDC, hOldBitmap));
		DeleteObject(hRgn);
		DeleteDC(backMemDC);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd,1);
		DeleteObject(MyBitmapShip);
		DeleteObject(MyBitmapWeapon);
		DeleteObject(MyBitmapMap);
		DeleteObject(MyBitmapUI);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}