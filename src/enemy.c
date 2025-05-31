#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "enemy.h"

void initEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].active = 0;
    }
}

//
void spawnEnemy(int x, int y) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) {
            int enemy_x, enemy_y;
            double distance;

            do {
                // ȭ�� ���� ������ �� ��ġ ���� ���� 
                // �� �׵θ����� ���� �������� �ʵ��� ����
                enemy_x = (rand() % (SCREEN_WIDTH-2)) + 1;
                enemy_y = (rand() % (SCREEN_HEIGHT-2)) + 1;

                // �÷��̾���� �Ÿ� ���
                int dx = enemy_x - x;
                int dy = enemy_y - y;
                distance = sqrt((double)dx * dx + (double)dy * dy);

            } while (distance < 3);  // �Ÿ� 3 �̸��̸� �ٽ� ����

            enemies[i].x = enemy_x;
            enemies[i].y = enemy_y;
            enemies[i].active = 1;
            enemies[i].type = rand() % 2;

            break; // �ϳ��� ����
        }
    }
}

//�� �̵� �˰��� ���� ����
void moveEnemiesDown(int x, int y) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {

            if (enemies[i].type == 0) {//���� �÷��̾� �������� �̵��ϴ� Ÿ��
                // x ���� �̵�
                if (enemies[i].x < x) {
                    enemies[i].x++;
                }
                else if (enemies[i].x > x) {
                    enemies[i].x--;
                }

                // y ���� �̵�
                if (enemies[i].y < y) {
                    enemies[i].y++;
                }
                else if (enemies[i].y > y) {
                    enemies[i].y--;
                }
            }

            else if (enemies[i].type == 1) {//���� �������� �̵��ϴ� Ÿ��
                if (rand() % 2) {
                    enemies[i].x += (enemies[i].x < x) ? 1 : -1;
                }
                else {
                    enemies[i].y += (enemies[i].y < y) ? 1 : -1;
                }
            }

            // ���� �÷��̾�� ����� �� �����
            if (enemies[i].x == x && enemies[i].y == y) {
                enemies[i].active = 0;
            }
        }
    }
}
