#include <iostream>
#include <string>
using namespace std;

string PY[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };

int main() {
	string num;
	cin >> num;
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		sum += (int)num[i]-48;
	}
	int lsum = sum;
	int level = 0;
	while (lsum != 0) {
		lsum /= 10;
		level++;
	}

	int* py = new int[level];

	for (int i = 0; i < level; i++) {
		py[i] = sum % 10;
		sum /= 10;
	}

	for (int i = level - 1; i > 0; i--) {
		cout << PY[py[i]] << " ";
	}

	cout << PY[py[0]];
  
  return 0;
}
