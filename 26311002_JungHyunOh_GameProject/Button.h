#pragma once
#include "GameObject.h"
#include <iostream>
#include <string>

using std::string;

class Button : public GameObject
{
public:
	int Init(string imagePath);
	int Render() override;
	int Destroy() override;

	void SetSelected(bool selected);
	void SetPressed(bool pressed);
	void SetAction(int (*action)(void));
	int Press();

private:
	VEC2 GetDrawScale();

private:
	int m_texture			{ -1 };
	int m_width				{};
	int m_height			{};

	bool m_selected			{};
	bool m_pressed			{};

	int (*m_action)(void)	{};
};

