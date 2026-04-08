//#include<iostream>
//using namespace std;
//
//int flag;
////创建树节点
//typedef struct BTNode {
//	char data;
//	BTNode* L;
//	BTNode* R;
//}BTNode, * BTree;
//
////创建栈结点
//typedef struct StackNode {
//	BTNode* data;
//	StackNode* next;
//}Sstack;
//
////栈空
//bool IsStackEmpty(Sstack* s) {
//	if (s->next == NULL)
//		return 1;
//	else return 0;
//}
//
////初始化栈
//Sstack* InitStack() {
//	Sstack* s = (Sstack*)malloc(sizeof(Sstack));
//	s->next = NULL;
//	return s;
//}
//
////入栈
//void Push(Sstack* s, BTNode* n) {
//	Sstack* p = (Sstack*)malloc(sizeof(Sstack));
//	p->data = n;
//	p->next = s->next;
//	s->next = p;
//}
//
////出栈
//BTNode* Pop(Sstack* s) {
//	if (IsStackEmpty(s)) {
//		cout << "栈空" << endl;
//		return NULL;
//	}
//	Sstack* p = s->next;//p获取栈顶元素
//	BTNode* q = p->data;//q获取树节点
//	s->next = p->next;
//	free(p);
//	return q;
//}
//
////获取栈顶元素 不删除
//BTNode* Get(Sstack* s) {
//	if (IsStackEmpty(s)) {
//		cout << "栈空" << endl;
//		return NULL;
//	}
//	Sstack* p = s->next;//p获取栈顶元素
//	BTNode* q = p->data;//q获取树节点
//	return q;
//}
//
//
////初始化树
//BTree InitBTree(BTree root, char r) {
//	BTNode* h = (BTNode*)malloc(sizeof(BTNode));
//	h->data = r;
//	h->L = h->R = NULL;
//	root = h;
//	return root;
//}
//
////查找
//BTNode* FindBTNode(BTree root, char fx) {
//	if (root->data == fx) {
//		return root;
//	}
//	BTNode* ans = NULL;
//	if (root->L != NULL) {
//		ans = FindBTNode(root->L, fx);
//		if (ans != NULL)return ans;
//	}
//	if (root->R != NULL) {
//		ans = FindBTNode(root->R, fx);
//		if (ans != NULL)return ans;
//	}
//	return NULL;
//}
//
////插入
//BTree Insert(BTree root, char x, char fx) {
//	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
//	p->data = x;
//	p->L = p->R = NULL;
//	BTNode* f = FindBTNode(root, fx);
//	
//	if (flag == 0) {
//		f->L = p;
//	}
//	else {
//		f->R = p;
//	}
//	
//	return root;
//}
//
////访问
//void Visit(BTNode* p) {
//	cout << p->data;
//}
//
////先序遍历（非递归）
//void FirstSearch(BTree root) {
//	if (root == NULL) {
//		cout << "空树" << endl;
//		return;
//	}
//
//	Sstack* s = InitStack();
//	BTNode* p = root;
//	BTNode* top = NULL;
//	while (p != NULL || !IsStackEmpty(s)) 
//	{
//		if (p != NULL) {
//			Visit(p);
//			Push(s, p);
//			p = p->L;
//		}
//		else if (!IsStackEmpty(s))
//		{
//			top=Pop(s);
//			p = top->R;
//		}
//	}
//}
//
////中序
//void MidSearch(BTree root) {
//	if (root == NULL) {
//		cout << "空树" << endl;
//		return;
//	}
//
//	Sstack* s = InitStack();
//	BTNode* p = root;
//	BTNode* top = NULL;
//	while (p != NULL || !IsStackEmpty(s)) {
//		if (p != NULL) {
//			Push(s,p);
//			p = p->L;
//		}
//		else {
//			top = Pop(s);
//			Visit(top);
//			p = top->R;
//		}
//	}
//}
//
//
////后序遍历
//void LastSearch(BTree root) {
//	if (root == NULL) {
//		cout << "空树" << endl;
//		return;
//	}
//	Sstack* s = InitStack();
//	BTNode* p = root;
//	BTNode* top = NULL;
//	BTNode* pre = NULL;
//	while (p != NULL || !IsStackEmpty(s))
//	{
//		if (p != NULL) {
//			Push(s,p);
//			p = p->L;
//		}
//		else {
//			top = Get(s);
//			if (top->R != NULL && pre != top->R) {	//左子树访问完了
//				p = top->R;
//			}
//			else {
//				Pop(s);
//				Visit(top);
//				pre = top;
//			}
//		}
//	}
//}
//
//int main() {
//	int n;
//	char r;
//	BTree root = NULL;
//	cin >> n >> r;
//	root = InitBTree(root,r);
//	char x, fx;
//	for (int i = 2; i <= n; i++) {
//		cin >> x >> fx >> flag;
//		root = Insert(root, x, fx);
//	}
//	FirstSearch(root);
//	cout << endl;
//	MidSearch(root);
//	cout << endl;
//	LastSearch(root);
//	cout << endl;
//	return 0;
//}
///*
//4
//A
//B A 0
//C A 1
//D B 0
//
//
//6
//A
//B A 0
//C A 1
//D B 1
//E B 0
//F D 1
//
//*/