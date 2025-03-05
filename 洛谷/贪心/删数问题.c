#include <stdio.h>
#include <string.h>

int main() {
	char a[200];
	int len, n;
	scanf("%s", a);
	len = strlen(a);
	scanf("%d", &n);
	for (int i = 0; i < len - 1; i++) {
		if (a[i] > a[i + 1]) {
			n--;
			for (int j = i; j < len - 1; j++) {
				a[j] = a[j + 1];
			}
			len--;
			i = -1;
		}
		if (n == 0)
			break;
	}
	
	for (int i = 0; i < len - 1; i++) {
		if (a[i] == '0') {
			for (int j = i; j < len - 1; j++) {
				a[j] = a[j + 1];
			}
			len--;
			i = -1;
		}
		else break;
	}
	for (int i = 0; i < len - n; i++) 
		printf("%c", a[i]);
	return 0;
}
