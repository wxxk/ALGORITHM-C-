#include <bits/stdc++.h>
using namespace std;
int main(){
	string a = "love is";
	a += " pain!";
	a.pop_back();	// ���ڿ� �� ����� (O(1)�� �ð����⵵) 
	cout << a << " : " << a.size() << "\n";
	cout << char(* a.begin()) << "\n";
	cout << char(* (a.end() -1)) << '\n';
	
	a.insert(0, "test ");
	cout << a << " : " << a.size() << "\n";
	
	a.erase(0, 5);
	cout << a << " : " << a.size() << "\n";
	
	auto it = a.find("love");	// auto : �ڵ� Ÿ�� �߷� 
	if (it != string::npos){	// std::string::find() : �Լ����� ã���� �ϴ� ���ڿ��� �߰ߵ��� �ʾ��� ��� ��ȯ�Ǵ� ��
		cout << "���ԵǾ� �ִ�." << '\n';
	}
	cout << it << "\n";
	cout << string::npos << '\n';
	
	cout << a.substr(5, 2) << '\n';
	
	return 0;
}

