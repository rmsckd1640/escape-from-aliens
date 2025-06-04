#ifndef ITEM_H
#define ITEM_H

#define MAX_ITEMS 10  // 동시에 화면에 존재할 수 있는 최대 아이템 수

/**
 * 아이템 구조체 정의
 * - x, y: 아이템 위치
 * - symbol: 아이템 종류 ('+', 'H', 'S', 'B')
 * - active: 1이면 활성, 0이면 비활성
 * - lifetime: 남은 턴 수 (0이면 사라짐)
 */
typedef struct {
    int x, y;
    char symbol;
    int active;
    int lifetime;
} Item;

/**
 * initItems
 * - 모든 아이템을 비활성 상태로 초기화합니다.
 */
void initItems();

/**
 * spawnItem
 * - 맵 내에서 중복되지 않도록 아이템을 1개 생성합니다.
 */
void spawnItem();

/**
 * drawItems
 * - 활성화된 아이템을 맵 상에 표시합니다.
 */
void drawItems();

/**
 * checkItemCollision
 * - 플레이어와 충돌한 아이템을 처리하고 효과를 적용합니다.
 *
 * @param playerX: 플레이어 x 좌표
 * @param playerY: 플레이어 y 좌표
 * @param speedBoostTurns: 속도 증가 효과가 있다면 여기로 턴 수 반환
 * @return 얻은 점수 (보너스)
 */
int checkItemCollision(int playerX, int playerY, int* speedBoostTurns);

/**
 * updateItems
 * - 아이템의 수명을 감소시키고, 수명이 다 되면 제거합니다.
 */
void updateItems();

/**
 * respawnItems
 * - 수명이 거의 다 된 활성 아이템을 새로운 위치로 재배치합니다.
 * - lifetime이 5 이하인 경우만 대상이 됩니다.
 */
void respawnItems();

#endif
