#include <stdio.h>

int N;
int arr[100001][3];

int solveMax() {
	int dyn[3];
	dyn[0] = arr[1][0];
	dyn[1] = arr[1][1];
	dyn[2] = arr[1][2];

	for (int i = 2; i <= N; i++) {
		int value1 = dyn[0] + arr[i][0];
		int value2 = dyn[1] + arr[i][0];

		int value3 = dyn[0] + arr[i][1];
		int value4 = dyn[1] + arr[i][1];
		int value5 = dyn[2] + arr[i][1];

		int value6 = dyn[1] + arr[i][2];
		int value7 = dyn[2] + arr[i][2];

		dyn[0] = (value1 > value2) ? value1 : value2;
		dyn[1] = (value3 > value4) ? value3 : value4;
		dyn[1] = (dyn[1] > value5) ? dyn[1] : value5;
		dyn[2] = (value6 > value7) ? value6 : value7;
	}

	int max = (dyn[0] > dyn[1]) ? dyn[0] : dyn[1];
	max = (dyn[2] > max) ? dyn[2] : max;
	return max;
}

int solveMin() {
	int dyn[3];
	dyn[0] = arr[1][0];
	dyn[1] = arr[1][1];
	dyn[2] = arr[1][2];

	for (int i = 2; i <= N; i++) {
		int value1 = dyn[0] + arr[i][0];
		int value2 = dyn[1] + arr[i][0];

		int value3 = dyn[0] + arr[i][1];
		int value4 = dyn[1] + arr[i][1];
		int value5 = dyn[2] + arr[i][1];

		int value6 = dyn[1] + arr[i][2];
		int value7 = dyn[2] + arr[i][2];

		dyn[0] = (value1 < value2) ? value1 : value2;
		dyn[1] = (value3 < value4) ? value3 : value4;
		dyn[1] = (dyn[1] < value5) ? dyn[1] : value5;
		dyn[2] = (value6 < value7) ? value6 : value7;
	}

	int min = (dyn[0] < dyn[1]) ? dyn[0] : dyn[1];
	min = (dyn[2] < min) ? dyn[2] : min;
	return min;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

	printf("%d %d\n", solveMax(), solveMin());

	return 0;
}

