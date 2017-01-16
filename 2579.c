#include <stdio.h>

#define max(a,b) (a) > (b) ? (a) : (b)

int cache[301][3];
int N;
int arry[301];

void init()
{
	int i, j;

	for (i = 0; i <= N; i++)
	{
		for (j = 0; j < 3; j++)
			cache[i][j] = -1;
	}
}

int process(int n, int count)
{
	int *ret = &cache[n][count];
	int Max = 0;
	if (n == 0)
		return *ret = 0;

	if (*ret != -1)
		return *ret;

	*ret = arry[n];

	switch (count)
	{
	case 0:
		if (N >= 2)
		{
			Max = max(process(n - 2, 0), process(n - 2, 1));
			*ret += Max;
		}
		break;
	case 1:
		if (N >= 1)
		{
			*ret += process(n - 1, count - 1);
		}
		break;
	}
	return *ret;
}


int main()
{
	int i;
	int ret = 0;
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	arry[0] = 0;
	init();

	for (i = 1; i < N + 1; i++)
	{
		scanf("%d", &arry[i]);
	}

	ret = max(process(N, 0), process(N, 1));

	printf("%d", ret);

}