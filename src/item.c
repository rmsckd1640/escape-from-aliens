#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "item.h"
#include "map.h"
#include "enemy.h"
#include "player.h"

Item items[MAX_ITEMS]; //아이템들을 저장하는 배열. 동시에 등장 가능한 최대 아이템 수만큼 크기 고정.
const int ITEM_TYPES_COUNT = 2; // 아이템 종류가 2개라는 것

#define ITEM_LIFESPAN_SEC 10      // 아이템이 생성된 후 10초 동안 유지된다 (10초 지나면 사라짐)
#define RESPAWN_THRESHOLD_SEC 5   // 아이템이 생성된 지 5초가 지나면 새 위치로 재배치할 수 있음


void initItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].active = 0;
    }
}

char getRandomItemSymbol() {
    return (rand() % 100 < 60) ? 'H' : 'B';  // 60%확률로 H, 40%확률로 B 
}

void spawnItem() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].active) {
            int px, py, overlap; //랜덤으로 좌표 생성
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
            items[i].created_at = time(NULL);  // 생성 시간 기록
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

void checkItemCollision(int playerX, int playerY, Player* p) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active && items[i].x == playerX && items[i].y == playerY) {
            switch (items[i].symbol) {
            case 'H':
                heal(p, 1);
                break;
            case 'B':
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
}

void updateItems() {
    time_t now = time(NULL);
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active) {
            double elapsed = difftime(now, items[i].created_at);
            if (elapsed >= ITEM_LIFESPAN_SEC) {
                items[i].active = 0;
            }
        }
    }
}

void respawnItems() {
    time_t now = time(NULL);
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active) {
            double elapsed = difftime(now, items[i].created_at);
            if (elapsed >= RESPAWN_THRESHOLD_SEC && elapsed < ITEM_LIFESPAN_SEC) {
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
                items[i].created_at = now;  // 재배치 시 시간 초기화
            }
        }
    }
}

void printHPBar(Player* p) {
    printf("HP: ");
    for (int i = 0; i < p->max_hp; i++) {
        if (i < p->hp) printf("\u2665");
        else printf("\u2661");
    }
    printf(" (%d/%d)\n", p->hp, p->max_hp);
}
