#pragma once
#include <windows.h>
#include <string>
#include "SceneGameBegin.h"
#include "SceneGamePlay.h"

using std::string;

class CApplication
{
public:
	int Init();
	int Update();
	int Destroy();
	int Render();

public:
	SIZE GetWinSize();

	void ChangeScene(int scene);

protected:
	int InitSdk();

protected:
	//windows
	POINT m_winPos{ 100, 100 };
	SIZE m_winSize{ 360, 640 };

	string m_winName = "StoneRush";

	SceneGameBegin m_sceneBegin;
	SceneGamePlay m_scenePlay;

	Scene* m_scene{};

	long long m_prevTime{ 0 };
};

//전역 접근
extern CApplication g_app;