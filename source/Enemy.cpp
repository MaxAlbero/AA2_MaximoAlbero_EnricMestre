#include "Enemy.h"
#include "Bullet.h"
#include <math.h>

void Enemy::OnCollision(Object* other)
{
	Bullet* bullet = dynamic_cast<Bullet*>(other);
	if (bullet != nullptr) {
		health -= 10;

		std::cout << "ENEMY HEALTH: " << health << std::endl;

		if (health <= 0)
		{
			Destroy();
			std::cout << "MUELTO DIAVLO" << std::endl;
		}
	}   
}

void Enemy::Attack(IAttacker* other) const {
	std::cout << "Enemy attacks!" << std::endl;
}

void Enemy::ReceiveDamage(int damageToAdd) {
	health -= damageToAdd;
	std::cout << "Enemy received " << damageToAdd << " damage. Health: " << health << std::endl;

	if (health <= 0) {
		// Destruir enemigo
		Destroy();
	}
}

void Enemy::CircleMove() {
	Vector2 center = Vector2(RM->WINDOW_WIDTH / 1.3f, RM->WINDOW_HEIGHT / 2.f);

	float pi = 3.14159f;

	angle += angularSpeed * 0.02f;

	if (angle > 2 * pi)
		angle -= 2 * pi;

	Vector2 newPos(cos(angle) * radius, sin(angle) * radius);

	_transform->position = center + newPos;
}