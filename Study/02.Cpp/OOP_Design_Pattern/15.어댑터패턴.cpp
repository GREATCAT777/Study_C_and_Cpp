//#pragma region 어댑터 패턴
//
//#include <string>
//using namespace std;
//
////클라이언트가 요구하는 인터페이스와 재사용하려는 모듈의 인터페이스가 일치하지 않을때 사용할 수 있는 패턴이 어댑터 패턴이다.
//
//struct SearchResult{
//	SearchResult(string key) { };
//};
//
//class TolrClient {
//public:
//	QueryResponse * query(const TolrQuery* tolrQuery) { return new QueryResponse(); };
//};
//
//class TolrQuery {
//public:
//	TolrQuery(const string& key){}
//};
//
//class QueryResponse {
//public:
//	QueryResponse() {}
//};
//
//class SearchService {
//public:
//	virtual SearchResult* search(string key) {};
//};
//
//class SerachServiceTolrAdaptor : public SearchService {
//private:
//	TolrClient* tolrClient = new TolrClient();
//
//public:
//	SearchResult* search(string key) override {
//		TolrQuery* tolrQuery = new TolrQuery(key);
//
//		QueryResponse* reponse = tolrClient->query(tolrQuery);
//		SearchResult* result = convertToResult(reponse);
//		return result;
//	};
//
//	SearchResult* convertToResult(QueryResponse* reponse) {
//
//		//reponse 가지고~~~~~ 쏼라쏼라
//
//		string retKey = "하와와.... 뭔말이에오... 알기쉽게 설명해주세오;;;;";
//		return new SearchResult(retKey);
//	}
//};
//
//// 이번에는 내공이 부족하여 다음번으로 넘어가겠소... 하....
//
//
//#pragma endregion
