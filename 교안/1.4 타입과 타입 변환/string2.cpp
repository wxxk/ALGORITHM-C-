#include <bits/stdc++.h>
using namespace std;
int main(){
	string a = "love is";
	a += " pain!";
	a.pop_back();	// 문자열 끝 지우기 (O(1)의 시간복잡도) 
	cout << a << " : " << a.size() << "\n";
	cout << char(* a.begin()) << "\n";
	cout << char(* (a.end() -1)) << '\n';
	
	a.insert(0, "test ");
	cout << a << " : " << a.size() << "\n";
	
	a.erase(0, 5);
	cout << a << " : " << a.size() << "\n";
	
	auto it = a.find("love");	// auto : 자동 타입 추론 
	if (it != string::npos){	// std::string::find() : 함수에서 찾고자 하는 문자열이 발견되지 않았을 경우 반환되는 값
		cout << "포함되어 있다." << '\n';
	}
	cout << it << "\n";
	cout << string::npos << '\n';
	
	cout << a.substr(5, 2) << '\n';
	
	return 0;
}

