#include <stdio.h>

//��Ŭ���� ȣ����
//gcd(a,b) = gcd(b,r) r = a%b
//r�� 0 �϶� �׶��� b�� �ִ�����
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