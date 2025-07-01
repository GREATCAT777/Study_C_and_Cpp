//#include<iostream>
//#include<vector> //vector 컨테이너는 자동으로 메모리가 할당되는 배열
//
//using namespace std;
//
//int main() {
//
//	vector<int> L(5, 0); //초기값이 0인 원소가 5개인 배열을 생성{ = vector<int> L(5); }
//
//	vector<int> R(L); //L의 배열을 복사해서 R이라는 배열을 만듭니다
//
//	R.assign(5, 2); //2의 값으로 5개의 원소 할당
//
//	R.at(3); //3번째 원소를 참조합니다. 밑보다 속도는 느리지만 범위를 점검하므로 안전함
//	R[3]; //3번째 원소를 참조합니다.위보다 속도는 빠르지만 범위를 점검 안함
//
//	R.front(); //첫번째 원소를 참조합니다
//
//	R.back(); // 마지막 원소를 참조합니다
//
//	R.clear(); //모든원소 제거, 메모리는 남아있다
//
//	R.push_back(7); //마지막 원소 뒤에 7을 삽입합니다
//
//	R.pop_back(); //마지막 원소를 제거합니다
//
//	R.begin(); //첫번째 원소를 가리킵니다(iterator와 같이 사용)
//
//	R.end(); //마지막의 "다음"을 가리킵니다(iterator와 같이 사용)
//
//	R.rbegin(); //거꾸로해서 첫번째 원소를 가리킵니다(iterator와 같이 사용)
//
//	R.rend(); //거꾸로해서 마지막의 다음을 가리킵니다(iterator와 같이 사용)
//
//	R.reserve(10); //10개의 원소를 저장할 위치를 예약합니다(미리 동적할당 해놓기)
//
//	R.resize(8, 0); //크기를 8으로 변경한다 더 커졌을경우 default 값인 0으로 초기화한다
//
//	R.size(); //원소의 갯수를 리턴한다
//
//	R.capacity(); //할당된 공간의 크기를 리턴한다
//
//	R.swap(L);// 메모리값과 원소를 R과L 서로 전부 바궈줍니다
//
//	//vector<int>().swap(L); // 메모리값이 0인 임시 객체를 만들어서 스왑을 해줍니다 = 할당한 메모리를 프로그램이 끝나기 전에 없애고 싶을때 사용
//
//	R.insert(2, 3, 4);//2번째 위치에 3개의 4값을 삽입합니다(나머지는 뒤로 밀림)
//	
//	R.insert(2, 3); //2번째 위치에 3의 값을 삽입 합니다// 삽입한 곳의 iterator를 반환 합니다
//
//	R.erase(iter); //iter가 가리키는 원소를 제거합니다,size만 줄어들고 capacity는 그래도 남습니다
//
//	R.empty(); //vector가 비어있으면 true를 리턴합니다,비어있다의 기준은 size가 '0'이라는 뜻
//
//	/*vector의 멤버 형식;
//	iterator: 반복자 형식;
//	reserve_iterator: 역 반복자 형식;
//	value_type: 원소의 형식;
//	size_type: 원소의 개수의 형식; */
//
//
//	cout << "L의 원소 는? : ";
//	for (vector<int>::size_type i = 0; i < L.size(); i++)
//	{
//		cout << L.at(i) <<" ";
//	}
//	cout << endl;
//
//	cout << "[*iter] iterator : ";
//	vector<int>::iterator iter;
//	for (iter = R.begin(); iter != R.end(); iter++) {
//		cout << *iter <<" ";
//	}
//
//	getchar();
//	return 0;
//}