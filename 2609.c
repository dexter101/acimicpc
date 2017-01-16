#include <stdio.h>

//유클리드 호제법
//gcd(a,b) = gcd(b,r) r = a%b
//r이 0 일때 그때의 b가 최대공약수
int gcd(int a, int b)
{
	int r = a % b;
	int result = 1;
	while (r != 0)
	{
		
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main()
{
	int A, B;
	long long LCD;
	int GCD;
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &A, &B);
	GCD = gcd(A, B);
	LCD = (A*B) / GCD;
	printf("%d\n", GCD);
	printf("%d", LCD);
}