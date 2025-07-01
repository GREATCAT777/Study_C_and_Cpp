//#include<iostream>
//#include<list>
//
//using namespace std;
//
///*
//int Add(int, int);
//float Add(float, float);
//
//int main() {
//
//	int num1, num2;
//	num1 = num2 = 10;
//
//	Add(num1, num2);
//	cout << Add(num1, num2) << endl;
//
//	float fnum1, fnum2;
//	fnum1 = fnum2 = 10.10;
//
//	Add(fnum1, fnum2);
//	cout << Add(fnum1, fnum2) << endl;
//
//	getchar();
//
//	return 0;
//}
//
//int Add(int a, int b) {
//
//	cout << "return int" << endl;
//	return a + b;
//}
//
//float Add(float a, float b) {
//
//	cout << "return float" << endl;
//	return a + b;
//}*/
//
///*class BUG
//{
//public:
//	BUG() {
//		cout << "생성자" << endl;
//	}
//
//	BUG(int num) {
//		cout << "생성자" << endl;
//		cout << num << endl;
//	}
//
//	void Init() {
//	
//	}
//
//	void FLy() {
//		cout << "난다" << endl;
//	}
//
//	void FLy(int a) {
//		for (int i = 0; i < a; i++)
//		{
//			cout << "난다"<< i << endl;
//		}
//	}
//
//	~BUG() {
//		cout << "소멸자" << endl;
//
//	}
//
//private:
//
//};
//
//int main() {
//	{
//		BUG bug;
//		bug.FLy();
//		bug.FLy(10);
//	}
//	BUG* fug =new BUG;
//	fug->FLy();
//	BUG* fug = new BUG(100);
//	BUG* dug = (BUG*)malloc(sizeof(BUG));
//
//	// ////메모리를 풀링한다 (밑)
//	//{
//	//	int memStart = (int)malloc(1024); //1기가 메모리 할당, memStart의 첫주소
//	//	BUG* vug1 = (BUG*)memStart;
//	//	memStart += sizeof(BUG);
//	//	vug1->FLy();
//	//	BUG* vug2 = (BUG*)memStart;
//	//	vug2->FLy();
//	//}
//	// ///스코프 벗어나면 접근을 못한다 대신에 클래스로 만들어서 관리한다
//
//	
//	
//	getchar();
//	return 0;
//}*/
//
///*class Bug {
//public: 
//	Bug() {
//	
//	}
//	int legcount;
//	bool isFy;
//	static char* name;
//	static int x;
//
//	static void PinrtBug() {
//		cout << "static 벌레출력" << endl;
//		//cout << legcount << endl; //클래스내부의 스태틱함수에서 다른 맴버변수를 사용하려면 스태틱변수여야한다
//		cout << name << endl; //선언가능
//	}
//
//	void print() {
//		cout << "벌레출력" << endl;
//	}
//};
//
//int Bug::x = 4;
//char* Bug::name = (char*)"벌레"; //코드영역에 미리 올라와있다
//
//int main() {
//	Bug::PinrtBug();
//
//	Bug bug;
//	bug.legcount = 6;
//	bug.isFy = false;
//	Bug bug2;
//	bug.legcount = 6;
//	bug.isFy = false;
//	Bug bug3;
//	bug.legcount = 6;
//	bug.isFy = false;
//
//	cout << bug.name << endl;
//	cout << bug2.name << endl;
//	cout << bug3.name << endl;
//
//	getchar();
//	return 0;
//}*/
//
///*class Singleton { //유저 데이터관리 ,
//public :
//	static Singleton* getInstance() { //주소값을 리턴하는 함수
//		if (Instance == NULL) {
//			Instance = new Singleton(); //아무리  많이 불러도 힙영역의 한구역 주소에서만 생성된다
//		}
//		return Instance;
//	}
//	void Print() { cout << "출력" << endl; }
//	void Setnum(int n) { num = n; }
//	int Getnum() { return num; }
//
//private : 
//	Singleton() {}
//	static Singleton* Instance;
//	int num;
//};
//
//Singleton* Singleton::Instance = NULL;
//
//void tmp() {
//	cout << Singleton::getInstance()->Getnum() << endl;
//}
//
//int main() {
//
//	Singleton::getInstance()->Setnum(100);
//	cout << Singleton::getInstance()->Getnum() << endl;
//
//	tmp();
//
//	getchar();
//
//	return 0;
//}*/
//
///*class P{
//public : 
//	void pubN(){}
//	int num;
//protected : //외부에서는 접근이 불가능함 하지만 자식 클래스에서는 접근이 가능함
//	void proN() {}
//	int num2;
//private :
//	void priN() {}
//	int num3;
//};
//
//class C : private P{
//public : 
//
//	void Show() {
//		cout << num << endl;
//		cout << num2 << endl;
//		cout << cnum << endl;
//		cout << cnum2 << endl;
//	}
//	void pubN2() {}
//	int cnum;
//protected : 
//	void proN2() {}
//	int cnum2;
//private :
//	void priN2() {}
//	int cnum3;
//};
//
//int main() {
//
//	C c;
//	cout << sizeof(C) << endl;
//
//	getchar();
//	return 0;
//}*/
//
///*
////참고용
//class Object {
//public:
//	void Update() {
//		//프레임 업데이트
//	}
//};
//
//class Entity :public Object {
//public :
//	void Setposition(float x,float y) {
//		posx = x;
//		posy = y;
//	} //좌표값 설정
//	float GetPositionX() { return posx; }
//	float GetPositionY() { return posy; }
//
//private:
//	float posx;
//	float posy;
//};
//
//class StaticEntity : public Entity {
//public: //움직이지 않음
//};
//
//class DynamicEntity : public Entity {
//public :  //움직이는 객체 미사일 캐릭터
//	void Move() {};
//};
//
//int main() {
//
//	getchar();
//	return 0;
//}*/
//
////
////class P {
////public:
////	P() {
////		cout << "아빠 왔다" << endl;
////	}
////	static void FuncP() {
////		cout << "아빠함수 왔다" << endl;
////	}
////	~P() {
////		cout << "아빠 간다" << endl;
////	}
////};
////
////class C : public P {
////public:
////	C() {
////		cout << "아들 왔다" << endl;
////	}
////	C(int a) {
////		cout << "아들 "<< a <<"번 왔다" << endl;
////	}
////	~C() {
////		cout << "아들 간다" << endl;
////	}
////};
////
////int main() {
////
////		C c;
////
////	getchar();
////	return 0;
////}
//
///*class P2 {
//public:
//P2() {
//cout << "아빠 왔다" << endl;
//}
//int fx() {
//return 1;
//}
//~P2() {
//cout << "아빠 간다" << endl;
//}
//};
//
//class C2 : public P2 {
//public:
//C2() {
//cout << "아들 왔다" << endl;
//}
//int fx() {
//return 0;
//}
//~C2() {
//cout << "아들 간다" << endl;
//}
//};
//
//int main() {
//{
//C2 c;
//cout << c.fx() << endl;
//}
//return 0;
//}*/
//
///*class Parent {
//public:
//Parent() {
//cout << "아빠1소환" << endl;
//}
//virtual void Call() {
//cout << "아빠왔다" << endl;
//}
//virtual~Parent() {
//cout << "아빠 1삭제" << endl;
//}
//};
//
//class Child1 : public Parent {
//public :
//Child1() {
//cout << "아들 1소환" << endl;
//}
//void Call() override { //재정의 되었다고 명시적으로 선언해주는 명령어 override
//cout << "아들 1왔다"  << endl;
//}
//virtual~Child1() {
//cout << "아들 1삭제" << endl;
//}
//};
//
//class Child2 : public Parent {
//public:
//Child2() {
//cout << "아들 2소환" << endl;
//}
//void Call() override {
//cout << "아들 2왔다" << endl;
//}
//virtual~Child2() {
//cout << "아들 2삭제" << endl;
//}
//};
//
//class Child3 : public Parent {
//public:
//Child3() {
//cout << "아들 3소환" << endl;
//}
//void Call() override {
//cout << "아들 3왔다" << endl;
//}
//virtual~Child3() {
//cout << "아들 3삭제" << endl;
//}
//};
//
//int main() {
//{
//Parent* arrP[3]; // 4바이트의 주소값
//arrP[0] = new Child1(); //자식 클래스의 자료값이 아무리 커도 포인터로 선언되어서 크기는 4바이트의 크기를 갖는다
//arrP[1] = new Child2();
//arrP[2] = new Child3();
//
//arrP[0]->Call();
//arrP[1]->Call();
//arrP[2]->Call();
//
//delete arrP[0]; //삭제되는 순서대로 헤제됨
//delete arrP[1];
//delete arrP[2];
//}
//
//getchar();
//return 0;
//}*/
//
///*
//class P {
//public:
//P() {
//cout << "할아버지 왔다"<<endl;
//}
//
//virtual void Call() {
//cout << "할아버지 여기있어" << endl;
//}
//
//virtual~P() {
//cout << "할아버지 간다" << endl;
//}
//};
//
//class C :public P {
//public:
//C() {
//cout << "아빠 왔다" << endl;
//}
//
//void Call() {
//cout << "아빠 여기있어" << endl;
//}
//
//~C() {
//cout << "아빠 간다" << endl;
//}
//};
//
//class CC : public C {
//public:
//CC() {
//cout << "아들 왔다" << endl;
//}
//
//void Call() {
//cout << "아들 여기있어" << endl;
//}
//
//~CC() {
//cout << "아들 간다" << endl;
//}
//};
//
//int mian() {
//{
//P* p[3];
//p[0] = new CC();
//p[1] = new CC();
//p[2] = new CC();
//
//p[0]->Call();
//p[1]->Call();
//p[2]->Call();
//
//}
//
//getchar();
//return 0;
//}
//*/
//
//class  A { // 순수가상함수가 하나라도 들어있으면 추상 클래스, 생성할수없다 ,스택,힙에도 올리지 못한다
//public:
//	A() {
//		a = 10;
//		b = 0.3f; //기본적으로 쓰면 double이라 인식하고 'f'를 같이 선언해주면 float로 인식한다 
//	}
//	int a;
//	float b;
//private:
//	virtual void print() = 0; //순수 가상함수
//
//
//}; //추상클래스를 사용하는이유 : 나에게 내코드를 강요하고 남에게 내 코드를 강요하기위해
//
//class B :public A {
//public:
//	void print() { //추상클래스를 상속받았다면 안에있는 순수가상함수를 재정의 해준다 그럼 사용가능!
//		cout << "의미있는 행동인가?" << endl;
//	}
//};
//
//int main() {
//
//	B b;
//	b.print();
//	cout << b.a << "   " << b.b << endl;
//
//	getchar();
//	getchar();
//
//	return 0;
//}