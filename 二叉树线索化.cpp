//#include<iostream>
//using namespace std;
//
//int flag;
//
////树节点结构
//typedef struct BTNode {
//	char data;
//	BTNode* L;
//	BTNode* R;
//	int lflag, rflag;//0代表儿子，1代表前驱或后继
//}BTNode, * BTree;
//
////初始化根节点
//BTree InitBTree(BTree root, char r) {
//	BTNode* h = (BTNode*)malloc(sizeof(BTNode));
//	h->data = r;
//	h->L = h->R = NULL;
//	h->lflag = h->rflag = 0;
//	root = h;
//	return root;
//}
//
////查找
//BTNode* Find(BTree root, char fx) {
//	if (root->data == fx) {
//		return root;
//	}
//	BTNode* ans = NULL;
//	if (root->lflag == 0 && root->L != NULL) {
//		ans = Find(root->L, fx);
//		if (ans != NULL)return ans;
//	}
//	if (root->rflag == 0 && root->R != NULL) {
//		ans = Find(root->R, fx);
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
//	p->lflag = p->rflag = 0;
//	BTNode* f = Find(root, fx);
//	if (flag == 0) f->L = p;
//	else f->R = p;
//	return root;
//}
//
//BTNode* pre = NULL;
////访问
//void Visit(BTNode* p) {
//	if (p->lflag == 0&&p->L==NULL) {
//		p->L = pre;
//		p->lflag = 1;
//	}
//	if (pre != NULL &&pre->rflag == 0&&pre->R==NULL) {
//		pre->R = p;
//		pre->rflag = 1;
//	}
//	pre = p;
//}
//		
//		
//
////中序遍历
//void MidSearch(BTree root) {
//	if (root == NULL)return;
//	if (root->lflag == 0 ) 
//		MidSearch(root->L);
//	Visit(root);
//	if (root->rflag == 0)
//		MidSearch(root->R);
//}
//
////获取前驱
//char front(BTNode* p) {
//	BTNode* q = p->L;
//	if (p->lflag == 1) {
//		if (p->L != NULL) {
//			return p->L->data;
//		}
//		else return 'x';
//	}
//	else {
//		while(q->rflag==0&&q->R!=NULL){
//			q = q->R;
//		}
//		return q->data;
//	}
//}
////获取后继
//char last(BTNode* p) {
//	BTNode* q = p->R;
//	if (p->rflag == 1) {
//		if (p->R != NULL) {
//			return p->R->data;
//		}
//	}
//	else {
//		while(q->lflag==0&&q->L!=NULL){
//			q = q->L;
//		}
//		return q->data;
//	}
//}
//
//int main() {
//	int n;
//	char r;
//	cin >> n >> r;
//	BTree root = NULL;
//	root = InitBTree(root, r);
//	char x, fx;
//	for (int i = 2; i <= n; i++) {
//		cin >> x >> fx >> flag;
//		root = Insert(root, x, fx);
//	}
//	MidSearch(root);
//	char m;
//	cin >> m;
//	BTNode* f = Find(root, m);
//	BTNode* q = NULL;
//	//前驱
//	if (f->lflag == 1) {
//		if (f->L != NULL) cout << "前驱是：" << f->L->data << endl;		
//		else cout << "没有前驱" << endl;
//	}
//	else {
//		q = f->L;
//		while (q->rflag == 0&&q->R != NULL)	q = q->R;
//		cout << "前驱是：" << q->data << endl;
//	}
//	//后继
//	if (f->rflag == 1) {
//		if (f->R != NULL)cout << "后继是：" << f->R->data << endl;
//		else cout << "没有后继" << endl;
//	}
//	else {
//		q = f->R;
//		while (q->lflag == 0 && q->L != NULL)q = q->L;
//		cout << "后继是：" << q->data << endl;
//	}
//
//	return 0;
//}
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