#include <iostream>
#include <vector>
#include <string>
#include <mutex>

using namespace std;

#pragma region 12. 자원 관리에는 객체가 그만!


// 프로그래밍 분야에서의 "자원(Resources)"이란, "사용을 마치고 난뒤 시스템에 되돌려주어야 하는 모든것
// 흔히 알고있는 동적할당 메모리가 이에 해당된다.
// 그 외에도 파일 서술자(File descripter),뮤텍스 잠금(mutex lock), GUI에서의 폰트와 브러쉬도 자원
// 사용을 마치고 난뒤에 해제해 주어야하는것들

class Investment {	/*여러 형태의 투자를 모델링한 클래스 계통의 최상위 클래스*/ };

Investment* CreateInvestment() {
	//Investment 클래스 계통에 속한 클래스의 객체를 동적 할당하고 그 포인터를 반환합니다.
	//이 객체의 해제는 호출자 쪽에서 직접 해야합니다.

	Investment* ret = new Investment();
	
	return ret;
}

void Func1() {
	Investment* pInv = CreateInvestment();

	// ~~~사용구간~~~~

	delete pInv;
}

//1. 사용구간에서 return 문이 들어갈 경우
//2. 루프문에서 continue 또는 goto문에 의해 갑작스럽게 루프로 부터 빠져나올때
//3. 사용구간에서 예외를 던질경우

//전부 delete문을 건너 뛴다. -> 자원이 샌다. 

//팩토리함수로 얻어낸 자원이 항상 해제되도록 만들 방법은, 자원을 객체에 넣고 그 자원 해제를 소멸자가 맡도록 하고
// 그 소멸자는 실행제어가 Func1를 떠날때 호출 되도록 만드는 것이다.

// 이러한 경우를 고려하여 만들어진것이 auto_ptr이다.
//auto_ptr란 포인터와 비슷하게 동작하는 스마트 포인터이다.
//하나의 블록 또는 함수 안에서만 쓰이고 그 곳에서 빠져나올때 소멸자가 자동적으로 delete를 호출해주게된다.

void Func1() {
	auto_ptr<Investment> pInv (CreateInvestment()); //자원의 획득과 자원 관리 객체의 초기화를 한문장에!!

	// ~~~사용구간~~~~

	//auto_ptr의 소멸자를 통해 pInv를 삭제합니다.
}

//자원 관리에 객체를 이용하는 방법의 두가지 특성
// - 첫째, 자원을 획득한 후에 자원 관리 객체에게 넘깁니다.
//		( 자원 획득 즉 초기화 , RAII )- 자원 획득과 자원 관리 객체의 초기화가 한문장에 이루어지는것은 당연한것이다.
// - 둘째, 자원 관리 객체는 자신의 소멸자를 사용해서 자원이 확실히 해제 되도록합니다.

//어떤 객체를 가리키는 auto_ptr의 갯수가 복사되어 둘이상이면 원본객체는 null로 만들고
// 복사하는 객체만이 유일한 소유권을 가지게 된다.

//이렇듯 auto_ptr가 관리하는 객체는 두개 이상의 auto_ptr이 물고있으면 안된다는 전제가 깔려있는데
//동적으로 할당되는 모든 자원에 대한 관리 객체로써 auto_ptr를 쓰는건 최선이 아닐것이다.
//STL컨테이너들은 원소들이 정상적으로 복사동작을 가져야하기 때문에,auto_ptr는 이들의 원소로 허용되지 않습니다.


//이렇게 auto_ptr를 쓸수없는 상황이면 "참조 카운팅 방식 스마트포인터(RCSP)"를 사용하자
//RCSP는 특정한 어떤 자원을 가리키는 외부 객체의 개수를 유지하고있다가 그 개수가 "0" 이되면  해당자원을 자동으로 삭제하는 스마트 포인터이다.
//이것만 보면 RCSP는 가비지컬렉션과 아주 흡사하다. (다른점은 참조상태가 고리 혹은 순환"서로 다른 두 객체가 서로를 바라보고 있는 상태" 이면 없앨수없다는 점은 GC와 다르다.)


