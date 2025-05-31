#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "map.h"
#include "enemy.h"

// 아이템 배열: 동시에 화면에 존재할 수 있는 최대 아이템 수
Item items[MAX_ITEMS];

// 아이템 종류 정의 (각 문자에 의미 부여)
// '+' : 점수 획득
// 'H' : 체력 회복 (현재는 점수로 대체 가능)
// 'S' : 속도 증가 (향후 구현 가능)
// 'B' : 폭탄 (근처 적 제거)
const char ITEM_TYPES[] = { '+', 'H', 'S', 'B' };
const int ITEM_TYPES_COUNT = 4; // 종류 개수

/**
 * 아이템 배열 초기화 함수
 * 모든 아이템을 비활성화 상태로 초기화
 * 게임 시작 시 반드시 호출 필요
 */
void initItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].active = 0;
    }
}

/**
 * 맵 내 랜덤 위치에 아이템 1개를 생성함
 * 생성된 아이템은 종류(symbol)와 지속시간(lifetime)을 가짐
 */
void spawnItem() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].active) {
            items[i].x = rand() % (MAP_WIDTH - 2) + 1;
            items[i].y = rand() % (MAP_HEIGHT - 2) + 1;
            items[i].symbol = ITEM_TYPES[rand() % ITEM_TYPES_COUNT];
            items[i].active = 1;
            items[i].lifetime = 20; // 20턴 후 사라짐
            break;
        }
    }
}

/**
 * 현재 활성화된 아이템들을 맵에 표시함
 * drawMap() 호출 전에 이 함수 호출 필요
 */
void drawItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active) {
            setTile(items[i].x, items[i].y, items[i].symbol);
        }
    }
}

/**
 * 플레이어가 아이템을 먹었는지 확인하고, 효과 적용
 * - 점수 획득, 체력 회복, 속도 증가, 폭탄 등의 기능 구현
 * - 아이템을 먹으면 비활성화됨
 *
 * @param playerX 플레이어 X 좌표
 * @param playerY 플레이어 Y 좌표
 * @return 점수 보너스 (게임 점수 증가용)
 */
int checkItemCollision(int playerX, int playerY) {
    int bonus = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active &&
            items[i].x == playerX &&
            items[i].y == playerY) {

            // 충돌한 아이템 종류에 따른 효과 처리
            switch (items[i].symbol) {
            case '+': // 점수 아이템
                bonus = 10;
                break;
            case 'H': // 체력 회복 → 점수로 대체 가능
                bonus = 5;
                break;
            case 'S': // 속도 증가 (현재 기능 없음)
                bonus = 0;
                break;
            case 'B': // 폭탄 아이템: 주변 반경 2 이하의 적 제거
                for (int j = 0; j < MAX_ENEMIES; j++) {
                    if (enemies[j].active) {
                        int dx = enemies[j].x - playerX;
                        int dy = enemies[j].y - playerY;
                        if (dx * dx + dy * dy <= 4) { // √(dx²+dy²) ≤ 2
                            enemies[j].active = 0;
                            bonus += 3; // 적 하나당 3점
                        }
                    }
                }
                break;
            }

            // 아이템 효과 적용 후 비활성화
            items[i].active = 0;
            break;
        }
    }

    return bonus;
}

/**
 * 매 턴마다 아이템의 수명을 감소시키고,
 * 수명이 0이 되면 자동으로 사라지게 처리함
 * 이 함수는 게임 루프 내에서 매 프레임/턴마다 호출 필요
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
