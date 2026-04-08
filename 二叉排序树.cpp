#include<iostream>
using namespace std;

typedef struct BSTNode {
	int data;
	BSTNode* L;
	BSTNode* R;
}BSTNode, * BSTree;

//创建结点
BSTNode* CreateNode(int x) {
	BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
	s->data = x;
	s->L = s->R = NULL;
	return s;
}

//查找（非递归）
BSTNode* Search1(BSTree root, int x) {
	BSTNode* p = root;
	while (p != NULL && p->data != x) {
		if (x < p->data)p = p->L;
		else p = p->R;
	}
	return p;//1.p=NULL  2.p->data==x
}

//查找（递归）
BSTNode* Search2(BSTree root, int x) {
	if (root == NULL || root->data == x)
		return root;
	if (x < root->data)
		Search2(root->L, x);
	else 
		Search2(root->R, x);
}

//插入（非递归）
BSTree Insert1(BSTree root, int x) {
	BSTNode* p = root;
	BSTNode* pre = NULL;
	BSTNode* s = CreateNode(x);
	if (root == NULL)
	{
		root =s;
		return root;
	}
	while (p != NULL) {
		if (x < p->data)pre = p, p = p->L;
		else pre = p, p = p->R;
	}
	if (x < pre->data)pre->L = s;
	else pre->R = s;
	return root;
}

//插入（递归）
BSTree Insert2(BSTree root, int x) {
	if (root == NULL)
	{
		root = CreateNode(x);
		return root;
	}
	if (x < root->data)
		root->L = Insert2(root->L, x);
	else root->R = Insert2(root->R, x);
	return root;
}

//中序遍历
void InOrder(BSTree root) {
	if (root == NULL)
		return;
	InOrder(root->L);
	cout << root->data << " ";
	InOrder(root->R);
}


int main() {
	int n, x;
	cin >> n;
	BSTree root = NULL;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		root=Insert2(root, x);
	}
	int tar;
	cin >> tar;
	BSTNode* T = Search2(root, tar);
	if (T != NULL)cout << "Yes!" << T->data << endl;
	else cout << "No!" << endl;
	cout << "中序遍历结果：" << endl;
	InOrder(root);
	return 0;
}
/*
5
6 2 5 7 3
2
  
6
4 2 3 1 6 5
3

*/