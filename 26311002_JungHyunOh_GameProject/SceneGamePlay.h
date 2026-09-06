#pragma once
#include "Player.h"

class SceneGamePlay
{
public:
	int Init();
	int Update();
	int Destroy();
	int Render();

protected:
	Player player;
};

