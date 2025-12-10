#pragma once
#include "TextObject.h"
#include "Scene.h"
#include "TestObject.h"
#include "Enemy.h"



class Gameplay : public Scene {
public:
	Gameplay() = default;

	void OnEnter() override {
		SPAWNER.SpawnObject(new TestObject());
		SPAWNER.SpawnObject(new Enemy());

		TextObject* text = new TextObject("UASINI");
		text->GetTransform()->position = { 100.0f, 100.0f };
		_ui.push_back(text);
	}

	void OnExit() override { Scene::OnExit(); }

	void Update() override { Scene::Update(); }

	void Render() override { Scene::Render(); }
};