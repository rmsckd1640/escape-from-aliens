#ifndef PLAYER_H
#define PLAYER_H

typedef struct { // �÷��̾� HP ����
    int hp;
    int max_hp;
} PlayerHP;

typedef struct { // �÷��̾� ��ǥ ����
    int x;
    int y;
} Position;

void initHP(PlayerHP* p); // �÷��̾� HP �ʱ�ȭ
void takeDamage(PlayerHP* p, int dmg); // �÷��̾ �������� �Ծ��� �� HP ����
void heal(PlayerHP* p, int amount); // �÷��̾ ȸ���� �� HP ����

void initPosition(Position* pos); // �÷��̾� ��ǥ �ʱ�ȭ
void move(Position* pos, char dir); // �÷��̾� ��ǥ �̵�

#endif