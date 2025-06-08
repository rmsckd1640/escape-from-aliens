#include <stdio.h>
#include "player.h"
#include "map.h"

void initHP(Player* p) { // 플레이어 HP 초기화
    p->max_hp = 3;
    p->hp = p->max_hp;
}

void takeDamage(Player* p, int dmg) { 
    p->hp -= dmg; // HP에서 데미지만큼 감소
    if (p->hp < 0) p->hp = 0; // HP가 0보다 작아지면 0으로 고정
}

void heal(Player* p, int amount) {
    p->hp += amount; // HP에 회복량만큼 추가
    if (p->hp > p->max_hp) p->hp = p->max_hp; // HP가 최대 HP보다 커지면 최대 HP로 고정
}

void initPosition(Player* pos) { // 플레이어 좌표 초기화
    pos->x = MAP_WIDTH / 2;
    pos->y = MAP_HEIGHT / 2;
}

void move(Player* pos, char dir) { // wasd 키를 입력해 좌표 이동
    int new_x = pos->x;
    int new_y = pos->y;

    switch (dir) {
    case 'w': new_y--; break; // 위
    case 's': new_y++; break; // 아래
    case 'a': new_x--; break; // 왼쪽
    case 'd': new_x++; break; // 오른쪽
    }

    if (new_x > 0 && new_x < MAP_WIDTH - 1 && 
        new_y > 0 && new_y < MAP_HEIGHT - 1) { // 맵안에서의 움직임만 허용
        pos->x = new_x;
        pos->y = new_y;
    }
}

void drawPlayer(Player* p, char map[][MAP_WIDTH]) { // 플레이어 화면 출력
    map[p->y][p->x] = '*';
}