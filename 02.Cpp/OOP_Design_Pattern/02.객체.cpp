// 객체의 핵심은 기능을 제공하는것
//ex)소리제어 객체 : 소리크기증가 기능, 소리크기 감소 기능 , 음소거

// 보통 객체가 제공하는 기능을 오퍼레이션이라 칭한다.
// 오퍼레이션의 사용법은 세가지로 구성되며 시그니처라 칭한다.

// 1.기능식별 이름
// 2.파라미터 및 파라미터 타입
// 3.기능 실행 결과값

// 객체가 제공하는 모든 오퍼레이션의 집합을 '인터페이스(interface)'라 칭하고,
// 서로 다른 이터페이스를 구분할 때 사용되느 명칭이 타입(type)이다.
// 인터페이스는 객체를 사용하기 위한 일종의 명세나 규칙이다.


//class VolumeController {
//private :
//	int volume;
//public :
//	void increaseVolume(){
//		volume++;
//	}
//	void decreaseVolume() {
//		volume--;
//	}
//	void mute() {
//		volume = 0;
//	}
//	double getVolumeRate() {
//		return ((double)volume / (double)100);
//	}
//};


//											3.write 실행 요청
//						[암호화 처리 객체] ------> [파일쓰기 객체]
//			1.read()실행 요청	↓
//								||
//								↑	2.byte배열 리턴
//						 [파일 읽기 객체]


// FileInputStream _iStream = new FileInputStream(filename);
// byte[] data = new byte[512];
// int readBytes = _iStream.read(data);

