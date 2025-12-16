#include "Player.h"

void Player::Move()
{
	if (IM->GetEvent(SDLK_S, KeyState::DOWN)) {
		_physics->AddForce(Vector2(0.f, 20.f));
	}
	if (IM->GetEvent(SDLK_W, KeyState::DOWN)) {
		_physics->AddForce(Vector2(0.f, -20.f));
	}
	if (IM->GetEvent(SDLK_A, KeyState::DOWN)) {
		_physics->AddForce(Vector2(-20.f, 0.f));
	}
	if (IM->GetEvent(SDLK_D, KeyState::DOWN)) {
		_physics->AddForce(Vector2(20.f, 0.f));
	}
	if (IM->GetEvent(SDLK_R, KeyState::DOWN)) {
		_physics->AddTorque(200.f);
	}

	if (IM->GetEvent(SDLK_SPACE, DOWN)) {
		Shoot();
	}
	else if (IM->GetLeftClick()) {
		Shoot();
	}
}
