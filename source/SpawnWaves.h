#pragma once
#include "InputManager.h"
#include "Spawner.h"

#include "SpawnerManager.h"

#include "Hmedusa.h"
#include "Vmedusa.h"
#include "Bubbles.h"
#include "Chomper.h"
#include "Circler.h"
#include "CirclerBody.h"
#include "Beholder.h"
#include "KillerWhale.h"

class SpawnWaves {
private:
	int currentWave = -1;
	int maxWaves = 7;
	float offsetCircler = 30.f;
	float offsetChomper = 50.f;

	float spawnTimer;
	float delaySpawnDuration = 1.0f;
	std::vector<int> waveOrder;
	std::vector<int> amountEnemies;

	void SetMaxWaves() {
		maxWaves = waveOrder.size();
	}

	void WaitForNextWave() {
		spawnTimer += TM.GetDeltaTime();
		if (spawnTimer >= delaySpawnDuration) {
			if (currentWave < maxWaves - 1) {
				currentWave++;
				spawnTimer = 0.f;
				WM->SetWaveActive(true);
				WM->SetNextWave(true);
			}
			else {
				SpawnBioTitan();
			}
		}
	}

public:
	std::vector<int>& GetWaveOrder() {
		return waveOrder;
	}

	std::vector<int>& GetAmountEnemies() {
		return amountEnemies;
	}

	void Start() {
		SetMaxWaves();
	}

	void Update() {
		if (WM->GetWaveActive()) {
			if (WM->GetNextWave()) {
				switch (waveOrder[currentWave])
				{
				case 0:
					SpawnBubbles(amountEnemies[currentWave]);
					break;
				case 1:
					SpawnKillerWhale(amountEnemies[currentWave]);
					break;
				case 2:
					SpawnHMedusa(amountEnemies[currentWave]);
					break;
				case 3:
					SpawnCircler();
					break;
				case 4:
					SpawnVMedusa(amountEnemies[currentWave]);
					break;
				case 5:
					SpawnBeholder(amountEnemies[currentWave]);
					break;
				case 6:
					SpawnChomper(amountEnemies[currentWave]);
					break;
				case 7:
					SpawnAmoeba(amountEnemies[currentWave]);
					break;
				default:
					break;
				}
				WM->SetNextWave(false);
			}
			WM->CheckCurrentWave();
		}
		else {
			WaitForNextWave();
		}
	}

	void SpawnVMedusa(int count) {
	

	}

	void SpawnHMedusa(int count) {
		for (int i = 0; i < count; i++) {

			float speed = rand() % 400 + 100;
			float positionY = rand() % RM->WINDOW_HEIGHT;
			SPAWNER.SpawnObject(new Hmedusa(Vector2(RM->WINDOW_WIDTH + 50.f, positionY)));
		}
	}

	void SpawnBeholder(int count) {
		//for (int i = 1; i < 3; i++) {
		//	SPAWNER.SpawnObject(new Beholder(Vector2(RM->WINDOW_WIDTH - 50 * 1, RM->WINDOW_HEIGHT - 20)));
		//}
	}
	void SpawnChomper(int count) {
		for (int i = 0; i < count; i++)
		{
			Chomper* chomper = new Chomper(Vector2(RM->WINDOW_WIDTH - 50, (offsetChomper * i)));
			SPAWNER.SpawnObject(chomper);
			WM->SetEnemy(chomper);
		}
	}
	void SpawnBubbles(int count) {
		float offsetX = 100.f;

		for (int i = 0; i < count; i++) {
			Enemy* bubbleUp = new Bubbles(TOP_TO_BOTTOM);
			bubbleUp->GetTransform()->position.x += offsetX * i;
			SPAWNER.SpawnObject(bubbleUp);
			WM->SetEnemy(bubbleUp);
			Enemy* bubbleDown = new Bubbles(BOTTOM_TO_TOP);
			bubbleDown->GetTransform()->position.x += offsetX * i;
			SPAWNER.SpawnObject(bubbleDown);
			WM->SetEnemy(bubbleDown);
		}
	}
	void SpawnKillerWhale(int count) {

		for (int i = 0; i < count; i++) {
			KillerWhale* kw = new KillerWhale(i % 2 == 0);
			SPAWNER.SpawnObject(kw);
			WM->SetEnemy(kw);
		}

		std::cout << "Spawned Whales" << std::endl;

	}

	void SpawnCircler() {
		Circler* head = new Circler();
		SPAWNER.SpawnObject(head);
		WM->SetEnemy(head);

		Enemy* previousSegment = head; // El primer segmento sigue a la cabeza

		for (int i = 0; i < 3; i++) {
			CirclerBody* body = new CirclerBody(previousSegment, 120.f);
			SPAWNER.SpawnObject(body);


			previousSegment = body; // El siguiente segmento seguirá a este
		}
	}

	void SpawnAmoeba(int count) {}
	void SpawnBioTitan() {
		

	}
};