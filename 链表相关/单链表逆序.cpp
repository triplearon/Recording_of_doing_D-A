#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
using namespace std;
typedef int address;
typedef int elementype;
typedef struct Node* PTN;
struct Node
{
	address Ads;
	elementype Data;
	address NA;
	PTN Next;
};
int length;
typedef PTN List;
const int MAX_SIZE = 100000;
Node NList[MAX_SIZE] = {};

void creatNode(address add, address nadd, elementype Data) {
	Node tag = {
		add,
		Data,
		nadd,
		NULL
	};

	NList[tag.Ads] = tag;
}

void creatList(address startAD) {
	PTN tag = & NList[startAD];
	while (tag->NA != -1) {
		tag->Next = &(NList[tag->NA]);
		tag = & NList[tag->NA];
		length++;
	}
	length++;
}

address ReversList(address startAD, int K) {
	int Num = length;
	PTN head = &NList[startAD];
	PTN newhead = head;
	for (int i = 1; i < K; i++) {
		newhead = newhead->Next;
	}
	PTN lastHead = head;
	while (Num >= K) {
		
		PTN N, O, T;
		N = lastHead;
		O = N->Next;
		T = O;
		N->Next = NULL;
		N->NA = -1;
		for (int i = 0; i < K - 1; i++) {
			T = T->Next;
			O->Next = N;
			O->NA = N->Ads;
			N = O;
			O = T;
		}

		Num -= K;
		if (Num >= K) {
			T = O;
			for (int i = 1; i < K; i++) {
				O = O->Next;
			}
			lastHead->Next = O;
			lastHead->NA = O->Ads;
			lastHead = T;
		}
		else if(O) {
			lastHead->Next = O;
			lastHead->NA = O->Ads;
		}
	}

	return newhead->Ads;
}

void Print(List L) {

	while (L->Next) {
		printf("%05d %d %05d\n",L->Ads,L->Data,L->NA);
		L = L->Next;
	}
	printf("%05d %d %d", L->Ads, L->Data, L->NA);
}


int main() {
	address startAD;
	int N, K;
	cin >> startAD >> N >> K;
	for (int i = 0; i < N; i++) {
		address add, nadd;
		elementype data;
		scanf("%d %d %d",&add,&data,&nadd);
		creatNode(add, nadd, data);
	}
	
	creatList(startAD);
	address reved = ReversList(startAD, K);
	Print(&NList[reved]);
}
