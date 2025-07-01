//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>
//#include<windows.h>
//#include<time.h>
//
//#define LEFT 75
//#define RIGHT 77
//#define UP 72
//#define DOWN 80
//#define SPACE 32
//#define MAP_WIDTH 12
//#define MAP_HEIGHT 22
//
//int block[7][4][4][4] = {
//	0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,	0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,	0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,	0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,
//	//ㄴ 반대
//	0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,	0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,	0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,	0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,
//	//ㄴ 좌우대칭
//	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
//	//ㅁ
//	0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,	0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,	0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,	0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,
//	// ㅡ
//	0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,	0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,	0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,	0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,
//	//ㅗ
//	0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,	0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,	0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,	0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,
//	//ㄱㄴ
//	0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,	0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,	0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,	0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0
//	//ㄱㄴ 좌우대칭
//}; //오른쪽으로 돌아감 int block[도행개수][각도형의 방향개수][세로][가로]
//
//char Map[MAP_WIDTH][MAP_HEIGHT];
//
//typedef struct game {
//	int level;
//	int over;
//	int rotation;
//	int abx, aby;
//	int curx, cury;
//	int curblock;
//	int nextblock;
//}Game;
//
//Game G;
//
//Game tempt;
//
//void setcur(int x, int y) {
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//} //커서 좌표 옮기는 함수
//
//void removecursor() {
//	CONSOLE_CURSOR_INFO curinfo;
//	curinfo.bVisible = 0;
//	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
//} //커서 지우기
//
//void removecurrentBlock(Game G) {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++){
//			if (block[G.curblock][G.rotation][i][j] == 1) {
//				setcur((i + G.curx) * 2 + G.abx, j + G.cury + G.aby);
//				printf("  ");
//			}
//		}
//	}
//} //이전에 그렸던 블록을 제거해줌
//
//void InitMap() {
//	for (int y = 0; y < MAP_HEIGHT; y++) {
//		for (int x = 0; x < MAP_WIDTH; x++) {
//			if ((x == 0) || (x == MAP_WIDTH - 1)) {
//				Map[x][y] = 1;
//			}
//			else if (y == MAP_HEIGHT - 1) {
//				Map[x][y] = 1;
//			}
//			else {
//				Map[x][y] = 0;
//			}
//		}
//	}
//}
//
//int CollisionCheck(Game G) {
//	int dat = 0;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (((G.curx + j) == 0) || ((G.curx + j) == MAP_WIDTH - 1)) {
//				dat = 1;
//			}
//			else {
//				dat = Map[G.cury + i][G.curx + j];
//			}
//			if ((block[G.curblock][G.rotation][i][j] == 1) && (dat == 1)) {
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//
//void nextBlockTable(Game G) {
//	Game temp = G;
//	temp.rotation = 0;
//	temp.curx = 14;
//	temp.cury = 1;
//	temp.curblock = temp.nextblock;
//	for (int i = 0; i < 6; i++) {
//		setcur(31, i + 1);
//		for (int j = 0; j < 6; j++) {
//			if (i == 0 || i == 5 || j == 0 || j == 5) {
//				printf("■");
//			}
//			else { printf("  "); }
//		}
//		showCurrentBlock(temp);
//
//	}
//}
//
//void newBlock(Game* G) {
//	int rot = rand() % 7;
//	if (G->curblock == -1) {
//		G->curblock = rot;
//		rot = rand() % 7;
//		G->nextblock = rot;
//	}
//	else {
//		G->nextblock = rot;
//		nextBlockTable(*G);
//	}
//}
//
//int moveBlock(Game* G) {
//	removecurrentBlock(*G);
//	G->cury++;
//	if (CollisionCheck(*G) == 1) {
//		if (G->cury <= 0) {
//			return 1;
//		}
//		G->cury--;
//		mergeBlock(*G);
//		G->curblock = G->nextblock;
//		newBlock(G);
//		G->curx = 5;
//		G->cury = -3;
//		G->rotation = 0;
//		nextBlockTable(*G);
//		return 2;
//	}
//	return 0;
//}
//
//void blockControl() {
//	char key;
//	if (_kbhit()) {
//
//		key = _getch();
//
//		switch (key) {
//		case UP:
//			tempt = G;
//			tempt.rotation = (tempt.rotation + 1) % 4;
//			if (CollosionCheck(tempt) == 0) {
//				removecurrentBlock(G);
//				G.rotation = tempt.rotation;
//				showCurrentBlock(G);
//			}
//			break;
//
//		case DOWN:
//			G.over = moveBlock(&G);
//			showCurrentBlock(G);
//			break;
//
//		case LEFT: 
//			if (G.curx > 0) {
//				removecurrentBlock(G);
//				G.curx--;
//				if (CollisionCheck(G) == 1) {
//					G.curx++;
//					showCurrentBlock(G);
//				}
//			}
//			break;
//		case RIGHT: 
//			if (G.curx < MAP_WIDTH) {
//				removecurrentBlock(G);
//				G.curx++;
//				if (CollisionCheck(G) == 1) {
//					G.curx--;
//					showCurrentBlock(G);
//				}
//			}
//			break;
//		}
//
//		if (key == SPACE) {
//			while (G.over == 0) {
//				G.over = moveBlock(&G);
//				showCurrentBlock(G);
//			}
//		}
//	}
//}
//
//void lineCheck(Game G) {
//	int i, j, k;
//	for (i = 0; i < MAP_HEIGHT - 1; i++) {
//		for (j = 1; j < MAP_WIDTH - 1; j++) {
//			if (Map[j][i] == 0) {
//				break;
//			}
//		}
//		if (j == MAP_WIDTH - 1) {
//			showTable(G);
//			setcur(1 * 2 + G.abx, i + G.aby);
//			for (j = 1; j < MAP_WIDTH - 1; j++) {
//				printf("ㅁ");
//				Sleep(10);
//			}
//
//			setcur(1 * 2 + G.abx, i + G.aby);
//			for (j = 1; j < MAP_WIDTH - 1; j++) {
//				printf("  ");
//				Sleep(10);
//			}
//
//			for (k = 1; k > 0; k--) {
//				for (j = 1; j < MAP_WIDTH - 1; j++) {
//					Map[j][k] = Map[j][k - 1];
//				}
//			}
//			for (j = 1; j < MAP_WIDTH - 1; j++) {
//				Map[j][0] = 0;
//			}
//		}
//	}
//}
//
//void mergeBlock(Game G) {
//	for (int i = 0; i < 4; i++){
//		for (int j = 0; j < 4; j++){
//			Map[G.curx + j][G.cury + i] |= block[G.curblock][G.rotation][j][i];
//		}
//	}
//	lineCheck(G);
//	showtable(G);
//}
//int main() {
//	InitMap();
//	
//}