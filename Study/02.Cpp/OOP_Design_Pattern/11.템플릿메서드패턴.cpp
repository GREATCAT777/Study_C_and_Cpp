//#include <iostream>
//#include <vector>
//#include <exception>
//#include <string>
//
//using namespace std;
//
////프로그램을 구현하다보면 완전히 동일한 절차를 가진 코드를 작성할때가 있다.
////이렇게 일부 구현이 다를때 사용할수있는 패턴이 템플릿 메서드 패턴이다.
//
////템플릿 메서드 패턴은 두가지로 구성이된다.
////-실행과정을 구현한 상위 클래스
////-실행과정의 일부단계를 구현한 하위클래스
//
//class Auth {
//
//};
//
//class AuthException : public exception {
//public:
//	AuthException()  {
//		printf("아이디가 존재하지 않습니다.");
//	}
//};
//
//class Authenticator {
//private:
//	exception* createException() {
//		return new AuthException();
//	}
//public:
//	Auth authenticate(string id, string pw) {
//		if (!doAuthenticate(id, pw))
//			throw createException();
//		return createAuth(id);
//	}
//	virtual ~Authenticator() {}
//protected:
//	virtual bool doAuthenticate(string id, string pw) = 0;
//	virtual Auth createAuth(string id) = 0;
//};
//
//// 이제 이 클래스를 상속받아 가상함수를 재정의해야한다.
//// 전체 실행과정은 Authenticator의 authenticate()에서 실행한다.
//// 유저의 인증방식을 어떤식으로 바꿔도 큰 틀에서 벗어나지 않는다. -> 짱인데?
//// 코드 중복문제도 해결했고 다양성을 지양한다.
//
//// -상위 클래스가 흐름제어의 주체이다.
//
//
////이렇게 상위 클래스에서 실행시점이 제어되고 , 기본구현을 제공하면서,
////하위 클래스에서 알맞게 확장할수 있는 메서드를 훅(hook)메서드라고 부른다.
//
//#pragma region 템플릿메서드 + 전략패턴
//
////spring Framework에서 Template로 끝나는 클래스들
////템플릿 메서드를 실행할때, 변경되는 부분을 실행할 객체를 파라미터를 통해서 전달받는 방식으로 구현되어있다.
//
//#pragma endregion
