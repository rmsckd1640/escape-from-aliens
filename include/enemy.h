#define MAX_ENEMIES 100
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20

typedef struct {
    int x;
    int y;
    int active; // 1: ȭ�鿡 ������, 0: ���ŵ�
    int type; //�� ���� - E : �������� �̵� , e : �÷��̾�� �ٰ���
} Enemy;

//�� ���� �迭
Enemy enemies[MAX_ENEMIES];

//�� �ʱ�ȭ
//MAX_ENEMIES�� �Էµ� ���ڸ�ŭ �� ���� ����
//���� ���� ���ְ� �������� ��� ����
void initEnemies();

// ���� �����ϰ� �� �迭�� ����Ѵ�.
// �Լ� ȣ�� �� �� 1�� ������.
// @param x: �÷��̾��� x ��ġ
// @param y: �÷��̾��� y ��ġ
void spawnEnemy(int x, int y);

// �� ������ ����
// �Լ� ȣ�� �� ���� ���� ��ġ�� �������� ����.
// @param x: �÷��̾��� x ��ġ
// @param y: �÷��̾��� y ��ġ
void moveEnemiesDown(int x, int y);
