#include <stdio.h>

int N;
int arry[100001][2];
int cache[100001][2];

int max(int a, int b) {
	return a < b ? b : a;
}

void init()
{
	int i;

	for (i = 0; i <= N; i++)
	{
		cache[i][0] = -1;
		cache[i][1] = -1;
	}
}

int process(int n, int row)
{
	int *ret = &cache[n][row];

	if (n == 0)
		return *ret = arry[n][row];
	if (n == 1)
		return *ret = arry[0][(row + 1) % 2] + arry[n][row];
	if (*ret != -1)
		return *ret;
	*ret = max(process(n - 2, 0), process(n - 2, 1));
	*ret = max(*ret, process(n - 1, (row + 1) % 2));

	*ret += arry[n][row];

	return *ret;
}

int main()
{
	int T;
	int i;

	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &arry[i][0]);
		for (i = 0; i < N; i++)
			scanf("%d", &arry[i][1]);
		init();
		printf("%d\n", max(process(N-1, 0), process(N-1, 1)));
	}
}