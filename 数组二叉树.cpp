//#include<iostream>
//using namespace std;
//#define maxx 100
//
//char tdata[maxx];
//
//int flag;
//
////初始化
//void initial(char r) {
//	for (int i = 0; i < maxx; i++) {
//		tdata[i] = ' ';
//	}
//	tdata[1] = r;
//}
//
////查找
//int find(char fx) {
//	int i;
//	for (i = 1; i < maxx; i++) {
//		if (tdata[i] == fx)
//			break;
//	}
//	return i;
//}
//
////插入
//void insert(char x, char fx) {
//	int fi = find(fx);
//	if (flag == 0) {
//		tdata[fi * 2] = x;
//	}
//	else {
//		tdata[fi * 2 + 1] = x;
//	}
//}
//
//int main() {
//	int n;
//	char r;
//	printf("输入插入的个数：\n");
//	cin >> n;
//	cout << "输入根节点数据" << endl;
//	cin >> r;
//	initial(r);
//	char x, fx;
//	for (int i = 1; i < n; i++) {
//		cin >> x >> fx >> flag;
//		insert(x, fx);
//	}
//	char target;
//	cout << "找谁?" << endl;
//	cin >> target;
//	int xi = find(target);
//	if (xi == 1) {
//		cout << "他是根节点" << endl;
//	}
//	cout << "他的儿子是：" << tdata[xi * 2] << "和" << tdata[xi * 2 + 1] << endl;
//	return 0;
//}
///*
//a
//b a 0
//c a 1
//d b 0
//e c 1
//f d 0
//*/