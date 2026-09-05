#include <stdio.h>
#include "CApplication.h"
#include "glc2d.h"

extern CApplication g_app;

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
	//m_sceneBegin.Init();
	m_scenePlay.Init();
	return 0;
}

int CApplication::Update()
{
	//m_sceneBegin.Update();
	m_scenePlay.Update();
	return 0;
}

int CApplication::Destroy()
{
	//m_sceneBegin.Destroy();
	m_scenePlay.Destroy();
	g2_DestroyWin();
	return 0;
}

int CApplication::Render()
{
	//m_sceneBegin.Render();
	m_scenePlay.Render();
	return 0;
}

int CApplication::InitSdk()
{
	g2_InitSdk();
	g2_CreateWin(m_winPos.x, m_winPos.y, m_winSize.cx, m_winSize.cy, m_winName.c_str());
	g2_SetFrameMove(AppUpdate);
	g2_SetRender(AppRender);

	return 0;
}
