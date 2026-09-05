#include "SceneGamePlay.h"
#include "glc2d.h"

int SceneGamePlay::Init()
{
	this->m_txMario = g2_TextureLoad("Texture/tst.png");
	return 0;
}

int SceneGamePlay::Destroy()
{
	g2_TextureRelease(m_txMario);
	return 0;
}

int SceneGamePlay::Update()
{
	return 0;
}

int SceneGamePlay::Render()
{
	g2_Draw2D(m_txMario, nullptr);
	return 0;
}