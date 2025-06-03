#include <stdio.h>
#include <time.h>
#include "score.h"

// 현재 점수를 저장하는 전역 변수
int score = 0;

/**
 * 점수를 0으로 초기화합니다.
 * 게임 시작 시 또는 새로 시작할 때 호출합니다.
 */
void initScore() {
    score = 0;
}

/**
 * 점수를 추가합니다.
 * @param s: 추가할 점수 (예: 아이템 획득 시 10점)
 */
void addScore(int s) {
    score += s;
}

/**
 * 현재 점수를 콘솔에 출력합니다.
 * UI 디버깅 또는 테스트용으로 사용할 수 있습니다.
 */
void printScore() {
    printf("Score: %d\n", score);
}

/**
 * 현재 점수를 score_log.txt 파일에 기록합니다.
 * 파일은 append 모드로 열려 기존 기록 뒤에 덧붙여집니다.
 * 기록은 날짜/시간과 함께 저장됩니다.
 * 예시 출력:
 *   [2025-05-31 15:45:23] Score: 90
 */
void saveScoreToFile() {
    // 파일을 append 모드("a")로 엽니다. 없으면 새로 생성됨.
    FILE* file = fopen("score_log.txt", "a");

    if (file == NULL) {
        perror("파일 열기 실패");
        return;
    }

    // 현재 시스템 시간을 받아옵니다.
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    // 시간과 점수를 포맷에 맞춰 파일에 기록합니다.
    fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] Score: %d\n",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
        t->tm_hour, t->tm_min, t->tm_sec,
        score);

    fclose(file); // 파일 닫기
}
