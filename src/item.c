#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "item.h"
#include "map.h"
#include "enemy.h"

Item items[MAX_ITEMS];

// 아이템 종류 정의
const int ITEM_TYPES_COUNT = 4;

/**
 * 아이템 배열 초기화
 */
void initItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].active = 0;
    }
}

/**
 * 특정 확률로 아이템 종류를 결정
 */
char getRandomItemSymbol() {
    int r = rand() % 100;
    if (r < 50) return '+';       // 50% 확률
    else if (r < 75) return 'H';  // 25%
    else if (r < 90) return 'S';  // 15%
    else return 'B';              // 10%
}

/**
 * 중복되지 않도록 아이템 1개를 맵에 생성
 */
void spawnItem() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].active) {
            int px, py;
            int overlap;
            do {
                px = rand() % (MAP_WIDTH - 2) + 1;
                py = rand() % (MAP_HEIGHT - 2) + 1;

                overlap = 0;
                for (int j = 0; j < MAX_ITEMS; j++) {
                    if (items[j].active && items[j].x == px && items[j].y == py) {
                        overlap = 1;
                        break;
                    }
                }
            } while (overlap);

            items[i].x = px;
            items[i].y = py;
            items[i].symbol = getRandomItemSymbol();
            items[i].active = 1;
            items[i].lifetime = 20;
            break;
        }
    }
}

/**
 * 활성화된 아이템 맵에 표시
 */
void drawItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active) {
            setTile(items[i].x, items[i].y, items[i].symbol);
        }
    }
}

/**
 * 플레이어와 아이템 충돌 확인 및 효과 적용
 */
int checkItemCollision(int playerX, int playerY, int* speedBoostTurns) {
    int bonus = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active &&
            items[i].x == playerX &&
            items[i].y == playerY) {

            switch (items[i].symbol) {
            case '+':
                printf("[아이템] 점수 +10!\n");
                bonus = 10;
                break;
            case 'H':
                printf("[아이템] 체력 회복 +5!\n");
                bonus = 5;
                break;
            case 'S':
                printf("[아이템] 속도 증가!\n");
                *speedBoostTurns = 10;
                break;
            case 'B':
                printf("[아이템] 폭탄 발동!\n");
                for (int j = 0; j < MAX_ENEMIES; j++) {
                    if (enemies[j].active) {
                        int dx = enemies[j].x - playerX;
                        int dy = enemies[j].y - playerY;
                        if (dx * dx + dy * dy <= 4) {
                            enemies[j].active = 0;
                            bonus += 3;
                        }
                    }
                }
                break;
            }

            items[i].active = 0;
            break;
        }
    }

    return bonus;
}

/**
 * 매 턴 아이템 수명 감소 처리
 */
void updateItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active) {
            items[i].lifetime--;
            if (items[i].lifetime <= 0) {
                items[i].active = 0;
            }
        }
    }
}
