#pragma once
#include "ImageObject.h"
//#include "RenderManager.h"

// Spwanear 2 imagenes, una enmedio de la pantalla, otra que sobrepase el limite de la pantalla
// meterSetVelocity negativo para que vaya hacia la izquierda
// cuado sobrepase el width se mueve a la posicion del segundo y asi en bucle

class Background : public ImageObject {  
public:
	Background()
		: ImageObject("resources/UmaSentimiento.jpg", Vector2(0.f, 0.f), Vector2(680.f, 383.f)) {
	
		_transform->position = Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT / 2.f);
		//_transform->scale = Vector2(0.5f, 0.5f);
	}
	
	void Update() override {
		ScrollBG();

		Object::Update();
	}

	void ScrollBG() {
		_physics->SetVelocity(Vector2(-5.f, 0.f));

		if (_transform->position.x < 0.f) { //RM->WINDOW_WIDTH
			std::cout << "BYE BYE" << std::endl;
			_transform->position.x = RM->WINDOW_WIDTH;
			
		} 
	}

};