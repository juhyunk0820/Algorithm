#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	calculate(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double distance;
	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		return -1;
	}
	else if ((distance < (double)(r1 + r2)) && abs(r1 - r2) < distance)
	{
		return 2;
	}
	else if (distance == (double)(r1 + r2) || distance == abs(r1 - r2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void) {
	int N;
	int x1, y1, x2, y2, r1, r2;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		printf("%d\n", calculate(x1, y1, r1, x2, y2, r2));
	}
	return 0;
}