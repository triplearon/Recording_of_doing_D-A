#include <iostream>

using namespace std;
typedef struct ExpNode* PtrToENode;
typedef int Exp;
typedef int Coe;
struct ExpNode
{
	Exp E;
	Coe N;
	PtrToENode Next;
};
typedef PtrToENode EList;
typedef PtrToENode Rear;

bool isEmpty(EList L) {
	return L->Next == NULL;
}

EList creat() {
	EList head = (EList)malloc(sizeof(struct ExpNode));
	head->Next = NULL;
	return head;
}

Rear creatRear(EList L) {
	Rear R =(Rear) malloc(sizeof(struct ExpNode));
	R->Next = L->Next;
	return R;
}

PtrToENode add(PtrToENode* N1, PtrToENode* N2) {
	PtrToENode sumNode = (EList)malloc(sizeof(struct ExpNode));
	sumNode->E = (*N2)->E;
	sumNode->N = (*N1)->N + (*N2)->N;
	sumNode->Next = NULL;


	return sumNode;
}

void pushNode(EList L,Rear R,PtrToENode N) {
	if (isEmpty(L)) {
		N->Next = L->Next;
		L->Next = N;
		R->Next = N;
	}
	else {
		R->Next->Next = N;
		N->Next = NULL;
		R->Next = N;
	}
}

void pushData(EList L,Rear R, Coe N, Exp E) {
	PtrToENode ND = (PtrToENode)malloc(sizeof(struct ExpNode));
	ND->E = E;
	ND->N = N;
	ND->Next = NULL;
	pushNode(L,R, ND);
}

void head(EList L) {
	if (isEmpty(L)) {
		std::cout << " 0 0";
		return;
	}
	
	std::cout <<" "<< L->Next->E << " " << L->Next->N;
}

void rear(Rear R) {
	if (R->Next == NULL) {
		std::cout << " 0 0";
		return;
	}

	std::cout <<" "<< R->Next->E << " " << R->Next->N;
}

EList attachSum(EList L1, EList L2) {
	EList sum = creat();
	Rear sumr = creatRear(sum);

	PtrToENode CN1 = L1->Next;
	PtrToENode CN2 = L2->Next;

	while (CN1 && CN2) {
		if (CN1->E > CN2->E) {
			pushData(sum, sumr, CN1->N, CN1->E);
			CN1 = CN1->Next;
		}
		else if (CN1->E < CN2->E) {
			pushData(sum, sumr, CN2->N, CN2->E);
			CN2 = CN2->Next;
		}
		else {
			pushNode(sum,sumr,add(&CN1, &CN2));
			CN1 = CN1->Next;
			CN2 = CN2->Next;
		}
	}

	if (CN1) {
		sumr->Next->Next = CN1;
	}
	else {
		sumr->Next->Next = CN2;
	}

	return sum;
}



int main() {
	EList T1 = creat();
	EList T2 = creat();
	Rear T1r = creatRear(T1);
	Rear T2r = creatRear(T2);

	for (int i = 0; i < 3; i++) {
		int c, e;
		cin >> c>>e;
		pushData(T1, T1r, c, e);
	}

	for (int i = 0; i < 2; i++) {
		int c, e;
		cin >> c>>e;
		pushData(T2, T2r, c, e);
	}

	EList sum = attachSum(T1, T2);

	head(sum);
}


