#include <stdio.h>
#include <math.h>

int main()
{
	int T;
	int x1, x2;
	int y1, y2;
	int r1, r2;
	double d1;
	int rr, min;
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		d1 = sqrt((double)((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
		rr = (r1 + r2);
		min = abs(r1 - r2);
		if (d1 == 0)
		{
			if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
		}
		else
		{
			if (min < d1 && d1 < rr)
				printf("2\n");
			else if (d1 == min || d1 == rr)
				printf("1\n");
			else if (d1 == 0 || d1 > rr || d1 < min)
				printf("0\n");
				
		}
	}
}