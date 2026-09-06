#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
    int Init() override;
    int Update() override;
    int Render() override;
    int Destroy() override;

protected:
    int m_txPlayer{ -1 };
};

