#pragma once
#include "Enemy.h"

class Chomper : public Enemy {
private:
	float moveSpeed;

	Vector2 circleCenter;
	float circleRadius;
	float circleAngle;
	float circleSpeed;
	bool circleComplete;
	float horizontalMove;

	float stopDuration;
	float stopTimer;

public:
	Chomper(Vector2 spawnPos)
		: Enemy() {
		_renderer = new ImageRenderer(_transform, "resources/image.png", Vector2(0.f,0.f), Vector2(306.f, 562.f));

		_transform->size = Vector2(100.f, 100.f);
		_transform->position = spawnPos;
		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		health = 200;
		currentState = STAY;

		//moveSpeed = 10.f;
		stopTimer = 0.f;
		stopDuration = 1.f;

		circleRadius = 20.f;      // Radio del círculo
		circleAngle = 0.f;
		circleSpeed = 10.0f;        // Radianes por segundo (ajusta la velocidad)
		circleComplete = false;
		horizontalMove = 50.f;

		circleCenter = spawnPos;
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

	void EnemyBehaviour() override {

		stopTimer += TM.GetDeltaTime();

		if (stopTimer >= stopDuration) {
			currentState = CIRCLE_MOVE;
		}
	}

	void CircleMove() override {
		float pi = 3.14159f;

		// Incrementar el ángulo según deltaTime
		circleCenter.x -= horizontalMove * TM.GetDeltaTime();
		circleAngle += circleSpeed * TM.GetDeltaTime();

		// Calcular nueva posición en el círculo
		float newX = circleCenter.x + circleRadius * cos(circleAngle);
		float newY = circleCenter.y + circleRadius * sin(circleAngle);

		// Mover a la nueva posición
		_transform->position = Vector2(newX, newY);

		// Verificar si completó el círculo (360 grados = 2*PI radianes)
		if (circleAngle >= 2.0f * pi) {
			circleAngle = 0.f;
		}
	}
};