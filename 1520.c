#include <stdio.h>

int M;
int N;
int arry[501][501];
int cache[501][501];

int process(int row, int col)
{
	int *ret = &cache[row][col];

	if (row == 0 && col == 0)
		return 1;
	if (*ret != -1)
		return *ret;

	*ret = 0;
	if (row != 0 && arry[row][col] < arry[row - 1][col])
		*ret += process(row - 1, col);
	if (col != 0 && arry[row][col] < arry[row][col - 1])
		*ret += process(row, col - 1);
	if (row != N - 1 && arry[row][col] < arry[row + 1][col])
		*ret += process(row + 1, col);
	if (col != M - 1 && arry[row][col] < arry[row][col + 1])
		*ret += process(row, col + 1);

	return *ret;
	
}

int main()
{
	int i, j;
	
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++) {
			scanf("%d", &arry[i][j]);
			cache[i][j] = -1;
		}
	}

	printf("%d\n", process(N - 1, M - 1));
	
	
}