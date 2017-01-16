#include <stdio.h>

int size; // 1<= size <= 500
int arry[500][500];
int cache[500][500];

int max(int a, int b) { return (a) > (b) ? (a) : (b); }

void init()
{
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < i +1; j++)
			cache[i][j] = -1;
}

int process(int row, int col)
{
	int* ret = &cache[row][col];

	if (row == 0)
		return *ret = arry[row][col];
	if (*ret != -1)
		return *ret;
	if (col == 0)
		return *ret = process(row - 1, col) + arry[row][col];
	if (col == row)
		return *ret = process(row - 1, col - 1) + arry[row][col];
	else {
		return *ret = max(process(row - 1, col), process(row - 1, col - 1)) + arry[row][col];
	}
}

int main()
{
	int i, j;
	int ret = -1;
	freopen("input.txt", "r", stdin);

	scanf("%d", &size);
	init();
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			scanf("%d", &arry[i][j]);
		}
	}
	for (i = 0; i < size; i++)
	{
		ret = max(ret, process(size-1, i));
	}
	printf("%d\n", ret);
}