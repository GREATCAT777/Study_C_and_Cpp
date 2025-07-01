//#pragma region 프록시패턴
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <exception>
//
//using namespace std;
//
//
////제품 목록을 구성할때 관련된 모든 이미지를 로딩하도록 구현할수있는데, 이경우 불필요하게 메모리를 사용하는 문제가 발생할수있다,
////ex) 목록하단에 위치한 이미지는 실제로 스크롤 하기전에 화면에 보이지 않음에도 불구하고 목록을 구성할때 메모리에 이미지 정보를 로딩하게 된다.
////개인적인 생각으로 요즘 용량이 큰 파일들을 로딩할때 걸리는 시간이 오래걸리면 먼저 로딩된걸 먼저 보여주는 방식으로 해주면 답답하지 않을거같다.
//
//class Image {
//public:
//	virtual void draw() {};
//};
//
//class ReaLimange :public Image{
//public:
//	int x;
//	int y;
//public:
//	ReaLimange(string path) {	}
//	void draw() override {};
//};
//
//class ProxyImage : public Image {
//private:
//	string path;
//	ReaLimange* image;
//public:
//	ProxyImage(string path) {
//		this->path = path;
//	}
//	void draw() override {
//		if (image == nullptr) {
//			image = new ReaLimange(path);
//		}
//		image->draw();
//	}
//};
//
//class LIstUI {
//private:
//	vector<Image*> images;
//public:
//	LIstUI(vector<Image*>& images) : images(images) {}
//	void OnScroll(int start, int end) {
//		for (int i = start; i < end; i++)
//		{
//			Image* image = images[i];
//			image->draw();
//		}
//	}
//};
//
//void if_______Excution() {// 상위 이미지 4개만 바로 이미지를 로딩해야하는경우
//	vector<string> path; 
//	vector<Image*>* images;
//
//	//이미지 목록을 가져옴 path 는 이미 채워져있다 가정하고
//	images = new vector<Image*>(path.size());
//	for (int i = 0; i < path.size(); i++)
//	{
//		if (i <= 4)
//			images->push_back(	(Image*)(new ReaLimange(path.at(i)))	);
//		else
//			images->push_back(	(Image*)(new ReaLimange(path.at(i)))	);
//	}
//
//	//LIstUI 생성
//	LIstUI* listUI = new LIstUI(*images);
//}
//
//////////////////////////////////////////////////////////////////////////////
//
//
//class Service {
//public:
//	virtual void someMethods() {}
//};
//
//class ProtectedService :public Service {
//private:
//	CurrentContext * currentContext;
//public:
//	void someMethods() override {
//		if (!currentContext->getAuth()->isAdmin())
//			throw new AcessDeniedException();
//
//		this->Service::someMethods();
//	}
//};
//
//#pragma region 그냥 표현한것
//
//class CurrentContext {
//public:
//	Auth* getAuth() { return new Auth(); }
//};
//class Auth {
//public:
//	bool isAdmin() { return true; }
//};
//
//class AcessDeniedException : public exception{
//};
//
//#pragma endregion
//
//
//
//#pragma endregion