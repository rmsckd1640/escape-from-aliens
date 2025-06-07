#ifndef ITEM_H
#define ITEM_H

#include <time.h>
#include "player.h"  // Player 구조체 사용을 위해 포함

#define MAX_ITEMS 10  // 동시에 화면에 존재할 수 있는 최대 아이템 수

/**
 * 아이템 구조체 정의
 *
 * 각 아이템은 맵 위에 표시되며 다음과 같은 정보를 가짐:
 * - x, y: 아이템의 맵 상 위치
 * - symbol: 아이템 종류 ('H': 체력 회복, 'B': 폭탄)
 * - active: 현재 활성 상태 여부 (1이면 화면에 있음, 0이면 사라짐)
 * - created_at: time(NULL) 기반 생성 시간. 수명 및 재배치 판단에 사용됨
 */
typedef struct {
    int x, y;               // 맵 위치
    char symbol;            // 아이템 종류 문자
    int active;             // 활성 여부
    time_t created_at;      // 생성된 시간
} Item;

/**
 * initItems
 *
 * 모든 아이템을 비활성 상태로 초기화한다.
 * 주로 게임 시작 시 또는 전체 리셋 시 호출.
 */
void initItems();

/**
 * spawnItem
 *
 * 비활성화된 아이템 슬롯을 찾아 새로운 아이템 1개를 생성한다.
 * 생성 위치는 맵 내에서 랜덤하게 지정되며, 다른 아이템과 겹치지 않는다.
 * 생성 시점의 시간도 기록하여 수명 추적에 사용된다.
 */
void spawnItem();

/**
 * drawItems
 *
 * 현재 활성화된 모든 아이템을 맵 상에 표시한다.
 * 각 아이템의 위치(x, y)와 symbol에 따라 출력함.
 */
void drawItems();

/**
 * checkItemCollision
 *
 * 플레이어 위치와 아이템이 충돌했는지 확인하고, 충돌 시 해당 효과를 적용한다.
 * - 'H': 플레이어 체력 1 회복
 * - 'B': 플레이어 주변 3x3 범위의 적을 모두 제거
 * 효과 적용 후 해당 아이템은 사라진다 (active = 0).
 *
 * @param playerX 플레이어의 x 좌표
 * @param playerY 플레이어의 y 좌표
 * @param p 플레이어 구조체 포인터 (hp 정보 사용)
 */
void checkItemCollision(int playerX, int playerY, Player* p);

/**
 * updateItems
 *
 * 모든 아이템의 생존 시간을 검사하여, 생성된 지 ITEM_LIFESPAN_SEC초 이상 지났다면 제거한다.
 * 내부적으로 현재 시간과 생성 시간(created_at)을 비교하여 active 여부를 조절함.
 */
void updateItems();

/**
 * respawnItems
 *
 * 생성된 지 RESPAWN_THRESHOLD_SEC초 이상이지만 아직 사라지지 않은(active 상태인)
 * 아이템을 맵 내 다른 위치로 재배치한다.
 * 재배치 시점에 생성 시간을 다시 초기화하여 수명을 리셋한다.
 */
void respawnItems();

/**
 * printHPBar
 *
 * 플레이어의 현재 체력을 시각적으로 ♥(채워짐)와 ♡(빈칸) 형태로 출력한다.
 * 예: ♥♥♡ (2/3)
 *
 * @param p 플레이어 구조체 포인터
 */
void printHPBar(Player* p);

#endif  // ITEM_H
