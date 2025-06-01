#include <stdio.h>
#include "player.h"

void initHP(PlayerHP* p) { // 플레이어 HP = 3 초기화
    p->max_hp = 3;
    p->hp = p->max_hp;
}

void takeDamage(PlayerHP* p, int dmg) { 
    p->hp -= dmg; // HP에서 데미지만큼 감소
    if (p->hp < 0) p->hp = 0; // HP가 0보다 작아지면 0으로 고정
}

void heal(PlayerHP* p, int amount) {
    p->hp += amount; // HP에 회복량만큼 추가
    if (p->hp > p->max_hp) p->hp = p->max_hp; // HP가 최대 HP보다 커지면 최대 HP로 고정
}