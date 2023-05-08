#include <bits/stdc++.h>
using namespace std;
/*
 * 1. input���� delimiter�� ã�´�. (�� ã�� ������ �ݺ�!)
 * 2. �ش� pos���� �ش� �κ� ���ڿ��� ����
 * 3. ������ ���ڿ��� �迭�� ����ֱ�
 * 4. �տ��� ���� input���ڿ��� �����.
 * 5. string ::npos�� ������ ���� ���ڿ��� �迭�� �ִ´�. 
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
	string s = "�ȳ��ϼ��� ū���̴� ŷ�����ʷ� õ���Դϴ� �����̿���!", d = " ";
	vector<string> a = split(s, d);
	for(string b : a) cout << b << "\n";

}
