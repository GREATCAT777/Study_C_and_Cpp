/*#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node* next;
	int data;
}typedef Node;

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void deleteNode(Node* Node) {
	free(Node);
}

Node* curser(Node* head, int a) {
	Node* cur = head;
	int count = 0;

	while (cur != NULL) {
		if (count++ == a) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

int countNode(Node* head) {
	int count =0;
	Node* cur = head;

	while (cur != NULL) {
		cur = cur->next;
		count++;
	}
	return count;
}

void printNode(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	return 0;
}

void addfirstnode(Node* head, Node* newNode) {
		newNode->next = head;
		head = newNode;
		newNode->data = -1;
}

void addbetweennode(Node* cur, Node* newNode) {
	newNode->next = cur->next;
	newNode->data = -2;
	cur->next = newNode;
}

void addlastnode(Node* head, Node* newNode) {
		Node* cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newNode;
		newNode->data = -3;
}

void delfirstnode(Node** head) {
	Node* temp = *head;
	*head = temp->next;
	free(temp);
}

void delbeteweennode(Node* target) {
	Node* remove = target->next;
	target->next = remove->next;
	free(remove);
}

void dellastnode(Node* head) {
	while (head->next != NULL) {
		head = head->next;
	}
	free(head);
}

void Nodetoy(Node* head, Node* newNode, int s) {
	int a = 0;
	switch (s) {
	case 1: {
		printf("맨앞에 노드 추가\n");
		addfirstnode(head,newNode);
	}break;
	case 2: {
		printf("맨뒤에 노드 추가\n");
		addlastnode(head, newNode);
	}break;
	case 3: {
		printf("원하는 자리에 노드 추가\n");
		scanf_s("%d", &a);
		addbetweennode(curser(head, a), newNode);
	}break;

	case 4: {
		printf("맨앞에 노드 삭제\n");
		delfirstnode(head);

	}break;
	case 5: {
		printf("맨뒤에 노드 삭제\n");
		dellastnode(head);
	}break;
	case 6: {
		printf("원하는 자리의 노드 삭제\n");
		printf("원하는 자리를 입력해 주세요\n");
		scanf_s("%d", &a);
		delbeteweennode(curser(head, a - 1));
	}break;

	case 7: {
		printf("노드 갯수 세기\n");
		printf("노드 갯수는 %d개 입니다\n",countNode(head));
	}break;
	case 8 :{
		printf("저장된 노드값 출력\n");
		printNode(head);
	}break;

	default : printf("범위내 선택지를 입력해 주세요\n");
		break;
	}
	return 0;
}

int main() {
	int x,i;
	int s;//모드 전환
	Node* head = (Node*)malloc(sizeof(Node));
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* cur = (Node*)malloc(sizeof(Node));

	head->data = 0;

	printf("원하는 노드의 갯수를 입력해주세요 각 노드마다 순서 정보가 들어갑니다\n");
	scanf_s("%d", &x);

	for (i = 0; i < x; i++) {
		newNode = createNode(i+1);
		addlastnode(head, newNode);
	}

	while(x>0){
		printf("원하시는 모드를 설정해주세요\n");
		printf("노드 추가 ( 1.맨앞 , 2.가운데 자리 , 3.맨뒤 )\n");
		printf("노드 삭제 ( 4.맨앞 , 5.가운데 자리 , 6.맨뒤 )\n");
		printf("7. 노드 개수 확인 , 8.노드 출력\n");
		scanf_s("%d", &s);
		Nodetoy(head, newNode, s);
	}

	free(head);
	free(newNode);
	free(cur);

	getchar();
	getchar();

	return 0;
}*/