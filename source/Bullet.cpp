#include "Bullet.h"

void Bullet::OnCollision(Object* other)
{
	Destroy();
}