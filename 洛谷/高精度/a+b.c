#include <stdio.h>
#include <string.h>
void reverse (int d[1000], int len) {
	int temp, mid = len/2;
	for (int i = 0, j = len - 1; i < mid, j >= mid; i++, j--) {
		temp = d[i];
		d[i] = d[j];
		d[j] = temp;
	}
}

int main () {
	int a[1000] = {0}, b[1000] = {0}, c[1000] = {0};
	char s1[1000], s2[1000];
	scanf("%s", s1);
	scanf("%s", s2);
	int lena = strlen(s1);
	int lenb = strlen(s2);
	int lenc = (lena > lenb) ? (lena + 1) : (lenb + 1);
	for (int i = 0; i < lena; i++) {
		a[i] = s1[i] - '0';
	}
	for (int i = 0; i < lenb; i++) {
		b[i] = s2[i] - '0';
	}
	
	reverse(a, lena);
	reverse(b, lenb);
	for (int i = 0; i < lenc; i++) {
		c[i] += a[i] + b[i];
		c[i+1] = c[i] / 10;
		c[i] = c[i] % 10;
	}
	lenc = lenc - 1;
	if (lenc >= 1) {
		while (c[lenc] == 0 && lenc >= 1) {
			lenc--;
		}
	}
	for (int i = lenc; i >=0; i--) {
		printf ("%d", c[i]);
	}
	
	return 0;
}