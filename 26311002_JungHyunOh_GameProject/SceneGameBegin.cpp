#include "SceneGameBegin.h"

int StartGame(void);
int ExitGame(void);

int SceneGameBegin::Init()
{
	m_txBg = g2_TextureLoad("resource/texture/tex_ui/background.png");
	m_startButton.Init("resource/texture/tex_ui/start.png");
	m_exitButton.Init("resource/texture/tex_ui/exit.png");

	m_startButton.transform.position = { 59.5f, 299.5f };
	m_exitButton.transform.position = { 59.5f, 399.5f };

	m_startButton.SetAction(StartGame);
	m_exitButton.SetAction(ExitGame);

	buttons = { &m_startButton , &m_exitButton };

	SelectButton(buttons[m_selectedIndex]);

	return 0;
}

int SceneGameBegin::Destroy()
{
	if(m_txBg != -1)
	{
		g2_TextureRelease(m_txBg);
		m_txBg = -1;
	}

	m_selectedButton = nullptr;
	m_startButton.Destroy();
	m_exitButton.Destroy();
	
	return 0;
}

int SceneGameBegin::Update(float deltaTime)
{
	const KEYCODE* keyboard = g2_GetKeyboard();

	if(keyboard['W'])
	{
		if (0 < m_selectedIndex)
		{
			--m_selectedIndex;
		}
		SelectButton(buttons[m_selectedIndex]);
	}
	else if (keyboard['S'])
	{
		if (buttons.size() - 1 > m_selectedIndex)
		{
			++m_selectedIndex;
		}
		SelectButton(buttons[m_selectedIndex]);
	}

	if (keyboard[VK_SPACE])
	{
		m_selectedButton->SetPressed(true);
		return m_selectedButton->Press();
	}

	return SCENE_KEEP;
}

int SceneGameBegin::Render()
{
	g2_Draw2D(m_txBg, nullptr);

	m_startButton.Render();
	m_exitButton.Render();

	return 0;
}

void SceneGameBegin::SelectButton(Button* button)
{
	if(nullptr == button || m_selectedButton == button)
	{
		return;
	}

	if(nullptr != m_selectedButton)
	{
		m_selectedButton->SetSelected(false);
	}

	m_selectedButton = button;
	m_selectedButton->SetSelected(true);
}

int StartGame(void)
{
	return SCENE_PLAY;
}

int ExitGame(void)
{
	return SCENE_QUIT;
}
