#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////////////
///////////Process(N) = 3 * process(N-2) + 2 * process(N-4) + 2 * process(N-6) .....////
////////////////////////////////////////////////////////////////////////////////////////

int N;

int cache[31];

void init()
{
	int i;

	for (i = 0; i <= N; i++)
		cache[i] = -1;
	cache[2] = 3;
}

int process(int n)
{
	int *ret = &cache[n];
	int i;
	int mul = 2;

	if (n % 2 == 1)
		return *ret = 0;
	if (n == 0)
		return *ret = 1;
	if (n < 0)
		return *ret = 0;
	if (*ret != -1)
		return *ret;
	
	*ret = 0;
	*ret = 3 * process(n - 2);
	i = n - (2 * (mul++));
	while (i >= 0)
	{
		*ret += 2 * process(i);
		i = n - 2 * (mul++);
	}

	return *ret;
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	init();
	printf("%d\n",process(N));
}