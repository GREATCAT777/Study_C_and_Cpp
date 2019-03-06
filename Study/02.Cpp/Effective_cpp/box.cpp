#include "box.h"
#include <iostream>
#include <stdio.h>

using namespace std;

template<typename T>
bool BOX::Box<T>::g_update = true;

//template<typename T>
//BOX::Box<T>::Box()
//{
//}

template<typename T>
BOX::Box<T>::Box()
{
}

template<typename T>
BOX::Box<T>::Box(T data) : Data(data) //Data = data 한줄 줄인것
{
}

template<typename T>
BOX::Box<T>::Box(T data, int x, int y) : Data(nullptr), posX(x), posY(y) //미리 정의된 생성자 형식에 덧붙임
{
}

template<typename T>
BOX::Box<T>::Box(int x, int y) : Data(nullptr),posX(x),posY(y)
{
}

template<typename T>
BOX::Box<T>::Box(const Box & rhs) : Data(rhs.Data) //복사 생성자
{
	this->posX = rhs.posX;
	this->posY = rhs.posY;
}

template<typename T>
BOX::Box<T>::~Box()
{
}

template<typename T>
bool BOX::Box<T>::Initialize()
{
	return false;
}

template<typename T>
bool BOX::Box<T>::Update()
{
	if (g_update || isupdate) {
		//  업데이트 하는지
	}

	return isupdate;
}

template<typename T>
void BOX::Box<T>::Endcall()
{
}

template<typename T>
T BOX::Box<T>::GetData() const // z후위에 const예약어를 붙이는 이유는 안에서 변수들의 값변경을 막기위함
{
	return Data;
}

template<typename T>
void BOX::Box<T>::SetData(const T& input)
{
	Data = input;
}

template<typename T>
void BOX::Box<T>::print() const
{
	cout << this->Data << endl;
}
