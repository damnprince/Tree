//#include<iostream>
//using namespace std;
//
//int flag;
////二叉树结点
//typedef struct BTNode {
//	char data;
//	BTNode* L;
//	BTNode* R;
//}BTNode, * BTree;
//
////队列节点
//struct QNode {
//	BTNode* tnode;//存放树节点
//	QNode* next;
//};
//
////队列指针
//struct Queue {
//	QNode *T;
//	QNode* W;
//};
//
////初始化队列
//Queue InitQueue() {
//	Queue q;
//	QNode* h = (QNode*)malloc(sizeof(QNode));
//	h->next = NULL;
//	q.T = q.W = h;
//	return q;
//}
//
////初始化二叉树
//BTree InitTree(BTree root,char r) {
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	s->data = r;
//	s->L = s->R = NULL;
//	root = s;
//	return root;
//}
//
////添加队列元素
//void InsertQueue(Queue* q, BTNode*s) {
//	QNode* qn = (QNode*)malloc(sizeof(QNode));
//	qn->tnode = s;
//	qn->next = NULL;
//	q->W->next = qn;
//	q->W = qn;
//}
//
////队列判空
//bool IsQueEmpty(Queue q) {
//	if (q.T == q.W) {
//		cout << "队列为空" << endl;
//		return true;
//	}
//	else return false;
//}
//
////删除队列元素
//void Delque(Queue* q) {
//	if (IsQueEmpty(*q)) {
//		return;
//	}
//	if (q->T->next == q->W) {
//		q->W = q->T;
//	}
//	QNode* p = q->T->next;
//	q->T->next = p->next;
//	free(p);
//	p = NULL;
//}
//
////查找树节点
//BTree FindTNode(BTree root, char fx) {
//	if (root->data == fx) {
//		return root;
//	}
//	BTNode* ans = NULL;
//	if (root->L != NULL) {
//		ans = FindTNode(root->L, fx);
//		if (ans != NULL)return ans;
//	}
//	if (root->R != NULL) {
//		ans = FindTNode(root->R, fx);
//		if (ans != NULL)return ans;
//	}
//	return NULL;
//}
//
////添加树节点
//BTree InsertTree(BTree root, char x, char fx) {
//	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
//	s->data = x;
//	s->L = s->R = NULL;
//	BTNode* fNode = FindTNode(root, fx);
//	if (flag == 0) {//新节点为左儿子
//		fNode->L = s;
//	}
//	else {//新节点为右儿子
//		fNode->R = s;
//	}
//	return root;
//}
//
////广度优先（层序）遍历
//void Widely_search(Queue q,BTree root) {
//	InsertQueue(&q, root);//将根节点插入队列中
//	while (!IsQueEmpty(q)) {		//队列非空
//		cout << q.T->next->tnode->data << " ";
//		if (q.T->next->tnode->L != NULL) {
//			InsertQueue(&q, q.T->next->tnode->L);
//		}
//		if (q.T->next->tnode->R != NULL) {
//			InsertQueue(&q, q.T->next->tnode->R);
//		}
//		Delque(&q);
//	}
//	cout << endl;
//}
//
////深度优先遍历
////先序 中序 后序
//
////先序
//void FirstSearch(BTree root) {
//	if (root == NULL) {
//		return;//递归出口
//	}
//	//先序输出
//	cout << root->data << " ";
//	FirstSearch(root->L);
//	FirstSearch(root->R);
//}
//
////中序
//void MidSearch(BTree root) {
//	if (root == NULL) {
//		return;
//	}
//	MidSearch(root->L);
//	cout << root->data << " ";
//	MidSearch(root->R);
//}
//
////后序
//void LastSearch(BTree root) {
//	if (root == NULL)
//		return;
//	LastSearch(root->L);
//	LastSearch(root->R);
//	cout << root->data << " ";
//}
//
//int main() {
//	int n;
//	char r;
//	cin >> n >> r;
//	BTree root = NULL;
//	root = InitTree(root, r);
//	Queue q = InitQueue();
//	char x, fx;
//	for (int i = 2; i <= n; i++) {
//		cin >> x >> fx>> flag;
//		root = InsertTree(root, x, fx);
//	}
//	cout << endl;
//	Widely_search(q,root);
//	cout << endl;
//	FirstSearch(root);
//	cout << endl;
//	MidSearch(root);
//	cout << endl;
//	LastSearch(root);
//	cout << endl;
//	return 0;
//}
//
///*
//4
//A
//B A 0
//C A 1
//D B 0
//B
//
//6
//A
//B A 0
//C A 1
//D B 1
//E B 0
//F D 1
//B
//*/