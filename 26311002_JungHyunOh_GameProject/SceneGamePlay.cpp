#include "SceneGamePlay.h"
#include "glc2d.h"

int SceneGamePlay::Init()
{
	player.Init();
	return 0;
}

int SceneGamePlay::Destroy()
{
	player.Destroy();
	return 0;
}

int SceneGamePlay::Update()
{
	player.Update();
	return 0;
}

int SceneGamePlay::Render()
{
	player.Render();
	return 0;
}