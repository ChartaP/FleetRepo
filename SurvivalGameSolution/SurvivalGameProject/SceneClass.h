#pragma once


class SceneClass
{
public:
	TCHAR name[16];


	virtual VOID Enter() = 0;
	virtual VOID Update() = 0;
	virtual VOID Exit() = 0;
	virtual VOID ScenePaint(HDC, HDC, HRGN*, HBITMAP, HBITMAP, HBITMAP, HBITMAP) = 0;

protected:

};