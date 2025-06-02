#include <stdio.h>
#include "player.h"

void initHP(PlayerHP* p) { // �÷��̾� HP = 3 �ʱ�ȭ
    p->max_hp = 3;
    p->hp = p->max_hp;
}

void takeDamage(PlayerHP* p, int dmg) { 
    p->hp -= dmg; // HP���� ��������ŭ ����
    if (p->hp < 0) p->hp = 0; // HP�� 0���� �۾����� 0���� ����
}

void heal(PlayerHP* p, int amount) {
    p->hp += amount; // HP�� ȸ������ŭ �߰�
    if (p->hp > p->max_hp) p->hp = p->max_hp; // HP�� �ִ� HP���� Ŀ���� �ִ� HP�� ����
}

void initPosition(Position* pos) { // �÷��̾� ��ǥ �ʱ�ȭ
    pos->x = 0;
    pos->y = 0;
}

void move(Position* pos, char dir) { // wasd Ű�� �Է��� ��ǥ �̵�
    switch (dir) {
    case 'w': pos->y--; break; // ��
    case 's': pos->y++; break; // �Ʒ�
    case 'a': pos->x--; break; // ����
    case 'd': pos->x++; break; // ������
    }
}