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
                // 맵 테두리에는 적이 생성되지 않도록 조정
                enemy_x = (rand() % (SCREEN_WIDTH-2)) + 1;
                enemy_y = (rand() % (SCREEN_HEIGHT-2)) + 1;

                // 플레이어와의 거리 계산
                int dx = enemy_x - x;
                int dy = enemy_y - y;
                distance = sqrt((double)dx * dx + (double)dy * dy);

            } while (distance < 3);  // 거리 3 미만이면 다시 생성

            enemies[i].x = enemy_x;
            enemies[i].y = enemy_y;
            enemies[i].active = 1;
            enemies[i].type = rand() % 2;

            break; // 하나만 생성
        }
    }
}

//적 이동 알고리즘 추후 개선
void moveEnemiesDown(int x, int y) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {

            if (enemies[i].type == 0) {//적이 플레이어 기준으로 이동하는 타입
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
            }

            else if (enemies[i].type == 1) {//적이 랜덤으로 이동하는 타입
                if (rand() % 2) {
                    enemies[i].x += (enemies[i].x < x) ? 1 : -1;
                }
                else {
                    enemies[i].y += (enemies[i].y < y) ? 1 : -1;
                }
            }

            // 적이 플레이어에게 닿았을 시 사라짐
            if (enemies[i].x == x && enemies[i].y == y) {
                enemies[i].active = 0;
            }
        }
    }
}
