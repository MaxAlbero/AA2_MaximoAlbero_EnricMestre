#pragma once
#include "ImageObject.h"
//#include "RenderManager.h"

class Background : public ImageObject {
public:
	Background()
		: ImageObject("resources/UmaSentimiento.jpg", Vector2(0.f, 0.f), Vector2(680.f, 383.f)) {
	
		_transform->position = Vector2(RM->WINDOW_WIDTH / 1.f, RM->WINDOW_HEIGHT / 2.f);
		_transform->scale = Vector2(0.5f, 0.5f);
	}
	/*
	void Update() override {
		ScrollBG();

		Object::Update();
	}*/

	//void ScrollBG();

};