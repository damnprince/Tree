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

//插入(递归)
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

//删除（递归）
AVLTree Delet(AVLTree root, int x) {
	if (root == NULL) {
		cout << "树空" << endl;
		return NULL;
	}
	if (x < root->data) {
		root->L = Delet(root->L, x);
		//判断失衡
		if (Geth(root->R) - Geth(root->L) > 1) {
			//RR  RL
			AVLNode* r = root->R;
			if (Geth(r->R) >= Geth(r->L)) {
				//RR失衡
				root = RRratation(root);
			}
			else {
				//RL失衡
				root = RLratation(root);
			}
		}
	}
	else if (x > root->data) {
		root->R = Delet(root->R, x);
		//判断失衡
		if (Geth(root->L) - Geth(root->R) > 1) {
			//LL LR
			AVLNode* l = root->L;
			if (Geth(l->L) >= Geth(l->R)) {
				//LL
				root = LLratation(root);
			}
			else {
				//LR
				root = LRratation(root);
			}
		}
	}
	else {
		if(root->L!=NULL&&root->R!=NULL){	//删除节点度为2
			AVLNode* q = root->R;			//找后继
			while (q->L != NULL) {
				q = q->L;
			}
			root->data = q->data;
			root->R = Delet(root->R, q->data);
			//判断失衡
			if (Geth(root->L) - Geth(root->R) > 1) {
				//LL LR
				AVLNode* l = root->L;
				if (Geth(l->L) >= Geth(l->R)) {
					//LL
					root = LLratation(root);
				}
				else {
					//LR
					root = LRratation(root);
				}
			}
		}
		else
		{
			//删除节点度为1或0
			AVLNode* p = root;
			if (root->L != NULL)root = root->L;
			else root = root->R;
			free(p);
			p = NULL;
		}
	}
	if(root!=NULL) root->h = 1 + maxx(Geth(root->L), Geth(root->R));
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
	cout << endl;
	while (root != NULL) {
		cin >> x;
		root = Delet(root, x);
		Inorder(root);
		cout << endl;
	}
	return 0;
}