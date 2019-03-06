#pragma once
#include <iostream>
using namespace std;

class TextBlock
{
public:
	TextBlock() {};
	~TextBlock() {};

	const char& operator[](size_t position) const
	{
		return text[position];
	}
	char& operator[](size_t position) {
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);

		// const_cast = const를 떼어낸다.
		//*this 타입에 const 를 붙인다.
		// op[]의 상수버전을 호출한다.
	}

private:
	std::string text;
};

