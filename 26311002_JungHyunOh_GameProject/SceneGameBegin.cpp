#include "SceneGameBegin.h"
#include "glc2d.h"

int SceneGameBegin::Init()
{
	this->m_txMario = g2_TextureLoad("Texture/tst.png");
	return 0;
}

int SceneGameBegin::Destroy()
{
	g2_TextureRelease(m_txMario);
	return 0;
}

int SceneGameBegin::Update()
{
	return 0;
}

int SceneGameBegin::Render()
{
	g2_Draw2D(m_txMario, nullptr);
	return 0;
}