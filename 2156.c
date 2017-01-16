#include <stdio.h>

int N;
int arry[10000];
int cache[10000][3];

int max(int a, int b) { return (a) > (b) ? a : b; }

void init()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++)
			cache[i][j] = -1;
	cache[0][0] = 0;
	cache[0][1] = arry[0];
	cache[0][2] = -9999999;
}

int process(int n, int count)
{
	int* ret = &cache[n][count];
	
	if (n == 0 && count == 0)
		return *ret = 0;

	if (*ret != -1)
		return *ret;

	if (count == 0) {
		*ret = max(process(n - 1, 1), process(n - 1, 2));
		*ret = max(process(n - 1, 0), *ret);
		return *ret;
	}
	return *ret = process(n - 1, count - 1) + arry[n];

}

int main()
{
	int i;
	int ret = -1;

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
		scanf("%d", &arry[i]);
	init();
	ret = max(process(N - 1, 0), process(N - 1, 1));
	ret = max(ret, process(N - 1, 2));
	printf("%d\n", ret);
}