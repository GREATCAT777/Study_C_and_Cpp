#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma region 17.인터페이스 설계는 제대로 쓰기엔 쉽게, 엉터리로 쓰기엔 어렵게 하자

struct Day_s
{
	explicit Day_s(int d) :val(d) {}
	int val;
};
struct Month_s
{
	explicit Month_s(int d) :val(d) {}
	int val;
};
struct Year_s
{
	explicit Year_s(int d) :val(d) {}
	int val;
};

class Date {
private:
	int month;
	int day;
	int year;

private:
	Date(int month, int day, int year):month(month), day(day), year(year){}
	//이렇게 말고

public:
	Date(const Month_s& month, const Day_s& day, const Year_s& year) :month(month.val), day(day.val), year(year.val) {}
	//이렇게 하자
}; 

class Month_c { //이런 방법도 좋다.
private:
	int val;
private:
	explicit Month_c(int val){}
	// 새로운 클래스로 struct를 반환하는게 아닌 Date 생성자에 클래스를 집어넣는것으로 하자
	// ps) 솔직히 _c _s 보기 불편하니 떼버리고 정적 함수 호출하는 방향으로 가는게 보기 편하다.
public:
	static Month_s Jan() { return Month_s(1); }
	//...
	//...
	static Month_s Dec() { return Month_s(12); }
};


void exam() {
	Date d(Month_c::Jan(), Day_s(30), Year_s(1995)); // 보기편하구먼!
}




class Investment{}; //전장에서 했던것들 기억하나?

Investment* createInvestment(); //이젠 이렇게 말고

shared_ptr<Investment> CreateInvestment();  //애초부터 팩토리 함수에서 스마트 포인터를 반환하는게 좋다!
											//애초에 shared_ptr에 넣어둘수밖에없고 나중에 객체를 삭제하는걸 깜빡하고 넘어갈 일도 없다!




//★★★ 정리
// - 좋은 인터페이스는 제대로 쓰기에 쉬우며 엉터리로 쓰기에 어렵다. 인터페이스를 만들때에는 이 특성을 담을수있게 고민하자
// - 인터페이스의 올바른 사용을 이끄는 방법으로는 인터페이스 사이의 일관성 잡아주기, 기본 제공 타입과의 동작 호환성 유지하기 가 있다.
// - 사용자의 실수를 방지하는 방법으로는 새로운 타입만들기, 타입에 대한 연산을 제한하기,객체의 값에대해 제약걸기,, 자원 관리 작업을 사용자 책임으로 놓지않기가 있다.
// - shared_ptr는 사용자 정의 삭제자를 지원한다. 떄문에 교차 DLL 문제를 막고, 뮤텍스등을 자동으로 잠금 해제하는데 쓸수있다.

#pragma endregion

#pragma region 18. 클래스 설계는 타입 설계와 똑같이 취급하자

//cpp에서 새로운 클래스를 설계한다는것은 새로운 타입을 하나 정의 하는것과 같다.

//효과적인 클래스를 설계할때 고려해야 하는점

// 1  - 새로 정의한 타입의 객체 생성 및 소멸은 어떻게 이루어져야 하는가? (8장 참조)
//			생성자,소멸자의 설계가 정해진다. 메모리 할당함수를 직접 작성할 경우에는 이들함수의 설계에도 영향을 미친다.

// 2  - 객체 초기화는 객체 대입과 어떻게 달라야 하는가? ( 항목 3 참조)
//			초기화와 대입에 해당되는 함수 호출이 아예 다르다. 헷갈리지 말자

// 3  - 새로운 타입으로 만든 객체가 값에 의해 전달되는 경우에 어떤 의미를 줄것인가?
//			어떤 타입에 대해 "값에 의한 전달"을 구현하는 쪽은 "복사 생성자" 이다.

// 4  - 새로운 타입이 가질 수 있는 적법한 값에 대한 제약은 무엇으로 잡을 것인가?
//			클래스 데이터 맴버의 몇 가지 조합 값만은 반드시 유효해야한다.  이런 조합을 가리켜 불변속성이라하며 클래스 차원에서 지켜주어야하는 부분이다.
//			생성자, 대입 연산자 각종 "쓰기(setter)"함수는 불변속성에 많이 좌우된다.

// 5  - 기존의 클래스 상속 계통망에 맞출것인가?
//			기존 클래스에서 상속을 한다면 상위 클래스에 제약을 받게된다.
//			맴버가 함수가 Virtual인지 아닌지의 여부가 가장 큰 요인이다.( 항목 33 및 35 참조)
//			우리가 만든 클래스를 다른 클래스에서 상속한다면 맴버 함수의 Virtual 함수 여부가 결정된다. 특히 소멸자 ( 항목6 참조)

