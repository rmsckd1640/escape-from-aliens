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
                enemy_x = rand() % SCREEN_WIDTH;
                enemy_y = rand() % SCREEN_HEIGHT;

                // �÷��̾���� �Ÿ� ���
                int dx = enemy_x - x;
                int dy = enemy_y - y;
                distance = sqrt((double)dx * dx + (double)dy * dy);

            } while (distance < 3);  // �Ÿ� 3 �̸��̸� �ٽ� ����

            enemies[i].x = enemy_x;
            enemies[i].y = enemy_y;
            enemies[i].active = 1;
            break; // �ϳ��� ����
        }
    }
}

//�� �̵� �˰��� ���� ����
void moveEnemiesDown(int x, int y) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
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

            // ȭ�� ������ ������ ��Ȱ��ȭ
            if (enemies[i].x == x && enemies[i].y == y) {
                enemies[i].active = 0;
            }
        }
    }
}
