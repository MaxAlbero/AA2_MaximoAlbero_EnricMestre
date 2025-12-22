#include "Player.h"

void Player::Move()
{
	if (IM->GetEvent(SDLK_S, KeyState::HOLD)) {
		_physics->AddForce(Vector2(0.f, 2000.f));
	}
	if (IM->GetEvent(SDLK_W, KeyState::HOLD)) {
		_physics->AddForce(Vector2(0.f, -2000.f));
	}
	if (IM->GetEvent(SDLK_A, KeyState::HOLD)) {
		_physics->AddForce(Vector2(-2000.f, 0.f));
	}
	if (IM->GetEvent(SDLK_D, KeyState::HOLD)) {
		_physics->AddForce(Vector2(2000.f, 0.f));
	}
	if (IM->GetEvent(SDLK_R, KeyState::HOLD)) {
		_physics->AddTorque(200.f);
	}



	if (IM->GetEvent(SDLK_SPACE, KeyState::DOWN)) {
		Shoot();
	}
	else if (IM->GetLeftClick()) {
		Shoot();
	}
}

void Player::OnCollision(Object* other)
{

}
