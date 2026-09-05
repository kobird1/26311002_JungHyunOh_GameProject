#pragma once
class SceneGamePlay
{
public:
	int Init();
	int Update();
	int Destroy();
	int Render();

protected:
	int m_txMario{ -1 };
};

