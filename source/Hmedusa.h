#pragma once
#include "Enemy.h"

class Hmedusa : public Enemy {
private:
	float moveSpeed;

public:
	Hmedusa()
		: Enemy ()
	{
		_renderer = new ImageRenderer(_transform, "resources/bebe.jpg", Vector2(0.f, 0.f), Vector2(360.f, 360.f));

		//_transform->size = Vector2(360.f, 360.f);
		_transform->rotation = 270.f;
		_transform->position = Vector2(RM->WINDOW_WIDTH / 1.f, RM->WINDOW_HEIGHT / 2.f);
		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		health = 20;
		moveSpeed = 100.f;
	}

	void Update() override {
		EnemyBehaviour();

		Object::Update();
	}

	//void OnCollision(Object* other) override;
	void EnemyBehaviour() override {
		_physics->SetVelocity(Vector2(-moveSpeed, 0.f));

	}
};