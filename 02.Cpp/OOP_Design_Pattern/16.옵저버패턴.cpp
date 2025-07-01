//
//
//#pragma region 옵저버 패턴
//
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
////웹사이트의 상태를 확인해서 응답속도가 느리거나 연결이 안되면 모니터링 담당자에게 이메일로 통지해주는 시스템을
////만들기위해 상태를 확인하려는 클래스를 구현하였다 하자.
////긴급한 메세지는 sms로도 바로 알려주는 기능을 추가해달라는 요구가 들어왔다 치자.
//
//
//class Status {
//public:
//	bool isNotNormal() {
//		return true;
//	}
//};
//
//Status* loadStatus() {
//	return new Status();
//}
//
//class EmailSender {
//public:
//	void sendEmail(Status* status) {}
//};
//
//class SmsSender {
//public:
//	void sendSms(Status* status) {}
//};
//
//class StatusChecker {
//private:
//	EmailSender emailSender;
//	SmsSender smsSender;
//public:
//	void check() {
//		Status* status = loadStatus();
//
//		if (status->isNotNormal()) {
//			emailSender.sendEmail(status);
//			smsSender.sendSms(status);
//		}
//	}
//};
//
////여기서 회사 내부 메신저로도 보내달라는 기능을 요구한다하면?
////이렇게 한객체의 상태변화를 정해지지 않은 여러 다른 객체에 통지하고싶을때 사용되는 패턴이 옵저버 패턴이다.
//
//#pragma endregion
//
//#pragma region 옵저버 패턴 적용후
//
//class StatusObserver {
//public:
//	string statusName;
//public:
//	virtual void onAbnormalStatus(Status status) {};
//};
//
//class StatusSubject {
//private:
//	map<string,StatusObserver*>* observers = new map<string, StatusObserver*>;
//public:
//	void add(StatusObserver* observer) {
//		observers->insert(make_pair(observer->statusName,observer));
//	};
//	void remove(StatusObserver* observer) {
//		observers->erase(observer->statusName);
//	};
//	void notifyStatus(Status* status) {
//		for(auto observer : *observers) {
//			observer.second->onAbnormalStatus(*status); //상태를 옵저버에 전달
//		}
//	};
//};
//
////옵저버에게 통지가 필요한 클래스
//
//class StatusChecker2 :public StatusSubject {
//public:
//	void check() {
//		Status* status = this->loadStatus();
//
//		if (status->isNotNormal())
//			this->StatusSubject::notifyStatus(status);
//	}
//	Status* loadStatus() {
//		return new Status();
//	}
//};
//
//class StatusEmailSender : public StatusObserver {
//private:
//	void sendEmail(Status status) {
//		//이메일 전송코드
//	}
//public:
//	//옵저버는 전달받은 상태값을 사용
//	void onAbnormalStatus(Status status) override {
//		sendEmail(status);
//	}
//};
//
//// 자 이제 이걸 어떻게 사용하느냐....
//
//void if_____Excution() {
//	StatusChecker2* checker = new StatusChecker2();
//
//	checker->add(new StatusEmailSender());
//	//checker->add(new 쏼라쏼라 클래스);
//
//
//	//쨔란!새로운 옵저버가 추가되어도 StatusChecker코드는 바뀌지 않는다.
//	//게임에서 몬스터들의 상태패턴에따라 변화하는 무언가를 구현해야할때 쓰면 유용할거같다.
//	//짱 좋음!
//}
//
////옵저버 패턴구현의 고려사항
////주제 객체의 통지기능 실행 주체
////옵저버 인터페이스의 분리
////통지시점에서의 주제 객체 상태
////옵저버 객체의 실행 제약 조건
//
//#pragma endregion
//
//
