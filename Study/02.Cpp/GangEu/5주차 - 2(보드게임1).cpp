//#include<iostream>
//#include<string.h>
//#include<time.h>
//#include<windows.h>
//#include<conio.h>
//
//using namespace std;
//
//#define INPUT_LEFT 75
//#define INPUT_RIGHT 77
//#define INPUT_UP 72
//#define INPUT_DOWN 80
//
//#define MAX_WORLD_X_POS 32
//#define MAX_WORLD_Y_POS 22
//#define DRAW_EMPTY 0
//#define DRAW_WALL 1
//#define DRAW_PLAYER 2
//#define DRAW_MONSTER 3
//#define DRAW_ITEM 4
//#define DRAW_WORM_HALL 5
//
//#define CRI_COEF 2
//#define level_UP_POINT 3
//#define DEFAULT_PLAYER_X_POS 15
//#define DEFAULT_PLAYER_Y_POS 15
//#define DEFAULT_MONSTER_X_POS 21
//#define DEFAULT_MONSTER_Y_POS 14
//
//char Map[MAX_WORLD_X_POS][MAX_WORLD_Y_POS];
//
//class Monster;
//
//class Player {
//public:
//	Player() {
//		hp = 10;
//		mp = 10;
//		atk = 5;
//		def = 3;
//		cri = 5;
//		dod = 10;
//		level = 1;
//		exp = 0;
//		inven[4] = NULL;
//		pos.X = DEFAULT_PLAYER_X_POS;
//		pos.Y = DEFAULT_PLAYER_Y_POS;
//	}
//
//	friend class Monster;
//
//	void Deffense(Monster m);
//
//	void Attack(Player p);
//
//	void Skill(Monster m);
//
//	void Action(int s, Player p, Monster m);
//
//	int compare(int* a, int* b) {
//
//		for (int j = 0; j < 5; j++) {
//
//			if (*a != *b) {
//				return 0;
//			}
//			else {
//				*a++;
//				*b++;
//			}
//		}
//		return 1;
//	}
//
//	void LevelUp() {
//		int s = 0;
//		if (exp >= level) {
//			cout << "LEVEL UP! 지금부터 스텟을 할당합니다" << endl;
//			level++;
//			for (int i = level_UP_POINT; i > 0; i--) {
//				cout << "원하시는 스텟을 골라주세요 1.hp 2.mp 3.atk 4.def 5. cri 6.dod" << endl;
//				cin >> s;
//				switch (s) {
//				case 1: hp += 5; cout << "hp가 5올랐습니다" << endl; break;
//				case 2: mp += 5; cout << "mp가 5올랐습니다" << endl; break;
//				case 3:	atk += 2; cout << "atk가 2올랐습니다" << endl; break;
//				case 4:	def += 1; cout << "def가 1올랐습니다" << endl; break;
//				case 5:	cri += 2; cout << "cri가 2올랐습니다" << endl; break;
//				case 6: dod += 2; cout << "dod가 2올랐습니다" << endl; break;
//				default:cout << "범위내에서 골라주세요" << endl; s++; break;
//				}
//			}
//			exp -= level; //잔류 경험치
//		}
//	}
//
//	void GetItem(int item) {
//		switch (item) {
//		case 0:cout << "불의 검 획득 : atk 5상승" << endl; atk += 5; break;
//		case 1:cout << "물의 방패 획득 : def 5상승" << endl; def += 5; break;
//		case 2:cout << "나무의 가시장갑 획득 : cri 5상승" << endl; cri += 5; break;
//		case 3:cout << "바람의 신발 획득 : dod 5상승" << endl; dod += 5; break;
//		}
//	}
//
//	int Gethp() {
//		return hp;
//	}
//
//	void Move() {
//		int key = 0;
//		COORD fpos;
//		fpos.X = 0;
//		fpos.Y = 0;
//
//		if (_kbhit()) {
//			key = _getch();
//			switch (key) {
//			case INPUT_LEFT: fpos.X -= 1; break;
//			case INPUT_RIGHT: fpos.X += 1; break;
//			case INPUT_UP: fpos.Y -= 1; break;
//			case INPUT_DOWN: fpos.Y += 1; break;
//			}
//		}
//		pos.X += fpos.X;
//		pos.Y += fpos.Y;
//	}
//
//	int exp;
//	int RP;
//	COORD pos;
//private:
//	int hp;
//	int mp;
//	int atk;
//	int def;
//	int cri;
//	int dod;
//	int level;
//	int inven[4];
//};
//
//class Monster {
//
//public:
//	Monster() {
//		hp = 4;
//		mp = 0;
//		atk = 2;
//		def = 1;
//		cri = 4;
//		dod = 4;
//		level = 1;
//		pos.X = DEFAULT_MONSTER_X_POS;
//		pos.Y = DEFAULT_MONSTER_Y_POS;
//	}
//
//	friend class Player;
//
//	void Deffense(Player p) {
//		if (p.RP < p.dod) {
//			cout << "회피!" << endl;
//		}
//		else {
//			p.hp -= p.atk - def;
//			cout << "플레이어는 " << p.atk - def << " 의 데미지를 입었습니다" << endl;
//		}
//	};
//
//	void Attack(Monster m) {
//		if (m.RM < m.cri) {
//			m.atk *= CRI_COEF;
//			Monster::Deffense(Player());
//			m.atk /= CRI_COEF;
//		}
//		else {
//			Monster::Deffense(Player());
//		}
//	}
//
//	void DeathDrop(Player p, int rand) {
//		if (hp <= 0) {
//			p.exp += level;
//			if (rand <= 20) {
//				p.GetItem(rand % 4);
//			}
//		}
//	}
//
//	int Gethp() {
//		return hp;
//	}
//
//	void Move() {
//
//	}
//
//	int RM;
//	COORD pos;
//private:
//	int hp;
//	int mp;
//	int atk;
//	int def;
//	int cri;
//	int dod;
//	int level;
//};
//
//void SetCurPos(int x, int y) {
//	COORD pos;
//	pos.X = x;
//	pos.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void SetRandom(Player p, Monster m) {
//	p.RP = rand() / 100;
//	m.RM = rand() / 100;
//}
//
//void Player::Deffense(Monster m) {
//	if (m.RM < m.dod) {
//		cout << "회피!" << endl;
//	}
//	else {
//		m.hp -= (m.atk - def);
//		cout << "몬스터는 " << m.atk - def << " 의 데미지를 입었습니다" << endl;
//	}
//}
//
//void Player::Attack(Player p) {
//	if (p.RP < p.cri) {
//		p.atk *= CRI_COEF;
//		Player::Deffense(Monster());
//		p.atk /= CRI_COEF;
//	}
//	else {
//		Player::Deffense(Monster());
//	}
//}
//
//void Player::Skill(Monster m) {
//	int i = 0;
//	int comand[5];
//	int readycomand1[5] = { 72,80,72,72,80 }; //위아래 위위아래 - 데미지 2배
//	int readycomand2[5] = { 75,77,75,77,72 }; //좌우 좌우 위 - 몬스터의 현재 체력의 25%데미지
//
//
//	cout << "커맨드 입력 10초" << endl;
//
//	if (i < 5) {
//		while (_kbhit()) {
//			Sleep(300);
//			comand[i] = _getch();
//			i++;
//		}
//		cout << "커맨드 입력 완료" << endl;
//	}
//
//	if (compare(comand, readycomand1) == 1) {
//		if (mp >= 5) {
//			mp -= 5;
//			atk *= 2;
//			Attack(Player());
//			atk /= 2;
//		}
//		else {
//			cout << "현재 mp량이 부족하여 스킬1 를 발동할수없습니다 (요구조건 : mp 5이상)" << endl;
//		}
//	}
//
//	else if (compare(comand, readycomand2) == 1) {
//		if (mp >= 20) {
//			mp -= 20;
//
//			m.hp -= (m.Gethp() / 4);
//
//			cout << "스킬2 발동 : " << (m.Gethp() / 4) << "의 데미지를 주었다" << endl;
//		}
//		else {
//			cout << "현재 mp량이 부족하여 스킬2 를 발동할수없습니다 (요구조건 : mp 20이상)" << endl;
//		}
//	}
//
//	else {
//		cout << "앗...아......" << endl;
//	}
//}
//
//void Player::Action(int s, Player p, Monster m) {
//	SetRandom(p, m);
//	switch (s) {
//	case 1: Attack(Player()); break;
//	case 2: Skill(Monster()); break;
//	default: cout << "다시 입력해주세요" << endl; break;
//	}
//}
//
//void Drawmap() {
//	SetCurPos(0, 0);
//	int i, j;
//	for (j = 0; j < MAX_WORLD_Y_POS; j++) {
//		for (i = 0; i < MAX_WORLD_X_POS; i++) {
//
//			switch (Map[i][j]) {
//			case DRAW_EMPTY: printf("  "); break;
//			case DRAW_WALL: printf("■"); break;
//			case DRAW_PLAYER: printf("★"); break;
//			case DRAW_MONSTER: printf("＠"); break;
//			case DRAW_ITEM: printf("＠"); break;
//			case DRAW_WORM_HALL: printf("＠"); break;
//			}
//			//printf("%d", Map[i][j]);
//		}
//		puts("");
//	}
//}
//
//void Initmap() {
//	int i, j;
//
//	for (i = 0; i < MAX_WORLD_X_POS; i++) {
//		for (j = 0; j < MAX_WORLD_Y_POS; j++) {
//			if (i == 0 || i == MAX_WORLD_X_POS - 1 || j == 0 || j == MAX_WORLD_Y_POS - 1) {
//				Map[i][j] = DRAW_WALL;
//			}
//			else {
//				Map[i][j] = DRAW_EMPTY;
//			}
//		}
//	}
//}
//
//void GenOBJ(Player p, Monster m) {
//	int r;
//	r = rand();
//	m.pos.X = r % (MAX_WORLD_X_POS - 1) + 1;
//	m.pos.Y = r % (MAX_WORLD_Y_POS - 1) + 1;
//	if (p.pos.X == m.pos.X && p.pos.Y == m.pos.Y) {
//		r = rand();
//		m.pos.X = r % (MAX_WORLD_X_POS - 1) + 1;
//		m.pos.Y = r % (MAX_WORLD_Y_POS - 1) + 1;
//	}
//}
//
//void RenMon(Monster m) {
//	Map[m.pos.X][m.pos.Y] = DRAW_MONSTER;
//}
//
//void RenPla(Player p) {
//	Map[p.pos.X][p.pos.Y] = DRAW_PLAYER;
//}
//void ClearWorld() {
//		int i, j;
//		for (i = 0; i < MAX_WORLD_X_POS; i++) {
//			for (j = 0; j < MAX_WORLD_Y_POS; j++) {
//				Map[i][j] = DRAW_EMPTY;
//			}
//		}
//	}
//
//
//
//int main() {
//	Player* player;
//	Monster* monster;
//
//	player = new Player(); //C++동적할당
//	monster = new Monster();
//
//	Initmap();
//	GenOBJ(*player, *monster);
//
//	while (player->Gethp() >= 0) {
//		Drawmap();
//
//		//캐릭터 이동
//		if (player->pos.X != monster->pos.X || player->pos.Y != monster->pos.Y) {
//			player->Move();
//			monster->Move();
//		}
//		else if (player->pos.X == monster->pos.X && player->pos.Y == monster->pos.Y) {
//
//			SetCurPos(3, MAX_WORLD_Y_POS + 1);
//			cout << "몬스터 발견, 배틀을 시작합니다 " << endl;
//
//			while (player->Gethp() > 0 && monster->Gethp() > 0) {
//				SetCurPos(3, MAX_WORLD_Y_POS + 2);
//
//				int s;
//				cout << "선택지 1.공격 2. 스킬(10초동안 커맨드 입력)" << endl;
//				cin >> s;
//				player->Action(s, *player, *monster);
//
//				if (monster->Gethp() > 0) {
//					monster->Attack(*monster);
//				}
//			}
//			SetRandom(*player, *monster);
//			monster->DeathDrop(*player, monster->RM);
//			player->LevelUp();
//		}
//		Sleep(100);
//		RenPla(*player);
//		RenMon(*monster);
//	}
//
//
//	delete(player);
//	delete(monster);
//
//	getchar();
//	return 0;
//}
