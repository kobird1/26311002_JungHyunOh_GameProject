#include "SceneGamePlay.h"
#include "glc2d.h"

int SceneGamePlay::Init()
{
	m_txBg = g2_TextureLoad("resource/texture/tex_ui/background.png");
	m_bgm = g2_SoundLoad("resource/audio/playBGM.wav");
	g2_SoundReset(m_bgm);
	g2_SoundPlay(m_bgm, true);

	player.Init();
	rockSpawnTimer = 0.0f;
	return 0;
}

int SceneGamePlay::Update(float deltaTime)
{
	player.Update(deltaTime);
	RECT pCollider = player.GetCollider();

	if (pCollider.left < 0)
	{
		player.transform.position.x -= pCollider.left;
	}
	else if (pCollider.right > 360)
	{
		player.transform.position.x -= pCollider.right - 360;
	}

	rockSpawnTimer += deltaTime;
	if (rockSpawnTimer >= 0.6f)
	{
		SpawnRock();
	}

	RECT overlap{};
	pCollider = player.GetCollider();
	
	for (int i = 0; i < static_cast<int>(rocks.size()); ++i)
	{
		Rock* rock = rocks[i];
		rock->Update(deltaTime);
		const RECT rCollider = rock->GetCollider();
		
		if (rCollider.bottom > 592)
		{
			delete rock;
			rocks.erase(rocks.begin() + i);
			--i;
			continue;
		}

		if (IntersectRect(&overlap, &pCollider, &rCollider))
		{
			return SCENE_BEGIN;
		}
	}
	return SCENE_KEEP;
}

int SceneGamePlay::Render()
{
	g2_Draw2D(m_txBg, nullptr);
	player.Render();
	for (const auto& rock : rocks)
	{
		rock->Render();
	}
	return 0;
}

int SceneGamePlay::Destroy()
{
	g2_SoundStop(m_bgm);
	for (auto& rock : rocks)
	{
		delete rock;
	}

	rocks.clear();
	return 0;
}

void SceneGamePlay::SpawnRock()
{
	Rock* rock = new Rock;

	rocks.push_back(rock);
	rock->Init();
	
	rockSpawnTimer -= 0.6f;
}