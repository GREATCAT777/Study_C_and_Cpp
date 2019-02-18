/*#include <stdio.h>
int main() {
	int ML, MR, MT, MB;//M사각형의 왼쪽,오른쪽,위,아래좌표 = (ML,MB) ~ (MR,MT)
	int NL, NR, NT, NB;//M사각형의 왼쪽,오른쪽,위,아래좌표 = (NL,NB) ~ (NR,NT)

	printf("기준 사각형의 왼쪽위,오른쪽아래의 마주보는 꼭지점을 입력하세요\n");
	scanf_s("%d,%d,%d,%d", &ML, &MT, &MR, &MB);
	printf("충돌 사각형의 왼쪽위,오른쪽아래의 마주보는 꼭지점을 입력하세요\n");
	scanf_s("%d,%d,%d,%d", &NL, &NT, &NR, &NB);

	if (ML <= NR && NL <= MR && NB <= MT && MB <= NT) {
		printf("두사각형이 충돌하였습니다\n");
	}
	else
		printf("두사각형은 떨어져 있습니다\n");

	return 0;
}*/