#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "Spawner.h"

class Enemy : public ImageObject
{
private:
	int health = 1;
	float radius = 100.f;
	float angle = 0.f;
	float angularSpeed = 0.01f;
public:
	Enemy()
		: ImageObject("resources/image.png", Vector2(0.f, 0.f), Vector2(100.f, 100.f)) 
	{
		_transform->size = Vector2(150.f, 150.f);
		_transform->position = Vector2(RM->WINDOW_WIDTH / 1.2f, RM->WINDOW_HEIGHT / 2.f);
		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	void Update() override {
		MovingEnemy();
		Object::Update();
	}

	void OnCollision(Object* other) override;
	void MovingEnemy();
};

