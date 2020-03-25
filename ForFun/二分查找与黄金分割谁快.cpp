#include <iostream>
#include<ctime>
#define SEARCH_ERROR -1;

clock_t start, endt;

using namespace std;

int binarySearch(int *List,int K,int length);

int FibonacciSearch(int* List, int K,int length);

int main() {
	int TestList[200000] = {};
	int length = 200000;

	for (int i = 0; i < length; i++) {
		TestList[i] = i;
	}

	srand(123456789);
	start = clock();
	for (int i = 0; i < 500000; i++) {
		int K = (rand() % 200000);
		binarySearch(TestList, K, length);
	}
	endt = clock();
	cout<<"bi: " << (double)(endt - start) * 1000 << "ms " << endl;

	srand(123456789);
	start = clock();
	for (int i = 0; i < 500000; i++) {
		int K = (rand() % 200000);
		FibonacciSearch(TestList, K, length);
	}
	endt = clock();
	cout << "Fi: " << (double)(endt - start) * 1000 << "ms " << endl;
}



int binarySearch(int* List, int K,int length)
{
	int left, right, mid;
	left = 0, right = length - 1, mid = left + (right - left) / 2;

	while (left <= right) {
		if (K > List[mid]) {
			left = mid + 1;
			mid = left + (right - left) / 2;
		}
		else if (K < List[mid]) {
			right = mid - 1;
			mid = left + (right - left) / 2;
		}
		else {
			return mid;
		}
	}

	return SEARCH_ERROR;

}

int FibonacciSearch(int* List, int K,int length)
{
	int left = 0, right = length - 1, GS = left + 0.618 * (right - left);
	
	while (left <= right) {
		if (K > List[GS]) {
			left = GS + 1;
			GS = left + (right - left) / 2;
		}
		else if (K < List[GS]) {
			right = GS - 1;
			GS = left + (right - left) / 2;
		}
		else {
			return GS;
		}
	}

	return SEARCH_ERROR;
}
