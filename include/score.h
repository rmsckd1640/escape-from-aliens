#ifndef SCORE_H
#define SCORE_H

extern int score;
extern int score_item;
extern int score_kill;

/**
 * 점수 초기화
 * - 게임 시작 시 호출
 */
void initScore();

/**
 * 점수 직접 추가
 * - 일반적인 점수 증가
 */
void addScore(int s);

/**
 * 아이템 점수 추가
 * - 아이템 획득 시 호출
 */
void addItemScore(int s);

/**
 * 적 처치 점수 추가
 * - 적 처치 시 호출
 */
void addKillScore(int s);

/**
 * 현재 점수 출력
 */
void printScore();

/**
 * 점수를 score_log.txt에 저장 (날짜와 함께)
 */
void saveScoreToFile();

/**
 * 최고 점수를 파일에서 불러옴
 *
 * @return 최고 점수 (없으면 0)
 */
int getHighScore();

/**
 * 최고 점수를 갱신하고 high_score.txt에 저장
 */
void updateHighScore();

/**
 * 게임 결과 리포트 출력
 * - 점수 구성 요소를 함께 출력
 */
void printGameReport();

#endif
