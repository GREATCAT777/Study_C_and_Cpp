////조건에 따라 다른 코드를 사용해야할때
//
//#include<iostream>
//
//#pragma region 변경전
//
//static enum State_E { NOCOIN, SETECTABLE, SOLDOUT };
//
//struct Product {
//	int id;
//	int price;
//};
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
//	void select(Product product) {
//		switch (state) {
//		case NOCOIN:
//			break;
//		case SETECTABLE:
//			provideProduct(product.id);
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
//public:
//	virtual bool isSelectable() {	}
//};
//
//class NoCoinState :public State {
//public:
//	void increaseCoin(int coin, VendingMachine vm) {
//		vm.increaseCoin(coin); //동전을 증가 시키고
//		vm.changeState(new SelectableSatate());//상태변환
//	}
//	void select(int productId, VendingMachine vm) {
//		printf("Beep!"); //동전이 없는 상태에서 선택하면 에러! Beep!!!
//	}
//	bool isSelectable() {
//		return false;
//	}
//};
//
//class SelectableSatate :public State {
//	void increaseCoin(int coin, VendingMachine& vm) {
//		vm.increaseCoin(coin);
//	}
//	void select(Product product, VendingMachine& vm) {
//		vm.provideProduct(product);
//		vm.decreaseCoin();
//
//		if (!vm.hasCoin()) {
//			vm.changeState(new NoCoinState());
//		}
//	}
//	bool isSelectable() {
//		return true;
//	}
//};
//
//class VendingMachine {
//private :
//	State* state;
//	int stackCoin;
//	Product curSelctedProduct;
//
//private:
//
//public:
//	VendingMachine() {
//		state = new NoCoinState();
//		stackCoin = 0;
//	}
//
//	void insertCoin(int coin) {
//		state->increaseCoin(coin,*this);
//		if (hasCoin()) {
//			changeState(new SelectableSatate());
//		}
//	}
//	void select(int productId) {
//		state->select(productId,*this);
//		if (state->isSelectable() && hasNoCoin()) {
//			changeState(new NoCoinState());
//		}
//	}
//	void changeState(State* newstate) {
//		this->state = newstate;
//	}
//	
//	void increaseCoin(int coin) {
//		stackCoin += coin;
//	}
//	void provideProduct(Product product) {
//		curSelctedProduct = product;
//	}
//	void decreaseCoin() {
//		if (stackCoin >= curSelctedProduct.price)
//			stackCoin -= curSelctedProduct.price;
//		else {
//			printf("코인이 충분하지 않습니다.");
//		}
//	}
//	bool hasCoin() {
//		return stackCoin >= 0 ? true : false;
//	}
//
//	bool hasNoCoin() {
//		return !hasCoin();
//	}
//};
//
////상태패턴에서 중요한점은 상태객체가 기능을 제공한다는 점이다.
////상태 별 처리 코드를 분리함으로써 콘텍스트의 코드가 간결해지고 변경의 유연함을 얻게된다.
//#pragma endregion