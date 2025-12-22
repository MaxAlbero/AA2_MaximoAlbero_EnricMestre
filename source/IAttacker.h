#pragma once
#include "IDamageable.h"

class IAttacker {
protected:
	int bulletDamage;
public:
	virtual ~IAttacker() = default;
	virtual void Shoot(IDamageable* other) const = 0; // case of player: other -> enemy / case of enemy: other -> player 
};