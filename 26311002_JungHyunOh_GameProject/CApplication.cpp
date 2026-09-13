#include <stdio.h>
#include "CApplication.h"
#include "glc2d.h"

CApplication g_app;

int AppUpdate()
{
	return g_app.Update();
}

int AppRender()
{
	return g_app.Render();
}

int CApplication::Init()
{
	InitSdk();
	ChangeScene(1);

	m_prevTime = g2_TimeGetTime();
	return 0;
}

int CApplication::Update()
{
	long long currentTime = g2_TimeGetTime();
	float deltaTime = static_cast<float>(currentTime - m_prevTime) / 1000.0f;
	m_prevTime = currentTime;

	int nextScene = m_scene->Update(deltaTime);
	if (0 != nextScene)
	{
		ChangeScene(nextScene);
	}

	return 0;
}

int CApplication::Destroy()
{
	m_scene->Destroy();
	g2_DestroyWin();
	return 0;
}

int CApplication::Render()
{
	m_scene->Render();
	return 0;
}

SIZE CApplication::GetWinSize()
{
	return m_winSize;
}

int CApplication::InitSdk()
{
	g2_InitSdk();
	g2_CreateWin(m_winPos.x, m_winPos.y, m_winSize.cx, m_winSize.cy, m_winName.c_str());
	g2_SetFrameMove(AppUpdate);
	g2_SetRender(AppRender);

	return 0;
}

void CApplication::ChangeScene(int scene)
{
	if (m_scene != nullptr)
	{
		m_scene->Destroy();
	}

	switch (scene)
	{
	case 1:
		m_scene = &m_sceneBegin;
		break;

	case 2:
		m_scene = &m_scenePlay;
		break;
	
	case 3:
		PostQuitMessage(0);
		return;

	default:
		break;
	}

	m_scene->Init();
}