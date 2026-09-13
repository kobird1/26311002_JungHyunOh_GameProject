#include "Button.h"

int Button::Init(string imagePath)
{
	m_texture = g2_TextureLoad(imagePath.c_str());
	m_width = g2_TextureWidth(m_texture);
	m_height = g2_TextureHeight(m_texture);

	return 0;
}

int Button::Render()
{
	if (-1 == m_texture)
	{
		return 0;
	}

	VEC2 scale = GetDrawScale();
	VEC2 position = transform.position;

	position.x -= m_width * (scale.x - transform.scale.x) * 0.5f;
	position.y -= m_height * (scale.y - transform.scale.y) * 0.5f;

	if (m_pressed)
	{
		position.y += 2.0f;
	}

	VEC2 center{
		position.x + transform.center.x * scale.x,
		position.y + transform.center.y * scale.y
	};

	float rotation = transform.rotation * 3.141592f / 180.0f;

	g2_Draw2D(
		m_texture,
		nullptr,
		&position,
		&scale,
		&center,
		rotation
	);


	return 0;
}

int Button::Destroy()
{
	if (-1 != m_texture)
	{
		g2_TextureRelease(m_texture);
		m_texture = -1;
	}

	m_width = 0;
	m_height = 0;

	return 0;
}

VEC2 Button::GetDrawScale()
{
	VEC2 scale = transform.scale;

	if (m_selected)
	{
		scale.x *= 1.1f;
		scale.y *= 1.1f;
	}

	return scale;
}

void Button::SetSelected(bool selected)
{
	m_selected = selected;

	if (!m_selected)
	{
		m_pressed = false;
	}
}

void Button::SetPressed(bool pressed)
{
	m_pressed = m_selected && pressed;
}

void Button::SetAction(int (*action)(void))
{
	m_action = action;
}

int Button::Press()
{
	m_pressed = false;

	if (nullptr != m_action)
	{
		return m_action();
	}

	return 0;
}