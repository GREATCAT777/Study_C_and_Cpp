//#include <stdio.h>
//int main() {
//	int a, b, c, d, e, f, g, h; //각점(a,b)(c,d)(e,f)(g,h)
//	int grad1, grad2; //기울기
//	int dex1, dex2; // 방정식 상수항
//	int F1, F2; //중간 계산값
//	int t, q; //교점의 좌표
//
//	printf("INPUT GRAPH1 POINT : ");
//	scanf_s("%d,%d,%d,%d", &a, &b, &c, &d);
//	printf("INPUT GRAPH2 POINT : ");
//	scanf_s("%d,%d,%d,%d", &e, &f, &g, &h);
//
//	grad1 = (b - d) / (c - a);
//	grad2 = (f - h) / (g - e);
//
//	dex1 = b - grad1 * a;
//	dex2 = f - grad2 * e;
//
//	F1 = grad1 - grad2;
//	F2 = dex1 - dex2;
//
//	t = -F1 / F2;
//	q = grad1 * t + dex1;
//
//	int temp;
//	if (a > c) {
//		temp = a;
//		c = a;
//		a = temp;
//	}
//	if (b > d) {
//		temp = d;
//		d = b;
//		b = temp;
//	}
//
//	if (a <= t && t <= c) {
//		if (b <= q && q <= d) {
//			printf("두선분이 교차한다\n");
//		}
//	}
//	else printf("두선분이 교차하지않는다\n");
//
//	return 0;
//}