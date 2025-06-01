#ifndef PLAYER_H
#define PLAYER_H

typedef struct { // 플레이어 HP 정보
    int hp;
    int max_hp;
} PlayerHP;

void initHP(PlayerHP* p); // 플레이어 HP 초기화
void takeDamage(PlayerHP* p, int dmg); // 플레이어가 데미지를 입었을 때 HP 감소
void heal(PlayerHP* p, int amount); // 플레이어가 회복할 때 HP 증가

#endif