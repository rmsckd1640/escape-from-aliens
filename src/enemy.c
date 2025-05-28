#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "enemy.h"

void initEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].active = 0;
    }
}

//
void spawnEnemy(int x, int y) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) {
            int enemy_x, enemy_y;
            double distance;

            do {
                // 화면 범위 내에서 적 위치 랜덤 설정 
                enemy_x = rand() % SCREEN_WIDTH;
                enemy_y = rand() % SCREEN_HEIGHT;

                // 플레이어와의 거리 계산
                int dx = enemy_x - x;
                int dy = enemy_y - y;
                distance = sqrt((double)dx * dx + (double)dy * dy);

            } while (distance < 3);  // 거리 3 미만이면 다시 생성

            enemies[i].x = enemy_x;
            enemies[i].y = enemy_y;
            enemies[i].active = 1;
            break; // 하나만 생성
        }
    }
}

//적 이동 알고리즘 추후 개선
void moveEnemiesDown(int x, int y) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            // x 방향 이동
            if (enemies[i].x < x) {
                enemies[i].x++;
            }
            else if (enemies[i].x > x) {
                enemies[i].x--;
            }

            // y 방향 이동
            if (enemies[i].y < y) {
                enemies[i].y++;
            }
            else if (enemies[i].y > y) {
                enemies[i].y--;
            }

            // 화면 밖으로 나가면 비활성화
            if (enemies[i].x == x && enemies[i].y == y) {
                enemies[i].active = 0;
            }
        }
    }
}
