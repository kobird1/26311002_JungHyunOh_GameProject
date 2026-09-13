#include "Player.h"

int Player::Init()
{
    m_txPlayer = g2_TextureLoad("resource/texture/playerTemp.png");
    transform.position = { 99.5f, 542.5f };
    transform.scale = { 3.0f, 3.0f };
    transform.center = { 8.0f, 8.0f };
    return 0;
}

int Player::Update(float deltaTime)
{
    const KEYCODE* keyboard = g2_GetKeyboard();
    bool isMoving{};

    if (keyboard['A'])
    {
        m_direction = Direction::LEFT;
        isMoving = true;
    }

    if (keyboard['D'])
    {
        m_direction = Direction::RIGHT;
        isMoving = !isMoving;
    }

    if (isMoving)
    {
        Move(m_direction, deltaTime);
    }
    
    return 0;
}

int Player::Render()
{
    VEC2 renderCenter{
        transform.position.x + transform.center.x * transform.scale.x,
        transform.position.y + transform.center.y * transform.scale.y
    };

    float renderRotation = transform.rotation * 3.141592f / 180.0f;

    g2_Draw2D(m_txPlayer,
        nullptr,
        &transform.position,
        &transform.scale,
        &renderCenter,
        renderRotation);
    return 0;
}

int Player::Destroy()
{
    if (-1 != m_txPlayer)
    {
        g2_TextureRelease(m_txPlayer);
        m_txPlayer = -1;
    }

    return 0;
}
