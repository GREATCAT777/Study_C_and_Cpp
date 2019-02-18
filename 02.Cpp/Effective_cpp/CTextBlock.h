#pragma once
#include <iostream>
using namespace std;

class CTextBlock
{
public:
	CTextBlock() {};
	~CTextBlock() {};

	size_t length() const { // 상수함수 
		if (!lengthIsValid) {
			textlength = strlen(pText);
			lengthIsValid = true;
		}
		return textlength;
	}

	char& operator[](size_t position) const
	{
		return pText[position];
	}

private:
	char* pText;
	mutable size_t textlength; //mutable 키워드는 어느때라도 (상수 맴버함수 안 이더라도 수정이 가능하다.)
	mutable bool lengthIsValid;
};

