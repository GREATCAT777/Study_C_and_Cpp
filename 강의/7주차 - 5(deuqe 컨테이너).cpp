//#include<iostream>
//#include<deque>
//#include<algorithm>
//#include<list>
//
//using namespace std;
//
//int main() {
//	deque<int> dq;
//
//	for (int i = 0; i < 10; i++)
//	{
//		dq.push_back((i + 1) * 10);
//	}
//
//	deque<int>::iterator iter;
//
//	cout << "Default : ";
//	for (iter = dq.begin(); iter != dq.end(); iter++) {
//		cout << *iter << " ";
//	}
//
//	cout << endl << endl;
//
//	cout << "test1:  push_front & back : ";
//
//	dq.push_front(1);
//	dq.push_front(2);
//	dq.push_back(100);
//	dq.push_back(200);
//
//	for (iter = dq.begin(); iter != dq.end(); iter++) {
//		cout << *iter << " ";
//	}
//
//	cout << endl;
//
//	cout << "test2 : reverse_iterator : ";
//	deque<int>::reverse_iterator riter;
//
//	for (riter = dq.rbegin(); riter != dq.rend(); riter++) {
//		cout << *riter << " ";
//	}
//
//	cout << endl;
//
//	cout << sizeof(dq) << endl;
//	cout << sizeof(iter) << endl;
//	cout << sizeof(riter) << endl;
//
//	getchar();
//	return 0;
//}