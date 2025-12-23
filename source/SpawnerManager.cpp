#include "SpawnerManager.h"

void SpawnManager::SetEnemy(Enemy* e) {
	waveEnemies.push.back(e);
}

SpawnerManager::~SpawnerManager()
{
	for (int i = waveEnemies.size() - 1; i >= 0; i--)
	{
		if (waveEnemies[i]->IsPendingDestroy()) {
			waveEnemies.erase(waveEnemies.begin() + i);
		}
		waveEnemies.clear();
	}
}