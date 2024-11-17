#include <iostream>
#include <cstdlib>  
using namespace std;

int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;  
        }
    }
    return -1; 
}

void sapXepNoiBong(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

void inMang(int a[], int n) {
    cout << "Mang hien tai:\n";
    cout << "----------------------------------------\n";
    cout << "Vi tri | Gia tri\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << i << "   |   " << a[i] << endl; 
    }
    cout << "----------------------------------------\n\n";
}

void nhapMang(int*& a, int& n) {
    cout << "\nNhap so phan tu cho mang: ";
    cin >> n;

    if (n <= 0) {
        cout << "Mang phai co it nhat 1 phan tu. Vui long nhap lai.\n";
        return;
    }

    a = new int[n];  
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": "; 
        cin >> a[i];
    }
    cout << "Mang da duoc nhap thanh cong.\n\n";
}

int main() {
    int n, choice, x;
    int* a = nullptr;

    do {
        system("cls"); 
        cout << "\n============= MENU =============";
        cout << "\nChon giai thuat can thuc hien:\n";
        cout << "1. Nhap mang\n";
        cout << "2. Tim kiem tuyen tinh\n";
        cout << "3. Sap xep noi bong\n";
        cout << "4. Tim phan tu lon nhat\n";
        cout << "5. Tim phan tu nho nhat\n";
        cout << "6. Thoat\n";
         cout << "================================\n";
        cout << "Nhap lua chon (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                nhapMang(a, n); 
                break;
            }
            case 2: {
                cout << "\nNhap gia tri can tim: ";
                cin >> x;
                int index = timKiemTuyenTinh(a, n, x);
                if (index != -1) {
                    cout << "Phan tu " << x << " duoc tim thay tai vi tri: " << index << "\n\n";
                } else {
                    cout << "Khong tim thay phan tu " << x << "\n\n";
                }
                
                break;
            }
            case 3: {
                cout << "\nMang truoc khi sap xep: \n";
                inMang(a, n);  
                sapXepNoiBong(a, n); 
                cout << "Mang sau khi sap xep: \n";
                break;
            }
            case 4: {
                cout << "\nPhan tu lon nhat trong mang: " << timMax(a, n) << "\n\n";
                break;
            }
            case 5: {
                cout << "\nPhan tu nho nhat trong mang: " << timMin(a, n) << "\n\n";
                break;
            }
            case 6: {
                cout << "\nThoat chuong trinh...\n\n";
                break;
            }
            default: {
                cout << "\nLua chon khong hop le! Vui long chon lai.\n\n";
                break;
            }
        }

        inMang(a, n); 
        cout << "=> An phim bat ki de nhap lua chon tiep theo...\n";
        system("pause");  

    } while (choice != 6);

    return 0;
}
