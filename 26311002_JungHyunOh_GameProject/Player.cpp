#include "Player.h"

int Player::Init()
{
    m_txPlayer = g2_TextureLoad("Texture/playerTemp.png");
    return 0;
}

int Player::Update()
{

    return 0;
}

int Player::Render()
{
    g2_Draw2D(m_txPlayer,
        nullptr,
        &transform.position,
        &transform.scale,
        &transform.center,
        transform.rotation);
    return 0;
}

int Player::Destroy()
{
    if (m_txPlayer != -1)
    {
        g2_TextureRelease(m_txPlayer);
        m_txPlayer = -1;
    }

    return 0;
}