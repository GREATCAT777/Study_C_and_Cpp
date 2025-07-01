//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <conio.h>
//
//#define Map_X_MaxSize 40
//#define Map_Y_MaxSize 20
//#define MonsterNum_Max 10
//#define MonsterGenTime 16
//#define EXP_Monster 50
//#define RIGHT 0
//#define LEFT 1
//#define UP 2
//#define DOWN 3
//#define Empty 0
//#define Wall 1
//#define Me 2
//#define Enemy 3
//#define Bonus 4
//
//using namespace std;
//char map[Map_Y_MaxSize][Map_X_MaxSize];
//char buffer[Map_Y_MaxSize][Map_X_MaxSize];
//int monsterPos = 0;
//int frame = 0;
//bool isCol = false;
//
//
//void RenderMap() {
//	for (int i = 0; i < Map_Y_MaxSize; i++){
//		for (int j = 0; j < Map_X_MaxSize; j++) {
//			map[i][j] = buffer[i][j];
//		}
//
//	}
//}
//
//void InitBuffer() {
//	for (int i = 0; i < Map_Y_MaxSize; i++) {
//		for (int j = 0; j < Map_X_MaxSize; j++) {
//			if (i == 0 || i == (Map_Y_MaxSize - 1) || j == 0 || j == (Map_X_MaxSize - 1)) {
//				buffer[i][j] = Wall;
//			}
//			else {
//				buffer[i][j] = Empty;
//			}
//		}
//
//	}
//}
//
//
//class Monster {
//public:
//	bool isAlive = false;
//	bool isFight = false;
//	COORD Pos;
//	int idx = 0;
//	int hp = 300;
//	int damage = 30;
//	int def = 10;
//	int dex = 10;
//	int critical = 10;
//
//	void ShowData() {
//		puts("");
//		printf("==Monster%d==\n", idx);
//		printf("HP=%d  Damage=%d  Def=%d  Dex=%d  Critical=%d", hp, damage, def, dex, critical);
//		puts("");
//		
//	}
//
//	void Origin() {
//		hp = 300;
//	}
//
//	void Destroy() {
//		isAlive = false;
//	}
//
//	int GetHP() {
//		return hp;
//	}
//};
//
//class Player {
//private:
//	int hp;
//	int damage;
//	int def;
//	int dex;
//	int critical;
//	int level = 1;
//	int EXP = 0;
//	int TotalEXP;
//
//	void LevelUp() {
//		level++;
//		hp = OHP;
//		hp += 20;
//		OHP = hp;
//		damage += 5;
//		def += 3;
//		dex += 1;
//		critical += 1;
//		printf("!! LevelUp !!");
//	}
//
//
//public:
//	string name = "Player";
//	COORD Pos;
//	char dir;
//	int OHP;
//	Player(int HP, int Damage, int Def, int Dex, int Critical) {
//		hp = HP;
//		OHP = hp;
//		damage = Damage;
//		def = Def;
//		dex = Dex;
//		critical = Critical;
//		TotalEXP = 100;
//	}
//
//	void PlusExp() {
//		EXP += EXP_Monster;
//		if (EXP >= TotalEXP) {
//			EXP = 0;
//			TotalEXP += 100;
//			LevelUp();
//
//		}
//	}
//
//
//	void Attack(Monster* m) {
//		cout << "Monster"<< m->idx<< " 를 공격했다." << endl;
//		int r = rand() % 100;
//		if (r < m->dex) {
//			cout << "Monster" << m->idx << " 가 공격을 피했다!!" << endl;
//			getchar();
//			return;
//		}
//		r -= m->dex;
//		if (r < critical) {
//			m->hp -= damage * 2;
//			cout << "Critica!! Damage = " << damage * 2 << endl;
//			getchar();
//			getchar();
//		}
//		else {
//			m->hp -= damage;
//			cout << "Damage = " << damage << endl;
//			getchar();
//			getchar();
//		}
//	}
//
//	void Deffence(Monster* m) {
//		cout << "Monster" << m->idx << " 가 공격했다." << endl;
//		int r = rand() % 100;
//		if (r < dex) {
//			cout << name << " 가 공격을 피했다!!" << endl;
//			getchar();
//			return;
//		}
//		r -= dex;
//		if (r < m->critical) {
//			hp -= m->damage * 2;
//			cout << "Critica!! Damage = " << m->damage * 2 << endl;
//			getchar();
//			getchar();
//		}
//		else {
//			hp -= m->damage;
//			cout << "Damage = " << m->damage << endl;
//			getchar();
//			getchar();
//		}
//	}
//
//	void ShowData() {
//		puts("");
//		cout <<"=="<< name <<"=="<< endl;
//		printf("HP=%d  Damage=%d  Def=%d  Dex=%d  Critical=%d", hp, damage, def, dex, critical);
//		puts("");
//
//	}
//
//	void ChangeName() {
//		cin >> name;
//	}
//
//	int GetHP() {
//		return hp;
//	}
//
//	void GetPotion() {
//		hp = OHP;
//	}
//};
//
//
//class Potion {
//public:
//	bool isPotion = false;
//	COORD pos;
//};
//
//void CheckCollision(Player* p, Monster* m[], Potion* po) {
//	for (int i = 0; i < MonsterNum_Max; i++) {
//		if (m[i]->isAlive && p->Pos.X == m[i]->Pos.X && p->Pos.Y == m[i]->Pos.Y) {
//			isCol = true;
//			m[i]->isFight = true;
//		}
//	}
//	if (po->isPotion && p->Pos.X == po->pos.X && p->Pos.Y == po->pos.Y) {
//		p->GetPotion();
//		po->isPotion = false;
//	}
//	if (p->Pos.X == 0 || p->Pos.X == Map_X_MaxSize - 1 || p->Pos.Y == 0 || p->Pos.Y == Map_Y_MaxSize - 1) {
//		switch (p->dir){
//		case RIGHT: p->Pos.X--; break;
//		case LEFT:  p->Pos.X++; break;
//		case UP:    p->Pos.Y++; break;
//		case DOWN:  p->Pos.Y--; break;
//		}
//	}
//}
//
//void GenPotion(Potion* po, Player* p) {
//	if (po->isPotion) {
//		return;
//	}
//
//	po->isPotion = true;
//	int indx = 0;
//
//	COORD arrPos[Map_X_MaxSize * Map_Y_MaxSize];
//	for (int i = 2; i < (Map_Y_MaxSize - 2); i++) {
//		for (int j = 1; j < (Map_X_MaxSize - 2); j++) {
//			arrPos[indx].X = i;
//			arrPos[indx].Y = j;
//			indx++;
//		}
//	}
//
//	int r = rand();
//	r = r % (indx - 5);
//	if (arrPos[r].X == p->Pos.X && arrPos[r].Y == p->Pos.Y) {
//		r += 1;
//	}
//	po->pos.X = arrPos[r].X;
//	po->pos.Y = arrPos[r].Y;
//}
//
//void RendPotion(Potion* po) {
//	if (po->isPotion) {
//		buffer[po->pos.Y][po->pos.X] = Bonus;
//	}
//		
//}
//
//void CheckInput(Player* p)
//{
//	char input;
//	if (_kbhit())
//	{
//		input = _getch();
//		switch (input)
//		{
//		case 'a':
//		case 'A': p->dir = LEFT; break;
//		case 's':
//		case 'S': p->dir = DOWN; break;
//		case 'd':
//		case 'D': p->dir = RIGHT; break;
//		case 'w':
//		case 'W': p->dir = UP;  break;
//		}
//	}
//}
//
//
//
//void RenderPlayer(Player* p) {
//	buffer[p->Pos.Y][p->Pos.X] = Me;
//}
//
//
//void MovePlayer(Player* p) {
//	switch (p->dir) {
//	case RIGHT: p->Pos.X++; break;
//	case LEFT:  p->Pos.X--; break;
//	case UP:    p->Pos.Y--; break;
//	case DOWN:  p->Pos.Y++; break;
//	}
//}
//
//void GenMonster(Monster* m[]) {
//	int i = 0;
//	while (i < MonsterNum_Max && m[i]->isAlive) {
//		i++;
//	}
//
//	if (i < MonsterNum_Max) {
//		m[i]->isAlive = true;
//		m[i]->idx = i;
//		m[i]->Origin();
//		switch (monsterPos) {
//		case 0: m[i]->Pos.X = 20; m[i]->Pos.Y = 18;  break;
//		case 1: m[i]->Pos.X = 20; m[i]->Pos.Y = 1;   break;
//		case 2: m[i]->Pos.X = 38; m[i]->Pos.Y = 10;  break;
//		case 3: m[i]->Pos.X = 1;  m[i]->Pos.Y = 10;  break;
//		}
//	}
//
//	monsterPos++;
//	if (monsterPos > 3) {
//		monsterPos = 0;
//	}
//	
//}
//
//void MoveMonster(Monster* m[], Player* p) {
//	for (int i = 0; i < MonsterNum_Max; i++) {
//		if (m[i]->isAlive) {
//			int x, y;
//			x = p->Pos.X - m[i]->Pos.X; y = p->Pos.Y - m[i]->Pos.Y;
//			if (x * x >= y * y) {
//				if (x > 0) {
//					m[i]->Pos.X++;
//				}
//				else{
//					m[i]->Pos.X--;
//				}
//			}
//			else if (x * x < y * y) {
//				if (y > 0) {
//					m[i]->Pos.Y++;
//				}
//				else {
//					m[i]->Pos.Y--;
//				}
//			}
//		}
//	}
//}
//
//void RenderMonster(Monster* m[]) {
//	for (int i = 0; i < MonsterNum_Max; i++) {
//		if (m[i]->isAlive) {
//			buffer[m[i]->Pos.Y][m[i]->Pos.X] = Enemy;
//		}
//	}
//
//}
//
//void Fighting(Player* p, Monster* m[]) {
//	int n = 0;
//	int j;
//	p->ShowData();
//	puts("");
//	for (int i = 0; i < MonsterNum_Max; i++) {
//		if (m[i]->isFight) {
//			j = i;
//			m[i]->ShowData();
//			n++;
//			puts("");
//		}
//	}
//	if (n == 1) {
//		printf("몬스터를 공격하시겠습니까?\n");
//		getchar();
//		getchar();
//		p->Attack(m[j]);
//		if (m[j]->hp <= 0) {
//			m[j]->isAlive = false;
//			m[j]->isFight = false;
//			printf("Monster%d 을 처치했다!!\n", j);
//			p->PlusExp();
//			getchar();
//			getchar();
//		}
//
//	}
//	else {
//		printf("몇번 몬스터를 공격하시겠습니까?");
//		cin >> n;
//		if (m[n]->isFight) {
//			p->Attack(m[n]);
//			if (m[n]->hp <= 0) {
//				m[n]->isAlive = false;
//				m[n]->isFight = false;
//				printf("Monster%d 을 처치했다!!\n", n);
//				p->PlusExp();
//				getchar();
//				getchar();
//			}
//		}
//	}
//	for (int i = 0; i < MonsterNum_Max; i++) {
//		if (m[i]->isFight) {
//			p->Deffence(m[i]);
//		}
//	}
//}
//
//void DrawWorld(Player* p) {
//	int HP = p->GetHP();
//	printf("Player : ◎    Monster : Μ   Bonus : ♤  Left='a' Right='d' Up='w' Down='s' \n");
//	p->ShowData();
//	puts("");
//	for (int i = 0; i < Map_Y_MaxSize; i++) {
//		for (int j = 0; j < Map_X_MaxSize; j++) {
//			switch (map[i][j]) {
//			case Empty: printf("  "); break;
//			case Wall:  printf("■"); break;
//			case Me:    printf("◎"); break;
//			case Enemy: printf("Μ"); break;
//			case Bonus: printf("♤"); break;
//			}
//		}
//		puts("");
//	}
//}
//
//int main() {
//	bool isFirst = true;
//	int k = 0;
//	Player* player = new Player(200, 70, 10, 20, 20);
//	player->Pos.X = 20;
//	player->Pos.Y = 10;
//	Monster* monster[MonsterNum_Max];
//	for (int i = 0; i < MonsterNum_Max; i++) {
//		monster[i] = new Monster;
//	}
//	Potion* potion = new Potion;
//	printf("Player의 이름을 입력하세요 : ") ;
//	player->ChangeName();
//	InitBuffer();
//	RenderPlayer(player);
//	RenderMap();
//	DrawWorld(player);
//
//	while (player->GetHP () > 0) {
//		if (!isCol) {
//			frame++;
//			system("cls");
//			InitBuffer();
//			CheckInput(player);
//			if (frame % 2 == 0) {
//				MoveMonster(monster, player);
//			}
//			MovePlayer(player);
//			if (frame % MonsterGenTime == 0) {
//				GenMonster(monster);
//			}
//			if (frame % (MonsterGenTime + 10) == 0) {
//				GenPotion(potion, player);
//			}
//			CheckCollision(player, monster, potion);
//			RenderMonster(monster);
//			RendPotion(potion);
//			RenderPlayer(player);
//			RenderMap();
//			DrawWorld(player);
//			Sleep(300);
//		}
//		else {
//			system("cls");
//			if (isFirst) {
//				isFirst = false;
//				printf("몬스터를 만났다!!!!\nEnter..\n\n");
//			}
//			Fighting(player, monster);
//			int j = 0;
//			while (j < MonsterNum_Max && !monster[j]->isFight){
//				j++;
//			}
//			if (j == MonsterNum_Max) {
//				isFirst = true;
//				isCol = false;
//			}
//		}
//
//	}
//	cout << "Player 사망!!";
//	for (int i = 0; i < MonsterNum_Max; i++) {
//		delete monster[i];
//	}
//	delete potion;
//	delete player;
//	puts("");
//	cout << "~~ GameOver ~~";
//	getchar();
//	
//	
//	return 0;
//
//}