void Func2() {
	shared_ptr<Investment> pInv(CreateInvestment());//pInv는 팩토리에서 반환된 객체 
	
	shared_ptr<Investment> pIn2(pInv);				//pInv2는 pInv와 같은 객체를 가리키고있다.

	pInv = pIn2;									//변환없음
	
	//shared_ptr의 소멸자를 통해 pInv과 pInv2 그리고 이들이 가리키는 객체도 삭제된다.
}

//shared_ptr는 복사 동작이 예상대로 이루어지기 때문에 STL컨테이너등의 환경에 잘 쓰일수있다.


//★★★ 정리
// - 자원 누출을 막기위해, 생성자 안에서 자원을 획득하고 소멸자에서 그것을 해제하는 RAII객체를 사용하자
// - 일반적으로 널리 쓰이는 RAII 클래스는 shared_ptr, auto_ptr 이다.
//		이 둘중에 shared_ptr가 복사시의 동작이 직관적이기 때문에 대개 더 좋다고한다.
//		auto_ptr은 복사되는 객체(원본객체)를 null로 만들어버린다.
#pragma endregion

#pragma region 13. 자원 관리 클래스의 복사 동작에 대해 진지하게 고찰하자


void lock(mutex* pm) { pm->lock(); }
void unlock(mutex* pm) { pm->unlock(); }

class MUTEX_Lock { //뮤텍스 잠금 관리클래스
private:
	mutex* mutexptr;
public:
	explicit MUTEX_Lock(mutex* pm) :mutexptr(pm) {
		lock(mutexptr);
	}
	~MUTEX_Lock() {
		unlock(mutexptr);
	}
};

void exam1() {
	mutex m;					//우리가  사용할 뮤텍스를 정의한다.
	{							//블록으로 임계영역을 정의한다.
		MUTEX_Lock m1(&m);		//뮤텍스에 잠금을 겁니다.

		//.....임계영역에서의 연산처리

	}							// 뮤텍스에 걸렸던 잠금이 자동으로 풀립니다.

	//만약 MUTEX_Lock객체가 복사되면 어떨게 될까요?
	MUTEX_Lock m11(&m);
	MUTEX_Lock m12(m11);
}

// RAII 객체가 복사될때 취해야 할 선택지
// ① -복사를 금지한다. 사실상 RAII객체가 복사되도록 놔두는것 자체가 말이 안되는 경우가 많다한다.
//		(uncopyable 클래스를 상속받는다.) --> 2장에서 Uncopyable 클래스 같이봐요
// ② -관리하고 있는 자원에 대해 참조 카운팅을 수행한다.
//		shared_ptr로 선언을 하면 소멸자를 선언하지 않는다. -> 선언할 필요가없다.
//		객체 소멸과정을 잊은게 아니라 컴파일러가 생성한 소멸자를 통해 동작한다.
class MUTEX_Lock2 { 
private:
	shared_ptr<mutex>mutexptr; //원시 포인터 대신 shared_ptr로 대신했다.
public:
	explicit MUTEX_Lock2(mutex* pm) :mutexptr(pm, lock) {
		//shared_ptr을 초기화 하는데 , 가리킬 포인터로 mutex객체의 포인터를 사용하고
		//삭제자로 unlcok의 함수를 사용합니다.
		lock(mutexptr.get());
	}
};
// ③ -관리하고있는 자원을 진짜로 복사합니다.
//		"자원을 다 썼을때 각각의 사본을 확실히 해제하는것"
//		깊은 복사를 수행하자
// ④ -관리하고 있는 자원의 소유권을 옮깁니다.
//		auto_ptr을 사용하자.


//	★★★정리
//	- RAII 객체의 복사는 그 객체가 관리하는 자원의 복사문제를 안고가기 때문에., 그 자원을 어떨게 복사하는냐에 따라 RAII
//		객체의 복사 동작이 결정됩니다.
//	- RAII 클래스에 구현하는 일반적인 복사 동작은 복사를 금지하거나 참조카운팅을 해주는선으로 마무리 하는것 입니다.

#pragma endregion

#pragma region 14. 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할수 있도록 하자
class MUTEX_Lock3 {
private:
	shared_ptr<mutex>mutexptr; 
public:
	explicit MUTEX_Lock3(mutex* pm) :mutexptr(pm, lock) {


		lock(mutexptr.get());
	}
};

#pragma endregion


