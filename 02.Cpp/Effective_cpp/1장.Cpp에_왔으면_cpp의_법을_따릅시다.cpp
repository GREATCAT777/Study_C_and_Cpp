//#include <iostream>
//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//#pragma region 1.#define을 쓰려거든 const,enum,inline을 떠올리자
//
//
//#define PI_MECRO 3.1415 //이렇게 말고
//const double PI_const = 3.1415; //이렇게 쓰자
//
//
//class 플레이어 { //클래스내의 정적 상수의 선언과 정의 방법
//private:
//	static const int HP; //선언
//	
//	enum { MaxSlot = 5}; //이건 나열자 둔갑술이라한다.
//	int Inven[MaxSlot]; //구식컴파일러에서 아래의 정의를 지원하지 않는다면 쓰자!
//};
//
//const int 플레이어::HP = 5; //정의 - 외부에서 하였다.
//
//
//
////중요하다!
//#define Return_MAX(a,b)	(a) > (b) ? (a) : (b) //가독성진짜.....
//
//void Exam1() {
//	int a = 5, b = 0;
//	Return_MAX(++a, b);		//a가 두번 증가합니다.
//	Return_MAX(++a, b+10);	//a가 한번 증가합니다.
//	// 말이되나? 이렇게 할바엔 다른식으로 정의하고말지 (애초에 쓰질말자 가독성도 떨어진다...)
//}
//
//template<typename T> //깔끔한 함수!
//inline int ReturnMAX(const T& a, const T& b) {
//	return  a > b ? a : b;
//}
//
//
////★★★ 정리
//// - 상수를 사용할때는 const객체 혹은 enum을 우선적으로 생각하자!
//// - 함수터럼쓰이는 메크로를 만드려면 inline함수를 우선 생각하자!
//#pragma endregion
//
//
//#pragma region 2.낌새만 보이면 const를 들이대보자.
//
//void const키워드의_무궁무진함() {
//
//	char greeting[] = "Hello";
//
//	char* p = greeting;					//비 상수 포인터, 비 상수 데이터
//
//	const char* p = greeting;			//비 상수 포인터, 상수 데이터
//
//	char* const p = greeting;			//상수 포인터, 비 상수 데이터
//
//	const char* const p = greeting;		//상수 포인터, 상수 데이터
//
//
//	// * 포인터 기준으로 왼쪽 오른쪽에 따라 성질이 달라진다!
//
//	//const * 포인터가 가리키는 대상이 상수!
//	//* const 포인터가 상수!
//
//
//	void 함수1(const 플레이어* p);
//	void 함수2(플레이어 const *p);
//	//둘다 (상수 클래스)의 포인터를 매개변수로 취하는 함수이다!
//
//
//	
//	vector<int> vec;
//
//	const vector<int>::iterator iter = vec.begin();
//	*iter = 10;										//iter는 T* const처럼 동작합니다.
//	//++iter;										//iter는 상수이다!
//
//	vector<int>::const_iterator Citer = vec.begin();
//	//*Citer = 10;									//Citer는 const T* 처럼 동작합니다.
//	++Citer;										//*Citer는 상수입니다.
//
//
//
//	class Rational{};
//	const Rational operator* (const Rational& lhs, const Rational& rhs);
//
//	Rational a,b, c;
//
//	//(a*b) = c; //만약 상수객체로 반환하지 않았다면 대입연산이 일어나는 참담한 상황이 벌어진다. 오타일뿐인데....!
//
//	//if (a * b = c); //비교할려고한것뿐인데 대입연산을 할뻔했다! 고마워 const!!!!
//
//}
//
//#pragma region 너무길어....
//
//#pragma region TextBlock
//
//class TextBlock
//{
//public:
//	TextBlock() {};
//	~TextBlock() {};
//
//	const char& operator[](size_t position) const
//	{
//		return text[position];
//	}
//	char& operator[](size_t position) {
//		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
//
//		// const_cast = const를 떼어낸다.
//		//*this 타입에 const 를 붙인다.
//		// op[]의 상수버전을 호출한다.
//	}
//
//private:
//	std::string text;
//};
//
//
//class CTextBlock
//{
//public:
//	CTextBlock() {};
//	~CTextBlock() {};
//
//	size_t length() const { // 상수함수 
//		if (!lengthIsValid) {
//			textlength = strlen(pText);
//			lengthIsValid = true;
//		}
//		return textlength;
//	}
//
//	char& operator[](size_t position) const
//	{
//		return pText[position];
//	}
//
//private:
//	char* pText;
//	mutable size_t textlength; //mutable 키워드는 어느때라도 (상수 맴버함수 안 이더라도 수정이 가능하다.)
//	mutable bool lengthIsValid;
//};
//#pragma endregion
//
//#pragma endregion
//
////★★★ 정리
//// - const를 붙여 선언하면 컴파일러가 사용상의 에러를 잡아내는데 도움을 줍니다. const는 어떤 유효범위에있는
////		객체에도 붙을수있으며, 함수 배개변수 및 반환 타입에도 붙을수있고 맴버함수에도 붙을수있습니다.
//// - 컴파일러 쪽에서 보면 비트수준 상수성을 지켜야하지만, 개년적인 상수성을 사용해서 프로그래밍하자
//// - 상수맴버 및 비상수 맴버 함수가 기능적으로 서로 똑같게 구현되어 있을 경우에는 코드 중복을 피하게 만들자
////		-> 비상수 버전에서 상수버전을 호출하도록 만들자!
//#pragma endregion
//
//
//#pragma region 3.객체를 사용하기전에 반드시 그 객체를 초기화하자.
//
//template<typename T>
//class Box
//{
//private:
//	bool m_isupdate = true;
//	static bool m_g_update = true;
//	T Data;
//	int posX;
//	int posY;
//
//public:
//	Box()
//	{
//	}
//	explicit Box(T data) : Data(data) //Data = data 한줄 줄인것
//	{
//	}
//
//	explicit Box(T data, int x, int y) : Data(nullptr), posX(x), posY(y) //미리 정의된 생성자 형식에 덧붙임
//	{
//	}
//
//	explicit Box(int x, int y) : Data(nullptr), posX(x), posY(y)
//	{
//	}
//
//	Box(const Box &rhs) : Data(rhs.Data) //복사 생성자
//	{
//		this->posX = rhs.posX; //이건 대입 하고있는것이다. 초기화가 아니다.
//		this->posY = rhs.posY;
//	}
//
//	~Box()
//	{
//	}
//
//	bool Initialize()
//	{
//		return true;
//	}
//
//	bool Update()
//	{
//		if (g_update || isupdate) {
//			//  업데이트 하는지
//		}
//		return isupdate;
//	}
//
//	void Endcall() {
//	}
//
//	T GetData() const // 후위에 const예약어를 붙이는 이유는 안에서 변수들의 값변경을 막기위함
//	{
//		return Data;
//	}
//
//	void SetData(const T& input)
//	{
//		Data = input;
//	}
//
//	void print() const
//	{
//		cout << this->Data << endl;
//	}
//};
//
//
////"별개의 번역 단위에서 정의된 비지역 정적 객체들의 초기화 순서는 정해져있지 않다"
//
//
//#pragma region 외부 소스파일
//
//class FileSystem {
//public:
//	size_t numDisks() const { return 1; }
//};
//
//FileSystem& tfs_g_Function() {
//	static FileSystem fs;
//	return fs;
//}
//
//extern FileSystem tfs_extern; 
//
//#pragma endregion
//
////현재는 같은 소스파일에 선언해두었지만 외부 소스파일에서 선언해두었다 가정하자
//
//
//class Directory { //라이브러리의 사용자가 외부에서 만든 클래스
//public:
//	Directory(int param) { //매개변수를 받아놓은건 두가지를 보여주기위함.... 다른건 없다
//		size_t disks = tfs_extern.numDisks(); //가장이상적으로 호출한경우다
//	}
//	Directory(float param) {
//		size_t disks = tfs_g_Function().numDisks(); //이렇게 호출해주어도 된다.
//	}
//};
//
//
//
////★★★ 정리
//// - 기본 제공타입의 객체는 직접 손으로 초기화 한다. 경우에 따라서(컴파일러 환경에따라서) 될수도 안될수도 있기 때문
//// - 생성자에서는 , 데이터 맴버에 대한 대입문을 생성자 본문 내부에 넣는 방법으로 맴버를 초기화 하지 말고 맴버 초기화 리스트 " :() " 를 즐겨 사용하자.
////		그리고 초기화 리스트에 데이터 맴버를 나열할때는 클래스에 각 데이터 맴버가 선언된 순서와 똑같이 나열합시다.
//// - 여러 번역 단위에있는 비지역 정적 객체들의 초기화 순서 문제는 피해서 설계해야합니다. 
////		비지역 정적 객체를 지역 정적 객체로 바꾸면 됩니다.
//
//#pragma endregion
//
//
//inline void Swap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main() {
//
//	return 0;
//}