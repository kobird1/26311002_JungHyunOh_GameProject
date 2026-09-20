#pragma once
#include <vector>
#include "Scene.h"
#include "Player.h"
#include "Rock.h"

using std::vector;

class SceneGamePlay : public Scene
{
public:
	int Init() override;
	int Update(float deltaTime) override;
	int Destroy() override;
	int Render() override;

protected:
	int m_txBg{ -1 };
	int m_bgm{ -1 };
	Player player;
	vector<Rock*> rocks;

	float rockSpawnTimer{};

	void SpawnRock();
};