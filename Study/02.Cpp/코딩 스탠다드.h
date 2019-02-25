#pragma once

#pragma region My_Coding_Standard_Rules

#include <iostream>
#include <exception>

class 선언 { // 순서 private , public , protected
private:
	int m_int; //맴버 변수 선언시 m_써주기
	float m_float;
	//특이사항시 (싱글톤 등등) 일떄는 그냥 써주기
public :
	int getMember() { //get함수는 get뒤에는 대문자로
		return m_int;
	}
	void Calcul() { //일반 클래스의 상징함수는 대문자로 시작

	}
};

class Base {
	virtual void Print() = 0;
};
class Inheritance_A : public Base {
	void Print() override {
		printf("상속A");
	}
};
class Inheritance_B : public Base {
	void Print() override {
		printf("상속B");
	}
};

class Singleton { //싱글톤
private:
	Singleton() {
		CheckInstance();
	}
	static Singleton* _instance;

	void CheckInstance() {
		if (_instance == nullptr)
			_instance = new Singleton();
	}
public :
	Singleton& Instacne() {
		CheckInstance();

		return *_instance;
	}
};

class Factory{
public :
	Base* AnOperation() { return FactoryMethod(); } //실질적인 호출을 하는곳
protected :
	virtual Base* FactoryMethod() = 0;
};

class A_Creator : public Factory {
private:
	Base* FactoryMethod() override {
		return new Inheritance_A();
	}
};

class B_Creator : public Factory {
private:
	Base * FactoryMethod() override {
		return new Inheritance_B();
	}
};


class MyException :public _exception {

};

#pragma endregion
