#pragma once
#include "Enemy.h"

class BioTitan : public Enemy {
private:
	int moveSpeed;
public:
	BioTitan()
		: Enemy() {
		_renderer = new ImageRenderer(_transform, "resources/image.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f));


		_transform->size = Vector2(300.f,300.f);
		_transform->position = Vector2(RM->WINDOW_WIDTH + _transform->size.x, RM->WINDOW_HEIGHT / 2.f);
		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		enemyHealth = 300;
		currentState = SIMPLE_MOVE;

		moveSpeed = 100.f;
	}


	void Update() override {

		switch (currentState) {
		case SIMPLE_MOVE:
			Move();
			break;
		case SHOOT:
			break;
		}


		Object::Update();
	}

	void Move() override {
		_physics->SetVelocity(Vector2(-moveSpeed, 0.f));

		if (_transform->position.x <= RM->WINDOW_WIDTH - _transform->size.x) {
			_physics->SetVelocity(Vector2(0.f, 0.f));
			currentState = SHOOT;
		}
	}

	//void Attack(IAttacker* other) const override;

};