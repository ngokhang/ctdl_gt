#include<stdio.h>
#include<limits.h>

// Dijkstra Algorithm

int m, n, s, e; // so dinh, so canh, dinh bat dau, dinh muc tieu.
int g[1000][1000]; // do thi

int min_distance(int distance[], int check[]) {
	int min = INT_MAX, min_index;
	for(int v = 0; v < m; v++) {
		if(check[v] == 0 && distance[v] <= min) {
			min = distance[v];
			min_index = v;
		}
	}
	return min_index;
}

void print_solve(int distance[], int n) {
	for(int i = 0; i < m; i++) {
		printf("%d %d", i, distance[i]);
	}
}

void dijkstra(int g[9][9], int s) {
	int distance[m]; // mang luu tru khoang cach tu dinh goc toi cac dinh
	int check[m]; // mang danh dau neu dinh da nam trong tap duong di ngan nhat
	
	// gan gia tri khoang cach cua cac dinh la vo cuc
	for(int i = 1; i <= m; i++) {
		distance[i] = INT_MAX;
		check[i] = 0;
	}
	
	//khoang cach cua dinh goc toi dinh goc luon bang 0
	distance[s] = 0;
	
	//tim duong di ngan nhat cho cac dinh 
	for(int cnt = 0; cnt < m - 1; cnt++) {
		int u = min_distance(distance, check);
		
		check[u] = 1;
		
		for(int i = 0; i < m; i++) {
			if (check[i] == 0 && g[u][i] && distance[u] != INT_MAX && distance[u] + g[u][i] < distance[i]) 
				distance[i] = distance[u] + g[u][i];
		}
	}
	print_solve(distance, m);
}

// coding for graph
void input() {
	scanf("%d%d%d%d", &m, &n, &s, &e);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y] = y;
		g[y][x] = x;
	}
}

void print() {
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

int main() {
	
	int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
							{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
							{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
							{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
							{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
							{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
							{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
							{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
							{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph, 1);
	return 0;	
}
