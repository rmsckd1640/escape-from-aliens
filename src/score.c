#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "score.h"

int score = 0;
int score_item = 0;
int score_kill = 0;

void initScore() {
    score = 0;
    score_item = 0;
    score_kill = 0;
}

void addScore(int s) {
    score += s;
}

void addItemScore(int s) {
    score_item += s;
    score += s;
}

void addKillScore(int s) {
    score_kill += s;
    score += s;
}

void printScore() {
    printf("Score: %d\n", score);
}

void saveScoreToFile() {
    FILE* file = fopen("score_log.txt", "a");
    if (file == NULL) {
        perror("파일 열기 실패");
        return;
    }

    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] Score: %d\n",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
        t->tm_hour, t->tm_min, t->tm_sec,
        score);

    fclose(file);
}

int getHighScore() {
    FILE* file = fopen("high_score.txt", "r");
    if (file == NULL) return 0;

    int high;
    fscanf(file, "%d", &high);
    fclose(file);
    return high;
}

void updateHighScore() {
    int high = getHighScore();
    if (score > high) {
        FILE* file = fopen("high_score.txt", "w");
        if (file == NULL) {
            perror("최고 점수 저장 실패");
            return;
        }
        fprintf(file, "%d\n", score);
        fclose(file);
        printf("[기록 갱신] 최고 점수 갱신! (%d → %d)\n", high, score);
    }
    else {
        printf("[기록] 현재 최고 점수: %d\n", high);
    }
}

void printGameReport() {
    printf("\n----- [게임 결과 리포트] -----\n");
    printf("획득 점수   : %d\n", score);
    printf("아이템 점수 : %d\n", score_item);
    printf("처치 점수   : %d\n", score_kill);
    printf("--------------------------------\n");
}
