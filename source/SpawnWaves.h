#pragma once
#include "InputManager.h"
#include "Spawner.h"

#include "Hmedusa.h"
#include "Vmedusa.h"
#include "Bubbles.h"
#include "Chomper.h"
#include "Circler.h"
#include "CirclerBody.h"
#include "Beholder.h"
#include "KillerWhale.h"

class SpawnWaves {

	
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

		SPAWNER.SpawnObject(new KillerWhale(true));
		SPAWNER.SpawnObject(new KillerWhale(false));
	}
	void SpawnCircler() {}
	void SpawnAmoeba() {}
	void SpawnBioTitan() {}
};