#pragma once
#include "ImageObject.h"

class PowerUp : public ImageObject {
public:
    PowerUp(const char* texturePath, Vector2 spriteSize);

    virtual ~PowerUp() {}

    void OnCollision(Object* other) override;
    void Update() override;
};