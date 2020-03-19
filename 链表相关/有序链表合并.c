/*  浙大数据结构mooc的题目 如果有版权就是他的
 *  浙大数据结构mooc的题目 如果有版权就是他的
 *  浙大数据结构mooc的题目 如果有版权就是他的
 *  原题在PTA里面 原题在PTA里面 原题在PTA里面
 *  函数题 需要实现的函数为List Merge(List L1,List L2)
 *  详情：https://pintia.cn/problem-sets/1211841066264109056/problems/1231458941036285952
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
