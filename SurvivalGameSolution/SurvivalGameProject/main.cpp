#include "main.h"

VOID CALLBACK TimerProc(HWND, UINT, UINT_PTR, DWORD);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HBITMAP* LoadBitmap(TCHAR*);
VOID setImgDir();
VOID DrawBitmap(HDC,INT,INT,INT,INT,INT,HBITMAP);
VOID DrawWorldMap(HDC,HBITMAP);

HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("SurvivalGame");

SceneMng* mySceneMng = NULL;
RECT crt;

ImgData ShipDir[128];
ImgData WeaponDir[128];
ImgData UIDir[128];
ImgData MapDir[128];

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
	memset(ShipDir, NULL, sizeof(ImgData) * 128);
	memset(WeaponDir, NULL, sizeof(ImgData) * 128);
	memset(UIDir, NULL, sizeof(ImgData) * 128);
	memset(MapDir, NULL, sizeof(ImgData) * 128);

	MapDir[MAP_SEA01_INDEX%4000] = MAP_SEA01_DATA;
}

HBITMAP* LoadBitmap(INT num)
{
	static HBITMAP shipBmp ;
	static HBITMAP weaponBmp ;
	static HBITMAP mapBmp ;
	static HBITMAP UIBmp ;

	HBITMAP *hBMP;

	switch (num)
	{
	case 1:
		shipBmp = (HBITMAP)LoadImage(NULL, TEXT("ShipImg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hBMP = &shipBmp;
		return hBMP;
	case 2:
		weaponBmp = (HBITMAP)LoadImage(NULL, TEXT("WeaponImg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hBMP = &weaponBmp;
		return hBMP;
	case 3:
		mapBmp = (HBITMAP)LoadImage(NULL, TEXT("MapImg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hBMP = &mapBmp;
		return hBMP;
	case 4:
		UIBmp = (HBITMAP)LoadImage(NULL, TEXT("UI.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hBMP = &UIBmp;
		return hBMP;
	}

	return NULL;
}

VOID DrawBitmap(HDC hdc, INT PosX, INT PosY, INT ScaleX,INT ScaleY,INT ImgNum, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	BITMAP bit;
	ImgData tempData;

	switch (ImgNum / 1000)
	{
	case 4:
		tempData = MapDir[ImgNum % 4000];
	}

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	
	TransparentBlt(hdc, PosX, PosY, ScaleX, ScaleY, MemDC, tempData.xPos, tempData.yPos, tempData.xScale, tempData.yScale, RGB(255, 0, 255));

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
			DrawBitmap(hdc,i*64,j*64,64,64,MAP_SEA01_INDEX,hBit);
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
	static HBITMAP* MyBitmapShip; //캐릭터 이미지 모아둔 비트맵
	static HBITMAP* MyBitmapWeapon; //캐릭터 이미지 모아둔 비트맵
	static HBITMAP* MyBitmapMap; //캐릭터 이미지 모아둔 비트맵
	static HBITMAP* MyBitmapUI; //캐릭터 이미지 모아둔 비트맵


	switch (iMessage)
	{
	case WM_CREATE:
		GetClientRect(hWnd, &crt);
		mySceneMng = new SceneMng();

		setImgDir();
		MyBitmapShip = LoadBitmap(1);
		MyBitmapWeapon = LoadBitmap(2);
		MyBitmapMap = LoadBitmap(3);
		MyBitmapUI = LoadBitmap(4);

		mySceneMng->ChangeScene(TEXT("GameScene"));

		SetTimer(hWnd, 1, 1000/60, TimerProc);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		backMemDC = CreateCompatibleDC(hdc);

		backBitmap = CreateCompatibleBitmap(hdc, crt.right, crt.bottom); //도화지 준비!
		hOldBitmap = (HBITMAP)SelectObject(backMemDC, backBitmap); //도화지 세팅
		FillRect(backMemDC, &crt, (HBRUSH)GetStockObject(LTGRAY_BRUSH)); //도화지 색 변경

		//그리는 곳 시작
		{
			DrawWorldMap(backMemDC, *MyBitmapMap);
		}
		//그리는 곳 끝

		BitBlt(hdc, 0, 0, crt.right, crt.bottom, backMemDC, 0, 0, SRCCOPY);


		DeleteObject(SelectObject(backMemDC, hOldBitmap));
		DeleteDC(backMemDC);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd,1);
		DeleteObject(*MyBitmapShip);
		DeleteObject(*MyBitmapWeapon);
		DeleteObject(*MyBitmapMap);
		DeleteObject(*MyBitmapUI);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}