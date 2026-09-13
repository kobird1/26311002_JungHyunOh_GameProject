#include "SceneGamePlay.h"
#include "glc2d.h"

int SceneGamePlay::Init()
{
	m_txBg = g2_TextureLoad("resource/texture/tex_ui/background.png");
	player.Init();
	return 0;
}

int SceneGamePlay::Destroy()
{
	if (m_txBg != -1)
	{
		g2_TextureRelease(m_txBg);
		m_txBg = -1;
	}

	player.Destroy();
	return 0;
}

int SceneGamePlay::Update(float deltaTime)
{
	player.Update(deltaTime);
	return 0;
}

int SceneGamePlay::Render()
{
	g2_Draw2D(m_txBg, nullptr);
	player.Render();
	return 0;
}