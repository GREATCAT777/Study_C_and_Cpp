//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//#pragma region 17.인터페이스 설계는 제대로 쓰기엔 쉽게, 엉터리로 쓰기엔 어렵게 하자
//
//struct Day_s
//{
//	explicit Day_s(int d) :val(d) {}
//	int val;
//};
//struct Month_s
//{
//	explicit Month_s(int d) :val(d) {}
//	int val;
//};
//struct Year_s
//{
//	explicit Year_s(int d) :val(d) {}
//	int val;
//};
//
//class Date {
//private:
//	int month;
//	int day;
//	int year;
//
//private:
//	Date(int month, int day, int year) :month(month), day(day), year(year) {}
//	//이렇게 말고
//
//public:
//	Date(const Month_s& month, const Day_s& day, const Year_s& year) :month(month.val), day(day.val), year(year.val) {}
//	//이렇게 하자
//};
//
//class Month_c { //이런 방법도 좋다.
//private:
//	int val;
//private:
//	explicit Month_c(int val) {}
//	// 새로운 클래스로 struct를 반환하는게 아닌 Date 생성자에 클래스를 집어넣는것으로 하자
//	// ps) 솔직히 _c _s 보기 불편하니 떼버리고 정적 함수 호출하는 방향으로 가는게 보기 편하다.
//public:
//	static Month_s Jan() { return Month_s(1); }
//	//...
//	//...
//	static Month_s Dec() { return Month_s(12); }
//};
//
//
//void exam() {
//	Date d(Month_c::Jan(), Day_s(30), Year_s(1995)); // 보기편하구먼!
//}
//
//
//
//
//class Investment {}; //전장에서 했던것들 기억하나?
//
//Investment* createInvestment(); //이젠 이렇게 말고
//
//shared_ptr<Investment> CreateInvestment();  //애초부터 팩토리 함수에서 스마트 포인터를 반환하는게 좋다!
//											//애초에 shared_ptr에 넣어둘수밖에없고 나중에 객체를 삭제하는걸 깜빡하고 넘어갈 일도 없다!
//
//
//
//
////★★★ 정리
//// - 좋은 인터페이스는 제대로 쓰기에 쉬우며 엉터리로 쓰기에 어렵다. 인터페이스를 만들때에는 이 특성을 담을수있게 고민하자
//// - 인터페이스의 올바른 사용을 이끄는 방법으로는 인터페이스 사이의 일관성 잡아주기, 기본 제공 타입과의 동작 호환성 유지하기 가 있다.
//// - 사용자의 실수를 방지하는 방법으로는 새로운 타입만들기, 타입에 대한 연산을 제한하기,객체의 값에대해 제약걸기,, 자원 관리 작업을 사용자 책임으로 놓지않기가 있다.
//// - shared_ptr는 사용자 정의 삭제자를 지원한다. 떄문에 교차 DLL 문제를 막고, 뮤텍스등을 자동으로 잠금 해제하는데 쓸수있다.
//
//#pragma endregion
//
//#pragma region 18. 클래스 설계는 타입 설계와 똑같이 취급하자
//
////cpp에서 새로운 클래스를 설계한다는것은 새로운 타입을 하나 정의 하는것과 같다.
//
////효과적인 클래스를 설계할때 고려해야 하는점
//
//// 1  - 새로 정의한 타입의 객체 생성 및 소멸은 어떻게 이루어져야 하는가? (8장 참조)
////			생성자,소멸자의 설계가 정해진다. 메모리 할당함수를 직접 작성할 경우에는 이들함수의 설계에도 영향을 미친다.
//
//// 2  - 객체 초기화는 객체 대입과 어떻게 달라야 하는가? ( 항목 3 참조)
////			초기화와 대입에 해당되는 함수 호출이 아예 다르다. 헷갈리지 말자
//
//// 3  - 새로운 타입으로 만든 객체가 값에 의해 전달되는 경우에 어떤 의미를 줄것인가?
////			어떤 타입에 대해 "값에 의한 전달"을 구현하는 쪽은 "복사 생성자" 이다.
//
//// 4  - 새로운 타입이 가질 수 있는 적법한 값에 대한 제약은 무엇으로 잡을 것인가?
////			클래스 데이터 맴버의 몇 가지 조합 값만은 반드시 유효해야한다.  이런 조합을 가리켜 불변속성이라하며 클래스 차원에서 지켜주어야하는 부분이다.
////			생성자, 대입 연산자 각종 "쓰기(setter)"함수는 불변속성에 많이 좌우된다.
//
//// 5  - 기존의 클래스 상속 계통망에 맞출것인가?
////			기존 클래스에서 상속을 한다면 상위 클래스에 제약을 받게된다.
////			맴버가 함수가 Virtual인지 아닌지의 여부가 가장 큰 요인이다.( 항목 33 및 35 참조)
////			우리가 만든 클래스를 다른 클래스에서 상속한다면 맴버 함수의 Virtual 함수 여부가 결정된다. 특히 소멸자 ( 항목6 참조)
//
//// 6  - 어떤 종류의 타입 변환을 허용할것인가?
////			우리가 만든 클래스는 다른 클래스와 섞여 사용해야한다. 따라서 타입변환을 고려한다면
////			암시적으로 타입을 변환 되도록 만들고 싶으면 기존 클래스에 타입 변환 함수를 하나 넣어주던가
////			인자 한개로 호출될수있는 비명시 호출 생성자를 만들어주자.
////			명시적으로 변환을 원한다면 해당 변환을 맡은 별도의 이름의 함수를 만들되 타입 변환 연산자 혹은
////			비명시호출 생성자는 만들지말아야한다. ( 항목 14에서 참조)
//
//// 7  - 어떤 연산자와 함수를 두어야 의미가 있을까? ( 항목 22,23,45 참조)
////			어떤것들은 맴버 함수로 적당하고, 또 몇몇은 그렇지 않다. 스스로 생각해보자.
//
//// 8  - 표준 함수들 중 어떤것을 허용하지 말 것인가? (항목 5 참조)
////			private로 선언해야 하는 함수
//
//// 9  - 새로운 타입의 맴버에 대한 접근권한을 어느쪽에 줄 것인가?
////			어떤 클래스 맴버를 public. protected, private영역에 둘것인가 생각하자
////			또한 friend로 만들어야 할 클래스 및 함수를 정하는것은 물로이고 한클래스를 다른 클래스에 중첩시켜도 되는가에 대한 결정을 내릴때 생각해보자
//
//// 10 - '선언되지 않은 인터페이스'로 무엇을 둘 것인가?
////			우리가 만들 타입이 제공할 보장이 어떤 종류일까에 대한 질문으로서, 보장할 수 있는 부분은 수행 성능 및 예외 안전성(항목 28 참조)
////			그리고 자원 사용(잠금 및 동적 메모리 등)이다. 이들에대해 우리가 보장하겠다고 결정한 결과는 클래스 구현에 있어 제약으로 작용된다.
//
//// 11 - 새로 만드는 타입이 얼마나 일반적인가?
////			실상은 타입 하나를 정의하는 것이 아닐지도 모른다. 우리가 정의하는 것이 동일 계열의 타입군(family of types) 전체 일지도 모른다.
////			그렇다면 우리는 새로운 '클래스'가 아닌 새로운 '클래스 템플릿'을 정의 해야한다.
//
//// 12 - 정말로 꼭 필요한 타입인가?
////			기존 클래스에 대해 기능 몇개가 아쉬워서 파생 클래스를 새로 뽑고 있다면 , 차라리 간단하게 비맴버 함수라던가 템플릿을 몇개 더 정의하자.
//
//
////★★★ 정리
////	- 클래스 설계는 타입설계다. 새로운 타입을 정의 하기 전에, 위 항목의 고려사항을 빠짐없이 점검해보자.
//
//#pragma endregion
//
//#pragma region 19."값에 의한 전달"보다는 "상수 객체 참조자에 의한 전달"방식을 택하는 편이 대개 낫다.
//
//class Person {
//private:
//	string name;
//	string address;
//public:
//	Person() {};
//	virtual ~Person() {};
//};
//class Student :public Person {
//private:
//	string schoolName;
//	string schoolAddress;
//public:
//	Student() {};
//	~Student() {};
//};
//
//bool balidateStudent(Student s) {};
////이대로 들어가면 Student 복사생성자 1번, Person 복사생성자 1번, string 복사생성자 4번이 추가적으로 불린다.
//// 소멸자는? 저만큼 들어간다. ㅇㅇ 진짜
//
//bool balidateStudent(const Student& s) {};
////복사 손실문제 해결이 된다.
////파생클래스가 기본클래스 객체로서 전달되는 경우에는 기본 클래스의 복사생성자가 호출되고,
////파생클래스 객체로 동작하는 부분이 잘려 떨어지게된다.
//
//
////STL의 반복자와 함수객체에도 마찬가지이다.
//// 반복자와 함수객체를 구현할때에는 반드시 "복사 효율을 높일 것" , "복사 손실 문제에 노출되지 않도록 만드는것이 필수이다."
//
//
////★★★ 정리
//// - "값에 의한 전달" 보다는 "상수객체 참조자에 의한 전달"을 선호하자. 효율적이고, 복사손실문제도 막아준다.
//// - 기본제공타입, STL반복자, 함수객체 타입에는 "값에 의한 전달" 방식을 차용하자.
//
//#pragma endregion
//
//#pragma region 20. 함수에서 객체를 반환해야 할 경우에 참조자를 반환하려고 들지 말자.
//
//class Rational {
//private:
//	int n, d;
//private:
//	//friend const Rational operator*(const Rational& lhs, const Rational& rhs);
//public:
//	Rational(int numerator = 0, int denominator = 1) :n(numerator), d(denominator) {};
//
//	//연산자 오버로딩의 문제에서 새로운 객체를 반환해야할때 주의) friend 키워드 짚고 넘어가자 진짜
//	friend inline const Rational operator*(const Rational& lhs, const Rational& rhs) {
//		return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
//	}
//};
//
////반환값을 생성하고 소멸시키는 비용이 들지만 올바른 동작에 들어가는 비용이다.
//
////★★★ 정리
//// - 지역 스택 객체에 대한 포인터나 참조자를 반환하는 일, 혹은 힙에 할당된 객체에 대한 참조자를 반환하는일,
////	또는 지역 정적 객체에 대한 포인터나 참조자를 반환하는 일은 그런 객체가 두개 이상 필요해질 가능성이 있다면
////	절대로 하지말자.(항목 3 참조 - 지역 정적 객체에 대해 참조자를 반환하도록 설계된 올바른 예제가 있다.)
//
//#pragma endregion
//
//#pragma region 21.데이터 맴버가 선언될 곳은 private영역임을 명심하자
//
//class AccessLevels {
//private:
//	int noAccess;	//접근 불가
//	int readOnly;	//읽기 전용
//	int readWrite;	//읽기 쓰기
//	int writeOnly;	//쓰기 전용
//public:
//	int		getreadOnly() const { return readOnly; }
//	void	setreadWrite(int val) { readWrite = val; }
//	int		getreadWrite() const { return readWrite; }
//	void	setwriteOnly(int val) { writeOnly = val; }
//};
//
//class SpeeddataCollection { //자동차의 평균속도를 구하는 클래스라하자.
//	int speed;
//public:
//	void addValue(int val) { speed += val; };
//	double averageSoFar() const {	/*return ? ;*/ };
//};
//
//// 메모리가 부족하고, 평균값이 자주 필요하지 않은 프로그램에서는 매번 평균값을 계산하는편이 좋을것이고
//
//// 평균값이 매번 필요하고 속도가 중요하며 메모리 크기에 구애받지 않는 환경이면 평균값을 유지하는 방법이 좋을것이다.
//
//
////★★★ 정리
//// - 데이처 맴버는 private로 선언합시다. 이를 통해 클래스 제작자는 문법적으로 일관성있는 데이터 접근 통로를 제공할수있고
////		필요에 따라서는 세밀한 접근제어도 가능하며, 클래스의 불변속성을 강화할수있을분 아니라, 내부 구현의 융통성도 발휘할수있스비다.
//// - protected는 public보다 더 많이 "보호"받고 있는 것이 절대로 아니다.
//
//#pragma endregion
//
//#pragma region 22. 맴버 함수 보다는 비 맴버 비 프렌드 함수와 더 가까워지자.
//
////웹브라우저를 나타내는 클래스가 하나 있다고 가정하자.
//namespace WebBrowserStuff {
//	class WebBrowser {
//	public:
//		void clearCache() {};
//		void clearHistory() {};
//		void removeCookies() {};
//		//이러한 세가지 함수가 있을수있겠다.
//		//이 세동작을 한번에 부르고 싶어하는 사람들도 있기에 세 함수를 모아서 불러주는 함수도 있을것이다.
//
//		//첫번째로 맴버 함수로써 구현하는것
//		void clearEverything() {
//			clearCache();
//			clearHistory();
//			removeCookies();
//		}
//	};
//
//	//두번째로 비맴버 함수에서 웹브라우서 객체의 맴버 함수를 순서대로 호출하는것
//	void clearBrowser(WebBrowser& wb) {
//		wb.clearCache();
//		wb.clearHistory();
//		wb.removeCookies();
//	}
//
//	//객체지향을 지키는 방법은 할수있을 만큼 데이터를 캡슐화 하는것이지만 clearBrowser의 구현이 캡슐화 기준에서 더 낫다.
//	//비맴버  함수를 사용하면 WebBrowser 관련 기능을 구성하는데 있어서 패키징 유연성이 높아지는 장점이있다.
//	// 또한 이로인해 얻게 되는 추가적인 이점으로 컴파일 의존도도 낮추고 WebBrowser의 확장성도 높일수 있다.
//
//	//1. 비맴버 비프렌드 함수에만 적용된다. 캡슐화라는 관점에서 friend키워드는 클래스 자체에서 맴버에 접근하는 권한이랑 같기 때문이다.
//	//2." 함수는 어떤 클래스의 비맴버가 되어야 한다. =/ 그 함수는 다른 클래스의 맴버가 될수없다. "라는 의미가 아니다.
//	//		Cpp로써 더 자연스러운 구현은 하나의 namespace에 묶어 놓는것이다.
//	//		편의 기능을 제공하는 함수들은 카테고리 별로 헤더를 만들어서 같은 namespace안에 선언 및 정의를 해주자.
//}
//
////★★★ 정리
//// - 맴버 ㅎ마수 보다는 비맴버 비프렌드 함수를 자주쓰도록 하자. 캡슐화 정도가 높아지고, 패키징 유연성도 커지며, 기능적인 확장성도 늘어난다.
//#pragma endregion
//
//#pragma region 23. 타입 변환이 모든 매개변수에 대해 적용되어야 한다면 비맴버 함수를 선언하자.
//
//class Rational {
//private:
//	int m_N;
//	int m_D;
//public:
//	Rational(int numerator = 0, int denomiator = 1) : m_N(numerator), m_D(denomiator) {};
//
//	int numerator() const {
//		return m_N;
//	}
//	int denomiator() const {
//		return m_D;
//	}
//};
//
////비 맴버 함수로 정의 해놓으면 모든 매개변수에 대해 타입 변환을 정의할수있다.
//const Rational operator* (const Rational& lhs, const Rational& rhs) {
//	return Rational(lhs.numerator() *rhs.numerator(), lhs.denomiator() * rhs.denomiator());
//}
//
////★★★ 정리
//// - 어떤 함수에 들어가는 모든 매개변수(this포인터가 가리키는 객체도 포함)에 대해 타입 변환을
////	해 줄 필요가 있다면, 그함수는 비맴버야 한다.
//
//#pragma endregion
//
//#pragma region 24.예외를 던지지 핞는 swap에 대한 지원도 생각해보자. (내용이 많이 심화적이니 책으로 읽는 것을 권장 ㅇㅇ)
//
//template<typename T>
//void MySwap(T& a, T& b) {
//	T temp(a);
//	a = b;
//	b = temp;
//}
//
//class WidgetIMPL {
//private:
//	int a, b, c;
//	vector<double> v;		//복사 비용이 높다.
//};
//
//class Widget {
//private:
//	WidgetIMPL * pIMPL;		//위젯의 실제 데이터를 가진 객체에 대한 포인터
//
//public:
//	Widget & operator=(const Widget& rhs) {
//		*pIMPL = *(rhs.pIMPL);
//	}
//	void swap(Widget& other) {
//		using std::swap;
//
//		swap(pIMPL, other.pIMPL);
//	}
//};
//
//
//namespace std {
//
//	template<>
//	void swap<Widget>(Widget& a, Widget& b) {
//		//swap(a.pIMPL, b.pIMPL);
//
//		a.swap(b);
//	}
//	//swap 템플릿의 특수화 함수를 살짝 고친것
//	//기존의 STL 컨테이너와 일관성도 유지된다.
//
//	//만약 클래스가 아니라 클래스 템플릿을 되어있다면? "Class<T>" ㅇㅇ?
//
//	//함수템플릿을 부분적으로 특수화 하고싶으면 그냥 오버로드 버전을 추가로 지원하는것이다.
//
//	template<typename T> //예시 신경꺼도 됨
//	class Widget2 {
//	private:
//		WidgetIMPL * pIMPL;
//	public:
//		void swap(Widget2& other) {
//			using std::swap;
//
//			swap(pIMPL, other.pIMPL);
//		}
//	};
//
//	template<typename T>
//	void swap(Widget2<T>& a, Widget2<T>& b) {
//		a.swap(b);
//	}
//	//일반적으로 함수 템플릿의 오버로딩은 해도 별문제가 없지만, std는 특별한 네이스페이스여서
//	// std내의 템플릿에 대한 완전 특수화는 ok지만 std에 새로운 템플릿을 추가하는 것은 ok가 아니다.
//
//	//컴파일도 되고 실행도 되지만 실행에 생성되는 결과가 미정의 사항이다.
//}
//
//
////템플릿 전용 버전의 swap을 사용하고싶으면
////맴버 swap을 호출하는 비맴버 swap을 선언한뒤, 이 비맴버 함수를 swap의 특수화 버전이나
//// 오버로딩 버전으로 선언하지만 않으면 된다.
//
//
//namespace Widget3stuff {
//
//	template<typename T>
//	class Widget3 {
//	private:
//		WidgetIMPL * pIMPL;
//	public:
//
//		void swap(Widget3& other) {
//			using std::swap;
//
//			swap(pIMPL, other.pIMPL);
//		}
//	};
//
//	template<typename T>
//	void swap(Widget3<T>& a, Widget3<T>& b) {
//		a.swap(b);
//	}
//	//비맴버 swap함수, std 네임스페이스의 일부가 아니다.
//
//
//	//이제는 어떤 코드가 두객체에 대해 swap을 호출하거라고, 컴파일러는 cpp의
//	//  ★★"이름 탐색 규칙"(혹은 인자기반 탐색, 쾨니그 탐색으로 알려진)★★   에 의해 Widget3stuff 네임스페이스 안에서 특수화 버전을 찾아낸다.
//
//	//클래스 템플릿 뿐만 아니라 클래스에 대해서도 잘통하기에 언제든지 써보자
//}
//
////이제는 사용자 입장에서 생각해보면
//
//template<typename T>
//void doSomething(T& obj1, T& obj2) {
//	swap(obj1, obj2);	//이부분에서 어떤 swap을 호출해야 할까?
//
//	//1.std에 있는 일반형버전			-- 이건 반드시 존재
//	//2.std의 일반형을 특수화 한 버전	-- 있을수도 없을수도
//	//3. T타입 전용의 버전				-- 있을수도 없을수도, 어떤 네임스페이스 안에 있을수도 없을수도
//
//	//우리가 원하는건 T전용 버전이 있으면 호출하고
//	// 없으면 std의 일반형이 호출되도록 해주고싶다.
//
//
//	//해결 방안
//
//	using std::swap;  //std::swap을 이 함수 안으로 끌어올 수 있도록 해준다.
//
//	swap(obj1, obj2);	//T 타입 전용의 swap을 호출한다.
//
//
//	//컴파일러가 위의 swap호출문을 만났을때 하는일은 현재 상황에 딱 맞는 swap을 찾는것이다.
//	// c++의 이름 탐색 규칙에 따라 , 우선 전역 유효범위 혹은 타입T와 동일한 네임 스페이스 안에 T전용의 swap이 있는지 찾는다.
//	//없으면 std::swap을 볼수있게 해주는 using 선언 덕분에 std::swap을 쓰게끔 결정할수도있다.
//	//하지만 T전용 버전을 일반형 템플릿 보다 더 우선적으로 선택하기에 특수화 버전이 이미 준비 되어있다면 특수화 버전이 쓰인다.
//
//
//	std::swap(obj1, obj2);
//	//그 어떤 템플릿 특수화 버전을 포함하여 std의 swap말고는 보지말라고 컴파일러를 구속한다.
//	// T 전용 버전이 있는 가능성을 배제하는 코드이다.
//
//
//	//소정리
//	//첫째. 표준에서 제공하는 swap이 우리의 클래스 및 클래스 템플릿에 대해 납득할 만한 효율을 보이면, 아무것도 하지말자
//	//		우리가 만든 타입으로 만든객체에 대해 swap을 시도하는 사용자 코드는 표준 swap을 호출할것이다. 아무 문제도 없을것이고
//
//	//둘쨰. 표준 swap의 효율이 기대한 만큼 충분하지 않다면 다음과 같이 해결해보자
//	//		-우리의 타입으로 만들어진 두 객체의 값을 빛나게 빨리 맞바꾸는 함수를 swap이라는 이름으로 만들고,
//	//			이것을 public 맴버 함수로 두자. (이함수는 예외를 던지면 안된다.)
//	//		-우리의 클래스 혹은 템플릿이 들어 있는 네임스페이스와 같은 네임스페이스에 비맴버 swap을 만들어 넣자. 그리고 1번에서 만든
//	//			swap맴버 함수를 이 비맴버 함수가 호출하도록 만든다.
//	//
//	//		-새로운 클래스(클래스 템플릿이 아닌)를 만들고 있다면, 그 클래스에 대한 std::swap의 특수화 버전을 준비해두자.
//	//			그리고 이 특수화 버전에서도 swap맴버 함수를 호출하도록 만들자.
//	//
//	//셋째.	사용자 입장에서 swap을 호출할때 ,swap을 호출하는 함수가 std::swap을 볼 수 있도록 using 선언을 반드시 포함 시킨다.
//	//		그 다음 에 swap을 호출하되 네임스페이스 한정자를 붙이지 않도록한다.
//
//
//	//참고 - 맴버 버전의 swap은 절대로 예외를 던지지 않도록 만들자.
//	//			그이유는 swap을 진짜 쓸모있게 응용하는 방법들중에 클래스가 강력한 예외 안전성 보장을 제공하도록 도움을 주는 방법이있기 때문이다.
//
//
//
//
//
////★★★ 정리
//// - std::swap이 우리의 타입에 대해 느리게 동작할 여지가 있다면 swap맴버 함수를 제공하자. 이 맴버 swap은 예외를 던지지 않도록 만들자.
//// - 맴버 swap을 제공했으면, 이 맴버를 호출하는 비맴버 swap도 제공합니다. 클래스(템플릿이 아닌) 에 대해서는 ,std::swap도 특수화 해주자.
//// - 사용자 입장에서 swap을 호출할때는 ,std::swap에 대한 using 선언을 넣어 준후에 네임 스페이스 한정 없이 swap을 호출하자
//// - 사용자 정의 타입에 대한 std 템플릿을 완전 특수화 하는것은 가능하나 std에 어떤것이라도 새로 추가하려 하지는 말자.
//
//
//#pragma endregion
