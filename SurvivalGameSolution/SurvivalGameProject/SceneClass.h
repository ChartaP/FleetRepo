#pragma once


class SceneClass
{
public:
	TCHAR name[16];

	virtual VOID FadeIn() = 0;
	virtual VOID FadeOut() = 0;

	virtual VOID Enter() = 0;
	virtual VOID Update() = 0;
	virtual VOID Exit() = 0;

protected:

};