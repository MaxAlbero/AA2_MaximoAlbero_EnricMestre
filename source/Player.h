#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Bullet.h"
#include "Spawner.h"
#include "IAttacker.h"
#include "IDamageable.h"

class Player : public ImageObject, public IAttacker, public IDamageable
{
private:
	int energy; //shields/shieldsPower... values from 0 to 100
	float maxSpeed;

public:
	Player()
		: ImageObject("resources/image.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f)) {

		// Posició random en tota la finestra
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = randomPosition;
		_transform->scale = Vector2(0.5f, 0.5f);
		_transform->rotation = 30.f;

		_physics->SetLinearDrag(10.f);
		_physics->SetAngularDrag(0.1f);

		energy = 100;
		maxSpeed = 1.0f;
		bulletDamage = 10;
	}

	void Update() override {

		Move();

		Object::Update();
	}

	void Move();

	void Shoot(IDamageable* other) const override {
		//Bullet* bullet = new Bullet();

		SPAWNER.SpawnObject(new Bullet(Vector2(_transform->position.x + 1, _transform->position.y)));

		other->ReceiveDamage(bulletDamage);
	}

	void ReceiveDamage(int damageToAdd) override;
};