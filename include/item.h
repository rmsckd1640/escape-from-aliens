#ifndef ITEM_H
#define ITEM_H

#include "player.h"  // PlayerHP 구조체 사용을 위해 필요

#define MAX_ITEMS 10  // 동시에 화면에 존재할 수 있는 최대 아이템 수

/**
 * 아이템 구조체 정의
 * - x, y: 아이템 위치
 * - symbol: 아이템 종류 ('H': 체력, 'B': 폭탄)
 * - active: 아이템 활성 여부 (1: 활성, 0: 비활성)
 * - lifetime: 남은 턴 수 (0이 되면 사라짐)
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
 * - 맵 내 중복되지 않는 위치에 아이템을 1개 생성합니다.
 */
void spawnItem();

/**
 * drawItems
 * - 활성화된 아이템을 맵 상에 표시합니다.
 */
void drawItems();

/**
 * checkItemCollision
 * - 플레이어 위치에 있는 아이템과 충돌 시 효과를 적용합니다.
 *   'H': 체력 회복 / 'B': 주변 적 제거
 *
 * @param playerX 플레이어 x 좌표
 * @param playerY 플레이어 y 좌표
 * @param hp 플레이어 체력 구조체 포인터
 */
void checkItemCollision(int playerX, int playerY, PlayerHP* hp);

/**
 * updateItems
 * - 아이템 수명을 1 감소시키고, 수명이 다 되면 비활성화합니다.
 */
void updateItems();

/**
 * respawnItems
 * - 수명이 5 이하인 활성 아이템을 새 위치로 이동시킵니다.
 */
void respawnItems();

/**
 * printHPBar
 * - 플레이어 체력을 ♥ / ♡ 형태로 출력합니다. 예: ♥♥♥♡♡ (3/5)
 */
void printHPBar(PlayerHP* hp);

#endif  // ITEM_H