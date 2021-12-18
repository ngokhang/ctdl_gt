#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}bs_tree;

bs_tree* create_node(int data) { // ham tao node trong cay
	bs_tree *node;
	node = (bs_tree *)malloc(sizeof(bs_tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bs_tree* insert(bs_tree *root, int data) { // ham them node trong cay
	if(root == NULL) {
		root = create_node(data);
		return root;
	} else if(data <= root->data) {
		root->left = insert(root->left, data);
	} else if(data >= root->data) {
		root->right = insert(root->right, data);
	}
	return root;
}

void input(bs_tree **root) { // ham insert cac node vao cay
	for(int i = 0;;i++) {
		int tmp;
		if(i == 0) {
			printf("Tree's root = ");
		} else {
			printf("\nTree's node [%d] = ", i);
		}
		scanf("%d", &tmp);
		if(tmp == 0) break;
		*root = insert(*root, tmp);
	}
}

// cac ham duyet cay 
void pre_order(bs_tree *root) {
	if(root == NULL) return;
	printf("%d ", root->data);
	pre_order(root->left);
	pre_order(root->right);
}

void in_order(bs_tree *root) {
	if(root == NULL) return;
	in_order(root->left);
	printf("%d ", root->data);
	in_order(root->right);
}

void post_order(bs_tree *root) {
	if(root == NULL) return;
	post_order(root->left);
	post_order(root->right);
	printf("%d ", root->data);
}

// ham tim kiem gia tri trong cay
bool search(bs_tree *root, int value) {
	if(root == NULL) {
		return false;
	} 
	if(value == root->data) {
		return true;
	} else {
		if(value < root->data) {
			search(root->left, value);
		} else if (value > root->data){
			search(root->right, value);
		}
	}
}

bs_tree* find_node_min(bs_tree* root) {
	while(root->left != NULL) {
		root = root->left;
	}
	return root;
}

bs_tree* delete_node(bs_tree *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) 
		root->left = delete_node(root->left, data);
	else if(data > root->data) 
		root->right = delete_node(root->right, data);
	else {
		if(root->right == NULL && root->left == NULL) {
			free(root);
			root = NULL;
		} else if(root->left == NULL) {
			bs_tree *temp = root;
			root = root->right;
			free(temp);
		} else if(root->right = NULL) {
			bs_tree *temp = root;
			root = root->left;
			free(temp);
		} else {
			bs_tree *temp = find_node_min(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
		}
	}
	return root;
}
 
int main() {
	int searching_value, x;
	bs_tree *root = NULL;  // nut goc
	
	input(&root);
	
	// duyet cay
	printf("\nPre-order\n");
	pre_order(root);
	printf("\nIn-orderd\n");
	in_order(root);
	printf("\nPost-order\n");
	post_order(root);
//	
	// tim gia tri trong cay
	printf("\nSearching value : ");
	scanf("%d", &searching_value);
	if(search(root, searching_value) == true) printf("\n%d is here");
		else printf("\n%d isn't here");
	
	//chen gia tri 
	int gt_chen;
	printf("\nNhap gia tri can chen : ");
	scanf("%d", &gt_chen);
	insert(root, gt_chen);
	printf("\nPre-order\n");
	pre_order(root);
	printf("\nIn-orderd\n");
	in_order(root);
	printf("\nPost-order\n");
	post_order(root);
	
	// xoa 
	int gt_xoa;
	printf("\nNhap gia tri can xoa : ");
	scanf("%d", &gt_xoa);
	delete_node(root, gt_xoa);
	printf("\nPre-order\n");
	pre_order(root);
	printf("\nIn-orderd\n");
	in_order(root);
	printf("\nPost-order\n");
	post_order(root);
	
	return 0;
}
