#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "map.h"
#include "enemy.h"

// ������ �迭: ���ÿ� ȭ�鿡 ������ �� �ִ� �ִ� ������ ��
Item items[MAX_ITEMS];

// ������ ���� ���� (�� ���ڿ� �ǹ� �ο�)
// '+' : ���� ȹ��
// 'H' : ü�� ȸ�� (����� ������ ��ü ����)
// 'S' : �ӵ� ���� (���� ���� ����)
// 'B' : ��ź (��ó �� ����)
const char ITEM_TYPES[] = { '+', 'H', 'S', 'B' };
const int ITEM_TYPES_COUNT = 4; // ���� ����

/**
 * ������ �迭 �ʱ�ȭ �Լ�
 * ��� �������� ��Ȱ��ȭ ���·� �ʱ�ȭ
 * ���� ���� �� �ݵ�� ȣ�� �ʿ�
 */
void initItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].active = 0;
    }
}

/**
 * �� �� ���� ��ġ�� ������ 1���� ������
 * ������ �������� ����(symbol)�� ���ӽð�(lifetime)�� ����
 */
void spawnItem() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!items[i].active) {
            items[i].x = rand() % (MAP_WIDTH - 2) + 1;
            items[i].y = rand() % (MAP_HEIGHT - 2) + 1;
            items[i].symbol = ITEM_TYPES[rand() % ITEM_TYPES_COUNT];
            items[i].active = 1;
            items[i].lifetime = 20; // 20�� �� �����
            break;
        }
    }
}

/**
 * ���� Ȱ��ȭ�� �����۵��� �ʿ� ǥ����
 * drawMap() ȣ�� ���� �� �Լ� ȣ�� �ʿ�
 */
void drawItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active) {
            setTile(items[i].x, items[i].y, items[i].symbol);
        }
    }
}

/**
 * �÷��̾ �������� �Ծ����� Ȯ���ϰ�, ȿ�� ����
 * - ���� ȹ��, ü�� ȸ��, �ӵ� ����, ��ź ���� ��� ����
 * - �������� ������ ��Ȱ��ȭ��
 *
 * @param playerX �÷��̾� X ��ǥ
 * @param playerY �÷��̾� Y ��ǥ
 * @return ���� ���ʽ� (���� ���� ������)
 */
int checkItemCollision(int playerX, int playerY) {
    int bonus = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active &&
            items[i].x == playerX &&
            items[i].y == playerY) {

            // �浹�� ������ ������ ���� ȿ�� ó��
            switch (items[i].symbol) {
            case '+': // ���� ������
                bonus = 10;
                break;
            case 'H': // ü�� ȸ�� �� ������ ��ü ����
                bonus = 5;
                break;
            case 'S': // �ӵ� ���� (���� ��� ����)
                bonus = 0;
                break;
            case 'B': // ��ź ������: �ֺ� �ݰ� 2 ������ �� ����
                for (int j = 0; j < MAX_ENEMIES; j++) {
                    if (enemies[j].active) {
                        int dx = enemies[j].x - playerX;
                        int dy = enemies[j].y - playerY;
                        if (dx * dx + dy * dy <= 4) { // ��(dx��+dy��) �� 2
                            enemies[j].active = 0;
                            bonus += 3; // �� �ϳ��� 3��
                        }
                    }
                }
                break;
            }

            // ������ ȿ�� ���� �� ��Ȱ��ȭ
            items[i].active = 0;
            break;
        }
    }

    return bonus;
}

/**
 * �� �ϸ��� �������� ������ ���ҽ�Ű��,
 * ������ 0�� �Ǹ� �ڵ����� ������� ó����
 * �� �Լ��� ���� ���� ������ �� ������/�ϸ��� ȣ�� �ʿ�
 */
void updateItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].active) {
            items[i].lifetime--;
            if (items[i].lifetime <= 0) {
                items[i].active = 0;
            }
        }
    }
}
