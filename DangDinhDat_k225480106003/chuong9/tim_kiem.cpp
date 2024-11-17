#include <iostream>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Hàm xóa màn hình
void xoaManHinh() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear");  
#endif
}

// 1. Tìm kiếm tuần tự (Linear Search)
int timKiemTuanTu(int arr[], int n, int target) {
    cout << "\n===== Chi tiet tim kiem tuan tu =====\n";
    for (int i = 0; i < n; i++) {
        cout << "Kiem tra phan tu tai chi so [" << i << "] voi gia tri: " << arr[i] << endl;
        if (arr[i] == target) {
            cout << "=> Tim thay phan tu tai chi so [" << i << "]\n";
            return i;  
        }
    }
    cout << "=> Khong tim thay phan tu trong mang.\n";
    return -1;  
}

// 2. Tìm kiếm nhị phân (Binary Search)
int timKiemNhiPhan(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    cout << "\n===== Chi tiet tim kiem nhi phan =====\n";
    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "Kiem tra mid = " << mid << " (gia tri: " << arr[mid] << ")\n";
        if (arr[mid] == target) {
            cout << "=> Tim thay phan tu tai chi so [" << mid << "]\n";
            return mid;  
        } else if (arr[mid] < target) {
            cout << "Phan tu can tim lon hon. Di chuyen left sang [" << mid + 1 << "]\n";
            left = mid + 1;  
        } else {
            cout << "Phan tu can tim nho hon. Di chuyen right ve [" << mid - 1 << "]\n";
            right = mid - 1;  
        }
    }
    cout << "=> Khong tim thay phan tu trong mang.\n";
    return -1; 
}

// 3. Tìm kiếm nhảy (Jump Search)
int timKiemNhay(int arr[], int n, int target) {
    int step = sqrt(n); 
    int prev = 0;
    cout << "\n===== Chi tiet tim kiem nhay =====\n";
    while (arr[min(step, n) - 1] < target) {
        cout << "Kiem tra khoi [" << prev << " -> " << step - 1 << "] voi gia tri cuoi: " << arr[min(step, n) - 1] << endl;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "=> Vuot qua gioi han mang. Khong tim thay phan tu.\n";
            return -1;  
        }
    }
    cout << "Tim trong khoi [" << prev << " -> " << min(step, n) - 1 << "]\n";
    for (int i = prev; i < min(step, n); i++) {
        cout << "Kiem tra phan tu tai chi so [" << i << "] voi gia tri: " << arr[i] << endl;
        if (arr[i] == target) {
            cout << "=> Tim thay phan tu tai chi so [" << i << "]\n";
            return i;  
        }
    }
    cout << "=> Khong tim thay phan tu trong khoi.\n";
    return -1; 
}

// 4. Tìm kiếm theo bảng băm (Hash Search)
int timKiemBangHam(unordered_map<int, int>& hashTable, int target) {
    cout << "\n===== Chi tiet tim kiem bang bam =====\n";
    cout << "Tim phan tu " << target << " trong bang bam...\n";
    if (hashTable.find(target) != hashTable.end()) {
        cout << "=> Tim thay phan tu tai chi so [" << hashTable[target] << "]\n";
        return hashTable[target]; 
    }
    cout << "=> Khong tim thay phan tu trong bang bam.\n";
    return -1;  
}

int main() {
    int choice, n, target;
    int *arr = nullptr;  
    unordered_map<int, int> hashTable;  

    do {
        xoaManHinh(); 
        cout << "=================== MENU ====================\n";
        cout << "1. Nhap phan tu cho mang\n";
        cout << "2. Tim kiem tuan tu\n";
        cout << "3. Tim kiem nhi phan\n";
        cout << "4. Tim kiem theo bang bam\n";
        cout << "5. Tim kiem nhay\n";
        cout << "6. Thoat\n";
        cout << "============================================\n";
        cout << "Chon phuong thuc tim kiem (1-6): ";
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Nhap so luong phan tu mang: ";
                cin >> n;
                arr = new int[n];  
                cout << "Nhap cac phan tu mang:\n";
                for (int i = 0; i < n; i++) {
                    cout << "Nhap phan tu thu " << i + 1 << " : ";
                    cin >> arr[i];
                }
                sort(arr, arr + n);  // Đảm bảo mảng được sắp xếp
                // Cập nhật bảng băm
                hashTable.clear();
                for (int i = 0; i < n; i++) {
                    hashTable[arr[i]] = i;
                }
                break;
            }
            case 2: {
                if (arr == nullptr) {
                    cout << "Chua co mang. Vui long nhap mang truoc.\n";
                    break;
                }
                cout << "Nhap phan tu can tim: ";
                cin >> target;
                timKiemTuanTu(arr, n, target);
                break;
            }
            case 3: {
                if (arr == nullptr) {
                    cout << "Chua co mang. Vui long nhap mang truoc.\n";
                    break;
                }
                cout << "Nhap phan tu can tim: ";
                cin >> target;
                timKiemNhiPhan(arr, n, target);
                break;
            }
            case 4: {
                if (hashTable.empty()) {
                    cout << "Chua co mang. Vui long nhap mang truoc.\n";
                    break;
                }
                cout << "Nhap phan tu can tim: ";
                cin >> target;
                timKiemBangHam(hashTable, target);
                break;
            }
            case 5: {
                if (arr == nullptr) {
                    cout << "Chua co mang. Vui long nhap mang truoc.\n";
                    break;
                }
                cout << "Nhap phan tu can tim: ";
                cin >> target;
                timKiemNhay(arr, n, target);
                break;
            }
            case 6:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
        cout << "Nhan Enter de quay lai menu..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != 6);  

    if (arr != nullptr) {
        delete[] arr;
    }

    return 0;
}

