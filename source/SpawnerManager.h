#pragma once
#include "Spawner.h"
#include "Enemy.h"
#include <vector>

#define WM SpawnerManager::GetInstance()



class SpawnerManager {
public:
	static SpawnerManager* GetInstance() {
		static SpawnerManager instance;
		return &instance;
	}

	void SetEnemy(Enemy* e) { //AddEnemy
		waveEnemies.push_back(e);
	}

	void CheckCurrentWave() {
		if (_waveActive) {
			for (int i = waveEnemies.size() - 1; i >= 0; i--) {
				if (waveEnemies[i]->IsPendngDestroy()) {
					waveEnemies.erase(waveEnemies.begin() + i);
				}
			}
			if (waveEnemies.empty()){
				SpawnPowerUp();
				_waveActive = false;
			}
		}
	}

	bool GetWaveActive() {
		return _waveActive;
	}
	
	bool GetNextWave() {
		return _nextWave;
	}

	void SpawnPowerUp() {
		//SPAWNER.SpawnObject(new PowerUp(spawnPowerUp));
	}

	void SetWaveActive(bool active) {
		_waveActive = active;
	}

	void SetNextWave(bool nextWave) {
		_nextWave = nextWave;
	}

	void SetPositionPowerUp(Vector2 newPos) {
		spawnPowerUp;
	}

private:
	std::vector<Enemy*> waveEnemies;
	Vector2 spawnPowerUp;
	bool _waveActive = false;
	bool _nextWave = false;
	SpawnerManager() = default;
	SpawnerManager(SpawnerManager&) = delete;
	SpawnerManager& operator= (const SpawnerManager&) = delete;
	~SpawnerManager();
};