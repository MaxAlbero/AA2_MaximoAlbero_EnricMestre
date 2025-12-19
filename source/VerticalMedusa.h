#pragma once
#include "Enemy.h"
#include "TimeManager.h"

class VerticalMedusa : public Enemy {
private:
	float moveSpeed;
	float stopDistance;
	float stopDuration;
	float stopTimer;
	float nextStopY;

public:
	VerticalMedusa()
		: Enemy() {
		_renderer = new ImageRenderer(_transform, "resources/bebe.jpg", Vector2(0.f, 0.f), Vector2(360.f, 360.f));

		_transform->position = Vector2(RM->WINDOW_WIDTH / 2.f, RM->WINDOW_HEIGHT);
		_physics->AddCollider(new AABB(_transform->position, _transform->size));
		
		health = 20;
		currentState = SIMPLE_MOVE;
		moveSpeed = 1.f;

		stopTimer = 0.f;
		stopDuration = 1.0f;
		stopDistance = 1.f;
		nextStopY = _transform->position.y - stopDistance;
	}

	void Update() override {
		EnemyBehaviour();

		switch (currentState) {
		case SIMPLE_MOVE:
			Move();
			break;
		case STAY:
			EnemyBehaviour();
			break;
		}

		if (_transform->position.y + _transform->size.y / 2 < 0) {
			std::cout << "AAAAAAAAAAHHHHHHHHH" << std::endl;
			Destroy();
		}

		Object::Update();
	}

	void Move() {
		_physics->SetVelocity(Vector2(0.f, -moveSpeed));

		if (_transform->position.y <= nextStopY) {
			currentState = STAY;
			stopTimer = 0.f;
			_physics->SetVelocity(Vector2(0.f, 0.f));
		}
	}

	//void OnCollision(Object* other) override;
	void EnemyBehaviour() override {
		std::cout << "VerticalMedusa Behaviour" << std::endl;

		stopTimer += TM.GetDeltaTime();

		if (stopTimer >= stopDuration) {
			nextStopY -= stopDistance;

			currentState = SIMPLE_MOVE;
			stopTimer = 0.f;
		}
	}
};