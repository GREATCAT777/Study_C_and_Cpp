/*#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define DIR_LEFT 0
#define DIR_RIGHT 1
#define DIR_UP 2
#define DIR_DOWN 3

#define MAX_WORLD_X_POS 30
#define MAX_WORLD_Y_POS 20

#define DFAULT_SNAKE_POS_X 10
#define DFAULT_SNAKE_POS_Y 10
#define DFAULT_SNAKE_LENGTH 3

#define DRAW_EMPTY 0
#define DRAW_WALL 1
#define DRAW_SANKE_BODY 2
#define DRAW_FOOD 3

struct Node {
	struct Node* next;
	COORD pos; //윈도우 헤더파일에있는 좌표 구조파일
}typedef Node;

struct Snake {
	Node* head;
	Node* tail;
	char dir; //방향
	int length;
}typedef Snake;

struct Food {
	COORD pos;
}typedef Food;

Snake player;
Food food;
char Map[MAX_WORLD_X_POS][MAX_WORLD_Y_POS];

void AppendSnake() {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	if (player.length == 0) {
		player.head = newNode;
		player.tail = player.head;
	}
	else {
		player.tail->next= newNode;
		player.tail = newNode;
	}
	player.length++;
}

void MoveSnake(){
	
	Node* curNode = player.head;
	Node* prevNode = curNode;
	int i;
	COORD addPos;
	addPos.X = 0;
	addPos.Y = 0;

	//while (curNode->next != NULL &&curNode->next != player.tail) {
	//prevNode = prevNode->next;

	for (i = 0; i < player.length-1; i++) {
		prevNode = curNode;
		curNode = curNode->next;
	}

	player.tail = prevNode;

	switch (player.dir) {
	case DIR_DOWN: addPos.Y = 1; break;
	case DIR_UP : addPos.Y = -1; break;
	case DIR_RIGHT: addPos.X = 1; break;
	case DIR_LEFT: addPos.X = -1; break;
	}
	curNode->pos.X = (player.head)->pos.X + addPos.X;
	curNode->pos.Y = (player.head)->pos.Y + addPos.Y;

	curNode->next = player.head;
	player.head = curNode;
	player.tail->next = NULL;
}

void InitSnake() {

	int i;
	COORD hPos;

	player.head = NULL;
	player.tail = NULL;
	player.dir = DIR_RIGHT;
	player.length = 0;

	hPos.X = DFAULT_SNAKE_POS_X;
	hPos.Y = DFAULT_SNAKE_POS_Y;
	for (i = 0; i < DFAULT_SNAKE_LENGTH; i++) {
		AppendSnake();
	}

	Node* curNode = player.head;
	while (curNode) {
		curNode->pos = hPos;
		hPos.X--;
		curNode = curNode->next;
	}
} //뱀 만들기

void ClearWorld() {
	int i, j;

	for (i = 0; i < 30; i++) {
		for (j = 0; j < 20; j++) {
			Map[i][j] = DRAW_EMPTY;
		}
	}
}

void RenderSnake() {
	Node* curNode = player.head;
	while (curNode) {
		Map[curNode->pos.X][curNode->pos.Y] = DRAW_SANKE_BODY;
		curNode = curNode->next;
	}
} //뱀 출력

void RenderFood() {
	Map[food.pos.X][food.pos.Y] = DRAW_FOOD;
}

void Drawmap() {
	int i, j;
	for (j = 0; j < 20; j++) {
		for (i = 0; i < 30; i++) {

			switch (Map[i][j]) {
			case DRAW_EMPTY: printf("  "); break;
			case DRAW_WALL: printf("■"); break;
			case DRAW_SANKE_BODY: printf("★"); break;
			case DRAW_FOOD: printf("＠"); break;
			}
			//printf("%d", Map[i][j]);
		}
		puts("");
	}
} //맵출력

void Initmap() {
	int i, j;

	for (i = 0; i < 30; i++) {
		for (j = 0; j < 20; j++) {
			if (i == 0 || i == 29 || j == 0 || j == 19) {
				Map[i][j] = DRAW_WALL;
			}
			else {
				Map[i][j] = DRAW_EMPTY;
			}
		}
	}
} //맵 생성

void GenFood() {
	int r;
	int i, j;
	int isAdd = 0;
	int idx = 0;

	Node* curNode = player.head;
	COORD arrPos[MAX_WORLD_X_POS * MAX_WORLD_Y_POS]; //스택자리에 할당되었다 빠지는값 ,명시적으로 선언을 해줌
	for (i = 1; i < 29; i++) {
		for (j = 1; j < 19; j++) {
			isAdd = 1;
			curNode = player.head;
			while (curNode) {
				if (curNode->pos.X == i && curNode->pos.Y == j) {
					isAdd = 0;
					break;
				}
				curNode = curNode->next;
			}
			if (isAdd) { //뱀의 몸좌표와 일치하는 것이 없을때
				arrPos[idx].X = i;
				arrPos[idx].Y = j;
				idx++;
			}
		}

		r = rand();
		r = r % ((MAX_WORLD_X_POS - 2) * (MAX_WORLD_Y_POS - 2) - player.length); //idx값 넣어줘도 상관없다.

		food.pos.X = arrPos[r].X;
		food.pos.Y = arrPos[r].Y;
	}
}

void SetCurPos(int x, int y) {
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Checkinput() {
	char input;
	if (_kbhit()) {
		input = _getch();
		switch (input) {
	case 'a':
	case 'A': player.dir = DIR_LEFT; break;
	case 's':
	case 'S': player.dir = DIR_DOWN; break;
	case 'd':
	case 'D': player.dir = DIR_RIGHT; break;
	case 'w':
	case 'W': player.dir = DIR_UP; break;
		}
	}
}

void CheckCollision() {
	Node* curNode = player.head;
	short x, y;
	while (curNode != NULL) {
		x = curNode->pos.X;
		y = curNode->pos.Y;

		if (x == 0 || x == MAX_WORLD_X_POS -1 || y==0 || y ==MAX_WORLD_Y_POS-1){
			exit(0); //콘솔창 종료함수
		}
		else if (curNode != player.head && x == player.head->pos.X && y == player.head->pos.Y) {
			exit(0);
		}
		else if (x == food.pos.X && y == food.pos.Y){
			AppendSnake();

			GenFood();
			break;
		}
		curNode = curNode->next;
	}
}

int main() {
	srand(time(NULL)); //GENFOOD 함수에서 빼온것 , 다시 집어넣어도 됨
	Initmap(); //초기 맵형성
	InitSnake(); //초기 지렁이 형성
	GenFood(); //초기 먹이 생성

	while (1)
	{
		SetCurPos(0, 0);
		ClearWorld(); //맵 초기화
		Initmap();  //맵 출력

		Checkinput(); //입력 확인
		MoveSnake(); //지렁이 동작

		RenderSnake(); //지렁이 출력
		RenderFood(); //지렁이 먹이 출력

		CheckCollision(); //충돌 판정

		//RenderBufferToWorld();
		Drawmap(); //현재 맵 상황 표현
		Sleep(100); //시스템 일시정지
	}
	return 0;
}*/