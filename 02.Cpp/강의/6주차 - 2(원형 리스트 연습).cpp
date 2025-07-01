//#include<iostream>
//using namespace std;
//
//typedef int LData;
//
//class Node {
//private:
//	LData data;
//public:
//	Node * next;
//
//	Node() {}
//	Node(LData data) :data(data) {}
//
//	LData getdata()
//	{
//		return data;
//	}
//};
//
//class CLinkedList
//{
//private:
//	Node * tail;
//	Node *cur;
//	Node *before;
//	int numOfData;
//
//public:
//	CLinkedList();
//	void LInsert(LData data); //꼬리에 노드를 추가
//	void LInsertFront(LData data); //머리에 노드를 추가
//
//	bool LFirst(LData *pdata);
//	bool LNext(LData *pdata);
//	LData LRemove();
//	int LCount();
//};
//
//CLinkedList::CLinkedList()
//{
//	//Node *newNode = new Node; 더미노드 없음.
//	tail = nullptr;
//	cur = nullptr;
//	before = nullptr;
//	numOfData = 0;
//}
//
//void CLinkedList::LInsert(LData data)
//{
//	Node *newNode = new Node(data);
//
//	if (tail == nullptr)
//	{
//		tail = newNode;
//		tail->next = newNode;
//	}
//	else
//	{
//		newNode->next = tail->next;
//		tail->next = newNode;
//		tail = newNode;
//	}
//	numOfData++;
//}
//
//void CLinkedList::LInsertFront(LData data)
//{
//	Node *newNode = new Node(data);
//
//	if (tail == nullptr)
//	{
//		tail = newNode;
//		tail->next = newNode;
//	}
//	else
//	{
//		newNode->next = tail->next;
//		tail->next = newNode;
//	}
//	numOfData++;
//}
//
//bool CLinkedList::LFirst(LData *pdata)
//{
//	if (tail->next == nullptr)
//		return false;
//
//	before = tail;
//	cout << "LinkedList head: " << tail << endl;
//	cout << "LinkedList head->next: " << tail->next << endl;
//	cur = tail->next;
//	*pdata = cur->getdata();
//
//	return true;
//}
//
//bool CLinkedList::LNext(LData *pdata)
//{
//	if (tail == nullptr)
//		return false;
//
//	before = cur;
//	cur = cur->next;
//	*pdata = cur->getdata();
//
//	return true;
//}
//
//LData CLinkedList::LRemove()
//{
//	Node *rpos = cur;
//	LData rdata = rpos->getdata();
//
//	if (rpos == tail)
//	{
//		if (tail == nullptr)
//			tail = nullptr;
//		else
//			tail = before;
//	}
//
//	before->next = cur->next;
//	cur = before;
//
//	delete rpos;
//	numOfData--;
//	return rdata;
//}
//
//int CLinkedList::LCount()
//{
//	return numOfData;
//}
//int main() {
//	CLinkedList* cNode = new CLinkedList();
//	for (int i = 0; i < 5; i++)
//	{
//		cNode->LInsert(i);
//	}
//
//	delete(cNode);
//	getchar();
//	getchar();
//	return 0;
//}