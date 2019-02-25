#include <iostream>



class Coupon {
private:
	int discountAmount;
public:
	Coupon(int discountAmount) {
		this->discountAmount = discountAmount;
	}
	int getDiscountAmount() {
		return discountAmount;
	}
	int calculateDiscountAmount(int price) {

		printf("Coupon Discount : %d \n", discountAmount);

		if (price < discountAmount)
			return 0;
		return price - discountAmount;
	}
};


class LimitPriceCoupon : public Coupon {
private:
	int limitPrice;
public :
	LimitPriceCoupon(int limitPrice, int discountAmount) :Coupon(discountAmount){
		this->limitPrice = limitPrice;
	}
	int getLimitPrice() {
		return this->limitPrice;
	}
	int calculateDiscountAmount(int price) {
		printf("LimitPriceCoupon Discount : %d \n", limitPrice);
		if (price < this->limitPrice)
			return price;

		return this->Coupon::calculateDiscountAmount(price);
	}
};
int main() {

	//Coupon coupon = Coupon(300);
	//int price = coupon.calculateDiscountAmount(1000);

	LimitPriceCoupon lpcoupon = LimitPriceCoupon(5000, 1000);
	int discountAmount = lpcoupon.getDiscountAmount();
	int limitPrice = lpcoupon.getLimitPrice();

	int dfas = lpcoupon.calculateDiscountAmount(8000);

	getchar();
	getchar();

	return 0;
}