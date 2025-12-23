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
					SpawnBubbles();
					break;
				case 1:
					SpawnKillerWhale(amountEnemies[currentWave]);
					break;
				case 2:
					SpawnHMedusa();
					break;
				case 3:
					SpawnCircler();
					break;
				case 4:
					SpawnVMedusa();
					break;
				case 5:
					SpawnBeholder();
					break;
				case 6:
					SpawnChomper();
					break;
				case 7:
					SpawnAmoeba();
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

		if(IM->GetEvent(SDLK_1, DOWN))
			SpawnBubbles();
		if(IM->GetEvent(SDLK_2, DOWN))
			SpawnKillerWhale(amountEnemies[currentWave]);
		if(IM->GetEvent(SDLK_3, DOWN))
			SpawnVMedusa();
		if(IM->GetEvent(SDLK_4, DOWN))
			SpawnHMedusa();
		if(IM->GetEvent(SDLK_5, DOWN))
			SpawnChomper();
		if(IM->GetEvent(SDLK_6, DOWN))
			SpawnCircler();
		if(IM->GetEvent(SDLK_7, DOWN))
			SpawnBeholder();
		if(IM->GetEvent(SDLK_8, DOWN))
			SpawnAmoeba();
		if(IM->GetEvent(SDLK_9, DOWN))
			SpawnBioTitan();
	}

	void SpawnVMedusa() {}
	void SpawnHMedusa() {}
	void SpawnBeholder() {
		//for (int i = 1; i < 3; i++) {
		//	SPAWNER.SpawnObject(new Beholder(Vector2(RM->WINDOW_WIDTH - 50 * 1, RM->WINDOW_HEIGHT - 20)));
		//}
	}
	void SpawnChomper() {
		for (int i = 0; i < 15; i++)
		{
			Chomper* chomper = new Chomper(Vector2(RM->WINDOW_WIDTH - 50, (offsetChomper * i)));
			SPAWNER.SpawnObject(chomper);
			WM->SetEnemy(chomper);
		}
	}
	void SpawnBubbles() {}
	void SpawnKillerWhale(int count) {

		for (int i = 0; i < count; i++) {
			KillerWhale* kw = new KillerWhale(i % 2 == 0);
			SPAWNER.SpawnObject(kw);
			WM->SetEnemy(kw);
		}

		std::cout << "Spawned Whales" << std::endl;

	}
	void SpawnCircler() {}
	void SpawnAmoeba() {}
	void SpawnBioTitan() {}
};