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


//删除（非递归）
BSTree Delet1(BSTree root, int x) {
	if (root == NULL) {
		cout << "树空" << endl;
		return NULL;
	}
	BSTNode* p = root;
	BSTNode* pre = NULL;
	//找到x所在的节点
	while (p->data != x) {
		if (x < p->data)pre = p, p = p->L;
		else pre = p, p = p->R;
	}
	BSTNode* ch = NULL;//ch用来保存度小于2的节点的儿子
	//找完之后判断该节点有几个度
	if (p->L != NULL && p->R != NULL) {
		//度为2
		/*二叉排序树删除度为2的节点的问题 可以转变为 通过中序遍历的前驱或后继替换该节点的数据
		剩下就是把前驱或后继删除掉 就变成了删除度为0或1的结点*/
		//以后继为例  找后继
		BSTNode* h = p->R;//后继结点
		BSTNode* hf = p;//后继父亲
		while (h->L != NULL) {
			hf = h;
			h = h->L;
		}
		//把目标节点的数据改为后继节点的数据
		p->data = h->data;
		//接下来处理后继节点
		p = h;
		pre = hf;
	}
	//由于删除后继操作与删除度为0/1的节点一样 所以归为一类
	if (p->L != NULL) ch = p->L;
	else ch = p->R;//默认度为0的节点的ch是右儿子
	if (pre != NULL) {
		if (pre->L == p)pre->L = ch;
		else pre->R = ch;
	}
	else //删除度为0或1的根结点
		root = ch;
	free(p);
	p = NULL;
	return root;
}

//删除(递归)
BSTree Delet2(BSTree root, int x) {
	if (root == NULL) {
		cout << "树空" << endl;
		return NULL;
	}
	if (x < root->data) {
		root->L = Delet2(root->L, x);
	}
	else if (x > root->data) {
		root->R = Delet2(root->R, x);
	}
	else {
		if (root->L != NULL && root->R != NULL) {
			//度为2
			BSTNode* p = root->L;//找前驱
			while (p->R != NULL) {
				p = p->R;
			}
			root->data = p->data;
			root->L= Delet2(root->L, p->data);
		}
		else {//度为1或0
			BSTNode* q = root;
			if (root->L != NULL)root = root->L;
			else root = root->R;
			free(q);
			q = NULL;
		}
	}
	return root;
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
	cout << endl;
	//root = Delet1(root, tar);
	root = Delet2(root, tar);
	cout << "删除" << tar << "后的序列为：" << endl;
	InOrder(root);
	cout << endl;

	return 0;
}
/*
5
6 2 5 7 3
2
  
6
4 2 3 1 6 5
3

9
7 3 11 8 9 12 5 21 2
8

*/