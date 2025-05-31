#ifndef SCORE_H
#define SCORE_H

extern int score;

void initScore();               // 점수 초기화
void addScore(int s);           // 점수 추가
void printScore();              // 현재 점수 출력
void saveScoreToFile();         // 점수 기록을 파일에 저장

#endif
