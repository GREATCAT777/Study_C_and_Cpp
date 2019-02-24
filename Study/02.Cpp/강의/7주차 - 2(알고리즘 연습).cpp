//#include<iostream>
////#include<vector>
//
//#define MAX 4
//using namespace std;
//
////
////class a_Queue {
////
////};
////
////class a_Queue {
////
////};
////
////int main() {
////
////	getchar();
////	return 0;
////}
//
////구현하기 나름이지만, queue와 달리 Circular Queue는 rear, front를 모두 0으로 넣고 시작한다.
//int rear = 0;
//int front = 0;
//int Q[MAX];
//
////함수 선언
//bool isFull();
//bool isEmpty();
//void enQueue(int item);
//int deQueue();
//
////삽입
//void enQueue(int item)
//{
//	if (isFull())
//	{
//		cout << "Queue is Full" << endl;
//		exit(1);
//	}
//	else//mod 연산 사용(나누기의 나머지 값을 가져가 쓰는것)
//	{
//		rear = (rear + 1) % MAX;
//		Q[rear] = item;
//	}
//}
//
////삭제
//int deQueue()
//{
//	if (isEmpty())
//	{
//		cout << "Queue is Empty" << endl;
//		exit(1);
//	}
//	else 
//		//mod 연산 사용
//	{
//		front = (front + 1) % MAX;
//		return Q[front];
//	}
//}
//
//
////Empty 확인
//bool isEmpty()
//{
//	if (front == rear)
//		return true;
//	else return false;
//}
//
//
//
////Full 확인
//bool isFull()
//{
//	//일반 Queue와 다른 Full 조건
//	if ((rear + 1) % MAX == front)
//		return true;
//	else
//		return false;
//}
//
//
//
//
////메인
//
//int main(void)
//{
//	cout << "enQueue: ";
//	for (int i = 1; i < MAX; i++)
//	{
//		cout << i<< " ";
//		enQueue(i);
//	}
//	
//	cout << endl<< "Dequeue: ";
//
//	for (int i = 1; i < MAX; i++)
//	{
//		cout << deQueue() << " ";
//	}
//
//	getchar();
//	return 0;
//}