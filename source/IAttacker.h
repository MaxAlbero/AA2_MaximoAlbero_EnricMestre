#pragma once

class IAttacker {
public:
	virtual ~IAttacker() = default;
	virtual void Attack(IAttacker* other) const = 0; // case of player: other -> enemy / case of enemy: other -> player 
};