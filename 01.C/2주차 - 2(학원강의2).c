/*#include<stdio.h>
#include<stdlib.h>*/

/*int main() {
	int a;
	int b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("a : %d \n", a);
	printf("&a : %d \n", &a);
	printf("b : %d \n", b);
	printf("&b : %d \n", &b);

	getchar();
	getchar();
	getchar();

	return 0;
}*/

/*int main() {
	int a;
	int* pa;

	a = 100;
	pa = &a; //포인터에는 주소를 담아준다
	printf("a : %d\n", a);
	printf("&a : %d\n", &a);
	printf("pa : %d\n", pa);
	printf("*pa : %d\n", *pa);

	return 0;
}*/

/*int main() {
	int a;
	int b;
	int c;
	int* pa;

	a = 100;
	b = 200;
	c = 300;
	pa = &a; //pa안에 a의 값을 넣어준다

	printf("b : %d\n", b);//b의 저장된 값을 보여준다
	printf("&b : %d\n", &b);//c의 주소값을 보여준다
	printf("&c : %d\n", &c);//b의 주소값을 보여준다
	printf("pa : %d\n", pa);//pa에 저장된 a의 값을 보여준다
	printf("pa-1 : %d\n", pa-1);//a의 주소값에서 차이값만큼 빼준다
	printf("*(pa-1) : %d\n", *(pa-1));//pa-1의 주소값에 저장된 값을 보여준다. //Debug 말고 Relase로 바꿔준다.
	printf("*(pa-2) : %d\n", *(pa-2));

	getchar();
	getchar();
	getchar();

	return 0;
}*/

/*int main() {
	int  a[5];
	int i;
	int* pa;
	for (i = 0; i < 5; i++) {
		a[i] = i + 1;
	}
	pa = a;

	for (i = 0; i < 5; i++) {
		printf("a[%d] : %d\n", i, a[i]);
	}
	for (i = 0; i < 5; i++) {
		printf("pa[%d] : %d\n", i, pa[i]);
	}
	for (i = 0; i < 5; i++) {
		printf("pa + %d : %d\n", i, pa + i);
		printf("*(pa + %d) : %d\n", i, *(pa + i));
	}
	for (i = 0; i < 5; i++) {
		printf("a + %d : %d\n", i, a + i);
		printf("*(a + %d) : %d\n", i, *(a + i));
	}
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}*/

/*int main() {
	int a = 10;
	int* pa = &a;
	int** ppa = &pa; // 더블 포인터 

	printf("a : %d\n", a);
	printf("pa : %d\n", pa);
	printf("ppa : %d\n", ppa);

	printf("*pa : %d\n", *pa);
	printf("*ppa : %d\n", *ppa);
	printf("**ppa : %d\n", **ppa);


	getchar();

	return 0;

}*/

/*int main() {

	int a[2][2];
	int i, j;
	int** ppa;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			a[i][j] = (i + 2)*(j + 1);
		}
	}

	ppa = a;

	//printf("a : %d\n", a);
	//printf("*a : %d\n", *a);
	//printf("&a : %d\n", &a);
	//printf("**a : %d\n", **a);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("ppa[%d][%d] : %d\n", i,j, ppa[i][j]); //포인터의 증감연산자로 선언을 해준것
		}
	}

	getchar();

	return 0;
}*/

/*int main() { //동적할당

	int* pa;
	int* pa2;
	//double* pd;
	//int a = 10;
	//pa = &a;
	pa = (int*)malloc(sizeof(int));
	printf("pa : %d \n", pa);
	*pa = 100;
	printf("*pa : %d \n", *pa);

	//pd = (double*)malloc(sizeof(double));

	pa2 = pa;

	free(pa);
	free(pa2);
	//free(pd);

	getchar();

	return 0;
}*/

/*int main() { //싱글포인터의 동적할당
	int* pa;
	{
		int* pa2;
		pa2 = (int*)malloc(4); // pa2 = (int*)malloc(sizeof(int)); 
		*pa2 = 100;
		pa = pa2;
	}
	printf(" *pa : %d", *pa);
	free(pa);

	getchar();

	return 0;
}*/

/*int main() {

	//int* p;
	//int i;
	//p = (int*)malloc(sizeof(int)*5);
//
	//for (i = 0; i < 5; i++) {
	//	p[i] = i;
	//}
	//for (i = 0; i < 5; i++) {
	//	printf("%d\n", p[i]);
	//}

	int** pa;
	int i = 0;

	pa = (int**)malloc(sizeof(int*) * 2); //더블포인터로 힙 영역에 메모리를 할당해준다

	for (i; i < 2; i++) {
		pa[i] = (int*)malloc(sizeof(int) * 2); //스코프를 벗어나도 저장을 할수있다
	}

	for (i; i < 2; i++) {
		free(pa[i]); //힙에 할당하는 메모리를 순서대로 해제해야한다
	}

	getchar();

	return 0;
}*/
/////////////////////////밑은 과제
/*int main() {

	int size;
	int** pa;
	int i = 0;

	printf("행렬의 크기를 입력해주세요 : ");
	scanf_s("%d", &size);

	pa = (int**)malloc(sizeof(int*) * size);

	for (i; i < size; i++) {
		pa[i] = (int*)malloc(sizeof(int) * size);
	}

	for (i = 0; i < size; i++) {
		printf("%d\n", pa[i]);
	}


	for (i = 0; i < size; i++) {
		free(pa[i]);
	}

	free(pa);

	getchar();
	getchar();
	getchar();

	return 0;
}*/