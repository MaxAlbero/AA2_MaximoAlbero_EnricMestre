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
	const int maxWaves = 5;
	float offsetCircler = 30.f;
	float offsetChomper = 50.f;

	float spawnTimer;
	float delaySpawnDuration = 5.0f;
	std::vector<int> waveOrder;
	std::vector<int> amountEnemies;

public:

	void Update() {

		if(IM->GetEvent(SDLK_1, DOWN))
			SpawnBubbles();
		if(IM->GetEvent(SDLK_2, DOWN))
			SpawnKillerWhale();
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
	void SpawnChomper() {}
	void SpawnBubbles() {}
	void SpawnKillerWhale() {

		KillerWhale* kw1 = new KillerWhale(true);
		KillerWhale* kw2 = new KillerWhale(false);

		SPAWNER.SpawnObject(kw1);
		WM->SetEnemy(kw1);

		SPAWNER.SpawnObject(kw2);
		WM->SetEnemy(kw2);

	}
	void SpawnCircler() {}
	void SpawnAmoeba() {}
	void SpawnBioTitan() {}
};