#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main() {
	cin >> T;
	string bufferflush;
	getline(cin, bufferflush);	//  6번째줄에서 T를 입력받고 남은 개행문자를 처리하기위해 사용 
	for (int i = 0; i < T; i++) {
		getline(cin, s);
		cout << s << "\n";
	}
	return 0;
}
