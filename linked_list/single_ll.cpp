#include<stdio.h>
#include<stdlib.h>

typedef struct listnode {
	int item;
	struct listnode *Next;
}ListNode;

void display(ListNode *head) {
	ListNode *ptr = head; // con tro tam thoi, nhiem vu tam thoi tro den node dau cua danh sach.
	while(ptr != NULL) {
		printf("%d\t", ptr->item);
		ptr = ptr->Next;
	}
	printf("\n");
}

void insert_data(int *x) {
	printf("\nNhap gia tri can them vao danh sach : ");
	scanf("%d", x);
}

void insert_begin(ListNode **ptrHead, int x) {
	ListNode *newNode;
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->item = x;
	newNode->Next = *ptrHead;
	*ptrHead = newNode;
}

void insert_end(ListNode **ptrHead, int value) {
	ListNode *newNode;
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->item = value;
	newNode->Next = NULL;
	if(*ptrHead == NULL) {
		*ptrHead = newNode;
	} else {
		ListNode *ptr_tmp = *ptrHead;
		while(ptr_tmp->Next != NULL) {
			ptr_tmp = ptr_tmp->Next;
		}
		ptr_tmp->Next = newNode;
	}
}

void insert_middle(ListNode **ptrHead, int position, int value) {
	int cnt = 1;
	int flag = 0;
	ListNode *newNode;
	ListNode *ptr_tmp = *ptrHead;
	while((ptr_tmp->Next != NULL) && (flag == 0)) {
		if(cnt == position) {
			newNode = (ListNode *)malloc(sizeof(ListNode));
			newNode->item = value;
			newNode->Next = ptr_tmp->Next;
			ptr_tmp->Next = newNode;
			flag = 1;
		}
		cnt++;
		ptr_tmp = ptr_tmp->Next;
	}
	if(flag == 0) {
		printf("\nVi tri can chen khong co trong danh sach lien ket");
	}
}

void delete_begin(ListNode **ptrHead) {
	ListNode *ptr_tmp;
	ptr_tmp = *ptrHead;
	*ptrHead = ptr_tmp->Next;
	ptr_tmp->Next = NULL;
	free(ptr_tmp);
}

void delete_end(ListNode **ptrHead) {
	ListNode *ptr_tmp_1;
	ListNode *ptr_tmp_2;
	ptr_tmp_1 = *ptrHead;
	ptr_tmp_2 = ptr_tmp_1->Next;
	while(ptr_tmp_2->Next != NULL) {
		ptr_tmp_1 = ptr_tmp_1->Next;
		ptr_tmp_2 = ptr_tmp_2->Next;
	}
	ptr_tmp_1->Next = NULL;
	free(ptr_tmp_2);
}

void delete_middle(ListNode **ptrHead, int position) {
	int cnt = 1;
	int flag = 0;
	ListNode *ptr_tmp_1 = *ptrHead;
	ListNode *ptr_tmp_2;
	while((ptr_tmp_1->Next != NULL) && (flag == 0)) {
		if(cnt == position) {
			ptr_tmp_2 = ptr_tmp_1->Next;
			ptr_tmp_1->Next = ptr_tmp_2->Next;
			ptr_tmp_2->Next = NULL;
			
			flag = 1; 
		}
		cnt++;
		ptr_tmp_1 = ptr_tmp_1->Next; 
		free(ptr_tmp_2);
	}
}

void search_node(ListNode *head, int node_index) {
	int cnt = 0;
	for(ListNode *p = head; p != NULL; p = p->Next) {
		if(cnt == node_index) {
			printf("\nGia tri o node [%d] la %d\n", node_index, p->item);
			return;
		}
		cnt++; // dem vi tri cua node trong danh sach
	}
}

void search_value(ListNode *head, int value) {
	int cnt = 0;
	for(ListNode *p = head; p != NULL; p = p->Next) {
		if(p->item == value) {
			printf("\nVi tri cua %d la node [%d]\n", value, cnt);
			return;
		} 
		cnt++;
	}
}

int main() {
	int n;
	do{
		printf("Nhap so luong Node : ");
		scanf("%d", &n);
	} while(n <= 0);
	
	ListNode *newNode;
	ListNode *head;
	ListNode **ptrHead;
		
	newNode = (ListNode *)malloc(sizeof(ListNode));
	head = newNode;
	ptrHead = &head;
	
	for(int i = 1; i <= n; i++) {
		if(i == n) {
			printf("Phan tu [%d] cua danh sach lien ket : ", i);
			scanf("%d", &newNode->item);
			newNode->Next = NULL;
		} else {
			printf("Phan tu [%d] cua danh sach lien ket : ", i);
			scanf("%d", &newNode->item);
			newNode->Next = (ListNode *)malloc(sizeof(ListNode));
			newNode = newNode->Next;
		}
	}
	
	display(head);
	// them vao dau danh sach lien ket 
	int x_begin;
	insert_data(&x_begin);
	insert_begin(ptrHead, x_begin);
	printf("\nDanh sach lien ket sau khi them %d vao dau\n", x_begin);
	display(head);
	// them vao cuoi danh sach lien ket
	int x_end;
	insert_data(&x_end);
	insert_end(ptrHead, x_end);
	printf("\nDanh sach lien ket sau khi them %d vao cuoi\n", x_end);
	display(head);
	// them vao vi tri bat ki
	int x_middle = 211;
	int pos = 1;
	insert_middle(ptrHead, pos, x_middle);
	printf("\nDanh sach lien ket sau khi chen %d vao vi tri %d la\n", x_middle, pos);
	display(head);
	//xoa vi tri dau tien
	delete_begin(ptrHead);
	printf("\nDanh sach lien ket sau khi xoa vi tri dau tien la\n");
	display(head);
	//xoa vi tri cuoi cung
	delete_end(ptrHead);
	printf("\nDanh sach lien ket sau khi xoa vi tri cuoi cung la\n");
	display(head);
	//xoa o vi tri bat ki
	delete_middle(ptrHead, 1);
	printf("\nDanh sach lien ket sau khi xoa vi tri [1] la\n");
	display(head);
	//gia tri o mot node
	search_node(head, 1);
	//tim vi tri cua value trong danh sach lien ket 
	search_value(head, 5);

	free(head);
	return 0;
}
