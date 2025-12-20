#pragma once
#include "TextObject.h"
#include "Scene.h"
#include "TestObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Hmedusa.h"
#include "Vmedusa.h"
#include "Bubbles.h"

#include "Background.h"
#include "Scroll.h"

class Gameplay : public Scene {

protected:
	Scroll _scroll;

public:
	Gameplay() = default;

	void OnEnter() override {

		Background* bg1 = new Background();
		//bg1->GetTransform()->position = { (float)RM->WINDOW_WIDTH, (float)RM->WINDOW_HEIGHT / 2.0f };
		//bg1->GetTransform()->size = { 1000.f, 1000.f };
		Background* bg2 = new Background();
		bg2->GetTransform()->position = Vector2(RM->WINDOW_WIDTH * 2.0f, RM->WINDOW_HEIGHT / 2.0f);
		//bg2->GetTransform()->size = { 1000.f, 1000.f };

		SPAWNER.SpawnObject(bg1);
		SPAWNER.SpawnObject(bg2);


		SPAWNER.SpawnObject(new Player());
		//SPAWNER.SpawnObject(new Enemy());

		//SPAWNER.SpawnObject(new Vmedusa(Vector2(RM->WINDOW_WIDTH / 2.f, RM->WINDOW_HEIGHT)));
		SPAWNER.SpawnObject(new Bubbles(TOP_TO_BOTTOM)); //SALE DE LA PARTE ALTA DE LA PANTALLA Y LUEGO BAJA
		SPAWNER.SpawnObject(new Bubbles(BOTTOM_TO_TOP)); //SALE DE LA PARTE BAJA DE LA PANTALLA Y LUEGO SUBE


		TextObject* text = new TextObject("UASINI");
		text->GetTransform()->position = { 100.0f, 100.0f };
		_ui.push_back(text);
	}

	void OnExit() override { Scene::OnExit(); }

	void Update() override { Scene::Update(); }

	void Render() override { Scene::Render(); }
};