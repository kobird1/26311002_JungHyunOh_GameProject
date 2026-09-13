#pragma once
#include "Player.h"
#include "Scene.h"

class SceneGamePlay : public Scene
{
public:
	int Init() override;
	int Update(float deltaTime) override;
	int Destroy() override;
	int Render() override;

protected:
	int m_txBg{ -1 };

	Player player;
};

