#include "Enemy.h"
#include "Bullet.h"
#include <math.h>

void Enemy::OnCollision(Object* other)
{
	Bullet* bullet = dynamic_cast<Bullet*>(other);
	if (bullet != nullptr) {
		health--;
		if (health <= 0)
		{
			Destroy();
			std::cout << "MUELTO DIAVLO" << std::endl;
		}
	}
}

void Enemy::MovingEnemy() {
	Vector2 center = Vector2(RM->WINDOW_WIDTH / 1.3f, RM->WINDOW_HEIGHT / 2.f);

	float pi = 3.14159f;

	angle += angularSpeed * 0.02f;

	if (angle > 2 * pi)
		angle -= 2 * pi;

	Vector2 newPos(cos(angle) * radius, sin(angle) * radius);

	_transform->position = center + newPos;
}