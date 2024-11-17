#include <iostream>
using namespace std;

int tinhGiaiThua(int n) {
    if (n == 0) {
        cout << "\ngiai thua(0) = 1\n";
        return 1;
    }

    cout << "giai thua(" << n << ") = " << n << " * giai thua(" << n - 1 << ")\n";
    int result = n * tinhGiaiThua(n - 1);  
    cout << "giai thua(" << n << ") = " << result << "\n"; 
    return result;
}

int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;

    cout << "\nBieu thuc giai thua:"<< endl;
    int ketQua = tinhGiaiThua(n);
    cout << "\nKet qua cuoi cung:\n";
    cout << "\nGiai thua cua " << n << " la: " << ketQua << "\n";

    return 0;
}
