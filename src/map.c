#include <stdio.h>
#include "map.h"

char map[MAP_HEIGHT][MAP_WIDTH];

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

void drawMap(void) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }
}

void setTile(int x, int y, char tile) {
    if (x > 0 && x < MAP_WIDTH - 1 && y > 0 && y < MAP_HEIGHT - 1) {
        map[y][x] = tile;
    }
}