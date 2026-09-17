#include "Rock.h"

int Rock::Init()
{
    m_txRock = g2_TextureLoad("resource/texture/rock.png");
    transform.position = { 99.5f, -80.0f };
    transform.scale = { 3, 3 };
    transform.center = { 10, 10 };
    m_moveSpeed = 400.0f;
    boxCollider.size = { 20, 20 };

    return 0;
}

int Rock::Update(float deltaTime)
{
    Move(m_direction, deltaTime);
   
    return 0;
}

int Rock::Render()
{
    VEC2 renderCenter = GetCenter();
    float renderRotation = GetRotation();

    g2_Draw2D(m_txRock,
              nullptr,
              &transform.position,
              &transform.scale,
              &renderCenter,
              renderRotation);
    return 0;
}

int Rock::Destroy()
{
    return 0;
}