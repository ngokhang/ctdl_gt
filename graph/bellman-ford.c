#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

//struct for the edges of the graph
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int w;  //weight of the edge (u,v)
};

//Graph - it consists of edges
struct Graph {
  int V;        //total number of vertices in the graph
  int E;        //total number of edges in the graph
  struct Edge *edge;  //array of edges
};


void display(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bellmanford(struct Graph *g, int source) {
  int i, j, u, v, w;
  int tV = g->V; //total vertex in the graph g
  int tE = g->E; //total edge in the graph g
  //distance array
  //size equal to the number of vertices of the graph g
  int d[tV];
  //predecessor array
  //size equal to the number of vertices of the graph g
  int p[tV];

  for (i = 0; i < tV; i++) {
    d[i] = INFINITY;
    p[i] = 0;
  }

  //mark the source vertex
  d[source] = 0;

  for (i = 1; i <= tV - 1; i++) {
    for (j = 0; j < tE; j++) {
      //get the edge data
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].w;

      if (d[u] != INFINITY && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }

  for (i = 0; i < tE; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].w;
    if (d[u] != INFINITY && d[v] > d[u] + w) {
      printf("Negative weight cycle detected!\n");
      return;
    }
  }

  printf("Distance array: ");
  display(d, tV);
  printf("Predecessor array: ");
  display(p, tV);
}
int main() {
  struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
  g->V = 4;  //total vertices
  g->E = 5;  //total edges

  g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));
// data
  g->edge[0].u = 0;
  g->edge[0].v = 1;
  g->edge[0].w = 5;

  g->edge[1].u = 0;
  g->edge[1].v = 2;
  g->edge[1].w = 4;

  g->edge[2].u = 1;
  g->edge[2].v = 3;
  g->edge[2].w = 3;

  g->edge[3].u = 2;
  g->edge[3].v = 1;
  g->edge[3].w = 6;

  g->edge[4].u = 3;
  g->edge[4].v = 2;
  g->edge[4].w = 2;

  bellmanford(g, 0); 

  return 0;
}
