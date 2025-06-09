#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define CLEAR_SCREEN() clearScreenWindows()
#define SLEEP(ms) Sleep(ms)

void clearScreenWindows() {
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

#else
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#define CLEAR_SCREEN() clearScreenUnix()
#define SLEEP(ms) usleep((ms) * 1000)

void clearScreenUnix() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

void hideCursor() {
    printf("\033[?25l");
    fflush(stdout);
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}
#endif

#include "enemy.h"
#include "map.h"
#include "player.h"
#include "item.h"
#include "battle.h"
#include "score.h"

#ifdef _WIN32
#define FRAME_SPAWN_ITEM   20
#define FRAME_SPAWN_BULLET 5
#define FRAME_SPAWN_ENEMY  100
#define FRAME_MOVE_ENEMY   10
#define FRAME_RE 1
#else
#define FRAME_SPAWN_ITEM   10
#define FRAME_SPAWN_BULLET 3
#define FRAME_SPAWN_ENEMY  40
#define FRAME_MOVE_ENEMY   5
#define FRAME_RE 50
#endif

time_t startTime;
time_t endTime;
int playTime;
Player p;

int start(void) {
    startTime = time(NULL);
    srand((unsigned int)time(NULL));
    hideCursor();

    initEnemies();
    initItems();
    initHP(&p);
    initPosition(&p);

    char input = 0;
    int frame = 0;

    while (1) {
        CLEAR_SCREEN();

        if (frame % FRAME_SPAWN_ITEM == 0) spawnItem();
        if (frame % FRAME_SPAWN_BULLET == 0) spawnBulletFromEdge();
        if (frame % FRAME_SPAWN_ENEMY == 0) spawnEnemy(p);

        if (frame % FRAME_MOVE_ENEMY == 0) {
            moveBullets();
            moveEnemiesDown(p);
            updateItems();
            respawnItems();
            checkEnemyCollision(&p, enemies);
        }

#ifdef _WIN32
        if (_kbhit()) {
            input = _getch();
#else
        if (kbhit()) {
            input = getchar();
#endif
            if (input == 'q') break;
            move(&p, input);
        }

        drawMap();

        if (p.hp <= 0) break;

        frame++;
        endTime = time(NULL);
        playTime = (int)(endTime - startTime);
        printf("\n시간: %4d초", playTime);
        printHPBar(&p);

        SLEEP(FRAME_RE);
        }

    return 0;
    }

void end() {
    CLEAR_SCREEN();
    initMap();

    for (int y = 0; y < MAP_HEIGHT; y++) {
        if (y == 5) {
            printf("#              game over               #\n");
        }
        else if (y == 12) {
            printf("#             시간:  %4d초            #\n", playTime);
        }
        else {
            for (int x = 0; x < MAP_WIDTH; x++) putchar(map[y][x]);
            putchar('\n');
        }
    }

    saveScoreWithTime(playTime);
    SLEEP(3000);
}

void showScore() {
    CLEAR_SCREEN();

    FILE* file = fopen("score_rank.txt", "r");
    int scores[10] = {0};
    int count = 0;

    if (file) {
        while (count < 10 && fscanf(file, "%d", &scores[count]) == 1) count++;
        fclose(file);
    }

    for (int y = 0; y < MAP_HEIGHT; y++) {
        if (y == 0 || y == MAP_HEIGHT - 1) {
            for (int x = 0; x < MAP_WIDTH; x++) putchar('#');
            putchar('\n');
        }
        else if (y == 3) {
            printf("#          TOP 9 SCORE RANKING         #\n");
        }
        else if (y >= 5 && y <= 13) {
            int idx = y - 5;
            if (count == 0 && y == 7) {
                printf("#               기록 없음              #\n");
            } else if (idx < count) {
                printf("#             %2d등 : %3d초             #\n", idx + 1, scores[idx]);
            } else {
                printf("#                                      #\n");
            }
        }
        else if (y == 16) {
            printf("#             뒤로가기 : r             #\n");
        }
        else {
            printf("#                                      #\n");
        }
    }

    // r 누를 때까지 대기
    char input = 0;
    do {
#ifdef _WIN32
        if (_kbhit()) input = _getch();
#else
        if (kbhit()) input = getchar();
#endif
    } while (input != 'r');
}




int main(void) {
    hideCursor();
    char input = 0;

    while (1) {
        CLEAR_SCREEN();
        initMap();

        for (int y = 0; y < MAP_HEIGHT; y++) {
            if (y == 5) {
                printf("#              \uAC8C\uC784  \uC81C\uBAA9              #\n");
            }
            else if (y == 10) {
                printf("#            \uAC8C\uC784  \uC2DC\uC791 : s            #\n");
            }
            else if (y == 13) {
                printf("#            \uB7AD\uD0B9  \uD655\uC778 : r            #\n");
            }
            else {
                for (int x = 0; x < MAP_WIDTH; x++) putchar(map[y][x]);
                putchar('\n');
            }
        }

#ifdef _WIN32
        while (!_kbhit()) { SLEEP(10); }
        input = _getch();
#else
        while (!kbhit()) { SLEEP(10); }
        input = getchar();
#endif

        if (input == 's') {
            start();
            end();
        }
        else if (input == 'r') {
            showScore();
        }
        else if (input == 'q') {
            CLEAR_SCREEN();
            printf("\n게임을 종료합니다. 안녕히 가세요!\n");
            break;
        }
    }

    return 0;
}