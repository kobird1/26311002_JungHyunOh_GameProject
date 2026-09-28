#pragma once
#include <vector>
#include "Scene.h"
#include "Button.h"

using std::vector;

class SceneGameResult : public Scene
{
public:
	int Init() override;
	int Update(float deltaTime) override;
	int Destroy() override;
	int Render() override;

protected:
	int m_txBg{ -1 };
	int m_font{ -1 };
	int m_selectedIndex{};

	Button m_startButton;
	Button m_exitButton;

	Button* m_selectedButton{};

	vector<Button*>buttons{};
};

