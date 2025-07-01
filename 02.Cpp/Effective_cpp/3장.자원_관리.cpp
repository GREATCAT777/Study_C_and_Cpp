//#include <iostream>
//#include <vector>
//#include <string>
//#include <mutex>
//
//using namespace std;
//
//#pragma region 12. 자원 관리에는 객체가 그만!
//
//
//// 프로그래밍 분야에서의 "자원(Resources)"이란, "사용을 마치고 난뒤 시스템에 되돌려주어야 하는 모든것
//// 흔히 알고있는 동적할당 메모리가 이에 해당된다.
//// 그 외에도 파일 서술자(File descripter),뮤텍스 잠금(mutex lock), GUI에서의 폰트와 브러쉬도 자원
//// 사용을 마치고 난뒤에 해제해 주어야하는것들
//
//class Investment {	/*여러 형태의 투자를 모델링한 클래스 계통의 최상위 클래스*/ };
//
//Investment* CreateInvestment() {
//	//Investment 클래스 계통에 속한 클래스의 객체를 동적 할당하고 그 포인터를 반환합니다.
//	//이 객체의 해제는 호출자 쪽에서 직접 해야합니다.
//
//	Investment* ret = new Investment();
//	
//	return ret;
//}
//
//void Func1() {
//	Investment* pInv = CreateInvestment();
//
//	// ~~~사용구간~~~~
//
//	delete pInv;
//}
//
////1. 사용구간에서 return 문이 들어갈 경우
////2. 루프문에서 continue 또는 goto문에 의해 갑작스럽게 루프로 부터 빠져나올때
////3. 사용구간에서 예외를 던질경우
//
////전부 delete문을 건너 뛴다. -> 자원이 샌다. 
//
////팩토리함수로 얻어낸 자원이 항상 해제되도록 만들 방법은, 자원을 객체에 넣고 그 자원 해제를 소멸자가 맡도록 하고
//// 그 소멸자는 실행제어가 Func1를 떠날때 호출 되도록 만드는 것이다.
//
//// 이러한 경우를 고려하여 만들어진것이 auto_ptr이다.
////auto_ptr란 포인터와 비슷하게 동작하는 스마트 포인터이다.
////하나의 블록 또는 함수 안에서만 쓰이고 그 곳에서 빠져나올때 소멸자가 자동적으로 delete를 호출해주게된다.
//
//void Func1() {
//	auto_ptr<Investment> pInv (CreateInvestment()); //자원의 획득과 자원 관리 객체의 초기화를 한문장에!!
//
//	// ~~~사용구간~~~~
//
//	//auto_ptr의 소멸자를 통해 pInv를 삭제합니다.
//}
//
////자원 관리에 객체를 이용하는 방법의 두가지 특성
//// - 첫째, 자원을 획득한 후에 자원 관리 객체에게 넘깁니다.
////		( 자원 획득 즉 초기화 , RAII )- 자원 획득과 자원 관리 객체의 초기화가 한문장에 이루어지는것은 당연한것이다.
//// - 둘째, 자원 관리 객체는 자신의 소멸자를 사용해서 자원이 확실히 해제 되도록합니다.
//
////어떤 객체를 가리키는 auto_ptr의 갯수가 복사되어 둘이상이면 원본객체는 null로 만들고
//// 복사하는 객체만이 유일한 소유권을 가지게 된다.
//
////이렇듯 auto_ptr가 관리하는 객체는 두개 이상의 auto_ptr이 물고있으면 안된다는 전제가 깔려있는데
////동적으로 할당되는 모든 자원에 대한 관리 객체로써 auto_ptr를 쓰는건 최선이 아닐것이다.
////STL컨테이너들은 원소들이 정상적으로 복사동작을 가져야하기 때문에,auto_ptr는 이들의 원소로 허용되지 않습니다.
//
//
////이렇게 auto_ptr를 쓸수없는 상황이면 "참조 카운팅 방식 스마트포인터(RCSP)"를 사용하자
////RCSP는 특정한 어떤 자원을 가리키는 외부 객체의 개수를 유지하고있다가 그 개수가 "0" 이되면  해당자원을 자동으로 삭제하는 스마트 포인터이다.
////이것만 보면 RCSP는 가비지컬렉션과 아주 흡사하다. (다른점은 참조상태가 고리 혹은 순환"서로 다른 두 객체가 서로를 바라보고 있는 상태" 이면 없앨수없다는 점은 GC와 다르다.)
//
//
//void Func2() {
//	shared_ptr<Investment> pInv(CreateInvestment());//pInv는 팩토리에서 반환된 객체 
//	
//	shared_ptr<Investment> pIn2(pInv);				//pInv2는 pInv와 같은 객체를 가리키고있다.
//
//	pInv = pIn2;									//변환없음
//	
//	//shared_ptr의 소멸자를 통해 pInv과 pInv2 그리고 이들이 가리키는 객체도 삭제된다.
//}
//
////shared_ptr는 복사 동작이 예상대로 이루어지기 때문에 STL컨테이너등의 환경에 잘 쓰일수있다.
//
//
////★★★ 정리
//// - 자원 누출을 막기위해, 생성자 안에서 자원을 획득하고 소멸자에서 그것을 해제하는 RAII객체를 사용하자
//// - 일반적으로 널리 쓰이는 RAII 클래스는 shared_ptr, auto_ptr 이다.
////		이 둘중에 shared_ptr가 복사시의 동작이 직관적이기 때문에 대개 더 좋다고한다.
////		auto_ptr은 복사되는 객체(원본객체)를 null로 만들어버린다.
//#pragma endregion
//
//#pragma region 13. 자원 관리 클래스의 복사 동작에 대해 진지하게 고찰하자
//
//void lock(mutex* pm) { pm->lock(); }
//void unlock(mutex* pm) { pm->unlock(); }
//
//class MUTEX_Lock { //뮤텍스 잠금 관리클래스
//private:
//	mutex* mutexptr;
//public:
//	explicit MUTEX_Lock(mutex* pm) :mutexptr(pm) {
//		lock(mutexptr);
//	}
//	~MUTEX_Lock() {
//		unlock(mutexptr);
//	}
//};
//
//void exam1() {
//	mutex m;					//우리가  사용할 뮤텍스를 정의한다.
//	{							//블록으로 임계영역을 정의한다.
//		MUTEX_Lock m1(&m);		//뮤텍스에 잠금을 겁니다.
//
//		//.....임계영역에서의 연산처리
//
//	}							// 뮤텍스에 걸렸던 잠금이 자동으로 풀립니다.
//
//	//만약 MUTEX_Lock객체가 복사되면 어떨게 될까요?
//	MUTEX_Lock m11(&m);
//	MUTEX_Lock m12(m11);
//}
//
//// RAII 객체가 복사될때 취해야 할 선택지
//// ① -복사를 금지한다. 사실상 RAII객체가 복사되도록 놔두는것 자체가 말이 안되는 경우가 많다한다.
////		(uncopyable 클래스를 상속받는다.) --> 2장에서 Uncopyable 클래스 같이봐요
//// ② -관리하고 있는 자원에 대해 참조 카운팅을 수행한다.
////		shared_ptr로 선언을 하면 소멸자를 선언하지 않는다. -> 선언할 필요가없다.
////		객체 소멸과정을 잊은게 아니라 컴파일러가 생성한 소멸자를 통해 동작한다.
//class MUTEX_Lock2 { 
//private:
//	shared_ptr<mutex>mutexptr; //원시 포인터 대신 shared_ptr로 대신했다.
//public:
//	explicit MUTEX_Lock2(mutex* pm) :mutexptr(pm, lock) {
//		//shared_ptr을 초기화 하는데 , 가리킬 포인터로 mutex객체의 포인터를 사용하고
//		//삭제자로 unlcok의 함수를 사용합니다.
//		lock(mutexptr.get());
//	}
//};
//// ③ -관리하고있는 자원을 진짜로 복사합니다.
////		"자원을 다 썼을때 각각의 사본을 확실히 해제하는것"
////		깊은 복사를 수행하자
//// ④ -관리하고 있는 자원의 소유권을 옮깁니다.
////		auto_ptr을 사용하자.
//
//
////	★★★정리
////	- RAII 객체의 복사는 그 객체가 관리하는 자원의 복사문제를 안고가기 때문에., 그 자원을 어떨게 복사하는냐에 따라 RAII
////		객체의 복사 동작이 결정됩니다.
////	- RAII 클래스에 구현하는 일반적인 복사 동작은 복사를 금지하거나 참조카운팅을 해주는선으로 마무리 하는것 입니다.
//
//#pragma endregion
//
//#pragma region 14. 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할수 있도록 하자
//class MUTEX_Lock3 {
//private:
//	shared_ptr<mutex>mutexptr; 
//public:
//	explicit MUTEX_Lock3(mutex* pm) :mutexptr(pm, lock) {
//
//		lock(mutexptr.get()); //
//	}
//};
//
//void exam2() {
//	shared_ptr<Investment> pInv(CreateInvestment());
//	int daysHeld(const Investment* pi); //투자금이 유입된 이후로 경과한 날수
//
//	//int days = daysHeld(pInv); //에러
//	//-> daysHeld()함수는 Investment* 타입의 실제 포인터를 원하는데 실제로 주고있는건 shared_ptr<Investment>타입의 포인터이다.
//
//	// 해결할 방법 두가지
//	//스마트 포인터들은 명시적 변환을 수행하는 get()이라는 맴버함수를 제공한다.
//	// 이함수를 사용하면 각 타입으로 만든 스마트 포인터 객체에 들어있는 실제 포인터의 사본을 얻어낼수있다.
//
//	int days = daysHeld(pInv.get()); //이제 문제없다.
//
//	//제대로 구현된 스마트 포인터라면 (포인터역참조 연산자, operator-> 랑 operator*)도 오버로딩하고있다.
//	//pInv->SampleFunction();
//	//(*pInv).SampleFunction();
//
//	class FontHandle{};
//	FontHandle getFont(); //폰트얻어오기 함수
//
//	class Font {
//	private:
//		FontHandle f;
//	public:
//		explicit Font(const FontHandle& rhs) :f(rhs) {}
//		FontHandle get() const { return f; }		// 하부 수준 API를 쓸때마다 호출해주는 get함수
//													// 하부수준에 접근할때마다 호출해줘야한다.
//													//그래서 나온 대안
//		operator FontHandle() const { return f; }	//암시적 변환 함수
//	};
//
//	Font f1(getFont());
//	
//	FontHandle f2 = f1; //폰트 객체를 복사하는 것인데 f1이 FontHandle로 암시적으로 변환된 후 복사되었다.
//
//	//f1이 소멸될 시점을 생각해보면 f2의 상태는?? 메롱하쥬?
//}
//
////★★★ 정리
//// - 실제 자원을 직접 접근해야 하는 깆존 API들도 많기 때문에, RAII 클래스를 만들때는 그 클래스가 관리하는 자원을 얻을수있는 방법을 열어주어야합니다.
//// - 자원 접근은 명시적 변환 혹은 암시적 변환을 통해 가능합니다. 안전성만 따지면 명시적 변환이 대체적으로 더 낫지만, 고객의 편의성을 놓고 보면 암시적 변환이 괜찮습니다.
//
//#pragma endregion
//
//#pragma region 15.new 및 delete 를 사용할때는 형태를 반드시 맞추자
//
////배열의 형태로 동적할당을 했을때에는 반드시 배열의 형태로 해제해주자.
//
////delete[] 로 선언한 형태로 해제가 될때에는 객체의 배열 크기 정보가 있다는것을 알려줄수있습니다.
//
////delete intVal			//객체 하나 삭제
////delete[] intVal		//객체의 배열을 삭제
//
////typedef로 정의된 배열들도 배열형태로 객체를 삭제해주자.
//
////★★★ 정리
//// - new 표현식에 배열을 썼으면 delete표현식에도 배열로 써주자. new[] -> delete[]
//// - 배열형태가 아니면 delete표현식에 배열로 선언하지 말자.		new	  -> delete
//
//#pragma endregion
//
//#pragma region new로 생성한 객체를 스마트 포인터에 저장하는 코드는 별도의 한 문장으로 만들자.
//
////처리 우선순위를 아렬주는 함수가 하나있고, 동적으로 할장한 Widget 객체에 대해 어떤 우선순위에 따라 처리를 적용하는 함수가 하나 있다고 가정합니다.
//
//class Widget {};
//
//int Priotity();
//
//void processWidget(shared_ptr<Widget> pw, int priotity);
//
//void Exam3(){
//	//processWidget(new Widget, Priotity()); //컴파일이 안된다.
//
//	//포인터를 받는 shared_ptr 의 생성자는 explici t로 선언되있기 때문에, new Widget 표현식에 의해 만들어진 포인터가 
//	//shared_ptr 타입의 객체로 바꾸는 암시적인 변환이 없기 때문이다.
//
//	//반면 이건 컴파일 된다.
//
//	processWidget( shared_ptr<Widget>( new Widget ), Priotity() );
//	//하지만 이것도 자원을 흘릴 가능성이 있다.
//
//	//컴파일러는 processWidget 호출 코드를 만들기 전에 우선 이 함수의 매개변수로 넘겨지는 인자를 평가(evaluate)하는 순서를 밟는다.
//	// 첫번째 인자는 두부분으로 나누어져있다.
//
//	//"new Widget" 표현식을 실행하는 부분
//	//"shared_ptr" 생성자를 호출하는 부분
//
//	//컴파일러는 다음 세가지 연산을 위한 코드를 만들어야 한다.
//
//	//1. Priotity()를 호출
//	//2. new Widget를 실행
//	//3. shared_ptr의 생성자 호출
//
//	//각각의 연산이 실행되는 순서는 컴파일러 제작사마다 다르다는게 문제이다.
//
//	//만약 두번째에서 Priotity()를 호출한다면
//	// 2 -> 1 -> 3 순서로 결정되는데
//	//Priotity() 호출부분에서 예외가 발생한다면 첫번째(2)에서 만들어진 포인터가 유실된다.
//	//자원 누출을 막아줄줄 알고 준비한 shared_ptr에 들어가기도 전에 예외가 난다.
//
//	//자원 누출될 가능성이 있는 이유는 자원이 생성되는 시점과 그 자원이 자원 관리 객체로 넘어가는 시점 사이에 예외가 나올수있기 때문이다.
//
//	//이러한 문제를 피하는것은 간단하다.
//
//	shared_ptr<Widget> pw(new Widget);	//new 로 생성한 객체를 스마트 포인터에 담는 코드를 하나의 독립적인 문장으로 만든다.
//	processWidget(pw, Priotity());		//자원이 누출될 걱정이 없다!
//}
//
////★★★ 정리
//// - new로 생성한 객체를 스마트 포인터로 넣는 코드는 별도의 한문장으로 만들자.
//// - 이런 준비가 안되어있으면 예외가 발생될 때 디버깅 하기 힘든 자원 누출이 초래될 수 있습니다.
//
//#pragma endregion
