//#include<iostream>
//#include<conio.h>
//#include<Windows.h>
//#include<math.h>
//#include<vector>
//#include<list>
//#include<map>
//
//
//using namespace std;
//
//class KNOUWN {
//public: 
//	int k;
//};
//
//class A : virtual public KNOUWN {
//public : 
//	int a;
//};
//
//class B : virtual public KNOUWN {
//public:
//	int b;
//};
//
//class C : public A, public B {
//public :
//	int c;
//};
//
//int main() {
//
//	C c;
//
//	cout<< sizeof(C)<<"       " << c.k <<endl; //여기 안에는 AAA::k , BBB::k, CCC::k 가 들어가있다 포인터주소로 되어있어 4바이트씩 먹는다
//
//	getchar();
//	getchar();
//	return 0;
//}
//
//class Shape { //실질적값이 들어있는 베이스 클래스
//public:
//	float m_area;
//};
//
//class ShapeCalculator { //중복될수있는 함수를 가상함수로써 선언을 하여 각 하위 클래스 내에서 재정의하고 
//public:
//	virtual float getArea() = 0; //면적 구하기 가상함수
//};
//
//class Triangle : virtual public Shape, virtual public ShapeCalculator {
//public:
//	float getArea() {
//		//삼각형 계산
//		return m_area;
//	}
//	COORD m_pos[3];
//};
//
//class Rectangle : virtual public Shape, virtual public ShapeCalculator {
//public:
//	float getArea() {
//		//시각형 계산
//		return m_area;
//	}
//	COORD m_pos;
//};
//
//class Circle : virtual public Shape, virtual public ShapeCalculator {
//public:
//	float getArea() {
//		//원계산
//		return m_area;
//	}
//	COORD m_pos;
//};
//
//int main() {
//	return 0;
//}
//
//class Monster {
//protected:
//	class Battle {
//	public:
//		int hp;
//		int mp;
//		int atk;
//		int def;
//	};
//	Battle* m_v;
//public:
//	Monster() {
//		cout << "test start" << endl;
//		m_v = new Battle();
//	}
//	virtual ~Monster() { //클래스 안의 클래스에 종속된 메모리 할당을 하게된다면 소멸자에 메모리 할당헤제를 해줘야한다
//		cout << "test end" << endl;
//		delete(m_v);
//	}
//};
//
//class orc : public Monster {
//public :
//	orc() {
//		cout << "orc test start" << endl;
//		m_v = new Battle();
//	}
//	~orc() {
//		cout << "orc test end" << endl;
//		delete(m_v);
//	}
//};
//
//int main() {
//
//	getchar();
//	return 0;
//}
//
//class Rect {
//public :
//	COORD pos;
//	int w, h;
//
//	Rect operator+(Rect r) { //리턴타입이 클래스이다
//		
//		Rect ret;
//		ret.pos.X = ret.pos.X + r.pos.X;
//		ret.pos.Y = ret.pos.Y + r.pos.Y;
//		ret.h = ret.h + r.h;
//		ret.w = ret.w + r.w;
//		
//		return ret;
//	}
//};
//
//int main() {
//
//	Rect x;
//	x.pos.Y = 100;
//	x.pos.Y = 200;
//	x.h = 300;
//	x.w = 400;
//
//	Rect y;
//	y.pos.Y = 10;
//	y.pos.Y = 20;
//	y.h = 30;
//	y.w = 40;
//
//	Rect z = x+y;
//
//	cout << z.h<<z.pos.X<<z.pos.Y<<z.w << endl;
//
//	return 0;
//}
//
//class shape { //실질적값이 들어있는 베이스 클래스
//public:
//	float m_area;
//};
//
//class shapecalculator { //중복될수있는 함수를 가상함수로써 선언을 하여 각 하위 클래스 내에서 재정의하고 
//public:
//	virtual float getarea() = 0; //면적 구하기 가상함수
//};
//
//class triangle : virtual public shape, virtual public shapecalculator {
//public:
//	float getarea() {
//		//삼각형 계산
//		return m_area;
//	}
//	COORD m_pos[3];
//	triangle operator+(triangle t1) {
//		triangle t2;
//		t2.m_area = t1.m_area + t2.m_area;
//		return t2;
//	}
//
//	triangle operator-(triangle t1) {
//		triangle t2;
//		t2.m_area = t1.m_area - t2.m_area;
//		return t2;
//	}
//	bool operator<(triangle t1) {
//		triangle t2;
//		if (t2.m_area < t1.m_area) {
//		return 1;
//		}
//		else return 0;
//	}
//	bool operator>(triangle t1) {
//		triangle t2;
//		if (t2.m_area > t1.m_area) {
//			return 1;
//		}
//		else return 0;
//	}
//	bool operator==(triangle t1) {
//		triangle t2;
//		if (t2.m_area == t1.m_area) {
//			return 1;
//		}
//		else return 0;
//	}
//
//
//};
//
//class rectangle : virtual public shape, virtual public shapecalculator {
//public:
//	float getarea() {
//		//시각형 계산
//		return m_area;
//	}
//	COORD m_pos[4];
//};
//
//class circle : virtual public shape, virtual public shapecalculator {
//public:
//	float getarea() {
//		//원계산
//		return m_area;
//	}
//	COORD m_pos[2];
//};
//
//int main() {
//
//	triangle t1;
//	t1.m_area = 20.0f;
//	triangle t2;
//	t2.m_area = 30.0f;
//	int x;
//
//	triangle T = t1+t2;
//	cout << T.m_area << endl;
//
//	T = t1 - t2;
//	cout << T.m_area << endl;
//
//	x = t1 < t2;
//	cout << x << endl;
//
//	x = t1 > t2;
//	cout << x << endl;
//
//	x = t1 == t2;
//	cout << x << endl;
//
//
//	getchar();
//
//	return 0;
//}
//
//void Swap(int& aa, int& bb) {//const로 인자를 받아온다면 이 함수안에서 변경해줄수없다
//	int temp = aa;
//	aa = bb;
//	bb = temp;
//}
//
//class AA {
//public:
//	int a;
//};
//
////void test(const AA* a) { //외부에서 먼저 처리하고 가져온다, 가져와서 내부에서는 변경할수없다
////	a->a = 10;
////	cout << a->a << endl;
////}
////
////void test(const AA& a) {
////	a->a = 10;
////	cout << a->a << endl;
////}
//
//int main() {
//
//	AA* x = new AA();
//
//	int a = 10;
//	int& b = a;
//
//	b = 20;
//
//	cout << "레퍼런스: " << a <<" "<< b << endl;
//
//
//	getchar();
//	return 0;
//}
//
//class tri {
//public :
//	tri operator+(tri& a) {
//
//		a.x = x + a.x;
//		a.y = y + a.y;
//
//		return a;
//	}
//	int x, y;
//};
//
//int main() {
//
//	tri T;
//
//	tri R;
//	R.x = 3, R.y = 4;
//	
//	tri I;
//	I.x = 3, I.y = 4;
//
//	T = R + I;
//
//	cout << "트라이값 x : " << T.x << endl;
//	cout << "트라이값 y : " << T.y << endl;
//
//	getchar();
//	getchar();
//	return 0;
//}
//
//#include"AAA.h"
//#include"BBB.h"
//void print(AAA& a) {
//	cout << "Pringt" << endl;
//	cout << a.a << endl;
//}
//
//int main() {
//
//	AAA a;
//
//
//	a.printA();
//	print(a);
//
//	getchar();
//	return 0;
//}
//
//class AAA {
//public : 
//	int a;
//	void PrintA() {
//		cout << this->a << endl;
//	}
//
//	void PrintThis() {
//		cout << this << endl;
//	}
//
//	void SetA(int a) {
//		this->a = a; //this로 클래스 객체 내부의 맴버를 가리켜준다
//	}
//
//	AAA* getThis() {
//		return this; //내자신의 포인터를 참조해야 할때(this는 포인터)
//	}
//};
//
//int main() {
//
//	AAA a;
//	cout << &a << endl;
//
//	a.PrintThis();
//
//	getchar();
//	return 0;
//}
//
//template<typename T1, typename T2, typename T3 >
//T3 Function(T1 a, T2 b, int s) {
//
//	switch (s) {
//	case 1: return a + b; break;
//	case 2: return a - b; break;
//	case 3: return a * b; break;
//	case 4: 
//		if (a >= b) {
//			return a / b;
//		}
//		else {
//			return 0;
//		}
//		break;
//	default : break;
//	}
//}
//
//int main() {
//	int a,b,s;
//	cout << "계산기 실행" << endl;
//	while (1) {
//		cout << "1. +   2. -   3. *   4. /" << endl;
//		cin >> s;
//		cout << "a값 입력" << endl;
//		cin >> a;
//		cout << "b값 입력" << endl;
//		cin >> b;
//		Function(a, b, s);
//
//	}
//	getchar();
//	return 0;
//}
//
//template<typename T, typename T2> //컴파일할때 선언해준 자료형으로 치환된다;
//class AAA {
//	T a;
//	T2 b;
//public : 
//	void SetA(T a) {
//		this->a = a;
//	}
//	T GetA(){
//		return a;
//	}
//};
//
//
//int main() {
//
//	AAA<int,int> a;
//	AAA<float,double> a2;
//	AAA<double,int> a3;
//
//	getchar();
//	return 0;
//}
//
//template<typename T>
//class Node {
//public:
//	Node() {
//		next = NULL;
//		}
//	template<typename T2>
//	void Print(T2 t2) {
//		cout << t2 << endl;
//	}
//
//	void SetData(int data) {
//		this->Data = data;
//	}
//
//	T GetData() {
//		return this->Data;
//	}
//
//	void Append(Node* node) {
//		next = node;
//	}
//private:
//	Node * next;
//	T Data;
//};
//
//int main() {
//	Node<int> node1;
//	node1.SetData(100);
//
//	Node<int> node2;
//	node2.SetData(200);
//	node1.Append(&node2);
//
//
//	Node<int> node3;
//	node3.SetData(300);
//	node2.Append(&node3);
//
//	Node<int> node4;
//	node4.SetData(400);
//	node3.Append(&node4);
//
//	cout << node1.GetData()<< " " << node2.GetData() << " " << node3.GetData() << " " << node4.GetData() << endl;
//
//
//	getchar();
//	return 0;
//}
//
//template<typename T>
//class Calcul {
//public: 
//	T add(T a,T b) {
//		if (sizeof(a) == 1 && sizeof(b) == 1) {
//
//			return 0;
//		}
//		else return a + b;
//	}
//
//	T a;
//	T b;
//};
//
//int main() {
//	Calcul<int> clac;
//	Calcul<float> clac2;
//	Calcul<char> clac3;
//
//
//	cout << "a+b : " << clac.add(10, 20) << endl;
//	cout << "a+b : " << clac2.add(10.1f, 20.2f) << endl;
//	cout << "a+b : " << clac3.add('hel','lo') << endl;
//
//	getchar();
//	return 0;
//}
//
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
//
//class AAA {
//public:
//	AAA(int n) {
//		a = n;
//	};
//	int a;
//};
//
//int main() {
//	vector<AAA> iList;
//	vector<AAA*> iList;
//	for (int i = 0; i < 10; i++)
//	{
//		AAA a(i);
//		AAA* a = new AAA(i);
//		iList.push_back(a);
//		iList.push_back(a);
//	}
//	for (int i = 0; i < iList.size(); i++)
//	{
//		cout << iList[i].a << endl;
//		cout << iList[i]->a << endl;
//	}
//
//	vector<AAA*>::iterator iter = iList.begin();
//	auto iter = iList.begin();
//
//	for (iter; iter != iList.end(); iter++) { //iList의 끝이 날때까지 반복한다;;
//		cout << (*iter)->a << endl;
//	}
//
//	getchar();
//	return 0;
//};
//
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
