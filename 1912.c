#include <stdio.h>

int arry[100001];
int cache[100001];

int main()
{
	int N;
	int max;
	int i;

	freopen("input.txt", "r", stdin);
	scanf("%d\n", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &arry[i]);

	for (i = 1; i <= N; i++)
	{
		if (cache[i - 1] + arry[i] > arry[i])
			cache[i] = cache[i - 1] + arry[i];
		else
			cache[i] = arry[i];
	}

	max = cache[1];
	for (i = 2; i <= N; i++)
		if (max < cache[i])
			max = cache[i];
	printf("%d", max);
}