#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// khai bao cac bien global
int m, n; // so dinh, so canh
int graph[1000][1000]; // do thi
bool visited[1000]; // danh dau cac dinh da duoc tham cua do thi

void input() 
{
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++) 
	{
		int x, y;
		scanf("%d%d", &x, &y);
		graph[x][y] = y;
		graph[y][x] = x;
		visited[i] = false;
	}
}

void dfs(int vertex) 
{
	printf("%d ", vertex);
	visited[vertex] = true;
	for(int i = 1; i <= n; i++) 
	{
		if(graph[vertex][i] == i && visited[i] == false) 
		{
			dfs(i);
		}
	}
}


int main() 
{
	
	input();
	
	printf("\nThuat toan dfs\n");
	int dfs_vertex = 1;
	dfs(dfs_vertex);
	
	return 0;
}
