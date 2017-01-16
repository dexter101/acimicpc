#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[1001];
bool visited[1001];

void dfs(int v)
{
	visited[v] = true;
	printf("%d ", v);

	for (int i = 0; i < a[v].size(); i++)
	{
		int next = a[v][i];
		if (!visited[next])
			dfs(next);
	}
}

void bfs(int v)
{
	queue<int> q;

	memset(visited, false, sizeof(visited));
	visited[v] = true;

	q.push(v);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);

		for (int i = 0; i < a[node].size(); i++)
		{
			if (!visited[a[node][i]]) {
				visited[a[node][i]] = true;
				q.push(a[node][i]);
			}
		}
	}
}

int main()
{
	int n, m, start;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &start);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	printf("\n");
	bfs(start);
}