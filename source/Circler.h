#pragma once
#include "Enemy.h"

class Circler : public Enemy {
private:
	float moveSpeed;

	Vector2 circleCenter;
	float circleRadius;
	float circleAngle;
	float circleSpeed;
	bool circleComplete;
	float horizontalMove;

public:
	Circler(Vector2 spawnPos)
		: Enemy() {
		_renderer = new ImageRenderer(_transform, "resources/image.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f));

		_transform->size = Vector2(100.f, 100.f);
		_transform->position = spawnPos;
		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		health = 200;
		currentState = STAY;

		circleRadius = 10.f;
		circleAngle = 0.f;
		circleSpeed = 3.0f;
		circleComplete = false;
		horizontalMove = 100.f;
	}

	void Update() override {

		switch (currentState) {
		case STAY:
			EnemyBehaviour();
			break;
		case CIRCLE_MOVE:
			CircleMove();
			break;
		}


		if (_transform->position.x < -_transform->size.x) {
			std::cout << "Ah bueno adios master" << std::endl;
			Destroy();
		}

		Object::Update();
	}

	void CircleMove() override {
		float pi = 3.14159f;

		circleAngle += circleSpeed * TM.GetDeltaTime();

		float newX = circleCenter.x + circleRadius * cos(circleAngle);
		float newY = circleCenter.y + circleRadius * sin(circleAngle);

		_transform->position = Vector2(newX, newY);

		if (circleAngle >= 2.0f * pi) {

			circleCenter.x -= horizontalMove;

			circleAngle = 0.f;
		}
	}
};