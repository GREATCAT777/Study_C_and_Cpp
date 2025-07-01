//#include<iostream>
//
//using namespace std;
//
//class Server {
//public:
//	Server() { Ping = 0; }
//	int Ping; 
//	int Printping() {return Ping;}
//};
//
//
//
//
//class Player1 : public Server {
//public:
//	Player1() { level = 1, Ping1 = 100; }
//	int level,Ping1;
//	int Sendping() { return Ping1; }
//	void RePing() {
//
//		cout << "핑1 재설정 : ";
//		cin >> Ping1;
//	}
//};
//
//class Player2 : public Server {
//public:
//	Player2() { level = 99, Ping2 = 200; }
//	int level, Ping2;
//
//	int Sendping() { return Ping2; }
//
//	void RePing() {
//		cout << "핑2 재설정 : ";
//		cin >> Ping2;
//	}
//};
//
//int main() {
//	Player1  p1;
//	Player2  p2;
//	Server sv;
//
//	cout << "p1의 Ping1 : " << p1.Ping1 << endl;
//	cout << "p2의 Ping2 : " << p2.Ping2 << endl;
//	cout << "p1의 Ping : " << p1.Ping << endl;
//	cout << "p2의 Ping : " << p2.Ping << endl;
//
//	p1.RePing();
//	p2.RePing();
//	
//
//	cout << "p1의 Ping1 : " << p1.Ping1 << endl;
//	cout << "p2의 Ping2 : " << p2.Ping2 << endl;
//	cout << "p1의 Ping : " << p1.Ping << endl;
//	cout << "p2의 Ping : " << p2.Ping << endl;
//
//	getchar();
//	getchar();
//	return 0;
//}