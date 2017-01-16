#include <stdio.h>

int N;
int P[10001];
int cache[1001];

////////////////////////////////////////////////////
/////////proces(N) = max(P[i] + process(N-i)////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

void init()
{
	int i;

	for (i = 0; i <= N; i++)
		cache[i] = -1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int process(int n)
{
	int i;
	int* ret = &cache[n];

	if (n == 1)
		return *ret = P[1];
	if (*ret != -1)
		return *ret;

	*ret = P[n];
	for (i = 1; i <= N; i++)
	{
		if (n - i > 0)
		{
			*ret = max(*ret, P[i] + process(n - i));
		}
	}
	return *ret;
}

int main()
{
	int i;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	init();
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &P[i]);
	}
	printf("%d\n", process(N));
}