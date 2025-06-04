#define MAP_H

#define MAP_WIDTH  40
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void initMap(void);       // 맵 초기화
void drawMap(void);       // 맵 출력
void setTile(int x, int y, char tile); // 특정 위치에 타일 세팅