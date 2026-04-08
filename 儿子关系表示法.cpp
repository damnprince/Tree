//#include<iostream>
//using namespace std;
//#define maxx 10
//struct cList {
//	int chi;
//	cList* next;
//};
//
//struct cNode {
//	char data;
//	int fa;
//	cList* son;
//}t[maxx];
//
//int len;
//初始化
//void InitTree(char r) {
//	t[0].data = r;
//	t[0].fa = -1;
//	t[0].son = NULL;
//	len++;
//}
//
//查找
//int find(char fx) {
//	int i = 0;
//	for (; i < len; i++) {
//		if (t[i].data == fx)break;
//	}
//	return i;
//}
//
//插入
//void Insert(char x, char fx) {
//	判满
//	if (len == maxx) {
//		cout << "树满" << endl;
//		return;
//	}
//	t[len].data = x;
//	int f = find(fx);
//	t[len].fa = f;
//	cList* s = (cList*)malloc(sizeof(cList));
//	s->chi = len;
//	s->next = t[f].son;
//	t[f].son = s;
//	len++;
//}
//
//输出
//void PrintTree() {
//	if (len == 0) {
//		cout << "空树" << endl;
//		return;
//	}
//	for (int i = 0; i < len; i++) {
//		cout << t[i].data << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	int n;
//	char r;
//	cout << "请输入节点个数：" << endl;
//	cin >> n;
//	cout << "请输入根结点数据：" << endl;
//	cin >> r;
//	InitTree(r);
//	for (int i = 0; i < n; i++) {
//		char x, fx;
//		cout << "请输入节点数据及其父节点数据：" << endl;
//		cin >> x >> fx;
//		Insert(x, fx);
//	}
//	char x;
//	cout << "请输入要查找的节点数据：" << endl;
//	cin >> x;
//	int f = find(x);
//	if (t[f].fa == -1) {
//		cout <<x<< "是根节点,没有父节点" << endl;
//	}
//	else {
//		cout << x << "的父亲是：" << t[t[f].fa].data << endl;
//	}
//
//	if (t[f].son == NULL) {
//		cout << "该节点没有儿子节点" << endl;
//	}
//	cList* p = t[f].son;
//	cout << x << "的儿子是：";
//	while (p != NULL) {
//		cout << t[p->chi].data << " ";
//		p = p->next;
//	}
//	cout << endl;
//	PrintTree();
//}
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