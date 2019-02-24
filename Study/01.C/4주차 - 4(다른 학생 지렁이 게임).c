/*#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define G_ST_TITLE 0
#define G_ST_GAME 1
#define G_ST_RESULT 2
#define MAP_SIZE_X 30
#define MAP_SIZE_Y 20
#define FLAG_TURE 1
#define FLAG_FALSE 0
#define DIR_UP  0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3
#define START_SNAKE_SIZE 3
#define SNAKE_START_POSX 15
#define SNAKE_START_POSY 10
typedef int DIR;
typedef int BOOL;


//타이틀

void Title();
void StartGame(); // 씬 전환
void DrawTitle(); // 설명, 
void PrintTitle();
void ChangeRenderFlag();

//게임

void Game();
void DrawGame();
void GenSnake();
void DrawSnake();
void MoveSnake();
BOOL CheckCollision();
BOOL CheckFood();
void GenFood();
void DrawFood();


//etc

void DrawRect();
void SetCurPos(int x, int y);
typedef struct Node
{
	COORD pos;
	struct Node* next;
	struct Node* prev;
} Node;
typedef struct Snake
{
	DIR dir;
	Node* headNode;
	Node* tailNode;
} Snake;
typedef struct Food
{
	COORD pos;
} Food;

int gameState;
int renderFlag;
int isFirstFrame;

Snake snake;
Food fd;
int main()
{
	renderFlag = FLAG_TURE;
	gameState = G_ST_TITLE;
	isFirstFrame = FLAG_TURE;

	while (1)
	{
		switch (gameState)
		{
		case G_ST_TITLE:  Title(); break;
		case G_ST_GAME:   Game();  break;
		}

		Sleep(200);
	}

	return 0;
}
void Title()
{

	if (kbhit())
	{
		gameState = G_ST_GAME;
		system("cls");
		return;
	}
	DrawTitle();
	PrintTitle();
	SetCurPos(0, 0);
	//if ()StartGame();
}
void StartGame()
{
}
void DrawTitle()
{
	DrawRect();
}
void DrawRect()
{
	int i, j;
	for (i = 0; i < MAP_SIZE_X; i++)
	{
		printf("■");
	}
	for (j = 0; j < MAP_SIZE_Y - 2; j++)
	{
		printf("\n");
		for (i = 0; i < MAP_SIZE_X; i++)
		{
			if (i == 0 || i == MAP_SIZE_X - 1)
			{
				SetCurPos(i, j);
				printf("■");
			}
		}
	}
	printf("\n");
	for (i = 0; i < MAP_SIZE_X; i++)
	{
		printf("■");
	}
	//printf("■                                                                            ■");
}
void PrintTitle()
{
	SetCurPos(10, 3);
	printf("지렁이 게임");
	SetCurPos(3, 10);
	if (renderFlag)
	{
		printf("게임을 시작하기 위해 아무키나 눌러 주세요...");
	}
	ChangeRenderFlag();
}
void SetCurPos(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void ChangeRenderFlag()
{
	if (renderFlag == FLAG_FALSE) renderFlag = FLAG_TURE;
	else       renderFlag = FLAG_FALSE;
}
void Game()
{
	Node* node;
	Node* tmpNode;
	int key;
	if (kbhit())
	{
		key = getch();
		switch (key)
		{
		case 75: snake.dir = DIR_LEFT; break;
		case 77: snake.dir = DIR_RIGHT; break;
		case 72: snake.dir = DIR_UP; break;
		case 80: snake.dir = DIR_DOWN; break;
		}
	}
	if (isFirstFrame)
	{
		GenSnake();
		GenFood();
		isFirstFrame = FLAG_FALSE;
	}
	DrawGame();

	if (CheckCollision())
	{
		gameState = G_ST_TITLE;
		isFirstFrame = FLAG_TURE;
		system("cls");
		node = snake.tailNode;
		while (node)
		{
			tmpNode = node->prev;
			free(node);
			node = tmpNode;
		}
		return;
	}
	if (CheckFood())
	{
		GenFood();
		node = (Node*)malloc(sizeof(Node));
		snake.tailNode->next = node;
		node->prev = snake.tailNode;
		snake.tailNode = node;
	}
	SetCurPos(0, 0);
}
void DrawGame()
{
	DrawRect();
	MoveSnake();
	DrawSnake();
	DrawFood();
}
void GenSnake()
{
	int i;
	Node* preNode = NULL;
	Node* curNode = NULL;
	snake.headNode = NULL;
	snake.tailNode = NULL;
	snake.dir = DIR_RIGHT;
	for (i = 0; i < START_SNAKE_SIZE; i++)
	{
		preNode = curNode;
		Node* pNode;
		pNode = (Node*)malloc(sizeof(Snake));
		pNode->prev = NULL;
		pNode->next = NULL;
		curNode = pNode;
		if (preNode)
		{
			preNode->next = curNode;
		}
		if (curNode != NULL)
		{
			curNode->prev = preNode;
		}
		if (i == 0)
		{
			snake.headNode = pNode;
		}
		else if (i == START_SNAKE_SIZE - 1)
		{
			snake.tailNode = pNode;
		}
		pNode->pos.X = SNAKE_START_POSX - i;
		pNode->pos.Y = SNAKE_START_POSY;
	}
}
void DrawSnake()
{
	Node* curNode = snake.headNode;
	while (curNode)
	{
		SetCurPos(curNode->pos.X, curNode->pos.Y);
		printf("●");
		curNode = curNode->next;
	}

}
void MoveSnake()
{
	Node* tmp;
	SetCurPos(snake.tailNode->pos.X, snake.tailNode->pos.Y);
	printf(" ");
	COORD movePos;
	switch (snake.dir)
	{
	case DIR_DOWN: movePos.X = 0; movePos.Y = 1;  break;
	case DIR_UP: movePos.X = 0; movePos.Y = -1;  break;
	case DIR_RIGHT: movePos.X = 1; movePos.Y = 0;  break;
	case DIR_LEFT: movePos.X = -1; movePos.Y = 0;  break;
	}
	snake.tailNode->pos.X = snake.headNode->pos.X + movePos.X;
	snake.tailNode->pos.Y = snake.headNode->pos.Y + movePos.Y;
	snake.headNode->prev = snake.tailNode;
	snake.tailNode->next = snake.headNode;
	snake.tailNode->prev->next = NULL;
	snake.tailNode->prev = NULL;
	snake.headNode = snake.tailNode;
	tmp = snake.headNode;
	while (tmp)
	{
		if (!tmp->next)  snake.tailNode = tmp;
		tmp = tmp->next;
	}
}
BOOL CheckCollision()
{
	Node* curNode = snake.headNode;
	BOOL b1, b2, b3;
	while (curNode)
	{
		COORD pos = curNode->pos;
		if (pos.X == 0 || pos.X == 29 || pos.Y == 19 || pos.Y == 0)
		{
			return FLAG_TURE;
		}
		b1 = curNode != snake.headNode;
		b2 = pos.X == snake.headNode->pos.X;
		b3 = pos.Y == snake.headNode->pos.Y;
		if (b1 && (b2 && b3))
		{
			return FLAG_TURE;
		}
		curNode = curNode->next;
	}
	return FLAG_FALSE;
}
void GenFood()
{
	int randX, randY;
	Node* curNode;
	BOOL bEnalbe = FLAG_FALSE;
	do
	{
		bEnalbe = FLAG_FALSE;
		curNode = snake.headNode;
		srand((unsigned)time(NULL));
		randX = rand() % 28 + 1;
		randY = rand() % 17 + 1;
		while (curNode)
		{
			if (randX == curNode->pos.X && randY == curNode->pos.Y)
			{
				bEnalbe = FLAG_TURE;
			}
			curNode = curNode->next;
		}
		if (bEnalbe == FLAG_FALSE)
		{
			fd.pos.X = randX;
			fd.pos.Y = randX;
		}
	} while (bEnalbe == FLAG_TURE);
}
void DrawFood()
{
	SetCurPos(fd.pos.X, fd.pos.Y);
	printf("★");
}
BOOL CheckFood()
{
	Node* curNode = snake.headNode;
	while (curNode)
	{
		if (curNode->pos.X == fd.pos.X && curNode->pos.Y == fd.pos.Y)
		{
			return FLAG_TURE;
		}
		curNode = curNode->next;
	}
	return FLAG_FALSE;
}*/