#include <stdio.h>
#include "enemy.h"
#include "map.h"

#define MAX_ENEMIES 10
#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 20

#ifdef _WIN32//윈도우
#include <windows.h>
#define CLEAR_SCREEN() clearScreenWindows()
#define SLEEP(seconds) Sleep((seconds) * 1000)
#else//맥


#endif

#ifdef _WIN32
//화면 초기화 함수
void clearScreenWindows() {
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#else

#endif

void drawScreen() {
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

    // 화면 초기화
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            if (x == SCREEN_WIDTH - 1) {
                screen[y][x] = 'w';
            }
            else if (y == SCREEN_HEIGHT - 1) {
                screen[y][x] = 'w';
            }
            else {
                screen[y][x] = ' ';
            }
        }

    // 적 배치
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            int x = enemies[i].x;
            int y = enemies[i].y;
            if (y >= 0 && y < SCREEN_HEIGHT && x >= 0 && x < SCREEN_WIDTH) {
                screen[y][x] = 'E';
            }
        }
    }

    screen[9][9] = 'P';//player위치 임시 설정

    // 화면 출력
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            putchar(screen[y][x]);
            putchar(screen[y][x]);
        }
        putchar('\n');//빠른 문자열 출력
    }
}



int testEnemy(void) {

    srand(time(NULL));
    initEnemies();

    while (1) {
        CLEAR_SCREEN();

        spawnEnemy(9, 9);
        moveEnemiesDown(9, 9);
        drawScreen();

        SLEEP(1);            // 1초 대기
    }


    //getchar();//입력대기를 시키므로서 콘솔창 안닫히게 임시 설정

    return 0;
}