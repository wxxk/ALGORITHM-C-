#include <bits/stdc++.h>
using namespace std;
char a[6] ="DCBAE";
int n = 3, num, sum;

int main() {
	for (int i = 0; i < n; i ++) {
		sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> num;
			sum += num;
		}
		cout << a[sum] << '\n';
	}
}
