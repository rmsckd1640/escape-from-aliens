#include <stdio.h>
#include <time.h>

#define MAX_SCORES 10
#define SCORE_FILE "score_rank.txt"

// 점수 저장 함수: 최고 기록 10개 유지
void saveScoreWithTime(int playTime) {
    FILE* file = fopen(SCORE_FILE, "r");
    int scores[MAX_SCORES + 1] = {0};  // 기존 10개 + 새 점수 1개
    int count = 0;

    if (file) {
        while (count < MAX_SCORES && fscanf(file, "%d", &scores[count]) == 1) {
            count++;
        }
        fclose(file);
    }

    scores[count++] = playTime;

    // 내림차순 정렬
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (scores[i] < scores[j]) {
                int temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    // 상위 10개만 파일에 저장
    file = fopen(SCORE_FILE, "w");
    if (file) {
        for (int i = 0; i < MAX_SCORES && i < count; i++) {
            fprintf(file, "%d\n", scores[i]);
        }
        fclose(file);
    }
}