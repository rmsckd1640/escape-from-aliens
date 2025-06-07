#include <stdio.h>
#include "map.h"
#include "enemy.h"  // 적 정보 사용을 위해 추가
#include "player.h"
#include "item.h"

void initMap(void) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = ' '; // 빈 공간
        }
    }

    // 테두리 벽 만들기
    for (int x = 0; x < MAP_WIDTH; x++) {
        map[0][x] = '#';
        map[MAP_HEIGHT - 1][x] = '#';
    }
    for (int y = 0; y < MAP_HEIGHT; y++) {
        map[y][0] = '#';
        map[y][MAP_WIDTH - 1] = '#';
    }
}

extern Player p;     // 다른 모듈에서 선언된 전역 플레이어 구조체

void drawMap(void) {
    initMap();

    // 1. 적 출력
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            map[enemies[i].y][enemies[i].x] = 'E';
        }
    }

    // 2. 아이템 출력
    drawItems(); // map에 H 또는 B 심볼을 표시

    // 3. 플레이어 출력
    drawPlayer(&p, map); // 플레이어 위치에 '*' 표시

    // 4. 맵 출력
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }

    // 5. 플레이어 HP 출력
    printHPBar(&p);  // ♥♥♡ 형태로 HP 바 출력

    // 6. 아이템 충돌 체크 (아이템을 먹었는지 검사하고 효과 적용)
    checkItemCollision(p.x, p.y, &p);

}

void setTile(int x, int y, char tile) {
    if (x > 0 && x < MAP_WIDTH - 1 && y > 0 && y < MAP_HEIGHT - 1) {
        map[y][x] = tile;
    }
}