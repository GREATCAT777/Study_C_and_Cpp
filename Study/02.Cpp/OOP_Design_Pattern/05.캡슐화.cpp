//캡슐화 : 객체가 내부적으로 기능을 어떻게 구현하는지를 감추는것이다.
// 내부기능 구현이 변경되더라도 그 기능을 사용한느 코드는 영향을 받지 않도록 만들어준다.

// 절차지향방식 코드
//class Member {
//private:
//	Date expiryDate;
//	bool male;
//public :
//	Date getExpiryDate() {
//		return expiryDate;
//	}
//	bool isMale() {
//		return male;
//	}
//};
//
//if (member.getExpiryDate() != null && member.getExpiryDate().getDate() < System.currentTimeMilis()) {
//	//만료되었을때의 처리
//}
//
////여성회원인 경우 만료기간이 지났어도 30일간은 서비스를 사용할수있도록 정책이 변경되었다고 가정해보자
//
//long day30 = 1000 * 60 * 60 * 24 * 30;
//if (
//	(member.isMale() 
//	&& member.getExpiryDate() != NULL
//	&& member.getExpiryDate().getDate() < System.currentTimeMilis())
//	||
//	(!member.isMale()
//	&& member.getExpiryDate() != NULL
//	&& member.getExpiryDate().getDate() < System.currentTimeMilis() - day30)
//) {
//	//만료되었을때의 처리
//}

//보기편한가? -> XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 절대 아니다.
//
//class Member {
//private:
//	static final long DAY30 = 1000 * 60 * 60 * 24 * 30;
//	Date expiryDate;
//	bool male;
//public:
//	bool isExpired() {
//		if (male) {
//			return expiryDate != null && expiryDate.getDate() < System.currentTimeMilis();
//		}
//
//		return expiryDate != null && expiryDate.getDate() < System.currentTimeMilis() - DAY30;
//};
//
//if (member.isExpired()) {
//	//만료에 따른 처리
//}

//캡슐화를 위한 두개의 규칙

//★데이터를 물어보지않는다.
// 데이터를 직접 가져오지않고 "get메서드 X" 기능을 실행해달라 요청해주자. "member.isExpired()"

//★데미테르의 법칙
//1.메서드에서 생성한 객체의 메서드만 호출
//2.파라미터로 받은 객체의 메서드만 호출
//3.필드로 참조하는 객체의 메서드만 호출

//void ProcessSome(Member member) {
//	if (member.getDate().getTime() < ............) {// 데메테르 법칙위반
//	}
//}
//
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//
//void ProcessSome(Member member) {
//	if (member.someMethod() < ............) {// 데메테르 법칙위반
//	}
//}

//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★마지막으로 보고가자★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
//
//class Customer {
//private:
//	Wallet wallet;
//public:
//	Wallet getWallet() {
//		return wallet;
//	}
//
//	int getPayment(int payment) {
//		if (wallet == NULL) throw new NotEnoughMoneyException();
//		if (wallet.getTotalMoney() >= payment) {
//			wallet.substractMoney(payment);
//			return payment;
//		}
//		throw new NotEnoughMoneyException();
//	}
//};
//
//class Wallet {
//private :
//	int money;
//public :
//	int getTotalMoney() {
//		return money;
//	}
//	void substractMoney(int debut) {
//		money -= debut;
//	}
//};
//
//class Paperboy {
//private :
//	int Payment = 1000;
//public :
//	void payTo(Customer customer) {
//		try {
//			int paidAmount = customer.getPayment(Payment);
//		}
//		catch (NotEnoughMoneyException ex) {
//			//다음에 요금받으러 오는 처리
//		}
//	}
//};
//
//class NotEnoughMoneyException {
//	//돈이엄서요....
//};





