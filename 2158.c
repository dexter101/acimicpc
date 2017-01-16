#include <stdio.h>

#define Max(a,b) (a)>(b)? (a):(b)

int N;
int cache[10000][3];
int arry[10000];

void init()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++)
			cache[i][j] = -1;
}

int process(int i, int flag)
{
	int *ret = &cache[i][flag];

	if (i == 0) {
		if (flag == 1)
			return *ret = arry[i];
		else
			return *ret = 0;

	}
	if (i == 1) {
		if (flag == 2) {
			return *ret = arry[i - 1] + arry[i];
		}
		else if (flag == 1) {
			return *ret = arry[i];
		}
		else {
			return *ret = arry[i - 1];
		}
	}
	if (*ret != -1)
		return cache[i][flag];

	switch (flag) {
	case 0:
		*ret = Max(process(i - 1, 2), process(i - 1, 1));
		break;
	case 1:
		*ret = process(i - 1, 0) + arry[i];
		break;
	case 2:
		*ret = process(i - 1, 1) + arry[i];
		break;
	}
	return *ret;
}

int main()
{
	int i;
	int max = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	init();
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arry[i]);
	}
	max = Max(process(N - 1, 0), process(N - 1, 1));
	max = Max(max, process(N - 1, 2));
	printf("%d\n", max);
}
