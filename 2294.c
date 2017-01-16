#include <stdio.h>

#define INFINITE 999999999

int cache[10001];
int arry[101];
int n, k;

int min(int a, int b)
{
	return a < b ? a : b;
}
void init()
{
	int i;
	for (i = 0; i <= k; i++)
		cache[i] = -1;
}

int process(int N)
{
	int *ret = &cache[N];
	int i;

	if (N == 0)
		return 0;

	if (*ret != -1)
		return *ret;
	
	*ret = INFINITE;

	for (i = 0; i < n; i++) {
		if (N - arry[i] >= 0)
			*ret = min(*ret, process(N - arry[i]));
	}
	*ret = *ret + 1;

	return *ret;
}

int main()
{	
	int i;

	freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &n, &k);
	init();
	for (i = 0; i < n; i++)
		scanf("%d", &arry[i]);
	if (process(k) == INFINITE + 1)
		printf("-1\n");
	else
		printf("%d\n", process(k));
	printf("asd");
}