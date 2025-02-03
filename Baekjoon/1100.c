#include <stdio.h>
#pragma warning(disable:4996)


int main() {
	char ar[8][8];
	int i, j;
	int cnt = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			scanf("%c", &ar[i][j]);
		}
		getchar();
	}


	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (ar[i][j] == 'F') {
						cnt++;
					}
				}
			}
			else {
				if (j % 2 == 1) {
					if (ar[i][j] == 'F') {
						cnt++;
					}
				}
			}
		}
	}
	printf("%d", cnt);
}