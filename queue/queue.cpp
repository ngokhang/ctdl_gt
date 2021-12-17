#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node *next;
}queue_node;

typedef struct {
    queue_node *head;
    queue_node *tail;
    int cnt;
}queue;

void init(queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->cnt = 0;
}

bool is_empty(queue *q) {
    if(q->tail == NULL) {
        return true;
    } else {
        return false;
    }
}

void enqueue(queue *q, int value) {
    queue_node *tmp;
    tmp->data = value;
    tmp->next = NULL;
    q->tail->next = tmp;
}

void push(queue *q, int val) {
    queue_node *node;
    node = (queue_node *)malloc(sizeof(queue_node));
    node->data = val;
    node->next = NULL;
    if(is_empty(q) == true) {
        q->head = q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
        (q->cnt)++;
    }
}

int head(queue *q) {
    if(is_empty(q) == true) {
        printf("\nQueue's empty");
    } else {
        return q->head->data;
    }
}

int tail(queue *q) {
    if(is_empty(q) == true) {
        printf("\nQueue's empty");
    } else {
        return q->tail->data;
    }
}

void input_data(queue *q, int n) {
    for(int i = 1; i <= n; i++) {
        int tmp;
        printf("\nQueue [%d] = ", i);
        scanf("%d", &tmp);
        push(q, tmp);
    }
}

int pop (queue *q) {
    int value;
    queue_node *p;
    p = q->head;
    value = p->data;
    q->head = q->head->next;
    free(p);
    return value;
}

void create_node(queue_node *new_node, int value) {
    new_node = (queue_node *) malloc(sizeof(queue_node));
    new_node->data = value;
    new_node->next = NULL;
}

void display(queue *q, int n) {
    printf("\nQueue in current \n");
    for(int i = 1; i <= n; i++) {
        //queue_node *new_node;
        int tmp = pop(q);
        printf("%d ", tmp);
        //create_node(new_node, tmp);
        push(q, tmp);
    }
}

int main() {
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    init(q);
    int n;
    printf("Nhap so luong node trong hang doi : ");
    scanf("%d", &n);
    input_data(q, n);
    display(q, n);
    free(q);
    return 0;
}
