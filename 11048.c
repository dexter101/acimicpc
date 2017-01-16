#include <stdio.h>

int N, M;
int cache[1001][1001];
int arry[1001][1001];

int max(int a, int b)
{
	return a > b ? a : b;
}

void init()
{
	int i, j;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			cache[i][j] = -1;
}

int process(int n, int m)
{
	int *ret = &cache[n][m];
	
	if (n == 1 && m == 1)
		return *ret = arry[1][1];
	if (*ret != -1)
		return *ret;
	*ret = 0;

	if (m != 1 && n != 1)
		*ret = max(*ret, process(n - 1, m - 1));
	if (m != 1)
		*ret = max(*ret, process(n, m - 1));
	if (n != 1)
		*ret = max(*ret, process(n - 1, m));
	
	return *ret = *ret + arry[n][m];
}

int main()
{
	int i, j;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	init();
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%d", &arry[i][j]);
		}
	}
	printf("%d\n", process(N, M));
}