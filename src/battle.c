#include "battle.h"
#include <stdio.h>

// Enemy 구조체가 정의된 enemy.h 포함 필요
#include "enemy.h"
#include "player.h"

//적 충돌 시 player 데미지
//추후 player 구조체 변경 시 수정
void checkEnemyCollision(PlayerHP* playerHp, const Position* playerPos, Enemy* enemies, int enemyCount) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) continue;//적 없으면 건너뜀.

        if (enemies[i].x == playerPos->x && enemies[i].y == playerPos->y) {//좌표 같을 시 player 데미지 받으며 enemy 없어짐.
            takeDamage(playerHp, 1);
            enemies[i].active = 0;//enemy 없어짐.
            printf(">> 적과 충돌! HP -(%d/%d)\n", playerHp->hp, playerHp->max_hp);
        }
    }
}
