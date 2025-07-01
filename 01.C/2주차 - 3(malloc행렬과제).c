/*#include <stdio.h>
#include <stdlib.h>
int main() {

	int i = 0, j = 0;
	int** A;
	int** B;
	int** C;
	int result ,Re;
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
	
	printf("\n재시작?? Yes=1, No=0\n");
	scanf_s("%d", &Re);

	if (Re == 1) {
		printf("\n");
		main(); //메인 함수를 다시 불러와 시작한다(? 이게 가능한가 - 재귀함수 ㄱㄱ)
	}


	getchar();
	getchar();

	return 0;
}*/