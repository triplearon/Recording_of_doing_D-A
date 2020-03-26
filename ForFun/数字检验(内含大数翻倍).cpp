/* 输入一个数（最多不超过20位），将其X2后，检测得到数中各数字出现次数 如果和原数字一样输出Yes 反之输出No 然后输出翻倍后的数。
 * 牵涉到大于long long长度的数字 遂考虑用string实现大数翻倍
 * 原题来自PTA 数据结构与算法自测题
 */


#include <iostream>
#include <string>

using namespace std;

string doubleIL(string num);

int main() {
	string num;
	cin >> num;
	string Dnum = doubleIL(num);

	int numList[10] = {};
	int DList[10] = {};

	for (int i = 0; i < num.size(); i++) {
		numList[num[i] - 48]++;
	}

	for (int i = 0; i < Dnum.size(); i++) {
		DList[Dnum[i] - 48]++;
	}

	for (int i = 0; i < 10; i++) {
		if (numList[i] != DList[i]) {
			cout << "No" << endl;
			cout << Dnum;
			return 0;
		}
	}

	cout << "Yes" << endl;
	cout << Dnum;
	return 0;
}

string doubleIL(string numL)
{
	string ans, tmep;
	int YS = 0, CS = 0;
	auto s = 0;
	int b = numL.size() - 1;


	while (b > -1) {
		int num = ((numL[b] - 48) * 2);
		CS = YS + num % 10;
		YS = num / 10;
		char temp = CS + 48;
		tmep.push_back(temp);
		--b;
	}

	if (YS != 0) {
		char temp = YS + 48;
		tmep.push_back(temp);
	}

	for (int i = tmep.size() - 1; i >= 0; i--) {
		ans.push_back(tmep[i]);
	}
	return ans;
}
