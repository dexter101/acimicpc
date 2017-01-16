#include <stdio.h>

#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) > (b) ? (b) : (a)

int first;
int second;

int n, k;
int arry[5000001];

void init()
{
	int i, temp;
	
	for (i = 0; i < n; i++) {
		scanf("%d", &arry[i]);
	}
	if (n == 1)
	{
		first = arry[0];
		return;
	}
	if (k == 1)
	{
		first = arry[0];
		second = arry[0];
		return;
	}

	first = max(arry[0], arry[1]);
	second = min(arry[0], arry[1]);
	for (i = 2; i < k; i++)
	{
		if (arry[i] >= first) // 1등
		{
			temp = first;
			first = arry[i];
			second = temp;
		}
		else if (arry[i] > second)
			second = arry[i];
	}
}

void sort()
{
	int i;
	int temp;
	int min_val = 1000000001;

	if (k == 1)
	{
		for (i = 0; i < n; i++)
			min_val = min(min_val, arry[i]);
		first = min_val;
		return;

	}


	for (i = k; i < n; i++)
	{
		if (arry[i] < first)
		{
			if (arry[i] > second)
			{
				first = arry[i];
			}
			else
			{	
				first = second; 
				second = arry[i]; //여기서 세컨이 arry[i] 가 아닐수도 있다 !! ㅠㅠㅠ 방법 자체의 문제
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	init();
	
	sort();

	printf("%d\n", first);

}