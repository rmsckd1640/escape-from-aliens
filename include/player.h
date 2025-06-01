#ifndef PLAYER_H
#define PLAYER_H

typedef struct { // �÷��̾� HP ����
    int hp;
    int max_hp;
} PlayerHP;

void initHP(PlayerHP* p); // �÷��̾� HP �ʱ�ȭ
void takeDamage(PlayerHP* p, int dmg); // �÷��̾ �������� �Ծ��� �� HP ����
void heal(PlayerHP* p, int amount); // �÷��̾ ȸ���� �� HP ����

#endif