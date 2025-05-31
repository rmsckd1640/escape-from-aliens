#ifndef ITEM_H
#define ITEM_H

#define MAX_ITEMS 10

typedef struct {
    int x, y;
    int active;
    int lifetime;
    char symbol; // '+', 'H', 'S', 'B'
} Item;

extern Item items[MAX_ITEMS];

void initItems();
void spawnItem();
void drawItems();
int checkItemCollision(int playerX, int playerY);
void updateItems(); // ���� ���� ó��

#endif
