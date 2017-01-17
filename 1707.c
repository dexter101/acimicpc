#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
 
using namespace std;
 
vector<int> a[20001];
int visited[20001];
 
void dfs(int v);
 
int main()
{
	int t;
	int V, E;
 
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	
	while (t--) {
		int u, v;
		bool flag = true;
		memset(visited, false, sizeof(visited));
 
		scanf("%d %d", &V, &E);
		for(int i = 1; i <= V; i++)
			a[i].clear();
		for (int i = 0; i < E; i++)
		{
			
			scanf("%d %d", &u, &v);
 
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i = 1; i <= V; i++)
			if (!visited[i])
			{
				visited[i] = 1;
				dfs(i);
			}
 
		for (int i = 1; i <= V; i++)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				int next = a[i][j];
				if (visited[i] == visited[next])
				{
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
 
void dfs(int v)
{
	for (int i = 0; i < a[v].size(); i++)
	{
		int next = a[v][i];
		if (visited[next] == 0)
		{
			if (visited[v] == 1)
				visited[next] = 2;
			else
				visited[next] = 1;
			dfs(next);
		}
	}
 
}