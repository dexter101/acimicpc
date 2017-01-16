#include <stdio.h>
#include <math.h>

int N, K;
int arry[101]; // 동전 가치
int cache[10001]; // 캐쉬
int count[101];
int total_count = 0;

int factorial(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}

void init()
{
	int i;

	for (i = 0; i <= K; i++)
		cache[i] = -1;
	for (i = 0; i < N; i++)
		count[i] = 0;

}
void count_init()
{
	int i;
	for (i = 0; i < N; i++)
		count[i] = 0;
}


int process(int n)
{
	int* ret = &cache[n];
	int i;
	int j;
	int temp;

	if (n == 0) {		
		return *ret = 1;
	}

	if (*ret != -1)
		return *ret;

	*ret = 0;

	for (i = 0; i < N; i++) {
		if (n - arry[i] >= 0) {
			count[i]++;
			total_count++;
			temp = process(n - arry[i]);
			temp *= factorial(total_count);
			for (j = 0; j < N; j++)
				temp /= factorial(count[j]);
			*ret += temp;
			count[i]--;
			total_count--;
		}
	}
	return *ret;
}

int main()
{
	int i;
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);
	init();
	for (i = 0; i < N; i++) {
		scanf("%d", &arry[i]);
	}
	printf("%d", process(K));
}