//class FlowController {
//public: 
//	void process() {
//		FIleDataReader reader = new FIleDataReader(filename);
//		byte[] plainBytes = reader.read();
//
//		ByteEncryptor encryptor = new ByteEncryptor();
//		byte[] encryptedBytes = encryptor.encrypt(plainBytes);
//
//		FileDataWriter writer = new FileDataWriter();
//		writer.write(encryptedBytes);
//	}
//};

//위 와 같이 한객체가 다른객체를 생성하거나 다른객체의 함수를 호출할떄 이를 그 객체에 의존한다고 표현한다.
//FlowController가 FIleDataReader,ByteEncryptor,FileDataWriter 에 의존한다.
//파라미터로 전닿받는 경우에도 의존한다고 볼수있다.

//	void process(ByteEncryptor encryptor) { //내부에서 encryptor를 사용할 가능성이 높다.}



//class Authenticator {
//public :
//	bool authenticate(string id, string password) {
//		Member m = findMemberByid(id);
//		if (m == NULL) return false;
//
//		return m.equalPassword(password);
//	}
//};
//
//class authenticationHandler {
//public :
//	void handleRequest(string inuptId, string inputPassword) {
//		Authenticator auth = new Authenticator();
//		if (auth.authenticate(inuptId, inputPassword)) {
//			//일치할때의 처리
//		}
//		else {
//			//불일치할때의 처리
//		}
//	}
//};



//잘못된아이디나 암호가 틀린것인지 여부를 확인해서 시스템상에 로그로 남겨달라는 요구가 추가되었다.

//class Authenticator {
//public :
//	void authenticate(string id, string password) {
//		Member m = findMemberByid(id);
//		
//		if (m == NULL)
//			throw new MemberNotFoundException();
//
//		if (!m.equalPassword(password))
//			throw new InvalidPasswordException();
//	}
//};
//
//class authenticationHandler {
//public :
//	void handleRequest(string inuptId, string inputPassword) {
//		Authenticator auth = new Authenticator();
//
//		try {
//			auth.authenticate(inuptId, inputPassword);
//		}
//		catch (MemberNotFoundException ex) {
//			//아이디가 잘못되었을경우
//		}
//		catch (InvalidPasswordException ex) {
//			//비밀번호가 틀렸을경우
//		}
//	}
//};

//내가 변경되면 나에게 의존하고있는 코드에 영향을 준다.
// 나의 요구가 변경되면 내가 의존하고 있는 타입에 영향을 준다.
