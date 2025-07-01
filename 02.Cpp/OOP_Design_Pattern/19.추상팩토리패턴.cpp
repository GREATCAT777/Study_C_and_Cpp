//
//#pragma region 추상팩토리 패턴
//#include <vector>
//
//using namespace std;
//
//const static int ENEMYCOUNT = 10;
//const static int OBSTACLECOUNT = 5;
//
//class EnemyFlight {
//private:
//	int atk;
//	int def;
//private:
//	void attackPower() {};
//	void defensivePower() {};
//public:
//	EnemyFlight(int atk, int def) :atk(atk), def(def) {};
//	EnemyFlight() {};
//};
//
//class Boss :public EnemyFlight {
//public:
//	Boss(int atk, int def) :EnemyFlight(atk, def) {};
//	Boss() {};
//	void specialAttack() {};
//	void attack() {};
//};
//
//class SmallFlight :public EnemyFlight{
//public:
//	SmallFlight(int atk, int def) :EnemyFlight(atk, def) {};
//	SmallFlight() {};
//	void attack() {};
//};
//
//class CloningBoss :public Boss {
//public:
//	CloningBoss(int atk, int def) :Boss(atk, def) {};
//	CloningBoss() {};
//};
//
//class StrongAttackBoss :public Boss {
//public:
//	StrongAttackBoss(int atk, int def) :Boss(atk, def) {};
//	StrongAttackBoss() {};
//};
//
//class MissileSmallFlight : public SmallFlight {
//public:
//	MissileSmallFlight(int atk, int def) :SmallFlight(atk, def) {};
//	MissileSmallFlight() {};
//};
//
//class DashSmallFlight : public SmallFlight {
//public:
//	DashSmallFlight(int atk, int def) :SmallFlight(atk, def) {};
//	DashSmallFlight() {};
//};
//
//class Obstacle {};
//
//class RockObstacle :public Obstacle {};
//
//class BombObstacle :public Obstacle {};
//
//
//class Stage {
//private:
//	int stageLevel;
//	Boss* boss;
//	vector<EnemyFlight*> enemies;
//	vector<Obstacle*> obstacles;
//
//private:
//	void createEnemies() {
//		for (int i = 0; i < ENEMYCOUNT; i++)
//		{
//			if (stageLevel == 1)
//				enemies[i] = new DashSmallFlight(1,1);
//			else if(stageLevel == 2)
//				enemies[i] = new MissileSmallFlight(1, 1);
//		}
//		if (stageLevel == 1)
//			boss = new StrongAttackBoss(1, 10);
//		else if (stageLevel == 2)
//			boss = new CloningBoss(5, 20);
//	}
//
//	void createObstacle() {
//		for (int i = 0; i < OBSTACLECOUNT; i++)
//		{
//			if (stageLevel == 1)
//				obstacles[i] = new RockObstacle();
//			else if (stageLevel == 2)
//				obstacles[i] = new BombObstacle();
//		}
//	}
//public:
//	Stage(int stageLevel) :stageLevel(stageLevel) {};
//};
//
//// 단계별로 적기,보스,장애물을 생성하는 규칙이 Stage클래스에 포함되있다는점...
//// 이럴땐 객체 생성 책임을 분리한다.
//// 이것이 추상팩토리 패턴
//
//#pragma endregion
//
//#pragma region 추상팩토리 패턴 적용
//
//class EnemyFactory {
//public:
//	static EnemyFactory* getFactory(int level) {
//
//		//적 생성 규칙 변경시 ,상속받아서 새로운 팩토리 클래스를 만들면됨(구현은 각자) -> 추상 팩토리!!!! 이거 던전 제너레이터에 쓸수있지 않을까?
//		if (level == 1)
//			return new EasyStageEnemyFactory();
//		else
//			return new hardEnemyFactory();
//	}
//	virtual Boss* createBoss() = 0;
//	virtual SmallFlight* createSmallFlight() = 0;
//	virtual Obstacle* createObstacle() = 0;
//};
//
//
//class EasyStageEnemyFactory :public EnemyFactory {
//public:
//	Boss* createBoss() override{
//		return new StrongAttackBoss();
//	};
//	SmallFlight* createSmallFlight()override {
//		return new DashSmallFlight();
//	};
//	Obstacle* createObstacle()override {
//		return new RockObstacle();
//	};
//};
//
//
//class hardEnemyFactory :public EnemyFactory {
//public:
//	Boss* createBoss()override {
//		return new CloningBoss();
//	};
//	SmallFlight* createSmallFlight() override {
//		return new MissileSmallFlight();
//	};
//	Obstacle* createObstacle()override {
//		return new BombObstacle();
//	};
//};
//
//class Stage_F {
//private:
//	EnemyFactory* enemyFactory;
//	Boss* boss;
//	vector<EnemyFlight*> enemies;
//	vector<Obstacle*> obstacles;
//public:
//	Stage_F(int level) {
//		//EnemyFactory객체를 구함
//		enemyFactory = EnemyFactory::getFactory(level);
//	}
//
//	void createEnemies() {
//		for (int i = 0; i < ENEMYCOUNT; i++)
//			enemies[i] = enemyFactory->createSmallFlight();
//
//		boss = enemyFactory->createBoss();
//	}
//	void createObstacle() {
//		for (int i = 0; i < OBSTACLECOUNT; i++)
//			obstacles[i] = enemyFactory->createObstacle();
//	}
//};
//
////아.... 사랑합니다..... 패턴 너무 좋아요
//
//#pragma endregion