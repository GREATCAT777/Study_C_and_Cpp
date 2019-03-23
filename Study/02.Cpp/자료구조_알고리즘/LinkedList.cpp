#include <iostream>

namespace LinkedList {



	class List {
		struct Node {
			int data;
			Node* next;
			Node* prev;

			Node(int d) :data(d), next(NULL), prev(NULL) {};

			Node* push_back(Node* tail, int data) {
				Node* newTail = new Node(data);
				newTail->prev = tail; //새로운 꼬리의 이전은 현재 꼬리
				tail->next = newTail; //현재 꼬리의 다음은 새로운 꼬리
				return newTail;
			}

			Node* push_front(Node* head, int data) {
				Node* newHead = new Node(data);
				newHead->next = head;	//새로운 머리의 다음은 현재 머리
				head->prev = newHead;	//현재 머리의 이전은 새로운 머리 
				return newHead;
			}
		};
	private:
		Node* head;
		Node* tail;
		int size;
	public:

		List() :head(nullptr), tail(nullptr) { size = 0; }

		~List() {
			while (!empty()) {								//헤드가 null이 될때까지 순회
				this->pop_back();							//꼬리 부터 삭제
			}
			size = 0;
		}

		int getSize() {
			return size;
		}

		void push_back(int data) {							//맨 뒷자리에 추가하기

			if (head == nullptr)
				head = tail = new Node(data);				//머리,꼬리 새로 만들어주기
			else {
				tail = tail->push_back(tail, data);			//현재 꼬리뒤에 새로운 노드를 추가하고, 새로운 노드를 꼬리로 선언
				size++;
			}
		}

		void push_front(int data) {							//맨 앞자리에 추가하기
			if (tail == nullptr)
				tail = head = new Node(data);
			else {
				head = head->push_front(head, data);		//현재 머리 앞에 새로운 노드를 추가하고, 새로운 노드를 머리로 선언
				size++;
			}
		}

		void pop_front() {									//머리 날리기
			if (head == tail) {								//머리와 꼬리의 포인터가 같으면
				delete head;								//머리삭제
				head = tail = nullptr;						//머리와 꼬리 널로 초기화
			}
			else {
				Node* del = head;							//삭제대상으로 선언
				head = head->next;							//현재의 머리를 다음 순번에게 넘겨준다.
				delete del;									//선언된 대상 삭제
				size--;
			}
		}

		void pop_back() {									//꼬리 날리기
			if (head == tail) {
				delete head;
				head = tail = nullptr;	
			}
			else {
				Node* del = tail; 
				tail = tail->next; 
				delete del;	
				size--;
			}
		}

		void clear() {
			this->~List();									// 소멸자 호출로 연결된 모든 녀석들 삭제
		}
		bool empty() {
			return !head;									//헤드가 유무 판단.
		}

		Node* at(int number) {								//원소 찾기

			if (number > size || number <= 0)					//사이즈보다 크거나 0보다 작으면 바로 null 반환
				return nullptr;

			Node* cur = head;
			for (size_t i = 0; i < number; i++)
			{
				cur = cur->next;
			}
			return cur;
		}

		void Insert(int number,int data) {

			if (tail == nullptr || head == nullptr)
				tail = head = new Node(data);

			else {
			Node* cur = at(number);

			cur = cur->push_back(cur,data);

			size++;
			}
		}
	};
}

