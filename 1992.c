#include <stdio.h>
#include <stdlib.h>

int arry[65][65];
int N;

int check(int n, int a, int b)
{
	int ret = arry[a][b];
	int result = 0;
	int i, j;
	int test = (ret != arry[0][0]);

	for (i = a; i < a + n; i++)
	{
		for (j = b; j < b + n; j++) {
			test = (ret != arry[i][j]);
			if (test)
				return 0;
		}
	}
	return 1;
}


//n by n 행렬을 구한다
int process(int n, int a, int b)
{
	int i, j;
	if (n == 1) {
		printf("%d", arry[a][b]);
		return 1;
	}
	if (check(n, a, b))
		printf("%d", arry[a][b]);
	else
	{
		printf("(");
		process(n / 2, a, b);
		process(n / 2, a, b + n / 2);
		process(n / 2, a + n / 2, b);
		process(n / 2, a + n / 2, b + n / 2);
		printf(")");
	}

}

int main()
{
	int i, j;
	char c;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	scanf("\n");

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
		{
			scanf("%c", &c);
			arry[i][j] = atoi(&c);
		}
		scanf("\n");
	}

	process(N, 0, 0);
	
}