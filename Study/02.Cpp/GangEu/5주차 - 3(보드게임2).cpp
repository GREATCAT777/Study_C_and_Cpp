//#include<iostream>
//#include<windows.h>
//#include<conio.h>
//
//using namespace std;
//
//#define DEFAULT_PLAYER_X_POS 15
//#define DEFAULT_PLAYER_Y_POS 15
//#define DEFAULT_MONSTER_X_POS 13
//#define DEFAULT_MONSTER_Y_POS 13
//#define MAX_WORLD_X_POS 30
//#define MAX_WORLD_Y_POS 20
//
//#define DRAW_EMPTY 0
//#define DRAW_WALL 1
//#define DRAW_PLAYER 2
//#define DRAW_MONSTER 3
//
//char Map[MAX_WORLD_X_POS][MAX_WORLD_Y_POS];
//
//class Object {
//public:
//	Object(int _hp, int _mp, int _atk, int _def, int _cri, int _dod, int _level, int _exp, int _rp, int _posx, int _posy) {
//		hp = _hp;
//		mp = _mp;
//		atk = _atk;
//		def = _def;
//		cri = _cri;
//		dod = _dod;
//		level = _level;
//		exp = _exp;
//		rp = _rp;
//		pos.X = _posx;
//		pos.Y = _posy;
//		live = 1;
//	}
//
//	void Attack(Object* o) {
//		o->Deffence(atk);
//	}
//
//	void Deffence(int a) {
//		if (a > def) {
//			hp -= a - def;
//		}else if(a <= def){
//			hp -= 1;
//		}
//		if (hp < 0) {
//			live = 0;
//		}
//	}
//
//	void Dead(Object* o) {
//		if (live = 0) {
//		o->exp += level;
//		}
//	}
//
//	void Showstate() {
//		cout << "LEVEL : " << level << ", HP : " << hp << ", MP : " << mp << ", ATK : " << atk << ", DEF : " << def << ", CRI : " << cri << ", DOD : " << dod << ", EXP : " << exp << endl;
//	}
//
//	bool Getlive() {
//		return live;
//	}
//
//	int Gethp() {
//		return hp;
//	}
//
//	int hp, mp, atk, def, cri, dod, level, exp, rp;
//	COORD pos;
//private:
//	bool live;
//};
//
//void SetCurPos(int x, int y) {
//	COORD pos;
//	pos.X = x * 2;
//	pos.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void Levelup(Object* o) {
//	int s = 0;
//	if (o->exp >= o->level) {
//		SetCurPos(0, MAX_WORLD_Y_POS + 5);
//		cout << "LEVEL UP! 지금부터 스텟을 할당합니다" << endl;
//		o->level++;
//		for (int i = 3; i > 0; i--) {
//			cout << "원하시는 스텟을 골라주세요 1.hp 2.mp 3.atk 4.def 5. cri 6.dod";
//			cin >> s;
//			switch (s) {
//			case 1: o->hp += 5; cout << "hp가 5올랐습니다" << endl; break;
//			case 2: o->mp += 5; cout << "mp가 5올랐습니다" << endl; break;
//			case 3:	o->atk += 2; cout << "atk가 2올랐습니다" << endl; break;
//			case 4:	o->def += 1; cout << "def가 1올랐습니다" << endl; break;
//			case 5:	o->cri += 2; cout << "cri가 2올랐습니다" << endl; break;
//			case 6: o->dod += 2; cout << "dod가 2올랐습니다" << endl; break;
//			default:cout << "범위내에서 골라주세요" << endl; s++; break;
//			}
//		}
//		o->exp -= o->level; //잔류 경험치
//	}
//}
//
//void AIMove(Object* o1,Object* o2) {
//
//}
//
//void Initmap(Object* o1, Object* o2) {
//	int i, j;
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
//	Map[o1->pos.X][o1->pos.Y] = DRAW_PLAYER;
//	Map[o2->pos.X][o2->pos.Y] = DRAW_MONSTER;
//}
//
//void Drawmap() {
//	int i, j;
//	for (j = 0; j < MAX_WORLD_Y_POS; j++) {
//		for (i = 0; i < MAX_WORLD_X_POS; i++) {
//
//			switch (Map[i][j]) {
//			case DRAW_EMPTY: cout << "  "; break;
//			case DRAW_WALL: cout << "■"; break;
//			case DRAW_PLAYER: cout << "★"; break;
//			case DRAW_MONSTER: cout << "＠"; break;
//			}
//		}
//		cout << endl;
//	}
//}
//
//void Render(Object* o) {
//	Map[o->pos.X][o->pos.Y] = DRAW_PLAYER;
//}
//
//void ClearWorld() {
//	int i, j;
//	for (i = 0; i < MAX_WORLD_X_POS; i++) {
//		for (j = 0; j < MAX_WORLD_Y_POS; j++) {
//			Map[i][j] = DRAW_EMPTY;
//		}
//	}
//}
//
//void Move(Object* o) {
//	if (_kbhit()) {
//
//		int input = _getch();
//		switch (input) {
//		case 'a':
//		case 'A': Map[o->pos.X][o->pos.Y] = DRAW_EMPTY; o->pos.X -= 1; Map[o->pos.X][o->pos.Y] = DRAW_PLAYER; break;
//		case 's':
//		case 'S': Map[o->pos.X][o->pos.Y] = DRAW_EMPTY; o->pos.Y += 1; Map[o->pos.X][o->pos.Y] = DRAW_PLAYER; break;
//		case 'd':
//		case 'D': Map[o->pos.X][o->pos.Y] = DRAW_EMPTY; o->pos.X += 1; Map[o->pos.X][o->pos.Y] = DRAW_PLAYER; break;
//		case 'w':
//		case 'W': Map[o->pos.X][o->pos.Y] = DRAW_EMPTY; o->pos.Y -= 1; Map[o->pos.X][o->pos.Y] = DRAW_PLAYER; break;
//		}
//	}
//};
//
//int main() {
//	Object* player = new Object(10, 10, 5, 3, 5, 10, 1, 0, 50, DEFAULT_PLAYER_X_POS, DEFAULT_PLAYER_Y_POS);
//	Object* monster = new Object(5, 0, 2, 1, 4, 4, 1, 0, 50, DEFAULT_MONSTER_X_POS, DEFAULT_MONSTER_Y_POS);
//
//	Initmap(player, monster);
//
//	while (player->Gethp() > 0) {
//		SetCurPos(0, 0);
//
//		Move(player);
//
//		Render(player);
//
//		if (player->pos.X == monster->pos.X && player->pos.Y == monster->pos.Y && monster->Getlive() == 1) {
//			SetCurPos(0, MAX_WORLD_Y_POS + 2);
//			cout << "몬스터를 만났습니다"<< endl;
//
//			while (player->Gethp() > 0 && monster->Gethp() > 0) {
//
//				player->Attack(monster);
//
//				monster->Attack(player);
//
//				SetCurPos(0, MAX_WORLD_Y_POS + 3);
//
//				cout << "Player Hp : " << player->Gethp() << endl;
//
//				cout << "Monster Hp : " << monster->Gethp() << endl;
//				
//				Sleep(500);
//			}
//			monster->Dead(player);
//			Levelup(player);
//			system("cls");
//		}
//		Drawmap();
//		SetCurPos(0, MAX_WORLD_Y_POS + 1);
//		player->Showstate();
//		Sleep(100);
//	}
//
//	cout << "게임 종료" << endl;
//
//	getchar();
//	getchar();
//
//	delete(player);
//	delete(monster);
//
//	return 0;
//}