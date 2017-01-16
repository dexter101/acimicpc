#include <stdio.h>

int N;
int arry[1001];
int cache[1001];

int max(int a, int b)
{
	return a > b ? a : b;
}

void init()
{
	int i;
	for (i = 1; i <= N; i++)
		cache[i] = -1;
}

int process(int n)
{
	int* ret = &cache[n];
	int i;

	if (N == 1)
		return *ret = 1;
	if (*ret != -1)
		return *ret;

	*ret = 0;

	for (i = 1; i < n; i++) {
		if (arry[i] < arry[n])
			*ret = max(*ret, process(i));
	}
	return *ret = *ret + 1;
}


int main()
{
	int i;
	int ret = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &arry[i]);
	}
	init();
	for (i = 1; i <= N; i++)
		ret = max(ret, process(i));
	printf("%d\n", ret);
}