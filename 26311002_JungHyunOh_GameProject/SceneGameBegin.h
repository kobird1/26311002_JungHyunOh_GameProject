#pragma once
class SceneGameBegin
{
public:
	int Init();
	int Update();
	int Destroy();
	int Render();

protected:
	//game texture
	int m_txMario{ -1 };
};

