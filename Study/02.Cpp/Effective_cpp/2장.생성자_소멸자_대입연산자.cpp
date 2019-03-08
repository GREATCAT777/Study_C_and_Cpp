#include <iostream>
#include <vector>
#include <string>

using namespace std;

#pragma region 4.cpp가 은근 슬쩍 만들어 호출해 버리는 함수들에 촉각을 세우자

class Empty {
//public:
	//Empty() {}
	//Empty(const Empty&) {}; //복사 생성자
	//~Empty() {}
	//Empty& operator = (const Empty&) {} //대입연산자

	//만약 아무것도 없는 빈 클래스를 선언했다면 위 4항목이 자동적으로 생성되었을것이다.
};

void 예제() {
	Empty e1;

	Empty e2(e1);

	e2 = e1;
	//에러 없음!! 너무나도 친절한 그대여..... 조금만.... 엄격해주시길....
}

//★컴파일러는 경우에 따라 클래스에 대해 기본 생성자, 복사 생성자,
//  복사 대입 연산자, 소멸자를 암시적으로 만들어 놓을 수 있습니다.


#pragma endregion

#pragma region 5.컴파일러가 만들어낸 함수가 필요없으면 확실히 이들의 사용을 금해버리자

class Uncopyable {

public:
	Uncopyable() {}
	~Uncopyable() {}

private:							//대입연산자와 복사생성자는 private영역으로 보호하고 객체 복사의 방지역할을 한다.
	Uncopyable(const Uncopyable&);
	Uncopyable& operator = (const Uncopyable&);  //private영역에 선언만 달랑 해놓자
};

//이제 복사를 원치않는 클래스는 이 녀석의 파생클래스로 만들어주면 된다.

class Unique : private Uncopyable {
	// 이렇게 private로 상속받게만 하면 끝이다!
	// 복사 생성자도, 복사대입 연산자도 이제는 선언되지 않는다.!
};

//★컴파일러에서 자동으로 제공하는 기능을 허용치 않으려면, 대응되는 맴버 함수를 private로 선언한 후에 구현은 하지말자!

#pragma endregion

#pragma region 6.다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자

class TimeKeeper {
public:
	TimeKeeper() {};
	virtual ~TimeKeeper() {}; //아래의 상황꼴이 나지 않으려면 꼭꼭꼭꼭꼭 소멸자에 virtual을 붙여두도록하자

	virtual TimeKeeper* getTimeKeeper() {		//TimeKeeper에서 파생된 클래스를 통해 동적으로 할당된 객체의 포인터를 반환 
		return this;
	}
};

class AtomicClock :public TimeKeeper {};
class WaterClock :public TimeKeeper {};
class WristWatch :public TimeKeeper {};

//getTimeKeeper()로 받아온 포인터가 파생 클래스 객체에 대한 포인터라는점, 이 포인터가 가리키는 객체가
// 삭제될 때에는 기본클래스 포인터에 들어있는 소멸자가 비가상소멸자(virtual이 붙지않은 소멸자)라는 점
//-기본 클래스의 포인터를 통해 파생클래스 객체가 삭제될 때는 그 기본 클래스에 비가상 소멸자가 들어있으면 
//	프로그램의 동작은 미정의 사항이라고 되어있다 한다.

//저렇게 기본클래스로 객체를 삭제할때 파생클래스의 데이터는 사라지지 않고 소멸자도 호출되지 않는다.
//기본 클래스의 부분은 소멸과정이 제대로 끝나버려서 어딘가에 데이터가 남게된다.(부분 소멸 : partial destroyed)




class SpecialString :public string {
	//뭔.... ㅋㅋㅋㅋㅋㅋㅋ string은 가상소멸자가 존재하지않는다.
	//이렇게 쓰지도 말고 쓸 생각도 하지말자
	//ps. cpp에서 지원하는 STL 컨테이너 타입 전부가 가상소멸자가 존재하지 않는다.

	//cpp에는 C#의 sealed나 JAVA의 final 상속제약 예약어가 없다.

	// 두번 말한다. 하지말자
};


//경우에 따라서 순수 가상소멸자를 두면 편할때가 있다고한다.
// 추상클래스를 만들어 주고싶은데 마땅히 넣을만한 순수가상함수가 없을때

class 특별ㅇㅇ {
public:
	virtual ~특별ㅇㅇ() = 0;// 자 이제 이클래스는 기본클래스이자 추상클래스이다!
							// 다른 건덕지(순수가상함수)가 없다!
							// 문제점 - 상속받은 파생클래스에서 이녀석을 정의해주어야한다.... 젠장!
};

