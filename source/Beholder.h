#pragma once
#include "Enemy.h"

class Beholder : public Enemy {
public:
	Beholder()
		: Enemy() {
		_renderer = new ImageRenderer(_transform, "resources/image.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f));

		_transform->size = Vector2(100.f, 100.f);

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		currentState = STAY;
	}


	void EnemyBehaviour() override {}

	void Move() {}

	void GoAway() {}



};