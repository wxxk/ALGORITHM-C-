#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main() {
	cin >> T;
	string bufferflush;
	getline(cin, bufferflush);	//  6��°�ٿ��� T�� �Է¹ް� ���� ���๮�ڸ� ó���ϱ����� ��� 
	for (int i = 0; i < T; i++) {
		getline(cin, s);
		cout << s << "\n";
	}
	return 0;
}
