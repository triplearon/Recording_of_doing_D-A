//输入打印总数和打印符号 空格隔开 慢速版

#include <iostream>

using namespace std;

int main() {
	int num;
	char tag;
	cin >> num >> tag;

	int level = 1;
	int count = 1;
	int numInLevel = 1;
	while (count < num) {
		level++;
		numInLevel = level * 2 - 1;
		count = count + 2 * numInLevel;
	}
	int left;
	if (count != num) {
		count -= 2 * numInLevel;
		level--;
		numInLevel = level * 2 - 1;
		left = num - count;
	
	}
	else {
		
		left = 0;
	}
	

	for (int i = 0, print = numInLevel, space = 0; i < level; i++, space++, print -= 2) {
		for (int i = 0; i < space; i++) {
			cout << " ";
		}

		for (int i = 0; i < print; i++) {
			cout << tag;
		}

		cout << "\n";
	}

	for (int i = 1, space = numInLevel/2-1, RnumInLevel = 0; i < level; i++) {
		RnumInLevel = (i + 1) * 2 - 1;
		for (int i = 0; i < space; i++) {
			cout << " ";
		}

		for (int i = 0; i < RnumInLevel; i++) {
			cout << tag;
		}

		space--;
		cout << "\n";
	}

	if (left) {
		cout << left;
	}
	else {
		cout << "0";
	}


	return 0;
}
