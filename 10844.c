#include <stdio.h>

#define DIV 1000000000

int N;
long long cache[101][10];

void init()
{
	int i, j;

	for (i = 0; i <= N; i++)
		for (j = 0; j < 10; j++)
			cache[i][j] = -1;

}

long long process(int n, int count)
{
	long long* ret = &cache[n][count];

	if (n == 1) {
		if (count == 0)
			return *ret = 0;
		return *ret = 1;
	}
		

	if (*ret != -1)
		return *ret;

	if(count == 0)
		return *ret = process(n - 1, 1) % DIV;
	if (count == 9)
		return *ret = process(n - 1, 8) % DIV;

	return *ret = (process(n - 1, count - 1) + process(n - 1, count + 1)) % DIV; 
}


int main()
{
	int i;
	long long ret = 0;
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	init();
	for (i = 0; i < 10; i++)
		ret += process(N, i);
	printf("%lld\n", ret % DIV);
}