#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++) {
  	for (j = 0; j < n; j++) {
  		if (Graph[i][j] == 0) {
  			cost[i][j] = INFINITY;
		  } else {
		  	cost[i][j] = Graph[i][j];
		  }
	  }
  }
    
  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]); // in ra khoang cach 
    }
}
int main() {
  int g[MAX][MAX], i, j, n, s;
  n = 7; // so luong dinh

  // nhap du lieu cho ma tran
  for(int i = 0; i < n; i++) {
  	for(int j = 0; j < n; j++) {
  		scanf("%d", &g[i][j]);
	  }
  }

  s = 0; // dinh bat dau
  dijkstra(g, n, s);

  return 0;
}
