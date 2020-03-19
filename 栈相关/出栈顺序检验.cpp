/*  题目来源浙大mooc数据结构课
 *  题目来源浙大mooc数据结构课
 *  题目来源浙大mooc数据结构课
 *  原题目在PTA上 原题目在PTA上 原题目在PTA上
 *  输入栈最大容量M 入栈数字1 2 3 ··· N 一共T个待检验的出栈顺序 顺序入栈 随机出栈
 *  检验出栈顺序的合理性 合理YES 不合理NO 
 */





#include <iostream>
using namespace std;
typedef struct Node* PtrToNode;
typedef int ElementType;
struct Node
{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

List creat();
void push(ElementType e, List L);
bool isEmpty(List L);
ElementType pop(List L);
unsigned size(List L);
ElementType head(List L);


int main2() {
	int M, N, T;
	cin >> M >> N >> T;
	int** arrayP = new int* [T];
	for (int i = 0; i < T; i++) {
		int* iArray = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> iArray[i];
		}
		arrayP[i] = iArray;
	}
	int c = 0;
	while (T) {
		int* NA = new int[N];
		int* IA = arrayP[c];
		int* TA = new int[N];
		List L = creat();
		bool isOverSize = 0;
		for (int i = 0; i < N; i++) NA[i] = i+1;

		if (IA[0] > M) {
			cout << "NO\n";
			T--;
			c++;
			continue;
		}
		else {
			for (int i = 1; i <= IA[0]; i++) {
				push(i, L);
			}
		}
		int count=0;
		for (int* p = NA + IA[0]; p != NA + N; ) {
			if (isEmpty(L)) {
				push(*p, L);
				p++;
			}
			while (IA[count] != head(L)) {
				push(*p, L);
				p++;
			}

			if (size(L) > M) {
				isOverSize = 1;
				break;
			}

			TA[count] = pop(L);
			count++;
		}

		if (isOverSize) {
			cout << "NO\n";
			T--;
			c++;
			continue;
		}

		while (!isEmpty(L)) {
			TA[count] = pop(L);
			count++;
		}
		bool isRight = 1;
		for (int i = 0; i < N; i++) {
			if (IA[i] != TA[i]) {
				isRight = 0;
				break;
			}
		}
		if (isRight) {
			cout << "YES\n";
			
		}
		else {
			cout << "NO\n";
		}


		c++;
		T--;
	}
}


List creat() {
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;

	return L;
}
void push(ElementType e, List L) {
	PtrToNode n = (List)malloc(sizeof(struct Node));
	n->Data = e;
	n->Next = L->Next;
	L->Next = n;
}

bool isEmpty(List L) {
	return L->Next == NULL;
}

ElementType pop(List L) {
	if (!isEmpty(L)) {
		PtrToNode t = L->Next;
		L->Next = L->Next->Next;
		int e = t->Data;
		free(t);
		return e;
	}
	return NAN;
}

unsigned size(List L)
{
	PtrToNode p = L;
	p = p->Next;
	unsigned count = 0;
	while (p) {
		count++;
		p = p->Next;
	}

	return count;
}

ElementType head(List L)
{
	return L->Next->Data;
}

