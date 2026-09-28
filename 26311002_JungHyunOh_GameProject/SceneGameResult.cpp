#include "SceneGameResult.h"

int SceneGameResult::Init()
{
	m_txBg = g2_TextureLoad("resource/texture/tex_ui/background.png");
	m_startButton.Init("resource/texture/tex_ui/start.png");
	m_exitButton.Init("resource/texture/tex_ui/exit.png");

	m_startButton.transform.position = { 59.5f, 299.5f };
	m_exitButton.transform.position = { 59.5f, 399.5f };

	return 0;
}

int SceneGameResult::Update(float deltaTime)
{
	return 0;
}

int SceneGameResult::Render()
{
	g2_Draw2D(m_txBg, nullptr);
	m_startButton.Render();
	m_exitButton.Render();

	return 0;
}

int SceneGameResult::Destroy()
{
	m_selectedButton = nullptr;
	return 0;
}