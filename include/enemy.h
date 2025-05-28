#define MAX_ENEMIES 100
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20

typedef struct {
    int x;
    int y;
    int active; // 1: 화면에 존재함, 0: 제거됨
} Enemy;

//적 정보 배열
Enemy enemies[MAX_ENEMIES];

//적 초기화 , 임시로 최대 10마리 -> 동적으로 조절가능하게 개선 가능
void initEnemies();

// 적을 생성하고 적 배열에 등록한다.
// @param x: 플레이어의 x 위치
// @param y: 플레이어의 y 위치
void spawnEnemy(int x, int y);

// 적 움직임 설정
// @param x: 플레이어의 x 위치
// @param y: 플레이어의 y 위치
void moveEnemiesDown(int x, int y);