//★★★ 정리
// - 다형성을 가진 기본 클래스에는 반드시 가상 소멸자르 선언해야합니다. 즉, 어떤 클래스가 가상 함수를 하나라도
//	가지고있다면 ,이 클래스의 소멸자도 가상 소멸자여야합니다.
// - 기본클래스로 설계되지 않았거나 다형성을 갖도록 설계되지 않은 클래스에는 가상 소멸자를 선언하지 말아야 합니다.

// ★파생클래스의 객체를 기본포인터로 삭제할때를 대비하기위해서 가상함수가 하나라도 존재하면 소멸자에 virtual을 붙여주자.

#pragma endregion

#pragma region 7.예외가 소멸자를 떠나지 못하도록 붙들어놓자

class DBConnection {
public:
	DBConnection create() { return *this; };		//DBConnection객체를 반환하는 함수
	void close() const { printf("닫혔냐?!"); };		//연결을 닫습니다. 실패하면 예외를 던집니다.
};

class DBConn {
private:
	DBConnection db;
public:
	~DBConn() {

		try { db.close(); }
		catch (...) {
			printf("야!! 안닫혔잖아!!!"); //close 호출이 실패했다는 로그를 작성한다.
			abort();	/*			https://docs.microsoft.com/ko-kr/cpp/cpp/abort-function?view=vs-2017	참고해야*/
		}
		
		//close에서 예외가 발생하면 바로 프로그램 강종시켜버리거나
		// 예외를 삼켜버리거나 둘중하나로 예외를 던지는 소멸자를 피하자
	}
};

class DBConn2 {
private:
	DBConnection db;
	bool closed;
public:
	~DBConn2() {

		if (closed) {
			try {	db.close();	}				//사용자가 연결을 안닫았으면 여기서 닫아보자.
			catch (...) {						//연결을 닫다가 실패하면, 실패를 알린후에 예외를 삼킨다!
				printf("야!! 안닫혔잖아!!!"); 
			}
		}
	}

	void close() {
		db.close();
		closed = true;
	}
};

//★★★ 정리
// - 소멸자에서 예외가 바져나가면 안 됩니다. 만약 소멸자 안에서 호출된 함수가 예외를 던질 가능성이 있다면,
//		어떤 예외 이든지 소멸자에서 모두 받아낸후에 삼켜버리던지 프로그램을 끝내든지 해야합니다.
// - 어떤 클래스의 연산이 진행되다가 던진 예외에 대해 사용자가 반응해야 할 필요가 있다면,
//		해당 연산을 제공하는 함수는 반드시 보통의 함수(소멸자가 아닌 함수)이어야 합니다.

#pragma endregion

#pragma region 8.객체 생성 및 소멸 과정 중에는 "절대로" 가상함수를 호출하지 말자

class Transaction {
public:
	Transaction() {
		logTransaction();
	};
	virtual void logTransaction() const = 0;// 파생 클래스에서 타입에 따라 달라지는 로그기록을 작성
};

class BuyTransaction :public Transaction {
public:
	virtual void logTransaction() const {
		//구입거래 내역로그 기록
	}
};

class SellTransaction :public Transaction {
public:
	virtual void logTransaction() const {
		//판매거래 내역로그 기록
	}
};



//기본클래스의 생성자가 호출될때에는 가상함수는 절대로 파생클래스 쪽으로 내려가지 않는다.

//기본클래스 생성자가 호출되는 시점에 파생클래스 데이터 맴버는 아직 초기화된 상태가 아니라는 점이다.

//파생클래스객체의 기본클래스 부분이 생성되는 동안 그 객체의 타입은 기본 클래스이다.

//실수라도 생성자 영역에서 호출되는 함수들에 가상함수를 포함시키지 말자!


//해결법

class Transaction2 {
public :
	explicit Transaction2(const string& LogInfo) {
		logTransaction(LogInfo);
	};

	void logTransaction(const string& LogInfo) const {};
};

class BuyTransaction2 :public Transaction2 {
private:
	static string createLogString(string param) { // 기본 클래스 생성자 쪽으로 넘길값을 생성하는 도우미 정적 함수
		return param;
	};
public:
	BuyTransaction2(string param) :Transaction2(createLogString(param)){
		//로그 정보를 기본클래스 생성자로 넘긴다.
		// "미초기화된 데이터 맴버는 정의되지 않은 상태에 있다"
	};
};

// ★★★ 정리
// - 생성자 혹은 소멸자 안에서 가상함수를 호출하지 말자.
//	가상함수라 해도 지금 실행 중인 생성자나 소멸자에 해당되는 클래스의 파생클래스 쪽으로 내려가지 않기때문이다.

#pragma endregion

#pragma region 9. 대입 연산자는 *this 참조자를 반환 하게하자

// 여기까지!

#pragma endregion