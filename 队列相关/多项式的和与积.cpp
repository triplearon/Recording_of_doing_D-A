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
	if (sumNode->N == 0) {
		free(sumNode);
		return NULL;
	}

	return sumNode;
}

void pushNode(EList L,Rear R,PtrToENode N) {
	if (!N || N->N==0) {
		return;
	}
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
	if (isEmpty(L1)) {
		return L2;
	}
	else if (isEmpty(L2)) {
		return L1;
	}
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
	else if(CN2) {
		sumr->Next->Next = CN2;
	}

	return sum;
}

PtrToENode multiplyN(PtrToENode N1, PtrToENode N2) {
	PtrToENode ans = (PtrToENode)malloc(sizeof(struct ExpNode));
	ans->E = N1->E + N2->E;
	ans->N = N1->N * N2->N;
	ans->Next = NULL;

	return ans;
}

EList multiplyL(EList L1, EList L2) {
	EList ans = creat();
	Rear ansr = creatRear(ans);
	Rear L1r = L1->Next;
	Rear L2r = L2->Next;

	if (isEmpty(L1) || isEmpty(L2)) {
		return ans;
	}
	while (L2r) {
		pushNode(ans, ansr, multiplyN(L1r, L2r));
		L2r = L2r->Next;
	}

	L1r = L1r->Next;

	while (L1r) {
		L2r = L2->Next;
		while (L2r) {
			PtrToENode Node = multiplyN(L1r, L2r);
			L2r = L2r->Next;
			if (Node->E < ansr->Next->E) {
				pushNode(ans, ansr, Node);
				
				continue;
			}

			PtrToENode NP = ans->Next;
			while (NP) {
				if (NP->Next->E == Node->E) {
					
					if (NP->Next->N +Node->N == 0) {
						if (NP->Next->Next == NULL) {
							ansr->Next = NP;
						}

						
						NP->Next = NP->Next->Next;
						
						break;
					}
					NP->Next->N += Node->N;
					break;
				}

				if (Node->E > NP->Next->E) {
					Node->Next = NP->Next;
					NP->Next = Node;
					break;
				}
				else {
					NP = NP->Next;
				}
			}

		}
		L1r = L1r->Next;
	}

	return ans;

}

void Print(EList L) {
	PtrToENode index = L->Next;
	if (isEmpty(L)) {
		cout << "0 0\n";
		return;
	}
	
	while (index->Next) {
		cout << index->N << " " << index->E << " ";
		index = index->Next;
	}

	cout << index->N << " " << index->E << endl;
}
int main3() {
	EList T1 = creat();
	EList T2 = creat();
	Rear T1r = creatRear(T1);
	Rear T2r = creatRear(T2);

	int times;
	cin >> times;
	for (int i = 0; i < times; i++) {
		int c, e;
		cin >> c>>e;
		pushData(T1, T1r, c, e);
	}

	cin >> times;

	for (int i = 0; i < times ; i++) {
		int c, e;
		cin >> c>>e;
		pushData(T2, T2r, c, e);
	}

	EList ST = attachSum(T1, T2);
	EList MT = multiplyL(T1, T2);
	
	Print(MT);
	Print(ST);
}
