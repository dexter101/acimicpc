#include <stdio.h>

#define min(a,b) (a)>=(b) ? (b) : (a)

int cache[1000001];
int N;
int cnt = 0;
int process(int n)
{
	int *ret = &cache[n];
	int temp;
	int div_3 = 0 , div_2 = 0;

	if (*ret != -1)
		return *ret;
	if (n == 1)
		return *ret = 0;
	//*ret = 0;
	if (n % 3 == 0)
		div_3 = 1;
	if (n % 2 == 0)
		div_2 = 1;

	if (div_3 && div_2)
	{
		temp = min(process(n/3), process(n / 2));
		*ret = min(temp, process(n - 1));
		*ret += 1;
	}
	else if (div_3)
	{
		*ret = min(process(n / 3), process(n - 1));
		*ret += 1;
	}
	else if (div_2) {
		*ret = min(process(n / 2), process(n - 1));
		*ret += 1;
	}
	else {
		*ret = process(n - 1);
		*ret += 1;
	}

	return *ret;
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
	printf("%d\n", process(N));
}