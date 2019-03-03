////데코레이터 패턴은 다양한 조합의 기능확장이 요구될때  클래스가 불필요하게 증가하는 문제를 해결하기위해 나왔다.
////클래스가 증가하고 계층구조가 복잡해지는 경우가 생길경우 적용하면 좋다.
//
//#pragma region 데코레이터 패턴
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//#define MAXSIZE 256
//
//using namespace std;
//
//struct Byte {
//	bool bit[8] = {0,};
//};
//
//class FileOut {
//public:
//	FileOut() {};
//	virtual ~FileOut() {};
//
//	void write(Byte data[]) {
//		ifstream stream("text.txt");
//		if (stream.is_open()) {
//			stream >> (char*)data; //그냥 쓰려고
//		}
//		else {
//			cout << "파일을 찾을 수 없습니다!" << endl;
//		}
//		stream.close();
//	}
//};
//
//class Decorator {
//private:
//	FileOut* DELEGATE;
//public:
//	Decorator(FileOut deleg) : DELEGATE(&deleg) {	}
//protected:
//	void DoDelgate(Byte data[]) {
//		DELEGATE->write(data);
//	}
//};
//
//class EncryptionOut : public Decorator {
//private:
//	
//public:
//	EncryptionOut(FileOut* deleg) : Decorator(* deleg) {};
//
//	void write(Byte data[]) {
//		this->Decorator::DoDelgate(encrypt(data));
//	}
//	
//	Byte* encrypt(Byte data[]) {
//
//		int dataLength = sizeof(data) / sizeof(Byte);
//
//		Byte ret[MAXSIZE] = { 0, };
//
//		for (int i = 0; i < MAXSIZE; i++)
//		{
//			if (i <= dataLength) {
//
//				ret[i] = data[i];
//
//				for (int j = 0; j < 8; j++)
//				{
//					ret[i].bit[i] = !ret[i].bit[i]; //아무튼 암호화임....;;
//				}
//			}
//		}
//
//		return ret;
//	}
//};
//
//class FileOutImpl : public FileOut {};
//
//class ZipOut :public Decorator {
//public:
//	ZipOut(FileOut* deleg) : Decorator(*deleg) {};
//};
//
//class BufferedOut : public Decorator {
//public:
//	BufferedOut(FileOut* deleg) : Decorator(*deleg) {};
//};
//
//void MethodExcutionRules() {
//	Byte data[MAXSIZE] = { 0, };
//
//	FileOut* DEL = (FileOut*)new FileOutImpl();
//	FileOut* fileOut = (FileOut*) new EncryptionOut(DEL);
//	fileOut->write(data);
//
//	//데이터를 압축한뒤에 암호화를 해서 파일에 쓰고싶다면 다음과같이 두개의 데코레이터 객체를 조합하면 된다.
//	FileOut* DEL = (FileOut*)new FileOutImpl();
//	FileOut* fileOut = (FileOut*) new EncryptionOut((FileOut*)new ZipOut(DEL));
//	fileOut->write(data);
//
//	//버퍼 -> 암호화 -> 압축 -> 파일쓰기
//	FileOut* DEL = (FileOut*)new FileOutImpl();
//	FileOut* fileOut = (FileOut*) new BufferedOut((FileOut*)new EncryptionOut((FileOut*)new ZipOut(DEL)));
//	fileOut->write(data);
//
//	//암호화 -> 압축 -> 버퍼 -> 파일쓰기
//	FileOut* DEL = (FileOut*)new FileOutImpl();
//	FileOut* fileOut = (FileOut*) new EncryptionOut((FileOut*)new ZipOut((FileOut*)new BufferedOut(DEL)));
//	fileOut->write(data);
//}
//
//
////데코레이터 패턴은  전략패턴 / 템플릿메서드패턴/ 상태패턴과 매우 흔하게 사용되는 패턴이라 한다.
//
//#pragma endregion
