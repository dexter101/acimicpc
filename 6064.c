#include <stdio.h>

#define min(a,b) (a)>=(b) ? (b) : (a)

int T;
int M, N, x, y;
int MAX;

int gcd(int a, int b)
{
	int i;
	int max_div = 1;
	int range = min(a, b);
	for (i = range; i >= 1; i--)
	{
		if (a%i == 0 && b % i == 0)
		{
			max_div = i;
			break;
		}
	}
	return max_div;
}
int find(int x1, int y1)
{
	int ret = -1;
	int i = 1;
	int a = x1 - M;
	int b = y1 - N;

	while (1)
	{
		if (N*i + b > MAX)
			break;
		
		if ((N*i + b - a) % M == 0)
		{
			ret = N * i + b;
			break;
		}
		i++;
	}

	return ret;
}

int main()
{
	int div;
	int a, b;
	int i;
	int GCD;
	long long ret =  -1;
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	while (T--)
	{
		
		ret = -1;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		GCD = gcd(M, N);
		MAX = M * N / gcd(M, N);
	
		printf("%d\n", find(x,y));

	}

}