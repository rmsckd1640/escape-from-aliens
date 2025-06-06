#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"
#include "map.h"

#define MAX_ENEMIES 10
#define MAX_BULLETS 100

typedef struct {
    int x;
    int y;
    int active; // 1: 화면에 존재함, 0: 제거됨
    int type; //적 종류 - E : 랜덤으로 이동 , e : 플레이어에게 다가옴
}Enemy;

typedef struct {
    int x, y;       // 현재 위치
    int dx, dy;     // 이동 방향
    int active;     // 활성 상태
} Bullet;

//적 정보 배열
Enemy enemies[MAX_ENEMIES];
Bullet bullets[MAX_BULLETS];

//적 초기화
//MAX_ENEMIES에 입력된 숫자만큼 적 생성 가능
//적을 전부 없애고 싶을때도 사용 가능
//bullet 초기화
void initEnemies();

// 적을 생성하고 적 배열에 등록한다.
// 함수 호출 시 적 1명 생성함.
// @param p: player 정보 
void spawnEnemy(const Player p);

// 적 움직임 설정
// 함수 호출 시 적에 대한 위치가 랜덤으로 변함.
// @param p: player 정보 
void moveEnemiesDown(const Player p);

// 적 움직임 맵 제한 반경 설정
// 맵 밖으로 움직이는 경우 확인
// @param enemy: 적 정보
// @param dx: x좌표 이동 예정 값
// @param dy: y좌표 이동 예정 값
void moveCheckEnemy(Enemy* enemy, int dx, int dy);

// 맵 가장자리에 총알을 생성
void spawnBulletFromEdge();

// 총알 한 칸 이동
void moveBullets();
#endif