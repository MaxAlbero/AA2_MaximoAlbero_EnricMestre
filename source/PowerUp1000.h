#pragma once
#include "PowerUp.h"

class PowerUp1000 : public PowerUp {
public:
    // El constructor recibe la ruta de imagen y el tamaño
    PowerUp1000(const char* texturePath, Vector2 spriteSize);

    // Sobrescribimos la colisión para cambiar el mensaje
    void OnCollision(Object* other) override;
};