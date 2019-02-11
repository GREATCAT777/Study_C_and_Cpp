//#include<iostream>
//#include<conio.h>
//#include<Windows.h>
//
//using namespace std;
//
//#define MAX 4
//
//class Circle {
//public:
//	Circle() {
//		rear = 0;
//		front = 0;
//		for (int i = 0; i < MAX + 1; i++) {
//			enQueue(i);
//		}
//	}
//	int rear;
//	int front;
//	int Q[MAX];
//
//	void enQueue(int insert)
//	{
//		if (isFull())
//		{
//			cout << "Queue is Full" << endl;
//			exit(1);
//		}
//		else//mod 연산 사용(나누기의 나머지 값을 가져가 쓰는것)
//		{
//			rear = (rear + 1) % MAX;
//			Q[rear] = insert;
//		}
//	}
//
//	int deQueue()
//	{
//		if (isEmpty())
//		{
//			cout << "Queue is Empty" << endl;
//			exit(1);
//		}
//		else
//			//mod 연산 사용
//		{
//			front = (front + 1) % MAX;
//			return Q[front];
//		}
//
//	}
//
//	bool isEmpty()
//	{
//		if (front == rear)
//			return true;
//		else return false;
//	}
//
//	bool isFull()
//	{
//		//일반 Queue와 다른 Full 조건
//		if ((rear + 1) % MAX == front)
//			return true;
//		else
//			return false;
//	}
//};
//
//void MoveCw(Circle* c) {
//	int tmp = c->Q[MAX];
//	for (int i = 0; i < MAX-1; i++)
//	{
//		c->Q[i] = c->Q[i + 1];
//	}
//	c->Q[0] = tmp;
//}
//
//void MoveCCw(Circle* c) {
//	int tmp = c->Q[0];
//	for (int i = MAX; i > 0 ; i--)
//	{
//		c->Q[i - 1] = c->Q[i];
//	}
//	c->Q[MAX] = tmp;
//}
//
//void Insertmid(Circle* L, Circle* R, int insert) {
//	L->Q[0] = insert;
//	R->Q[0] = insert;
//}
//
//void LCW_rot(Circle* L, Circle* R) {
//	MoveCw(L);
//	R->Q[0] = L->Q[0];
//}
//
//void LCCW_rot(Circle* L, Circle* R) {
//	MoveCCw(L);
//	R->Q[0] = L->Q[0];
//}
//
//void RCW_rot(Circle* L, Circle* R) {
//	MoveCw(R);
//	R->Q[0] = L->Q[0];
//}
//
//void RCCW_rot(Circle* L, Circle* R) {
//	MoveCCw(R);
//	R->Q[0] = L->Q[0];
//}
//
//void ShowCur(Circle* L, Circle* R) {
//	cout << "L원 배열 : ";
//	for (int i = 0; i < MAX + 1; i++) {
//		cout << L->Q[i] << " ";
//	}
//	cout<< endl << "L원 배열 : ";
//	for (int i = 0; i < MAX + 1; i++) {
//		cout << R->Q[i] << " ";
//	}
//}
//
//int main() {
//	Circle* L = new Circle;
//	Circle* R = new Circle;
//
//	for (int i = 0; i < MAX+1; i++) {
//		L->enQueue(i);
//	}
//	for (int i = 5; i < MAX + 6; i++) {
//		R->enQueue(i);
//	}
//
//	ShowCur(L, R);
//
//	
//
//	getchar();
//	getchar();
//
//	delete(L);
//	delete(R);
//	return 0;
//}