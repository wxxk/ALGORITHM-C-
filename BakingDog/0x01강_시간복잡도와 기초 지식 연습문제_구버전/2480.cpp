#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, temp;
	cin >> a >> b >> c;
	
	if (a == b && a == c) {
		cout << 10000 + (a * 1000);	
	}
	else if (a == b || b == c || a == c) {
		if (a == b || a == c) {
			temp = a;
		}
		else {
			temp = b;
		}
		cout << 1000 + (temp * 100) << '\n';
	}
	else {
		cout << (a > (b > c ? b : c) ? a : (b > c ? b : c)) * 100 << '\n';
	}
} 
