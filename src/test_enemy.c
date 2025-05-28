#include <stdio.h>
#include "enemy.h"
#include "map.h"

#define MAX_ENEMIES 10
#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 20

#ifdef _WIN32//������
#include <windows.h>
#define CLEAR_SCREEN() clearScreenWindows()
#define SLEEP(seconds) Sleep((seconds) * 1000)
#else//��


#endif

#ifdef _WIN32
//ȭ�� �ʱ�ȭ �Լ�
void clearScreenWindows() {
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#else

#endif

void drawScreen() {
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

    // ȭ�� �ʱ�ȭ
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

    // �� ��ġ
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            int x = enemies[i].x;
            int y = enemies[i].y;
            if (y >= 0 && y < SCREEN_HEIGHT && x >= 0 && x < SCREEN_WIDTH) {
                screen[y][x] = 'E';
            }
        }
    }

    screen[9][9] = 'P';//player��ġ �ӽ� ����

    // ȭ�� ���
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            putchar(screen[y][x]);
            putchar(screen[y][x]);
        }
        putchar('\n');//���� ���ڿ� ���
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

        SLEEP(1);            // 1�� ���
    }


    //getchar();//�Է´�⸦ ��Ű�Ƿμ� �ܼ�â �ȴ����� �ӽ� ����

    return 0;
}