#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "item.h"
#include "map.h"
#include "enemy.h"

Item items[MAX_ITEMS];

const int ITEM_TYPES_COUNT = 2;

void initItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].active = 0;
    }
}

char getRandomItemSymbol() {
    return (rand() % 100 < 60) ? 'H' : 'B';  // 체력 또는 폭탄
}

void spawnItem() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].active) {
            int px, py, overlap;
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

void drawItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active) {
            setTile(items[i].x, items[i].y, items[i].symbol);
        }
    }
}

int checkItemCollision(int playerX, int playerY, int* speedBoostTurns) {
    int bonus = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active && items[i].x == playerX && items[i].y == playerY) {
            switch (items[i].symbol) {
            case 'H':
                printf("[아이템] 체력 회복 +5!\n");
                bonus = 5;
                break;
            case 'B':
                printf("[아이템] 폭탄 발동!\n");
                for (int j = 0; j < MAX_ENEMIES; j++) {
                    if (enemies[j].active) {
                        int dx = abs(enemies[j].x - playerX);
                        int dy = abs(enemies[j].y - playerY);
                        if (dx <= 1 && dy <= 1) {
                            enemies[j].active = 0;
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

void respawnItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active && items[i].lifetime <= 5) {
            int px, py, overlap;
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
            items[i].lifetime = 20;
            printf("[재배치] 아이템 '%c'이(가) 새 위치로 이동함 (%d,%d)\n", items[i].symbol, px, py);
        }
    }
}
