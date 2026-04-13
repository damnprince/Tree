#include<iostream>
using namespace std;

typedef struct Node {
	int weight;//权值
	int f;//父节点下标
	int l, r;//左右儿子下标
}HafumanTree;


void Find(HafumanTree* tree, int x, int* s1, int* s2) {
	int minn = 0;
	//找第一小
	for (int i = 0; i <= x; i++) {
		if (tree[i].f == -1) {
			minn = i;//找到第一个根节点
			break;
		}
	}
	for (int i = 0; i <= x; i++) {
		if (tree[i].f == -1 && tree[i].weight < tree[minn].weight) 
			minn = i;
	}
	*s1 = minn;
	//找第二小
	for (int i = 0; i <= x; i++) {
		if (tree[i].f == -1&&i!=*s1) {
			minn = i;//找到第一个根节点
			break;
		}
	}
	for (int i = 0; i <= x; i++) {
		if (tree[i].f == -1 && i != *s1 && tree[i].weight < tree[minn].weight)
			minn = i;
	}
	*s2 = minn;
}

//创建哈夫曼树
HafumanTree* CreateTree(int w[], int n) {
	int m = 2 * n - 1;//哈夫曼树总节点个数
	//用结构体数组表示树
	HafumanTree* tree = (HafumanTree*)malloc(sizeof(HafumanTree) * m );
	//每个叶子节点就是一棵树
	for (int i = 0; i < n; i++) {
		tree[i].f = -1;
		tree[i].l = tree[i].r = -1;
		tree[i].weight = w[i];
	}
	//合并两颗权值最小的树
	int s1, s2;//s1存放tree[0]~tree[n-1]中权值最小的节点的下标，s2第二小
	for (int i = n; i < m; i++) {
		Find(tree, i - 1, &s1, &s2);
		tree[i].f = -1;
		tree[i].l = s1;
		tree[i].r = s2;
		tree[s1].f = i;tree[s2].f = i;
		tree[i].weight = tree[s1].weight + tree[s2].weight;
	}
	return tree;
}

//哈夫曼树编码
char** CreateCode(HafumanTree* tree, int n) {
	char* t = (char*)malloc(sizeof(char) * n);
	char** code = (char**)malloc(sizeof(char*) * n);
	memset(code, 0, sizeof(char*) * n);
	t[n - 1] = '\0';
	int start = 0;
	int p = 0, pre = 0;
	for (int i = 0; i < n; i++) {
		start = n - 1;
		p = i, pre = tree[p].f;
		while (pre != -1) {
			start--;
			if (p == tree[pre].l) 
				t[start] = '1';
			else 
				t[start] = '0';
			p = pre;
			pre = tree[pre].f;
		}
		code[i] = (char*)malloc(sizeof(char) * (n - start));
		strcpy_s(code[i], sizeof(char)*n, &t[start]);
	}
	return code;
}

int main() {
	int n;
	cout << "请输入个数" << endl;
	cin >> n;
	char a[105];
	int w[105];//存放每个结点的权值
	//设置每个结点的数据和权值
	getchar();
	for (int i = 0; i < n; i++) {
		scanf_s("%c", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	//创建哈夫曼树
	HafumanTree* Tree = CreateTree(w, n);//传入权值和叶子节点个数
	//test
	/*int i = 0;
	while (i < n) {
		cout << a[i] << ":" << Tree[i].f << " " << Tree[i].weight << endl;
		i++;
	}
	while (i < 2 * n - 1) {
		cout << "Tree[" << i << "]:" << Tree[i].f << " " << Tree[i].weight << " " << Tree[i].l << " " << Tree[i].r << endl;
		i++;
	}*/

	char** Code = CreateCode(Tree, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ":" << Code[i] << endl;
	}
	return 0;
}
/*
9
agmteh is
1 1 1 1 2 2 3 3 5

*/