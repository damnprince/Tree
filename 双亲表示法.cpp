//#include<iostream>
//using namespace std;
//#define maxx 10
//
//struct Tree {
//	char data;
//	int fa;
//}t[maxx];
//
//int len;
//
////初始化
//void InitRoot(char r) {
//	t[0].data = r;
//	t[0].fa = -1;
//	len++;
//}
////查找某个结点的下标
//int Find(char fx) {
//	int i = 0;
//	for (i; i < len; i++) {
//		if (t[i].data == fx) {
//			break;
//		}
//	}
//	return i;
//}
//
////插入
//void Insert(char x, char fx) {
//	t[len].data = x;
//	int i = Find(fx);//找x的父亲fx的下标
//	t[len].fa = i;
//	len++;
//}
//
//int main() {
//	int n;
//	char r;
//	cout << "请输入要插入结点的个数：" ;
//	cin >> n;
//	cout << "请输入根结点的数据：" ;
//	cin>> r;
//	InitRoot(r);
//	char x, fx;
//	for (int i = 1; i < n; i++) {
//		cin >> x >> fx;
//		Insert(x, fx);
//	}
//	//输入某个节点的数据，去找他的父亲和儿子
//	char a;
//	cout << "请输入要查找的节点数据：";
//	cin >> a;
//	int i=Find(a);//i接受a的下标
//	int fi = t[i].fa;//fi接受a父亲节点
//	if (fi == -1) {
//		cout << a << "是根节点,没有父亲" << endl;
//	}
//	else {
//		cout << a << "的父亲是" << t[fi].data << endl;
//	}
//	for (int j = 1; j < len; j++)
//	{
//		if (t[j].fa == i) {
//			cout << a << "的儿子是" << t[j].data << endl;
//		}
//	}
//
//
//	return 0;
//}