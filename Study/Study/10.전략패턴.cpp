//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#pragma region 기존
//
//class Item {
//private:
//	bool is_fresh;
//	int price;
//public:
//	bool isFresh() {
//		return is_fresh;
//	}
//	int getPrice() {
//		return price;
//	}
//};
//
//class Calculator {
//public:
//	int Calculate(bool firstGuest, vector<Item>& items) {
//		int sum = 0;
//		for (int i = 0; i < items.size(); i++)
//		{
//			if (firstGuest)
//				sum += (items[i].getPrice() * 0.9); //첫 손님 10퍼 할인
//			else if (items[i].isFresh())
//				sum += (items[i].getPrice() * 0.8); //약간 상한거 20퍼 할인
//			else
//				sum += items[i].getPrice();
//		}
//		return sum;
//	}
//};
//
//// 서로 다른 계산 정책들이 한코드에 섞여있어 , 정책이 추가될수록 코드분석을 어렵게 만든다.
////가격 정책이 추가될때마다. calculate 매서드를 수정하는것이 점점 어려워진다. 
////-> 변수추가, if블록 하나더 추가
//#pragma endregion
//
//#pragma region 전략패턴으로 재구성된 구조
//
//class DiscountStrategy //인터페이스 클래스
//{
//public:
//	virtual int getDiscountPrice(Item& item) {};
//	virtual int getDiscountPrice(int totalPrice) {};
//	virtual ~DiscountStrategy() {};
//};
//
//class DC_FirstGuest :public DiscountStrategy { // 새로운 계산법이 늘어갈때마다 새로운 클래스를 작성해준다.
//public:
//	int getDiscountPrice(Item& item) { //첫손님 할인
//		return (item.getPrice() * 0.9);
//	}
//};
//class DC_LastGuest : public DiscountStrategy {//마지막 손님 할인
//public:
//	int getDiscountPrice(Item& item) {
//		return (item.getPrice() * 0.8);
//	}
//};
//class DC_NonFreshItems : public DiscountStrategy { //덜 신선한 재료 할인
//public:
//	int getDiscountPrice(Item& item) {
//		return (item.getPrice() * 0.8);
//	}
//};
//
//
//class Calculator_DP { //계산기에서는 전략을 생성하지않고 받은 전략으로만 계산한다.
//private:
//	DiscountStrategy* strategy;
//public:
//	Calculator_DP(DiscountStrategy* discountStrategy) :strategy(discountStrategy) {	}
//
//	void SetDiscountStrategy(DiscountStrategy* discountStrategy) {
//		this->strategy = discountStrategy;
//	}
//
//	int Calculate(vector<Item>& items) {
//		int sum = 0;
//		for (int i = 0; i < items.size(); i++) {
//
//			sum += strategy->getDiscountPrice(items[i]); //보기 편해졌고 여러가지를 정의할수있다.
//
//		}
//		return sum;
//	}
//};
//
//class Counter {//계산대.... 그냥 로직보여줄려고 만든 이름 크게 신경안써도 된다.
//public: 
//	DiscountStrategy* strategy;
//	vector<Item> items;
//public:
//
//	void onRegistoritems_ButtonClick(vector<Item>& items) {
//		//사야할 물건들 계산대에서 등록할때 = 바코드 찍을때
//		this->items = items;
//	}
//	void onFirstGuest_ButtonClick() {
//		//첫손님 할인 버튼
//		strategy = new DC_FirstGuest();
//	}
//	void onLastGuest_ButtonClick() {
//		//마지막 손님 할인 버튼
//		strategy = new DC_LastGuest();
//	}
//	void onNonFreshItems_ButtonClick() {
//		//덜 신선한 재료 할인 버튼
//		strategy = new DC_NonFreshItems();
//	}
//	void onCalculation_ButtonClick() {
//		//계산 버튼을 누를때
//		Calculator_DP* calc = new Calculator_DP(strategy);
//		int price = calc->Calculate(items);
//	}
//};
//
//#pragma endregion
