#include "SceneGamePlay.h"
#include "glc2d.h"

int SceneGamePlay::Init()
{
	m_txBg = g2_TextureLoad("resource/texture/tex_ui/background.png");
	m_bgm = g2_SoundLoad("resource/audio/playBGM.wav");
	g2_SoundPlay(m_bgm, true);

	player.Init();
	rock.Init();
	return 0;
}

int SceneGamePlay::Destroy()
{
	return 0;
}

int SceneGamePlay::Update(float deltaTime)
{
	player.Update(deltaTime);
	rock.Update(deltaTime);

	RECT pCollider = player.GetCollider();
	RECT rCollider = rock.GetCollider();
	RECT overlap{};

	if (pCollider.left < 0)
	{
		player.transform.position.x -= pCollider.left;
	}
	else if (pCollider.right > 360)
	{
		player.transform.position.x -= pCollider.right - 360;
	}

	if (IntersectRect(&overlap, &pCollider, &rCollider))
	{
		return SCENE_BEGIN;
	}

	return 0;
}

int SceneGamePlay::Render()
{
	g2_Draw2D(m_txBg, nullptr);
	player.Render();
	rock.Render();
	return 0;
}