// 6  - 어떤 종류의 타입 변환을 허용할것인가?
//			우리가 만든 클래스는 다른 클래스와 섞여 사용해야한다. 따라서 타입변환을 고려한다면
//			암시적으로 타입을 변환 되도록 만들고 싶으면 기존 클래스에 타입 변환 함수를 하나 넣어주던가
//			인자 한개로 호출될수있는 비명시 호출 생성자를 만들어주자.
//			명시적으로 변환을 원한다면 해당 변환을 맡은 별도의 이름의 함수를 만들되 타입 변환 연산자 혹은
//			비명시호출 생성자는 만들지말아야한다. ( 항목 14에서 참조)

// 7  - 어떤 연산자와 함수를 두어야 의미가 있을까? ( 항목 22,23,45 참조)
//			어떤것들은 맴버 함수로 적당하고, 또 몇몇은 그렇지 않다. 스스로 생각해보자.

// 8  - 표준 함수들 중 어떤것을 허용하지 말 것인가? (항목 5 참조)
//			private로 선언해야 하는 함수

// 9  - 새로운 타입의 맴버에 대한 접근권한을 어느쪽에 줄 것인가?
//			어떤 클래스 맴버를 public. protected, private영역에 둘것인가 생각하자
//			또한 friend로 만들어야 할 클래스 및 함수를 정하는것은 물로이고 한클래스를 다른 클래스에 중첩시켜도 되는가에 대한 결정을 내릴때 생각해보자

// 10 - '선언되지 않은 인터페이스'로 무엇을 둘 것인가?
//			우리가 만들 타입이 제공할 보장이 어떤 종류일까에 대한 질문으로서, 보장할 수 있는 부분은 수행 성능 및 예외 안전성(항목 28 참조)
//			그리고 자원 사용(잠금 및 동적 메모리 등)이다. 이들에대해 우리가 보장하겠다고 결정한 결과는 클래스 구현에 있어 제약으로 작용된다.

// 11 - 새로 만드는 타입이 얼마나 일반적인가?
//			실상은 타입 하나를 정의하는 것이 아닐지도 모른다. 우리가 정의하는 것이 동일 계열의 타입군(family of types) 전체 일지도 모른다.
//			그렇다면 우리는 새로운 '클래스'가 아닌 새로운 '클래스 템플릿'을 정의 해야한다.

// 12 - 정말로 꼭 필요한 타입인가?
//			기존 클래스에 대해 기능 몇개가 아쉬워서 파생 클래스를 새로 뽑고 있다면 , 차라리 간단하게 비맴버 함수라던가 템플릿을 몇개 더 정의하자.


//★★★ 정리
//	- 클래스 설계는 타입설계다. 새로운 타입을 정의 하기 전에, 위 항목의 고려사항을 빠짐없이 점검해보자.

#pragma endregion

#pragma region 19."값에 의한 전달"보다는 "상수 객체 참조자에 의한 전달"방식을 택하는 편이 대개 낫다.

class Person {
private:
	string name;
	string address;
public:
	Person() {};
	virtual ~Person() {};
};
class Student :public Person {
private:
	string schoolName;
	string schoolAddress;
public:
	Student() {};
	~Student() {};
};

bool balidateStudent(Student s) {};
//이대로 들어가면 Student 복사생성자 1번, Person 복사생성자 1번, string 복사생성자 4번이 추가적으로 불린다.
// 소멸자는? 저만큼 들어간다. ㅇㅇ 진짜

bool balidateStudent(const Student& s) {};
//복사 손실문제 해결이 된다.
//파생클래스가 기본클래스 객체로서 전달되는 경우에는 기본 클래스의 복사생성자가 호출되고,
//파생클래스 객체로 동작하는 부분이 잘려 떨어지게된다.


//STL의 반복자와 함수객체에도 마찬가지이다.
// 반복자와 함수객체를 구현할때에는 반드시 "복사 효율을 높일 것" , "복사 손실 문제에 노출되지 않도록 만드는것이 필수이다."


//★★★ 정리
// - "값에 의한 전달" 보다는 "상수객체 참조자에 의한 전달"을 선호하자. 효율적이고, 복사손실문제도 막아준다.
// - 기본제공타입, STL반복자, 함수객체 타입에는 "값에 의한 전달" 방식을 차용하자.

#pragma endregion

#pragma region 20. 함수에서 객체를 반환해야 할 경우에 참조자를 반환하려고 들지 말자.

class Rational {
private:
	int n, d;
	friend const Rational operator*(const Rational& lhs, const Rational& rhs);
public:
	Rational(int numerator = 0, int denominator = 1) :n(numerator), d(denominator) {};
};

//연산자 오버로딩의 문제에서 새로운 객체를 반환해야할때
inline const Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}

//반환값을 생성하고 소멸시키는 비용이 들지만 올바른 동작에 들어가는 비용이다.

//★★★ 정리
// - 지역 스택 객체에 대한 포인터난 참조자를 반환하는 일, 혹은 힙에 할당된 객체에 대한 참조자를 반환하는일,
//	또는 지역 정적 객체에 대한 포인터나 참조자를 반환하는 일은 그런 객체가 두개 이상 필요해질 가능성이 있다면
//	절대로 하지말자.(항목 3 참조 - 지역 정적 객체에 대해 참조자를 반환하도록 설계된 올바른 예제가 있다.)

#pragma endregion


