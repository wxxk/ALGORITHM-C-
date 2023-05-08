#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
	if(n == 1 || n == 0) return n;
	return n * fact(n - 1);
}

int fibo(int n) {
//	cout << "fibo : " << n << '\n';	// 디버깅을 위한 출력 
	if (n == 0 || n == 1) return n;
	return (fibo(n - 1) + fibo(n - 2));
}

int n = 5;
int main() {
	cout << fact(n) << '\n';
	cout << fibo(n) << '\n';
	return 0;
}
