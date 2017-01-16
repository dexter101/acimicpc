#include <stdio.h>

#define DIV 10007

///////////////////////////////////////////////
///////////return *ret = *ret % DIV////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

int N;
long long cache[1001];

long long process(int n)
{
	long long *ret = &cache[n];

	if (n == 0 || n == 1)
		return *ret = 1;
	
	if (*ret != -1)
		return *ret;

	*ret = process(n - 1) + 2 * (process(n - 2));

	return *ret = *ret % DIV;
}

void init()
{
	int i;

	for (i = 0; i <= N; i++)
		cache[i] = -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	init();
	printf("%lld\n", process(N));
}