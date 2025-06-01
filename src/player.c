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