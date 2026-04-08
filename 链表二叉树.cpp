//#include<iostream>	
//using namespace std;
//
//typedef struct TNode{
//	char data;
//	TNode* L;
//	TNode* R;
//}TNode,*Root;
//
//int flag;
//
////初始化
//Root Initial(char r) {
//	TNode* s = (TNode*)malloc(sizeof(TNode));
//	s->data = r;
//	s->L = s->R = NULL;
//	return s;
//}
//
//
////查找
//TNode* Find(Root root, char fx) {
//	if (root->data == fx) {
//		return root;
//	}
//	TNode* ans = NULL;
//	if (root->L != NULL) {
//		ans = Find(root->L, fx);
//		if (ans != NULL)return ans;			//找到了返回这个节点，没找到就在右边的树找
//	}
//	if (root->R != NULL) {
//		ans = Find(root->R, fx);
//		if (ans != NULL)return ans;
//	}
//	return NULL;
//}
//
////插入
//Root Insert(Root root, char x, char fx) {
//	TNode* s = (TNode*)malloc(sizeof(TNode));
//	s->data = x;
//	s->L = s->R = NULL;
//	TNode* fnode = Find(root, fx);
//	if (flag == 0) {
//		fnode->L = s;
//	}
//	else {
//		fnode->R = s;
//	}
//	return root;
//}
//
//
//int main() {
//	int n;
//	char r;
//	cin >> n >> r;
//	Root root=Initial(r);
//	char x, fx;
//	for (int i = 1; i < n; i++) {
//		cin >> x >> fx >> flag;
//		root = Insert(root, x, fx);
//	}
//	char target;
//	cout << "输入目标" << endl;
//	cin >> target;
//	TNode* Tar = Find(root, target);
//	if (Tar->L != NULL) {
//		cout << "左儿子是：" << Tar->L->data << endl;
//	}
//	else {
//		cout << "没有左儿子" << endl;
//	}
//	if (Tar->R != NULL) {
//		cout << "右儿子是：" << Tar->R->data << endl;
//	}
//	else {
//		cout << "没有右儿子" << endl;
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