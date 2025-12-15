#pragma once
#include "Enemy.h"

//#include "ImageObject.h"

class MedusaH : public ImageObject {
public:
	MedusaH()
		: ImageObject("resources/bebe.jpg", Vector2(0.f, 0.f), Vector2(306.f, 562.f)) {
		_transform->size = Vector2(150.f, 150.f);
		_transform->position = Vector2(RM->WINDOW_WIDTH / 2.f, RM->WINDOW_HEIGHT / 2.f);
		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}
};