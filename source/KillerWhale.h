#pragma once
#include "Enemy.h"

class KillerWhale : public Enemy {
private:
	float attachedSpeed;
	float moveSpeed;

	bool topOfScreen;

public:
	KillerWhale(bool startAtTop = false)
		: Enemy() {
		_renderer = new ImageRenderer(_transform, "resources/image.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f));
		_transform->size = Vector2(150.f, 80.f);

		// Posición inicial según donde empiece
		if (startAtTop) {
			_transform->position = Vector2(RM->WINDOW_WIDTH + _transform->size.x, 0.f);
			topOfScreen = true;
		}
		else {
			_transform->position = Vector2(RM->WINDOW_WIDTH + _transform->size.x, RM->WINDOW_HEIGHT - _transform->size.y);
			topOfScreen = false;
		}

		_physics->AddCollider(new AABB(_transform->position, _transform->size));

		health = 100;
		currentState = STAY;
		
		
		attachedSpeed = 300.f; // Velocidad horizontal cuando está pegado a las paredes
		moveSpeed = 200.f;
	}

	void Update() override {
		switch (currentState) {
		case STAY:
			EnemyBehaviour();
			break;
		case SIMPLE_MOVE:
			Move();
			break;
		}

		// Destruir si sale de la pantalla por la izquierda
		if (_transform->position.x + _transform->size.x < 0) {
			std::cout << "Killer Whale salió de la pantalla" << std::endl;
			Destroy();
		}

		Object::Update();
	}

	void Move() override {
		if (currentState == SIMPLE_MOVE && topOfScreen == true) {
			_physics->SetVelocity(Vector2(0.f, moveSpeed));

			// Verificar si alcanzó el suelo
			if (_transform->position.y >= RM->WINDOW_HEIGHT - _transform->size.y) {
				currentState = STAY;
				topOfScreen = false;
				_transform->position.y = RM->WINDOW_HEIGHT - _transform->size.y;
				std::cout << "Killer Whale se pegó al suelo" << std::endl;
			}
		}
		else if (currentState == SIMPLE_MOVE && topOfScreen == false) {
			_physics->SetVelocity(Vector2(0.f, -moveSpeed));

			// Verificar si alcanzó el techo
			if (_transform->position.y <= 0.f) {
				currentState = STAY;
				topOfScreen = true;
				_transform->position.y = 0.f;
				std::cout << "Killer Whale se pegó al techo" << std::endl;
			}
		}
	}

	void EnemyBehaviour() override {
		if (topOfScreen == true) {
			_physics->SetVelocity(Vector2(-attachedSpeed, 0.f));
			//_transform->position.y = 0.f;

			if (_transform->position.x <= RM->WINDOW_WIDTH / 2.f) {
				currentState = SIMPLE_MOVE;
				std::cout << "Killer Whale se despegó del techo" << std::endl;
			}
		}
		else {
			_physics->SetVelocity(Vector2(-attachedSpeed, 0.f));
			//_transform->position.y = RM->WINDOW_HEIGHT - _transform->size.y;  // Asegurar que esté pegado al suelo

			if (_transform->position.x <= RM->WINDOW_WIDTH / 2.f) {
				currentState = SIMPLE_MOVE;
				std::cout << "Killer Whale se despegó del suelo" << std::endl;
			}
		}
	}
};