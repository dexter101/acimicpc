#include <stdio.h>
#define MAX 210

int N;
int time[100];
char answer[100];

int main()
{
	int time_sum = 0;
	int i;
	freopen("input.txt", "r", stdin);
	

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &time[i]);
		scanf("%c\n", &answer[i]);
	}
	i = 0;
	while (time_sum < MAX)
	{
		time_sum += time[i];
		if(answer[i] == 'N')

	}
}