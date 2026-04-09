#include<iostream>
using namespace std;

typedef struct AVLNode {
	int data;
	AVLNode* L;
	AVLNode* R;
	int h;
}AVLNode, * AVLTree;

//创建结点
AVLNode* CreateNode(int x) {
	AVLNode* s = (AVLNode*)malloc(sizeof(AVLNode));
	s->data = x;
	s->L = s->R = NULL;
	s->h = 1;
	return s;
}


int maxx(int a, int b) {
	return a > b ? a : b;
}

//获取树的高度
int Geth(AVLNode* x) {
	if (x == NULL)return 0;
	else return x->h;
}

//LL失衡（右旋）
AVLTree LLratation(AVLTree x) {
	AVLNode* y = x->L;
	//右旋后 x变为y的右子树 y的右子树变为x的左子树
	x->L = y->R;
	y->R = x;
	//重新获取xy的高度
	x->h = 1 + maxx(Geth(x->L), Geth(x->R));
	y->h = 1 + maxx(Geth(y->L), Geth(y->R));
	return y;//y变为根节点
}

//RR失衡（左旋）
AVLTree RRratation(AVLTree x) {
	AVLNode* y = x->R;
	x->R = y->L;
	y->L = x;
	x->h = 1 + maxx(Geth(x->L), Geth(x->R));
	y->h = 1 + maxx(Geth(y->L), Geth(y->R));
	return y;
}

//RL失衡
AVLTree RLratation(AVLTree x) {
	x->R = LLratation(x->R);//先右旋
	x = RRratation(x);//再左旋
	return x;
}
  
//LR失衡
AVLTree LRratation(AVLTree x) {
	x->L = RRratation(x->L);//先左旋
	x = LLratation(x);//再右旋
	return x;
}

//插入
AVLTree Insert(AVLTree root, int x) {
	if (root == NULL) {
		root = CreateNode(x);
		return root;
	}
	if (x < root->data) {
		root->L = Insert(root->L, x);
		//判断失衡	LL LR
		if (Geth(root->L)-Geth(root->R) > 1) {
			if (x < root->L->data) {
				//LL失衡
				root = LLratation(root);
			}
			else
			{	//LR失衡
				root = LRratation(root);
			}
		}
	}
	else {
		root->R = Insert(root->R, x);
		//判断失衡 RR RL
		if (Geth(root->L) - Geth(root->R) > 1) {
			if (x > root->R->data) {
				//RL失衡
				root = RLratation(root);
			}
			else 
			{	//RR失衡
				root = RRratation(root);
			}
		}
	}
	root->h = 1 + maxx(Geth(root->L), Geth(root->R));
	return root;
}

//中序遍历
void Inorder(AVLTree root) {
	if (root == NULL) {
		return;
	}
	Inorder(root->L);
	int p = Geth(root->L) - Geth(root->R);//节点的度
	cout << root->data << " " << p <<endl;
	Inorder(root->R);
}


int main() {
	int n, x;
	cin >> n;
	AVLTree root = NULL;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		root = Insert(root, x);
	}
	Inorder(root);

	return 0;
}