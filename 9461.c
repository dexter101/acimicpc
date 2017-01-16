#include <stdio.h>

int T, N;
long long cache[101];

void init()
{
	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 1;
	cache[4] = 2;
	cache[5] = 2;

}
long long process(int n)
{
	long long *ret = &cache[n];

	if (n < 0)
		return *ret = 0;
	if (*ret != 0)
		return *ret;

	*ret = process(n - 1) + process(n - 5);
	return *ret;

}

int main()
{
	int i;
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	init();
	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);
		printf("%lld\n",process(N));
	}

}