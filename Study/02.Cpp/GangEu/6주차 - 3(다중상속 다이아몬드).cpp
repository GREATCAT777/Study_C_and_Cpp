//#include<iostream>
//
//using namespace std;
//
//class Animal {
//private:
//	int weight;
//public:
//	Animal() { weight = 0; }
//	int getWeight() { return weight; }
//};
//
//class Tiger : public Animal {public: int T_claw; void printAdress() { cout << "address : " << this << endl; }	};
//class Lion : public Animal { public: int L_claw; void printAdress() { cout << "address : " << this << endl; }	};
//class Liger : public Tiger, public Lion { int liger_teeth; };
//
//int main() {
//	Liger lg;
//	cout << "Animal 사이즈 : "<< sizeof(Animal) << endl;
//	cout << "Tiger 사이즈 : " << sizeof(Tiger) << endl;
//	cout << "Lion 사이즈 : " << sizeof(Lion) << endl;
//	cout << "Liger 사이즈 : " << sizeof(Liger) << endl;
//
//
//
//	/*cout << "Tiger 주소 : " << lg.Tiger::printAdress << endl;
//	cout << "Lion 주소 : " << lg.Lion::printAdress<< endl;
//	cout << "Lion 주소 : " << lg.printAdress << endl;*/
//
//	lg.Tiger::printAdress();
//	lg.Lion::printAdress();
//
//	cout << "Liger의 몸무게 : " << lg.Tiger::Animal::getWeight() << endl;
//
//	getchar();
//	return 0;
//}