/*  浙大数据结构mooc的题目 如果有版权就是他的
 *  浙大数据结构mooc的题目 如果有版权就是他的
 *  浙大数据结构mooc的题目 如果有版权就是他的
 *  原题在PTA里面 原题在PTA里面 原题在PTA里面
 *  函数题 需要实现的函数为List Merge(List L1,List L2)
*/


#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);
void attach(ElementType e, PtrToNode* prear);
void attachL(PtrToNode* L1, PtrToNode* L2);
List copyL(List L);
int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();


	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
}

/* 你的代码将被嵌在这里 */



List Read()
{
	List L = (List)malloc(sizeof(struct Node));
	L->Data = 0;
	L->Next = NULL;
	List rear = L;

	int size;
	scanf_s("%d", &size);
	while (size--) {
		int c;
		scanf_s("%d", &c);
		attach(c, &rear);
		
	}

	return L;
}


	void Print(List L)
{	
		List lp = L;
		if (lp->Next == NULL) {
			printf("NULL");
			return;
		}
		lp = lp->Next;
		while (lp) {
			printf("%d ", lp->Data);
			lp = lp->Next;
		}
		printf("\n");
}

List Merge(List L1, List L2)
{	
	List L1c = copyL(L1);
	List L2c = copyL(L2);

	List L = L1c;
	L1c = L1c->Next;
	L2c = L2c->Next;

	while (L2c) {



		while (L1c->Next && L1c->Next->Data < L2c->Data ) {
			L1c = L1c->Next;
		}

		if (!(L1c->Next)) {
			L1c->Next = L2c;
			break;
		}

		if (L1c->Data <= L2c->Data) {
			attachL(&L1c, &L2c);
		}
		else {
			List t = L2c;
			L2c = L2c->Next;
			t->Next = L1c;
			L->Next = t;
		}

		L1c = L->Next;
	}
	
	L1->Next = NULL;
	L2->Next = NULL;

	return	L;

}

void attach(ElementType e, PtrToNode* pRear)
{
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	
	p->Data = e;
	p->Next = NULL;
	(*pRear)->Next = p;
	(*pRear) = (*pRear)->Next;

}

void attachL(PtrToNode* L1, PtrToNode* L2) 
{
	List t = *L2;
	(*L2) = (*L2)->Next;
	t->Next = (*L1)->Next;
	(*L1)->Next = t;
}

List copyL(List L) {
	List t = (List)malloc(sizeof(struct Node));
	t->Next = NULL;
	PtrToNode rear = t;
	L = L->Next;
	while (L) {
		List E = (List)malloc(sizeof(struct Node));
		E->Next = L->Next;
		E->Data = L->Data;
		rear->Next = E;
		E->Next = NULL;
		rear = E;
		List temp = L;
		L = L->Next;
		free(temp);
		
	}

	return t;
}
