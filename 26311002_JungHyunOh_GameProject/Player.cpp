#include "Player.h"

int Player::Init()
{
    m_txPlayer = g2_TextureLoad("resource/texture/playerTemp.png");
    transform.position = { 99.5f, 542.5f };
    transform.scale = { 3, 3 };
    transform.center = { 8, 8 };

    boxCollider.size = { 16, 16 };
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
    VEC2 renderCenter = GetCenter();
    float renderRotation = GetRotation();

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
    return 0;
}
