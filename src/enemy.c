#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "enemy.h"

//초기화
void initEnemies() {
    //적 초기화
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].active = 0;
    }
    //총알 초기화
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = 0;
    }
}

//적 생성
void spawnEnemy(const Player p) {
    //적 생성
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) {
            int enemy_x, enemy_y;
            double distance;

            do {
                // 화면 범위 내에서 적 위치 랜덤 설정 
                // 맵 테두리에는 적이 생성되지 않도록 조정
                enemy_x = (rand() % (MAP_WIDTH -2)) + 1;
                enemy_y = (rand() % (MAP_HEIGHT -2)) + 1;

                // 플레이어와의 거리 계산
                int dx = enemy_x - p.x;
                int dy = enemy_y - p.y;
                distance = sqrt((double)dx * dx + (double)dy * dy);

            } while (distance < 5);  // 거리 3 미만이면 다시 생성

            enemies[i].x = enemy_x;
            enemies[i].y = enemy_y;
            enemies[i].active = 1;
            enemies[i].type = rand() % 2;

            break; // 하나만 생성
        }
    }
}

//적 이동 알고리즘
void moveEnemiesDown(const Player p) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) continue;

        int dx = 0, dy = 0;

        if (enemies[i].type == 0) {//적이 플레이어 기준으로 이동하는 타입
            if (enemies[i].x == p.x)
            {
                dy += (enemies[i].y < p.y) ? 1 : -1;
            }
            else if (enemies[i].y == p.y)
            {
                dx += (enemies[i].x < p.x) ? 1 : -1;
            }
            else if (rand() % 2) {
                dx += (enemies[i].x < p.x) ? 1 : -1;
            }
            else {
                dy += (enemies[i].y < p.y) ? 1 : -1;
            }
        }

        else if (enemies[i].type == 1) {//적이 랜덤으로 이동하는 타입
            dx = (rand() % 3) - 1;
            dy = (rand() % 3) - 1;
        }

        moveCheckEnemy(&enemies[i], dx, dy);

        // 적이 플레이어에게 닿았을 시 사라짐
        if (enemies[i].x == p.x && enemies[i].y == p.y) {
            enemies[i].active = 0;
        }
    }
}

//적 이동 반경 확인
void moveCheckEnemy(Enemy* enemy, int dx, int dy) {
    int newX = enemy->x + dx;
    int newY = enemy->y + dy;

    // 맵 밖으로 나가지 않도록 제한
    if (newX >= 1 && newX < MAP_WIDTH-1) {
        enemy->x = newX;
    }
    if (newY >= 1 && newY < MAP_HEIGHT-1 ) {
        enemy->y = newY;
    }
}

//총알 생성 함수
void spawnBulletFromEdge() {
    int edge = rand() % 4;  // 0: top, 1: bottom, 2: left, 3: right
    int x=0 , y=0 , dx = 0, dy = 0;

    switch (edge) {
    case 0: // top
        x = rand() % MAP_WIDTH;
        y = 0;
        dy = 1;
        break;
    case 1: // bottom
        x = rand() % MAP_WIDTH;
        y = MAP_HEIGHT - 1;
        dy = -1;
        break;
    case 2: // left
        x = 0;
        y = 1 + rand() % (MAP_HEIGHT - 2);
        dx = 1;
        break;
    case 3: // right
        x = MAP_WIDTH - 1;
        y = 1 + rand() % (MAP_HEIGHT - 2);
        dx = -1;
        break;
    }

    // bullets 배열에서 비활성화된 것 찾아서 할당
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) {
            bullets[i].x = x;
            bullets[i].y = y;
            bullets[i].dx = dx;
            bullets[i].dy = dy;
            bullets[i].active = 1;
            break;
        }
    }
}

//총알 이동 알고리즘
void moveBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) continue;

        int newX = bullets[i].x + bullets[i].dx;
        int newY = bullets[i].y + bullets[i].dy;

        int hitWallX = (newX < 1 || newX >= MAP_WIDTH-1 );
        int hitWallY = (newY < 1 || newY >= MAP_HEIGHT-1 );

        // 벽에 닿으면 사라짐
        if (hitWallX || hitWallY) {
            bullets[i].active = 0;
            continue;
        }

        // 이동 적용
        bullets[i].x = newX;
        bullets[i].y = newY;
    }
}

