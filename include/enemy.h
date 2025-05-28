#define MAX_ENEMIES 100
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20

typedef struct {
    int x;
    int y;
    int active; // 1: ȭ�鿡 ������, 0: ���ŵ�
} Enemy;

//�� ���� �迭
Enemy enemies[MAX_ENEMIES];

//�� �ʱ�ȭ , �ӽ÷� �ִ� 10���� -> �������� ���������ϰ� ���� ����
void initEnemies();

// ���� �����ϰ� �� �迭�� ����Ѵ�.
// @param x: �÷��̾��� x ��ġ
// @param y: �÷��̾��� y ��ġ
void spawnEnemy(int x, int y);

// �� ������ ����
// @param x: �÷��̾��� x ��ġ
// @param y: �÷��̾��� y ��ġ
void moveEnemiesDown(int x, int y);
