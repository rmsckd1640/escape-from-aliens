#ifndef PLAYER_H
#define PLAYER_H

typedef struct { // 플레이어 정보
    int hp;
    int max_hp; 
    int x;
    int y;
} Player;

Player p;

void initHP(Player* p); // 플레이어 HP 초기화
void takeDamage(Player* p, int dmg); // 플레이어가 데미지를 입었을 때 HP 감소
void heal(Player* p, int amount); // 플레이어가 회복할 때 HP 증가

void initPosition(Player* pos); // 플레이어 좌표 초기화
void move(Player* pos, char dir); // 플레이어 좌표 이동

#endif