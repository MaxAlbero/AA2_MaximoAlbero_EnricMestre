#include "PowerUp1000.h"
#include "Player.h"
#include <iostream>

// Llamamos al constructor del padre (PowerUp)
PowerUp1000::PowerUp1000(const char* texturePath, Vector2 spriteSize)
    : PowerUp(texturePath, spriteSize)
{
    _transform->scale = Vector2(50.0f, 50.0f);
}

void PowerUp1000::OnCollision(Object* other) {
    // Verificamos si es el jugador
    Player* player = dynamic_cast<Player*>(other);

    if (player != nullptr) {
        // EL OVERRIDE: Este mensaje será distinto al del padre
        std::cout << "Score + 1000" << std::endl;

        // Llamamos a destruir para que desaparezca al tocarlo
        this->Destroy();
    }
}