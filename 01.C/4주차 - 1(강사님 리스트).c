/*#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node* next;
	int data;
} typedef Node;

Node* head = NULL; // 첫번째 노드
Node* tail = NULL; //끝나는 노드
int count = 0;

void InsertNode(int idx){

	if (idx<0 || idx> count) { //예외처리 
		printf("ERROR!\n");
		return;
	}

	Node* curNode = head; // 현재의 값
	Node* prevNode = curNode; //이전의 값
	Node* newNode = (Node*)malloc(sizeof(Node)); //새로 집어넣을 값
	int i;

	newNode->next = NULL;
	newNode->data = newNode; //자기자신의 주소값

	if (idx == 0) {
		newNode->next = head; // 맨앞부분에 집어넣을때
		head = newNode;
	}
	else if (idx == count) {
		tail->next = newNode; // 맨뒷부분에 집어넣을때
		tail = newNode;
	}
	else {
		for (i = 0; i < idx; i++) {
			prevNode = curNode; //중간에 집어넣을때
			curNode = curNode->next;
		}
		prevNode->next = newNode; //이전노드의 포인터를 새로운노드에 가리키고
		newNode->next = curNode; // 새로운 노드의 포인터를 현재노드에 가리킨다
	}

	curNode = head;

	for (i = 0; i < count; i++) {
		curNode = curNode->next;
	}
	tail = curNode;
	count++;

}

void PrintNode() {
	Node* curNode = head;
	while (curNode != NULL) {
		printf("curNode : %d\n", curNode->data );
		curNode = curNode->next;
	}
	printf("\n");
}

void AppenNode() {
	InsertNode(count);
} // 새로운 꼬리 노드 만들어주기

void NewHead() {
	InsertNode(0);
} //새로운 머리 만들어주기

void RemoveNode(int idx) {
	Node* curNode = head; // 현재의 값
	Node* prevNode = curNode; //이전의 값
	Node* delNode = curNode;
	int i;

	if (idx == 0) { //맨 앞의 노드를 삭제
		delNode = head; //삭제할노드를 정해주고
		head = head->next; //삭제할 노드의 주소값을 옮긴다음
		free(delNode); // 삭제할노드의 메모리할당을 풀어준다
	}
	else if (idx == count - 1) { //맨뒤의 노드를 삭제
		curNode = head;
		for (i = 0; i < count; i++) {
			prevNode = curNode;
			curNode = curNode->next;
		}
		delNode = curNode;
		prevNode->next = NULL;
		tail = prevNode;
		free(delNode);
	}
	else { //중간의 노드를 삭제
		curNode = head;
		for (i = 0; i < count; i++) {
			prevNode = curNode;
			curNode = curNode->next;
		}
		delNode = curNode;
		prevNode->next = curNode->next;
		free(delNode);
	}
	count--;
}

void FreeAllnodes() {
	Node* delNode;
	Node* curNode = head;
	int i;

	for (i = 0; i < count; i++) {
		delNode = curNode;
		curNode->next = delNode;
		free(delNode);
	}
}

int main() {
	InsertNode(0);
	PrintNode();

	InsertNode(0);
	PrintNode();

	InsertNode(0);
	PrintNode();
	
	InsertNode(count);
	PrintNode();

	InsertNode(1);
	PrintNode();

	puts("==============================");

	RemoveNode(1);
	PrintNode();

	RemoveNode(0);
	PrintNode();

	RemoveNode(count - 1);
	PrintNode();

	FreeAllnodes();

	getchar();

	return 0;
}*/