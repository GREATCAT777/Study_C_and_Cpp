//#include<iostream>
//
//using namespace std;
//
//template<typename G> //기능은 정해져 있으나 자료형이 정해져있지 않음
//
//void Swaptemp(G &num1, G &num2) { //함수 템플릿{ 참조자(T) 를 이용한 참조에 의한 호출 }
//	G temp = num1;
//	num1 = num2;
//	num2 = temp;
//}
//
//template<typename T>
//
//class Data { //클래스 템플릿
//private:
//	T data;
//public:
//	Data(T x) {
//		data = x;
//	}
//	void ShowInfo() {
//		cout << data << endl;
//	}
//};
//
//int main() {
//	int a = 1, b = 2;
//	cout << "a = " << a << " b = " << b << endl;
//	Swaptemp(a, b);
//	cout << "a = " << a << " b = " << b << endl;
//
//	float c = 13.4f, d = 17.5f;
//	cout << "c = " << c << " d = " << d << endl;
//	Swaptemp(c, d);
//	cout << "c = " << c << " d = " << d << endl << endl;
//
//	Data<int> data1(50); ///클래스 템플릿을 사용하면 자료형을 선언해주어야 한다
//	data1.ShowInfo();
//
//	Data<char> data2('A');
//	data2.ShowInfo();
//
//	Data<double> data3(24.377);
//	data3.ShowInfo();
//
//
//	getchar();
//
//	return 0;
//}
//
////{
////	함수 템플릿 = 함수를 만드는데 사용되는 템플릿;
////	템플릿 함수 = 템플릿 기반으로 만들어진 함수;
////
////	클래스 템플릿 = 클래스를 만드는데 사용되는 템플릿;
////	템플릿 클래스 = 템플릿 기반으로 만들어진 클래스;
////}