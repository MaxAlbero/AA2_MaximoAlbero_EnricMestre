#pragma once
#include "Enemy.h"
#include "Player.h"

class Beholder : public Enemy {
private:
	float moveSpeed;

	float stopDuration;
	float stopTimer;

	Vector2 targetPosition;
	Player* player;
	float tolerance;

	int numOfChase;
	int maxChases;

public:
	Beholder(Vector2 spawnPos, Player* playerRef)
		: Enemy(), player(playerRef) {
		_renderer = new ImageRenderer(_transform, "resources/image.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f));

		_transform->size = Vector2(100.f, 100.f);
		_transform->position = spawnPos;

		_physics->AddCollider(new AABB(_transform->position, _transform->size));


		health = 100;
		currentState = STAY;
		moveSpeed = 100.f;

		stopDuration = 1.5f;
		stopTimer = 0.f;
		
		tolerance = 10.f;

		numOfChase = 0;
		maxChases = 3;

		if (player) {
			targetPosition = player->GetTransform()->position;
		}
	}
	
	void Update() override {

		if (player == nullptr) {
			Destroy();
			return;
		}

		switch (currentState) {
		case STAY:
			EnemyBehaviour();
			break;
		case CHASE:
			Move();
			break;
		case RETURN:
			GoAway();
			break;
		}

		Object::Update();
	}

	   
	void EnemyBehaviour() override {

		_physics->SetVelocity(Vector2(0.f, 0.f));

		if (numOfChase >= maxChases) {
			currentState = RETURN;
		}

		stopTimer += TM.GetDeltaTime();

		if (stopTimer >= stopDuration) {
			targetPosition = player->GetTransform()->position;
			currentState = CHASE;
			stopTimer = 0.f;
			numOfChase++;
		}
	}

	void Move() override {
		Vector2 currentPos = _transform->position;

		Vector2 direction = targetPosition - currentPos;
		float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

		if (distance <= tolerance) {
			currentState = STAY;
			_physics->SetVelocity(Vector2(0.f, 0.f));
			return;
		}

		direction.x /= distance;
		direction.y /= distance;

		_physics->SetVelocity(Vector2(direction.x * moveSpeed, direction.y * moveSpeed));
	}

	void GoAway() override {

	}



};