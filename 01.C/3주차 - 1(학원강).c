/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {

	int i = 0, j = 0;
	int** A;
	int** B;
	int** C;
	int result,R;
	int Ah, Aw, Bh, Bw; //행,열,행,열

	printf("배열A의 행,열 크기는? : ");
	scanf_s("%d,%d", &Ah, &Aw);

	printf("배열B의 행,열 크기는? : ");
	scanf_s("%d,%d", &Bh, &Bw);

	//동적할당
	A = (int**)malloc(sizeof(int*)*Ah); //이중포인터에 (int * '행'크기)만큼 메모리 할당,배열의 '행'
	B = (int**)malloc(sizeof(int*)*Bh);
	C = (int**)malloc(sizeof(int*)*Ah);
	
	for (i=0; i < Ah; i++) { //'행'크기만큼 반복
		A[i] = (int*)malloc(sizeof(int) * Aw); //(int * '열'크기)만큼 종적메모리 할당, 배열의 '열'
	}
	
	for (i = 0; i < Bh; i++) { 
		B[i] = (int*)malloc(sizeof(int) * Bw);
	}
	for (i = 0; i < Ah; i++) {
		C[i] = (int*)malloc(sizeof(int) * Bw);
	}

	/////////////////////////////////////////////////////////////
	for (i=0; i < Ah; i++) {
		for (j=0; j < Aw; j++) {
			A[i][j] = 1; //행렬의 원소 채우기
		}
	}
	for (i = 0; i < Bh; i++) {
		for (j = 0; j < Bw; j++) {
			B[i][j] = 1; 
		}
	}
	/////////////////////////////////////////////////////////////
	printf("A배열\n");
	for (i=0; i < Ah; i++) {
		for (j=0; j < Aw; j++) {
			printf("%5d", A[i][j]); //행렬 출력
		}
		printf("\n");
	}

	printf("B배열\n");
	for (i = 0; i < Bh; i++) {
		for (j = 0; j < Bw; j++) {
			printf("%5d", B[i][j]);
		}
		printf("\n");
	}

	//////////////////////////////////////////////////////

	if (Aw == Bh) {
		for (i = 0; i < Ah; i++) { //C행렬 채우기
			for (j = 0; j < Bw; j++) {
				result = 0;
				for (int k = 0; k < Aw; k++) {

					result += A[i][k] * B[k][j];
				}
				C[i][j] = result;
			}
		}

		printf("C배열\n");

		for (i = 0; i < Ah; i++) { 
			for (j = 0; j < Bw; j++) {
				printf("%5d", C[i][j]); //C행렬 출력
			}
			printf("\n");
		}

	}
	else {
	printf("두행렬은 곱할수없습니다\n");
	}
	

	for (i = 0; i < Ah; i++) { //행크기만큼 반복
		free(A[i]); //2차원 배열의 '열' 공간 메모리 헤제
	}
	free(A); //2차원 배열의 '행'공간 메모리 헤제

	for (i = 0; i < Bh; i++) {
		free(B[i]);
	}
	free(B);

	for (i = 0; i < Ah; i++) {
		free(C[i]);
	}
	free(C);
	
	scanf_s("%d", &R);
	if (R == 1) {
		main();
	}

	getchar();
	getchar();

	return 0;
}*/

/*int add(int x , int y) { //보기 편하게 만든 코드
	
	int result = 0;
	
	if (x > 0 && y > 0) {
		result = x + y;
	}

	return result;
}
void printadd(int x, int y) { ///다른 함수의 의존성을 낮추는것에 유리
	
	int result = 0;
	
	if (x > 0 && y > 0) {
		result = x + y;
	}
	
	printf("%d\n", result);
}
int main() {

	int x, y;

	scanf_s("%d %d",&x,&y);

	printf("%d \n",add(x,y));
	printadd(x, y);

	getchar();
	getchar();

	return 0;
}*/

/*void calc(int x, int y, char z) {
	if (z == '+') {
		printf("%d", x + y);
	}
	else if (z == '-') {
		printf("%d", x - y);
	}
	else if (z == '*') {
		printf("%d", x * y);
	}
	else if (z == '/') {
		printf("%d", x / y);
	}
}

main() {
	int a, b;
	char c;
	
	scanf_s("%d %d",&a,&b);
	scanf_s("%d", &c);

	calc(a, b, c);

	getchar();
	getchar();

	return 0;

}*/

/*int calc(int x, int y, int z){

	int result = 0;
	if (x >= 0 && z > 0) {

		switch (y) {
		case 43 : result = x + z; //+
			break;
		case 45 : result = x - z; //-
			break;
		case 42 : result = x * z;// *
			break;
		case 47 : result = x / z;// /
			break;
		default: printf("연산에러"); result = 0;
			break;
		}

	}
	else result = 1;

	return result;
}


int main(){

	int x = 0, z = 0;
	char  p;
	int y = 0;
	printf("계산식을 입력하세요\n");

	scanf_s("%d,%d", &x,&z);

	scanf_s("%s", &p);
	y = p;

	printf("%d\n", y);

	printf("%d\n", calc(x, y, z));

	getchar();
	getchar();
	getchar();
	getchar();
	getchar();

	return 0;
}*/
 ///집가서 마저 만들기
/*void clac(int x, int y, char z) {
	int result = 0;
	switch (z) {
	case '+' : result = 
		break;
	case '-' : result = 
		break;
	case '*' : result = 
		break;
	default :
		break;
	}
	if (z == '/') {
		printf
	}
	else
	{
		printf
	}
}

int main() {

	int x, y;
	char op;
	scanf_s("%d %d", &x, &y);
	getchar();
	scanf_s("%c", &op, 1);

	clac(x, y, op);
}*/

