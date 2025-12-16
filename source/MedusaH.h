#pragma once
#include "Enemy.h"

//#include "ImageObject.h"

class MedusaH : public Enemy {
protected:
	int moveSpeed = 1;

public:
	MedusaH()
		: Enemy ()
	{
		_renderer = new ImageRenderer(_transform, "resources/bebe.jpg", Vector2(0.f, 0.f), Vector2(360.f, 360.f));

		//_transform->size = Vector2(360.f, 360.f);
		_transform->position = Vector2(RM->WINDOW_WIDTH / 2.f, RM->WINDOW_HEIGHT / 2.f);
		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	void Update() override {
		EnemyBehaviour();

		Object::Update();
	}

	//void OnCollision(Object* other) override;
	void EnemyBehaviour() override;
};