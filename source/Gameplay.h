#pragma once
#include "TextObject.h"
#include "Scene.h"
#include "TestObject.h"
#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "SpawnWaves.h"
#include "PowerUp1000.h"
#include "Background.h"
#include "Scroll.h"

#include "LoadLevel.h"

class Gameplay : public Scene {
public:
	SpawnWaves* waves;
	Gameplay() = default;

	void OnEnter() override {

		waves = new SpawnWaves();
		LoadLevel levelLoader;
		std::string filePath = "level_1.xml";

		if (levelLoader.LoadFile(filePath, waves->GetWaveOrder(), waves->GetAmountEnemies())) {
			std::cout << "Level loaded successfully" << std::endl;
			waves->Start();
		}
		else {
			std::cout << "Failed to load level" << std::endl;
		}

		Background* bg1 = new Background();

		Background* bg2 = new Background();
		bg2->GetTransform()->position = Vector2(RM->WINDOW_WIDTH * 2.0f, RM->WINDOW_HEIGHT / 2.0f);

		SPAWNER.SpawnObject(bg1);
		SPAWNER.SpawnObject(bg2);

		Player* player = new Player();
		SPAWNER.SpawnObject(player);

		waves->SetPlayer(player);


		TextObject* text = new TextObject("UASINI");
		text->GetTransform()->position = { 100.0f, 100.0f };
		_ui.push_back(text);
		SPAWNER.SpawnObject(new PowerUp("resources/image.png", Vector2(100.f, 100.f)));
		SPAWNER.SpawnObject(new PowerUp1000("resources/image.png", Vector2(128.f, 128.f)));
	}

	void OnExit() override { Scene::OnExit(); }

	void Update() override { 
		waves->Update();

		Scene::Update(); 
	
	}

	void Render() override { Scene::Render(); }
};