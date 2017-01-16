#include <stdio.h>
#include <stdlib.h>

int N;
int arry1[5];
int arry2[5];

int compare(const void *a, const void *b) {
	return (*(const int*)a - *(const int*)b);
}

int main()
{
	int i;
	int *ptr;
	int key;

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arry1[i]);
		arry2[i] = arry1[i];
	}

	qsort(arry2, N, sizeof(int), compare);
	for (i = 0; i < N; i++)
		printf("%d ", arry1[i]);
	printf("\n");
	for (i = 0; i < N; i++)
		printf("%d ", arry2[i]);
	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("%d : ", arry2[i]);
		key = arry2[i];
		ptr = (int*)bsearch(&key, arry1, 5, sizeof(arry1[0]), compare);
		if (ptr != NULL)
			printf("arr[%d]에서 %d를 찾았습니다.\n", (ptr - arry1), arry2[i]);
		else
			printf("못 찾았습니다.\n");
	}
	
}