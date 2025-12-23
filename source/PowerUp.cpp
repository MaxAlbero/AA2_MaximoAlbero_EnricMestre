#include "PowerUp.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "Player.h"
#include <iostream>

PowerUp::PowerUp(const char* texturePath, Vector2 spriteSize)
    : ImageObject(texturePath, Vector2(0, 0), spriteSize)
{
    _transform->position = Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f);
    _transform->size = spriteSize;

    _physics->AddCollider(new AABB(_transform->position, _transform->size));
}

void PowerUp::OnCollision(Object* other)
{
    Player* player = dynamic_cast<Player*>(other);
    if (player != nullptr) {
        std::cout << "PowerUp recogido!" << std::endl;
        this->Destroy();
    }
}

void PowerUp::Update() {
    Object::Update();
}