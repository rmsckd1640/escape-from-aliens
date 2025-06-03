#include "player.h"

#define ENEMY_DAMAGE 1 // 닿았을 때 입히는 데미지

// 적이 플레이어에게 닿았는지 검사하고 데미지를 입힌다.
// @param enemies: 적 배열
void checkEnemyCollision(PlayerHP* playerHp, const Position* playerPos, Enemy* enemies, int enemyCount);


