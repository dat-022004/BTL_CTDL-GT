#include <iostream>
using namespace std;

int tinhFibonacci(int n, int memo[]) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    int fib1 = tinhFibonacci(n - 1, memo);
    int fib2 = tinhFibonacci(n - 2, memo);

    cout << "Fibonacci(" << n << ") = Fibonacci(" << n - 1 << ") + Fibonacci(" << n - 2 << ") = "
         << fib1 << " + " << fib2 << " = " << fib1 + fib2 << endl;
    memo[n] = fib1 + fib2;
    return memo[n];
}

int main() {
    int n;
    cout << "Nhap so n de tinh Fibonacci: ";
    cin >> n;
    int memo[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1; 
    }
    cout << "\nTinh Fibonacci:\n";
    int ketQua = tinhFibonacci(n, memo);
    cout << "\nKet qua cuoi cung:\n";
    cout << "So Fibonacci thu " << n << " la: " << ketQua << endl;

    return 0;
}
