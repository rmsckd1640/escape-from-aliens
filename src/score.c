#include <stdio.h>
#include <time.h>
#include "score.h"

// ���� ������ �����ϴ� ���� ����
int score = 0;

/**
 * ������ 0���� �ʱ�ȭ�մϴ�.
 * ���� ���� �� �Ǵ� ���� ������ �� ȣ���մϴ�.
 */
void initScore() {
    score = 0;
}

/**
 * ������ �߰��մϴ�.
 * @param s: �߰��� ���� (��: ������ ȹ�� �� 10��)
 */
void addScore(int s) {
    score += s;
}

/**
 * ���� ������ �ֿܼ� ����մϴ�.
 * UI ����� �Ǵ� �׽�Ʈ������ ����� �� �ֽ��ϴ�.
 */
void printScore() {
    printf("Score: %d\n", score);
}

/**
 * ���� ������ score_log.txt ���Ͽ� ����մϴ�.
 * ������ append ���� ���� ���� ��� �ڿ� ���ٿ����ϴ�.
 * ����� ��¥/�ð��� �Բ� ����˴ϴ�.
 * ���� ���:
 *   [2025-05-31 15:45:23] Score: 90
 */
void saveScoreToFile() {
    // ������ append ���("a")�� ���ϴ�. ������ ���� ������.
    FILE* file = fopen("score_log.txt", "a");

    if (file == NULL) {
        perror("���� ���� ����");
        return;
    }

    // ���� �ý��� �ð��� �޾ƿɴϴ�.
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    // �ð��� ������ ���˿� ���� ���Ͽ� ����մϴ�.
    fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] Score: %d\n",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
        t->tm_hour, t->tm_min, t->tm_sec,
        score);

    fclose(file); // ���� �ݱ�
}
