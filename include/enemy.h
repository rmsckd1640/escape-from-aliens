#ifndef ENEMY_H
#define ENEMY_H

#define MAX_ENEMIES 100

#include "player.h"
#include "map.h"

typedef struct {
    int x;
    int y;
    int active; // 1: 화면에 존재함, 0: 제거됨
    int type; //적 종류 - E : 랜덤으로 이동 , e : 플레이어에게 다가옴
}Enemy;

//적 정보 배열
Enemy enemies[MAX_ENEMIES];

//적 초기화
//MAX_ENEMIES에 입력된 숫자만큼 적 생성 가능
//적을 전부 없애고 싶을때도 사용 가능
void initEnemies();

// 적을 생성하고 적 배열에 등록한다.
// 함수 호출 시 적 1명 생성함.
// @param pos: player 위치 정보 
void spawnEnemy(const Position pos);

// 적 움직임 설정
// 함수 호출 시 적에 대한 위치가 랜덤으로 변함.
// @param pos: player 위치 정보 
void moveEnemiesDown(const Position pos);
#endif