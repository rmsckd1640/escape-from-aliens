#include <stdio.h>
#include "player.h"

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
    pos->x = 0;
    pos->y = 0;
}

void move(Player* pos, char dir) { // wasd 키를 입력해 좌표 이동
    switch (dir) {
    case 'w': pos->y--; break; // 위
    case 's': pos->y++; break; // 아래
    case 'a': pos->x--; break; // 왼쪽
    case 'd': pos->x++; break; // 오른쪽
    }
}