#pragma once
class SceneClass
{
public:
	CHAR name[8];

	virtual VOID FadeIn() = 0;
	virtual VOID FadeOut() = 0;

	virtual VOID Enter() = 0;
	virtual VOID Update() = 0;
	virtual VOID Exit() = 0;

private:

};