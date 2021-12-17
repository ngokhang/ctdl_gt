#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100

int n, m, k;
int g[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];

// Coding for queue
typedef struct node {
	int data;
	struct node *next;
} queue_node;

typedef struct queue {
	queue_node *f;
	queue_node *r;
	int count;
}queue;

void init(queue *q) {
	q->f = NULL;
	q->r = NULL;
	q->count = 0;
	return;
}

bool is_empty(queue *q) {
	if(q->count == 0) {
		return true;
	}
	return false;
}

int front(queue *q) {
	return q->f->data;
}

void enqueue(queue *q, int val) {
	queue_node *new_node;
	new_node = (queue_node *)malloc(sizeof(queue_node));
	new_node->data = val;
	new_node->next = NULL;
	if(is_empty(q) == 1) {
		q->r = q->f = new_node;
		q->count++;
	} else {
		q->r->next = new_node;
		q->r = new_node;
		q->count++;
	}
}

void dequeue(queue *q) {
	int val;
	queue_node *temp;
	temp = q->f;
	val = temp->data;
	q->f = q->f->next;
	free(temp);
	q->count--;
}
// end of queue

// coding for graph
void input() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y] = y;
		g[y][x] = x;
		visited[i] = false;
	}
}

void bfs(int vertex) {
	queue *q;
	q = (queue *)malloc(sizeof(queue));
	init(q);	
	enqueue(q, vertex);
	visited[vertex] = true;
	
	while(!is_empty(q)) {
		int u = front(q);
		if(u != 0) {
			printf("%d ", u);
		}
		dequeue(q);
		for(int i = 1; i <= m; i++) {
			if(!visited[g[u][i]]) {
				visited[g[u][i]] = true;
				enqueue(q, g[u][i]);
			}
		}
	}
	
	free(q);
};

int main() {
	
	input();
	printf("\n");
	bfs(k);
	
	return 0;
}
