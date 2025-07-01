//★SOLID 설계원칙

#pragma region  단일 책임 원칙 (Single responsibility principle)

//- 클래스는 단 한 개의 책임을 가져야한다.
//- 클래스를 변경하는 이유는 단 한 개여야 한다.
//
//class Car1 {
//private:
//	char* serialNumber;
//	double price;
//	char* type;
//	char* maker;
//	char* model;
//	int capacity;
//public:
//	Car1(char* serialNumber, double price, char* type, char* maker, char* model, int stringNum)
//		:serialNumber(serialNumber), price(price), type(type), maker(maker), model(model), capacity(capacity) {}
//};
//
//class Car2 {
//private:
//	CarSpec spec;
//	char* serialNumber;
//public:
//	Car2(char* serialNumber, CarSpec spec) :serialNumber(serialNumber), spec(spec) {	}
//};
//
//class CarSpec {
//	double price;
//	char* type;
//	char* maker;
//	char* model;
//	int capacity;
//};

//Car1,Car2 둘중 누가 더 편히 보인다 생각하면 편할것이다.

#pragma endregion

#pragma region 개방-폐쇄 원칙(Open-closed principle)

//- 확장에는 열려있어야하고, 변경에는 닫혀 있어야한다.
//- 기능을 변경하거나 확장할수있으면서
//- 그 기능을 사용하는 코드는 수정하지않는다.
//
//class Sender {
//private:
//	int data;
//public:
//	Sender(int data) :data(data) {}
//	int getData() { return data; }
//
//	void Send() {
//		SendHeader();
//		SendBody();
//	}
//protected:
//	virtual void SendHeader() { /*헤더 데이터 전송*/ }
//	virtual void SendBody() { /*텍스트로 데이터 전송*/ }
//};
//class ZippedSender :public Sender {
//private:
//	ZippedSender(int data) :Sender(data) {}
//	void SendBody() override final {
//		//데이터 압축처리
//	}
//};

//ps) 상위클래스의 함수를 재정의하여 쓸때 protected 공개범위 예약어를 붙여주자

//이 원칙이 깨질때의 주요 증상
//-> 다운캐스팅을 한다.
//-> 비슷한 if-else 블록이 존재한다.

//결론 : 변화가 예상되는것을 추상화해서 변경의 유연함을 얻도록하자
#pragma endregion

#pragma region 리스코프 치환 원칙 (Liskov soubstitution principle)

//-상위타입의 객첼를 하위 타입의 객체로 치환해도 상위타입을 사용하는 프로그램은 정상적으로 동작해야한다.

//ex) 직사각형과 정사각형을 클래스 단위의 개념으로 생각하보았을때 
//정사각형은 직사각형을 상속받아 구현하는것이 합리적으로 보이지만
//실질적으로는 별개의 클래스로 구현하여 관리하는게 좋다.

//위반사례
//->명시된 명세에서 벗어난 값을 리턴한다.
//->명시된 명세에서 벗어난 exception를 발생한다.
//->명시된 명세에서 벗어난 기능을 수행한다.

//-리스코프 치환 원칙은 "확장"에 관한것
//변화되는 기능을 상위 타입에 추가 -> 하위 클래스에서 알맞게 오버라이딩

#pragma endregion

#pragma region 인터페이스 분리 원칙 (Interface segregation principle)

//인터페이스는 그 인터페이스를 사용하는 클라이언트를 기준으로 분리해야한다.
//협업과정에서 하나의 헤더파일에 의존하고있다면 그 헤더를 분리하여 관리하는게 좋다.
//하나의 헤더에서 변경사항이 요구되었을 경우 다른 헤더를 다시 컴파일 하지않아도 되는 장점이있다.

#pragma endregion

#pragma region 의존 역전 원칙 (Dependency inversion principle)

//- 고수준 모듈은 저수준 모듈의 구현에 의존해서는 안된다. 저수준 모듈이 고수준 모듈에서 정의한 추상타입에 의존해야한다.

//고수준 모듈 : 바이트 데이터를 읽어와 암호화하고 결과 바이트 데이터를 쓴다.
//저수준 모듈 : 파일에서 데이터를 읽어온다. AES알고리즘응로 암호화한다. 파일에 바이트 데이터를 쓴다.

//- 의존역전 원칙을 통한 변경의 유연함 확보
//고수준 저수준 모두 추상타입에 의존하게끔 구현

//- 소스코드 의존과 런타임 의존
//- 의존 역전 원칙은 런타임의 의존이 아닌 소스코드의 의존을 역전 시킴으로써
//변경의 유연함을 확보할수있도록 만들어주는 원칙

#pragma endregion

//솔직히 의존 역전 원칙은 아직 잘 모르겠다. 두고두고 봐야지

