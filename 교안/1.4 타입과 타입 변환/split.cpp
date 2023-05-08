#include <bits/stdc++.h>
using namespace std;
/*
 * 1. input에서 delimiter를 찾는다. (못 찾을 때까지 반복!)
 * 2. 해당 pos까지 해당 부분 문자열을 추출
 * 3. 추출한 문자열을 배열에 집어넣기
 * 4. 앞에서 부터 input문자열을 지운다.
 * 5. string ::npos를 만나면 남은 문자열을 배열에 넣는다. 
*/

vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

int main() {
	string s = "안녕하세요 큰돌이는 킹갓제너럴 천재입니다 정말이에요!", d = " ";
	vector<string> a = split(s, d);
	for(string b : a) cout << b << "\n";

}
