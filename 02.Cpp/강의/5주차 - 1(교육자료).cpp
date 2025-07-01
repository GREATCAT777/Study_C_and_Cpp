/*#include<iostream>
#include<stdbool.h>
#include<windows.h>
#include<conio.h>

#define MAX_NAME_LEN 20

using namespace std;*/

/*int main() {

	int a = 10;
	char c = 'd';

	std::cin >> a;

	std::cout << "Hello world" << std::endl;

	std::cout << a <<","<< c << std::endl;

	std::cout << "스킬 이름" << c << "데미지" << a;
	
	getchar();
	getchar();
	return 0;
}*/

/*int main() { //입력받은수부터 100개의 숫자를 더한값 출력
	int a;

	std::cout << "1~99까지의 숫자를 입력해주세요"<<std::endl;

	std::cin >> a; //입력받는다

	if (a > 0 && a < 100) {
		for (int i = 0; i < 100; i++) {

		}
	}
	else {
		std::cout << "다시입력해주세요";
	}

	std::cout << a << std::endl;

	getchar();
	getchar();

	return 0;
}*/

/*int main() {
	int a;

	std::cout << "1~99까지의 숫자를 입력해주세요" << std::endl;

	std::cin >> a;

	if (a < 1 || a>99) {
		std::cout << "에러"<<std::endl;
		return -1;
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		sum += a;
		a++;
	}

	std::cout << "결과 :" << sum << std::endl;
	
	getchar();
	getchar();
	return 0;
}*/

/*int main() {
	bool isEnable = true; //정수형의 일종
	bool bEnable = false;

	char name[100]; //문자기반의 아스키코드로 입력받는다

	std::cin >> name;

	std::cout << name;

	return 0;
}*/

/*int main() { //입력받은 알파벳 문자열을 역순으로 나열한다
	char string[100];

	std::cin >> string;

	std::cout << string << std::endl;

	for (int i = 99; i < 0; i--) {
		std::cout << string[i] << std::endl;
	}

	getchar();
	getchar();
	return 0;
}*/

/*int main() {
	char str[10];

	std::cin >> str;
	
	std::cout << str << std::endl;

	int endIdx = 0;
	 //\0 = NULL;
	while (str[endIdx] != '\0') {
		endIdx++;
	}
	for (endIdx--; endIdx >= 0; endIdx--) {
		std::cout << str[endIdx];
	}
	std::cout << std::endl;
}*/

/*int main() { //입력받은 숫자를 역순으로 출력하는것
	int arr;
	std::cin >> arr;
	std::cout << arr << std::endl;

	while (arr > 0) {
		std::cout << arr % 10;
		arr = arr/10;
	}
	std::cout << std::endl;

	getchar();
	return 0;
}*/

/*int main() {
	int a;
	bool b;


	//a = func1() ? func2(); func3();
	return 0;
}*/

/*using namespace temp;

namespace temp {
	int test; //전역변수
} //네임스페이스를 만든다

int main() {

	test = 100;
	int num;

}*/

/*int main() {
	bool b = true;

	int a = b ? 10 : 20;

	cout << a << endl;

	b = false;

	a = b ? 10 : 20;

	cout << a << endl;

	cin >> b;

	b ? printf("10") : printf("20");

	getchar();
	return 0;
}*/

//완성하는걸 중요치 말고 내가 만들고 싶은 걸 내 방식대로 표현을 하는것
//탄막액션, 2d횡스크롤
//web + client(MFC , GDI++,SDL)

/*struct SCAR { //4byte
	int Wheelcount; 
	int weight; 
	int cost; 
	char name[MAX_NAME_LEN]; //생각보다 널널하게 먼저 잡아준다
}typedef SCAR;

class CCAR { //캡슐화

public :
	int Wheelcount;
	int weight;
	int cost;
	char name[MAX_NAME_LEN]; 

	void Setnum(int n) {
		num = n; //n에서 들어온값을 private : num에 넣어준다;
		Drive();
	}

	void Drive() { //클래스안에는 함수선언 가능 C++에서만
		cout << "달려라" << endl;
	}

private : //데이터 은닉화
	int num; //내부에서는 접근이 가능하다 하지만 외부에서는 접근이 불가능하다

	struct man {
		int age;
	};
};

int main() {
	///*SCAR scar;
	//scar.cost = 100;
	//scar.weight = 1000;
	//scar.Wheelcount = 3;
	//cin >> scar.name;

	//cout << scar.name << endl;
	//cout << scar.weight << endl;
	//cout << scar.cost << endl;
	//cout << scar.Wheelcount << endl;

	CCAR ccar;

	ccar.cost = 100;
	ccar.weight = 1000;
	ccar.Wheelcount = 3;
	cin >> ccar.name;

	cout << ccar.name << endl;
	cout << ccar.weight << endl;
	cout << ccar.cost << endl;
	cout << ccar.Wheelcount << endl;

	ccar.Drive();
	ccar.Setnum(0);

	getchar();
	return 0;
}*/

