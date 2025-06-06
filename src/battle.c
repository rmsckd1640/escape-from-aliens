#include "battle.h"
#include <stdio.h>

//적 충돌 시 player hp 깎임.
//추후 player 구조체 변경 시 수정.

void checkEnemyCollision(Player *p, Enemy* enemies, int enemyCount) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) continue;//적 없으면 건너뜀.

        if (enemies[i].x == p->x && enemies[i].y == p->y) {//좌표 같을 시 player 데미지 받으며 enemy 없어짐.
            takeDamage(p, 1);
            enemies[i].active = 0;//enemy 없어짐.
            printf(">> 적과 충돌! HP -(%d/%d)\n", p->hp, p->max_hp);
        }
    }
}

