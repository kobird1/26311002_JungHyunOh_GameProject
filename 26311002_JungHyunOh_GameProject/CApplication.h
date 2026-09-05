#pragma once
#include <windows.h>
#include <string>
#include "SceneGameBegin.h"
#include "SceneGamePlay.h"

class CApplication
{
public:
	int Init();
	int Update();
	int Destroy();
	int Render();

protected:
	int InitSdk();

protected:
	//windows
	POINT m_winPos{ 100, 100 };
	SIZE m_winSize{ 800, 600 };

	std::string m_winName = "BugerRush";

	SceneGameBegin m_sceneBegin;
	SceneGamePlay m_scenePlay;
};

