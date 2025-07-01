/*#include<stdio.h>
int main() {
	int MX, MY, MR, NX, NY, NR;

	printf("원의 좌표와 반지름의 길이를 넣어주세요\n");
	scanf_s("%d,%d,%d", &MX, &MY, &MR);
	printf("원의 좌표와 반지름의 길이를 넣어주세요\n");
	scanf_s("%d,%d,%d", &NX, &NY, &NR);

	if ( (	 (MX - NX)*(MX - NX) + (MY - NY)*(MY - NY)	) <= (MR + NR)*(MR + NR)) {
		printf("충돌합니다\n");
	}
	else
		printf("충돌하지 않습니다\n");

	return 0;
}*/

/*int main() {
	int MX, MY, MW, MH;
	int NX, NY, NW, NH;
	int r1, l1, t1, b1;
	int r2, l2, t2, b2;

	printf("사각형을 하나 입력해 주세요 (x,y),너비,높이: ");
	scanf_s("%d,%d,%d,%d",&MX,&MY,&MW,&MH);
	printf("다른 사각형을 하나 입력해 주세요 (x,y),너비,높이: ");
	scanf_s("%d,%d,%d,%d", &NX, &NY, &NW, &NH);

	l1 = MX;
	r1 = MX+MW;
	b1 = MY;
	t1 = MY+MH;

	l2 = NX;
	r2 = NX + NW;
	b2 = NY;
	t2 = NY + NH;


	//사각형 충돌 체크 , 두사각형을 이루는 구성의 선분을 선언하여 비교한다
	if (l1 <= r2 && r1 >= l2 && b1 <= t2 && t1 >= b2) {
		puts("충돌");
	}
	else puts("충돌 X");

	//getchar(); ?
		return 0;
}*/

/*int main() {
	int i;
	int arr[10];
	for (int a = 0; a < 10; a++) {
		scanf_s("%d",&i);
		arr[a] = i;
	}
	for (int a = 0; a < 10; a++) {
		printf("arr[%d] : %d\n",a, arr[a]);
	}

	return 0;

}*/ // 내가 만든것

/*int main() {
	int arr[10]; // = {10,32,5465,47684,456,87654,213,4766,4522,8762};
	for (int i = 0; i < 10; i++) {
		arr[i] = i * 10 + i;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	getchar();//아무입력이나 받을때까지 대기

	return 0;
}*/

/*int main() { // 구구단 출력
	//몇단을 출력할지 선택하세요 : 

	int dan[9]; // 여기에 구구단 결과값들을 저장
	int input; // 원하는 단수 입력해주기

	while (1) {
		scanf_s("%d", &input);
			if (input > 0) {
				for (int i = 0; i < 9; i++) {
					dan[i] = (i + 1)*input;
				}
				for (int i = 0; i < 9; i++) {
					printf("dan[%d] %d * %d = %d\n", input,input,i+1, dan[i]);
				}
			}
			else printf(" '0' 이상의 값을넣어주세요\n");
	}
	return 0;
}*/

/*int main() {
	int a[2][2] = { {1,2}, {3,4} };
	int b[2][2] = { {1,2}, {3,4} }; // 2행 2열인 배열
	int c[2][2];
	int i, j;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("c[%d][%d] = %d\n", i, j, c[i][j]);
		}
	}
	return 0;

}*/

/*int main() {
	int a[2][2] = { { 1,2 },{ 3,4 } };
	int b[2][2] = { { 5,6 },{ 7,8 } }; // 2행 2열인 배열
	int c[2][2];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("c[%d][%d] = %d \n", i, j, c[i][j]);
		}
	}
}*/

/*int main() { //삼중 for 문을 이용한 행렬 만들기

	int a[2][2];
	int b[2][2];
	int c[2][2];
	int result;
	int i, j, k;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			result = 0;
			for (k = 0; k < 2; k++) {

				result += a[i][k] * b[k][j];
			}
			c[i][j] = result;
		}
	}
	return 0;
}*/

/*int main() { //삼중 for 문을 이용한 행렬 만들기

	int a[3][3] = { { 1,1,1 },{ 1,1,1 },{ 1,1,1 } };
	int b[3][3] = { { 1,1,1 },{ 1,1,1 },{ 1,1,1 } };
	int c[3][3] = { { 1,1,1 },{ 1,1,1 },{ 1,1,1 } };
	int d[3][3];
	int result;
	int i, j, k,l;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				result = 0;

				for (l = 0; l < 3; l++) {
					result += a[i][k] * b[k][l] * c[l][j];
				}
				d[i][j] = result;
			}
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%5d", d[i][j]);
		}
		printf("\n");
	}


	getchar();

	return 0;
} // 집에서 체크해보기*/

/*int main() {
	
	int  a[3][3];
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {

			a[i][j] = (i + 1) * 10 + j + 1;

		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {

			printf( "a[%d][%d] : %d\n", i,j,a[i][j]);

		}
	}

	return 0;

}*/