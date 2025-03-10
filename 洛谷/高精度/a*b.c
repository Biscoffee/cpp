#include <stdio.h>
#include <string.h>
#define MAX 100001
void reverse (int d[MAX], int len) {
	int temp, mid = len/2;
	for (int i = 0, j = len - 1; i < mid, j >= mid; i++, j--) {
		temp = d[i];
		d[i] = d[j];
		d[j] = temp;
	}
}

int main () {
	char s1[MAX], s2[MAX];
	int a[MAX], b[MAX], c[MAX] = {0};
	scanf("%s", s1);
	scanf("%s", s2);
	int lena = strlen(s1);
	int lenb = strlen(s2);
	int lenc = lena + lenb;
	for (int i = 0; i < lena; i++) {
		a[i] = s1[i] - '0';
	}
	for (int i = 0; i < lenb; i++) {
		b[i] = s2[i] - '0';
	}
	
	reverse(a, lena);
	reverse(b, lenb);
	for (int i = 0; i < lenb; i++) {
		for (int j = 0; j < lena; j++) {
			c[i+j] += b[i] * a[j];
			c[i+j+1] += c[i+j] / 10;
			c[i+j] = c[i+j] % 10;
		}
	}
	lenc = lenc - 1;
	while (c[lenc] == 0 && lenc >= 1) {
		lenc--;
	}
	for (int i = lenc; i >= 0; i--) {
		printf("%d", c[i]);
	}
	
	return 0;
}
