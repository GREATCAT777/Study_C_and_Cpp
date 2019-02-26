#pragma once

#pragma region My_Coding_Standard_Rules

#include <iostream>
#include <exception>

class Rules { //클래스 선언시 대문자로 시작
	// 순서 private 변수, public 변수 , protected변수, private 메서드, public 메서드 , protected 메서드
private:
	int m_int; //맴버 변수 선언시 m_써주기
	float m_float;
	//특이사항시 (싱글톤 등등) 일떄는 그냥 써주기
public :
	int getMember() { //get메서드는 get뒤에는 대문자로
		return m_int;
	}
	void Calc() { //일반 클래스의 메서드는 대문자로 시작 ->> "OOP"개념을 대입할때

	}
	//캡슐화를 단단히하자 -> public 매서드 내부에서 private메서드를 호출하는 쪽으로
	//하나의 클래스는 하나의 동작만 제발.... 지켜라
	////자식 클래스에서 부모 클래스의 메서드를 호출할때 " this->class::Function(); " 구조로 호출하자
};

class Base { //베이스클래스를 만들때에는 앞에 Base 접두어 선정
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
	Base* AnOperation() { return FactoryMethod(); } //실질적인 호출을 하는곳 ex) A_creator.AnOperation();
protected :
	virtual Base* FactoryMethod() = 0; //상속받은 객체를 통해 재정의를 하고
};

class A_Creator : public Factory { //Inheritance_A를 생성하는 녀석
private:
	Base* FactoryMethod() override {
		return new Inheritance_A();
	}
};

class B_Creator : public Factory {//Inheritance_B를 생성하는 녀석
private:
	Base * FactoryMethod() override {
		return new Inheritance_B();
	}
};

class MyException :public _exception {

};

#pragma endregion
