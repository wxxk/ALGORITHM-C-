#include <bits/stdc++.h>
using namespace std;
//vector<int> num;
//int n = 9;
//int input;
//
//int max_index;
//
//int main() {
//	for (int i = 0; i < n; i++) {
//		cin >> input;
//		num.push_back(input);
//	}
//	
//	int max = num[0];	
//	for (int i = 1; i < n; i ++) {
//		if (num[i] > max) {
//			max = num[i];
//			max_index = i;
//		}
//	}
//	cout << max << '\n';
//	cout << max_index + 1 << '\n';
//}

vector<int> v;
int input;
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> input;
		v.push_back(input);
	}
	
	int max_v = *max_element(v.begin(), v.end());
	auto max_i = max_element(v.begin(), v.end()) - v.begin();
	
	cout << max_v << '\n';
	cout << max_i + 1 << '\n';
}
