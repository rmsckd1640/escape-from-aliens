#ifndef ITEM_H
#define ITEM_H

#define MAX_ITEMS 10  // 화면에 동시에 존재할 수 있는 최대 아이템 수

/**
 * 아이템 구조체 정의
 * - x, y: 아이템 위치
 * - symbol: 아이템 종류 ('+', 'H', 'S', 'B')
 * - active: 아이템 활성 상태 (0 = 비활성, 1 = 활성)
 * - lifetime: 아이템이 사라지기 전까지 남은 턴 수
 */
typedef struct {
    int x, y;
    char symbol;   // '+': 점수 / 'H': 체력 / 'S': 속도 / 'B': 폭탄
    int active;
    int lifetime;
} Item;

/**
 * initItems
 * - 모든 아이템을 비활성화 상태로 초기화
 * - 게임 시작 시 호출
 */
void initItems();

/**
 * spawnItem
 * - 맵 내 무작위 위치에 아이템 1개 생성
 * - 다른 아이템과 겹치지 않도록 위치 조정
 */
void spawnItem();

/**
 * drawItems
 * - 활성화된 아이템들을 맵 상에 출력
 * - drawMap() 호출 전에 사용 필요
 */
void drawItems();

/**
 * checkItemCollision
 * - 플레이어 좌표와 아이템 충돌 확인
 * - 아이템 효과 적용 (점수, 체력 회복, 속도 증가, 적 제거 등)
 * - 속도 증가 효과는 speedBoostTurns 포인터로 전달됨
 *
 * @param playerX 플레이어 x 좌표
 * @param playerY 플레이어 y 좌표
 * @param speedBoostTurns 속도 증가 효과 턴 수 (출력)
 * @return 점수 보너스
 */
int checkItemCollision(int playerX, int playerY, int* speedBoostTurns);

/**
 * updateItems
 * - 매 턴마다 호출하여 아이템의 남은 수명을 1씩 감소
 * - 수명이 다 된 아이템은 자동 제거됨
 */
void updateItems();

#endif
