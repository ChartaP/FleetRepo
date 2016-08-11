#pragma once

HBITMAP LoadBitmap(INT);
VOID setImgDir();
VOID DrawLocalBitmap(HDC, INT, INT, INT, INT, INT, HBITMAP);
VOID DrawWorldBitmap(HDC, INT, INT, INT, INT, INT, HBITMAP);