/// 노트 필기 메모리 할당 보는법
/*int func(int a1, int a2, int a3) {
	int b1, b2, b3, result;
	b1 = a1;
	b2 = a2;
	b3 = a3;
	result = b1 + b2 / b3;
	return result;
}

int main() {
	int a = 1;
	int b = 3;
	int c = 5;

	int d = func(a, b, c);

	

	getchar();

	return 0;

}*/

/*int swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

	return x, y;
}
int main() {
	int a = 4;
	int b = 5;

	swap(&a,&b);

	printf("%d %d", a, b);

	getchar();
	getchar();

	return 0;
}*/

/*int swap(int* a, int* b, int* c, int* d) {
	int temp = *a;
	*a = *d;
	*d = temp;

	temp = *b;
	*b = *c;
	*c = temp;

	return a, b, c, d;
}
int main() {
	int q = 4, w = 6, e = 1, r = 15;

	swap(&q, &w, &e, &r);

	printf("%d %d %d %d",q,w,e,r);

	getchar();
	getchar();

	return 0;
}*/

/*int reverseArr(int* arr, int arrsize) {
	int* newArr = (int*)malloc(sizeof(int)*arrsize);
	int i;
	for (i = 0; i < arrsize; i++) {
		newArr[i] = arr[i];
		// *(newArr[i]= *(arr+i)
	}
	for (i = 0; i < arrsize; i++) {
		arr[i] = newArr[arrsize - 1 - i];
	}
	free(newArr);
}
int  main() {
	int a[10];
	int i;
	for (i = 0; i < 10; i++) {
		a[i] = i;
	}

	reverseArr(a, 10);
	
	for (i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

	getchar();
	getchar();
	getchar();

	return 0;
}*/

//여러가지 자료형의 모음체

/*struct Entity{ // 4byte로 맞춰놓는것이 좋다  - 데이터 처리와 각종 버그 피할수있음 

	int hp;
	int mp;
	char name[12];
} typedef Entity;

typedef int WORD;

int main() {
	Entity ent, ent2;

	ent.hp = 100;
	ent.mp = 50;

	ent2.hp = 1000;
	ent2.mp = 100;

	//WORD num;
	//num = 100;

	printf("%d %d\n", ent.hp, ent.mp);
	printf("%d %d\n", ent2.hp, ent2.mp);

	getchar();
	getchar();

	return 0;
}*/

/*struct Game{
	int Buy;
	int Sell;
	int Money;
}typedef Game;

int main() {
	int num;

	Game Menu[10];
	Game buyer;
	for (int i = 0; i < 10; i++) {
		Menu[i].Buy = 5000 + i*100;
		Menu[i].Sell = 2500 + i * 200;
	}
	printf("어떤상품을 원하시나요? 1~10");
	scanf_s("%d",&num);
	
	printf("현재 소비자가 가지고 있는돈은 얼마인가요?\n");
	scanf_s("%d", &buyer.Money);

	if (buyer.Money > Menu[num].Buy) {
		printf("메뉴를 살수잇습니다 . 만약 다시 되파신다면 %d원 손해입니다", Menu[num].Buy - Menu[num].Sell);
	}


	getchar();
	getchar();
	getchar();

	return 0;
}*/

/*struct Product {
	int price;
	int reselPrice;
}typedef Product;

struct Customer {
	int money;
}typedef Customer;

int main() {
	Customer c;
	Customer* pc;   ///4바이트
	Product prod[10];

	pc = &c;
	pc->money;

	for (int i = 0; i < 10; i++) {
		prod[i].price = (i + 1) * 1000;
		prod[i].reselPrice = (i + 1) * 30;
	}

	printf("소비자의 예산을 입력해주세요\n");
	scanf_s("%d", &(c.money)); ///같은의미
	scanf_s("%d", &(pc->money)); ///같은의미

	for (int i = 0; i < 10; i++) {
		if (c.money >= prod[i].price) {
			puts("구매가능\n");
			printf("되팔면 %d원 손해\n", prod[i].price - prod[i].reselPrice);
		}
		else {
			puts("구매불가능\n");
		}
	}
	puts("");

	getchar();
	getchar();
	getchar();

	return 0;
}*/

/*struct Node
{
	struct Node* next;
	int data[3];
}typedef Node;

void AddNode(Node* head, Node* newNode) {
	Node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = newNode;
}

int main() {
	Node* head = (Node*)malloc(sizeof(Node)); //sizeof에서 자료구조를 관리할때 몇바이트를 할당할지 계산하여 숫자로 넣어준다
	
	Node* node;

	Node* node2;
	
	head->data[0] = 10;
	head->data[1] = 20;
	head->data[2] = 30;
	head->next = NULL;
	

	node = (Node*)malloc(sizeof(Node));
	node->data[0] = 100;
	node->data[1] = 200;
	node->data[2] = 300;
	node->next = NULL;
	AddNode(head, node);

	node2 = (Node*)malloc(sizeof(Node));
	node2->data[0] = 100;
	node2->data[1] = 200;
	node2->data[2] = 300;
	node2->next = NULL;
	AddNode(head, node2);


	free(head);
	free(node);
	free(node2);

	getchar();

	return 0;
}*/

//지렁이 몸통 한칸 한칸을 리스트의 구조로 만든다

/*struct Node {
	struct Node* next;
	int data;
}typedef Node;


void AddLastNode(Node* head, Node* newNode) {
	Node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = newNode;
}


void AddFirstNode(Node* head, Node* newNode) {
	Node* cur = head;
	if(cur->next != NULL) {
		newNode->next = cur;
		newNode = cur;
	}
	else {
		while ();
	}
}

void AddbetweenNode() {

}


int main(){
	Node* head = (Node*)malloc(sizeof(Node));








	free(head);

}*/