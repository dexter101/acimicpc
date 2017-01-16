#include <stdio.h>

#define div 10007

long long cache[1001];

void init(int n)
{
	int i;
	for (i = 0; i <= n; i++)
		cache[i] = -1;
	
}

long long process(int n)
{
	long long *ret = &cache[n];

	if (n == 0 || n == 1)
		return 1;

	if (*ret != -1)
		return *ret;

	*ret = 0;
	*ret = process(n - 1) + process(n - 2);

	return *ret = *ret % div;
}

int main()
{
	int N;

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	init(N);

	printf("%lld\n", process(N));
}