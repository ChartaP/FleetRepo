#include "main.h"

VOID CALLBACK TimerProc(HWND, UINT, UINT_PTR, DWORD);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HBITMAP* LoadBitmap(TCHAR*);

VOID DrawBitmap(HDC, INT, INT, HBITMAP);

HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");

SceneMng mySceneMng;
RECT crt;

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

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (INT)Message.wParam;
}

HBITMAP* LoadBitmap(TCHAR* FILE_NAME)
{
	static HBITMAP bmp = (HBITMAP)LoadImage(NULL, FILE_NAME , IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP *hBMP = &bmp;
	return hBMP;
}


VOID DrawBitmap(HDC hdc, INT x, INT y, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);

	TransparentBlt(hdc, x, y, 48, 48, MemDC, 0, 0, 8, 8, RGB(255, 0, 255));
		


	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

VOID CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	HDC hdc;
	hdc = GetDC(hWnd);

	mySceneMng.Update();

	ReleaseDC(hWnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;//���� DC
	HDC backMemDC;//�ӽ� DC
	static HBITMAP backBitmap = NULL;//��ȭ�� ��Ʈ��
	HBITMAP hOldBitmap;//�ӽ� ��Ʈ��
	PAINTSTRUCT ps;
	static HBITMAP* MyBitmapChar; //ĳ���� �̹��� ��Ƶ� ��Ʈ��
	static HBITMAP* MyBitmapMap; //ĳ���� �̹��� ��Ƶ� ��Ʈ��
	static HBITMAP* MyBitmapUI; //ĳ���� �̹��� ��Ƶ� ��Ʈ��


	switch (iMessage)
	{
	case WM_CREATE:
		//GetClientRect(hWnd, &crt);

		//mySceneMng.ChangeScene("GameScene");

		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		backMemDC = CreateCompatibleDC(hdc);

		backBitmap = CreateCompatibleBitmap(hdc, crt.right, crt.bottom); //��ȭ�� �غ�!
		hOldBitmap = (HBITMAP)SelectObject(backMemDC, backBitmap); //��ȭ�� ����
		FillRect(backMemDC, &crt, (HBRUSH)GetStockObject(LTGRAY_BRUSH)); //��ȭ�� �� ����

		//�׸��� �� ����
		{

		}
		//�׸��� �� ��

		BitBlt(hdc, 0, 0, crt.right, crt.bottom, backMemDC, 0, 0, SRCCOPY);

		DeleteObject(SelectObject(backMemDC, hOldBitmap));
		DeleteDC(backMemDC);
		//TextOut(hdc, 16, 16, Path, lstrlen(lstrcat(Path, L"char.bmp")));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}