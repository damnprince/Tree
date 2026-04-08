//#include<iostream>
//using namespace std;
//
//typedef struct Node {
//	char data;
//	Node* ch;
//	Node* bro;
//}Node, * ListTree;
//
////初始化
//ListTree InitTree(ListTree root, char r) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	s->data = r;
//	s->ch = s->bro = NULL;
//	root = s;
//	return root;
//}
//
////查找	递归实现
//ListTree Find(ListTree root, char fx) {
//	if (root->data == fx) {
//		return root;
//	}
//	//先从儿子开始找
//	if (root->ch != NULL) {
//		Node* ans = Find(root->ch, fx);
//		if (ans != NULL) {
//			return ans;
//		}
//	}
//	//再从兄弟里找
//	if (root->bro != NULL) {
//		Node* ans = Find(root->bro, fx);
//		if (ans != NULL) {
//			return ans;
//		}
//	}
//	//如果都没找到，就返回NULL
//	return NULL;
//}
//
////ListTree ffind(ListTree root, char fx) {
////	if (root->data == fx)
////		return root;
////	Node* q = root->ch;
////	for (q; q != NULL; q = q->ch) {
////		Node* p = q->bro;
////		while (p->bro != NULL&&p->data!=fx) {
////			p = p->bro;
////		}
////		if (p->data == fx)
////			return p;
////	}
////	return NULL;
////}
//
////插入
//ListTree Insert(ListTree root, char x, char fx) {
//	Node* s = (Node*)malloc(sizeof(Node));
//	s->data = x;
//	s->ch = s->bro = NULL;
//	Node* f = Find(root, fx);//f是父亲
//	if (f->ch == NULL) {//如果父节点没有儿子，就插在他的ch
//		f->ch = s;
//	}
//	else {//如果有儿子了，就从大儿子开始找，直到找到最小的儿子，就插到他后面
//		Node* p = f->ch;//p是大儿子
//		while (p ->bro!= NULL) {
//			p = p->bro;
//		}
//		p->bro = s;
//	}
//	return root;
//}
//
//void test01() {
//	int n;
//	cout << "几个数？" << endl;
//	cin >> n;
//	cout << "根节点？" << endl;
//	char r;
//	cin >> r;
//	ListTree root = NULL;
//	root = InitTree(root, r);
//	for (int i = 0; i < n; i++) {
//		char x, fx;
//		cout << "插入x和fx" << endl;
//		cin >> x >> fx;
//		root = Insert(root, x, fx);
//	}
//	char x;
//	cout << "找谁？" << endl;
//	cin >> x;
//	Node* p = Find(root, x);
//	Node* h = p->ch;
//	while (h != NULL) {
//		cout << h->data << " ";
//		h = h->bro;
//	}
//}
//
//int main() {
//	test01();
//
//	return 0;
//}
///*
//A
//B
//A
//C
//A
//D
//A
//E
//B
//*/