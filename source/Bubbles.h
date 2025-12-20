#pragma once
#include "Enemy.h"

class Bubbles : public Enemy {
private:
	float moveSpeed;
	float stopPointX;

public:
	Bubbles()
		: Enemy() {
		_renderer = new ImageRenderer(_transform, "resources/image.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f));

		_transform->position = Vector2(RM->WINDOW_WIDTH / 1.f, RM->WINDOW_HEIGHT / 5.f);
		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		moveSpeed = 1000.f;
		stopPointX = RM->WINDOW_WIDTH / 3.f;

		currentState = SIMPLE_MOVE;

	}

	void Update() override {

		switch (currentState) {
		case SIMPLE_MOVE:
			Move();
			break;
		case STAY:
			EnemyBehaviour();
			break;
		}

		Object::Update();
	}

	//void OnCollision(Object* other) override;
	void EnemyBehaviour() override {
		//std::cout << "BUBBLE STOPPED" << std::endl;

	}

	void Move() {
		_physics->SetVelocity(Vector2(-moveSpeed, 0.f));

		if (_transform->position.x <= stopPointX) {
			currentState = STAY;
			//stopTimer = 0.f;
			_physics->SetVelocity(Vector2(0.f, 0.f));

			//std::cout << "Medusa detenida en Y: " << _transform->position.y
			//	<< ", Siguiente parada en: " << nextStopY << std::endl;
		}


	}
};