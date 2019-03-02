////조건에 따라 다른 코드를 사용해야할때
//
//#include<iostream>
//
//#pragma region 변경전
//
//static enum State_E { NOCOIN, SETECTABLE, SOLDOUT };
//
//class VendingMachine {
//private:
//	State_E state = State_E::NOCOIN;
//public:
//	void insertCoin(int coin) {
//		switch (state) {
//		case NOCOIN:
//			increaseCoin(coin);
//			state = State_E::SETECTABLE;
//			break;
//		case SETECTABLE:
//			increaseCoin(coin);
//			break;
//		case SOLDOUT:
//			returnCoin();
//			break;
//		}
//	}
//
//	void select(int productID) {
//		switch (state) {
//		case NOCOIN:
//			break;
//		case SETECTABLE:
//			provideProduct(productID);
//			decreaseCoin();
//
//			if (hasNoCoin())
//				state = State_E::NOCOIN;
//			break;
//		case SOLDOUT: break;
//		}
//	}
//
//	void increaseCoin(int coin) {}
//	void provideProduct(int productID) {}
//	void decreaseCoin() {}
//	bool hasNoCoin() {}
//	void returnCoin() {}
//};
//
////조건이 추가될때마다 복잡해지고 중복 코드가 많이 등장한다.
////-> 상태에 따라 동일한 기능 요청의 처리를 다르게함
//
//#pragma endregion
//
//#pragma region 상태패턴을 적용한 것
//
//class State {
//public:
//	virtual void increaseCoin(int coin,VendingMachine vm) {};
//	virtual void select(int productId, VendingMachine vm) {};
//	virtual ~State() {};
//};
//
//class NoCoinSatate :public State {
//public:
//	void increaseCoin(int coin, VendingMachine vm) {
//		vm.insertCoin(coin); //동전을 증가 시키고
//		vm.changeState(new SelectableSatate());//상태변환
//	}
//	void select(int productId, VendingMachine vm) {
//		printf("Beep!"); //동전이 없는 상태에서 선택하면 에러! Beep!!!
//	}
//};
//
//class SelectableSatate :public State {
//	void increaseCoin(int coin, VendingMachine vm) {
//		vm.insertCoin(coin);
//	}
//	void select(int productId, VendingMachine vm) {
//		printf("Beep!"); //동전이 없는 상태에서 선택하면 에러! Beep!!!
//	}
//};
//
//
//
//class VendingMachine {
//private :
//	State* state;
//public:
//	VendingMachine() {
//		state = new NoCoinSatate();
//	}
//
//	void insertCoin(int coin) {
//		state->increaseCoin(coin,*this);
//	}
//	void select(int productId) {
//		state->select(productId, *this);
//	}
//	void changeState(State* newstate) {
//		this->state = newstate;
//	}
//};
//
//
//#pragma endregion
//
////상태패턴에서 중요한점은 상태객체가 기능을 제공한다는 점이다.