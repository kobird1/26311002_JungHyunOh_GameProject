#pragma once
#include "glc2d.h"

struct Transform
{
	VEC2 position{ 0.0f, 0.0f };
	VEC2 scale{ 1.0f, 1.0f };
	VEC2 center{ 0.0f, 0.0f };
	float rotation{ 0.0f };
};

class GameObject
{
public:
	virtual int Init() { return 0; }
	virtual int Update() { return 0; }
	virtual int Destroy() { return 0; }
	virtual int Render() { return 0; }

protected:
	Transform transform;
};

