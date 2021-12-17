#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node {
    int item;
    struct node *next;
}stack_node;

typedef struct {
    stack_node *top;
}stack;

bool is_empty(stack *s) {
    if(s->top == NULL) {
        return true;
    }
    return false;
}

void init(stack *s) {
    s->top = NULL;
    return;
}

bool stack_empty(stack *s) {
    if(s->top == NULL) {
        return true;
    } else {
        return false;
    }
}

void Push(stack *s, int x) {
    stack_node *new_node;
    new_node = (stack_node *)malloc(sizeof(stack_node));
    new_node->item = x;
    new_node->next = s->top;
    s->top = new_node;
    return;
}

int Pop(stack *s) {
    stack_node *tmp;
    tmp = (stack_node *) malloc(sizeof(stack_node));
    tmp = s->top;
    s->top = s->top->next;
    int value;
    value = tmp->item;
    tmp->next = NULL;
    free(tmp);
    return value;
}

void input_data(stack *s, int n) {
    for(int i = 1; i <= n; i++) {
        int tmp;
        printf("\nStack [%d] = ", i);
        scanf("%d", &tmp);
        Push(s, tmp);
    }
}

void display(stack *s, int n) {
    printf("\nStack in current\n");
    for(int i = 1; i <= n; i++) {
        int tmp = Pop(s);
        printf("\n\t%d\n", tmp);
    }
}

int main() {
    int n;
    printf("Stack's capacity : ");
    scanf("%d", &n);
    stack *s;
    s = (stack *)malloc(sizeof(stack));
    init(s);
    
    input_data(s, n);
    display(s, n);

    free(s);
    return 0;
}