/*class Bird {
public : 
	Bird() { //default생성자(안만들어줘도 빈내용,빈스코프으로 생성된다)
		cout << "생성" << endl;
		isFly = false;
	}

	explicit Bird(bool b) { //이놈 따로
		cout << "생성2" << endl;
		isFly = b;
	}

	Bird(bool b, int temp) { //이놈따로
		cout << "생성3" << endl;
		cout << temp << endl;
		isFly = b;
		num = temp;
		p = (int*)malloc(100); //동적할당
	}

	~Bird() { //default소멸자
		cout << num << " : 소멸자호출" << endl;
		free(p); //동적할당 해제
	}

	void Fly() {
		if (isFly) {
			cout << "난다" << endl;
		}
		else {
			cout << "못 난다" << endl;
		}
	}
	void Bark() {
		cout << "짖어" << endl;
	}

private :
	bool isFly;
	int* p;
	int num;
};

int main() {
	{// 소멸자를 보여주기위해 스코프로 막는다
		Bird bird(true, 1); //기본 생성자 부르기
		bird.Bark();
		bird.Fly();

		Bird bird2(true, 2); //두번째 생성자를 생성한다 (명시적으로 보기 안좋음;)
		bird2.Bark();
		bird2.Fly();

		Bird bird3(true, 123); //두번째 생성자를 생성한다 (명시적으로 보기 안좋음;)
		bird3.Bark();
		bird3.Fly();

		Bird bird4(true);
	}
	//형변환 과정(explicit 선언시)
	//1.Bird b4 = true; 안됨 "묵시적인 형변환"

	//2.Bird b4 = (Bird)true; 됨 "명시적인 형변환은 여기서부터"
	//3.Bird b4 = Bird(true); 됨
	//4.Bird b4(true); 됨 "실무에서 잘 씀"
	getchar();
	return 0;
}*/

//공격을 서로반복하고 둘중한명의 hp 가 0이하가 되면 종료
/*class Player {
public:
	Player() {
		hp = 1000;
		mp = 0;
		def = 150;
		cout <<"Player의 정보" << endl << "체력 : " << hp << endl <<"방어력 : "<< def << endl;
	}
	int attack() {
		return atk;
	}
	void getattak(int a) {
		atk = a;
		cout << "공격력 : " << atk << endl;
	}
	void deffence(int a) {
		hp = hp+def - a;
		cout << "Player의 HP가 :" << hp << " 가 되었습니다"<<endl;
	}
	int gethp() {
		return hp;
	}
	
private : 
	int hp;
	int mp;
	int atk;
	int def;
};

class Monster {
public:
	Monster() {
		hp = 3000;
		mp = 0;
		def = 200;
		atk = 300;
		cout << "Monster의 정보" << endl << "체력 : " << hp << endl << "방어력 : " << def << "공격력 : " << atk << endl;
	}
	int attack() {
		return atk;
	}
	void deffence(int a) {
		hp = hp + def - a;
		cout << "Monster의 HP가 :" << hp << " 가 되었습니다" << endl;
	}
	int gethp() {
		return hp;
	}
private:
	int hp;
	int mp;
	int atk;
	int def;
};

int main() {
	int a;
	int b;

	Monster* monster;
	Player* player;

	player = new Player(); //클래스용 메모리얼로케이션
	monster = new Monster();

	cout << "Player의 원하시는 공격력을 입력해주세요"<<endl;
	cin >> a;
	player->getattak(a);

	cout << "배틀 시작!" << endl;

	while (player->gethp() > 0 && monster->gethp() > 0) {
		b = player->attack();
		monster->deffence(b);
		b = monster->attack();
		player->deffence(b);

		Sleep(500);
	}
	delete(monster);
	delete(player);
	return 0;
}*/

// 강사님 어택디펜스 코드

/*class Player
{
public:
	Player(int _hp, int _mp, int _atk, int _def)
	{
		hp = _hp;
		mp = _mp;
		atk = _atk;
		def = _def;
	}
	void Attack(Player* m)
	{
		m->Deffence(atk);
	}
	void Deffence(int a)
	{
		hp -= a - def;
	}
	void skill(Player* m) {
		mp -= 100;
		m->Deffence(atk*2);
	}
	int GetHp()
	{
		return hp; //hp 돌려준다
	}
private:
	int hp;
	int mp;
	int atk;
	int def;
};


int main()
{
	Player player(1000, 100, 50, 10);
	Player monster(500, 10, 15, 1);
	int x;

	while (player.GetHp() > 0 && monster.GetHp() > 0)
	{
		Sleep(500);

		if (_kbhit())
		{
			cout << "스킬 발동!" << endl;
			player.skill(&monster);
		}
		else {
		player.Attack(&monster);
		monster.Attack(&player);
		}
		cout << "Player Hp : " << player.GetHp() << endl;
		cout << "Monster Hp : " << monster.GetHp() << endl;
	}

	cout << "게임종료" << endl;


	getchar();
	getchar();


	return 0;
}*/

/*class Player
{
public:
	Player(int _hp, int _mp, int _atk, int _def)
	{
		hp = _hp;
		mp = _mp;
		atk = _atk;
		def = _def;
	}
	void Attack(Player* m)
	{
		m->Deffence(atk);
	}
	void Deffence(int a)
	{
		hp -= a - def;
	}
	int GetHp()
	{
		return hp;
	}
private:
	int hp;
	int mp;
	int atk;
	int def;
};


int main()
{
	Player* player;
	player = new Player(1000, 100, 50, 10); //클래스용 메모리얼로케이션
	Player monster(500, 10, 15, 1);


	while (player->GetHp() > 0 && monster.GetHp() > 0)
	{
		player->Attack(&monster);
		monster.Attack(player);
		cout << "Player Hp : " << player->GetHp() << endl;
		cout << "Monster Hp : " << monster.GetHp() << endl;
	}

	cout << "게임종료" << endl;

	delete player;

	getchar();
	getchar();


	return 0;
}*/