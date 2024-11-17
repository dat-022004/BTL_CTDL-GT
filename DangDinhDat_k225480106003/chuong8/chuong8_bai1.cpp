#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Hàm xóa màn hình
void clearScreen() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear");  
#endif
}

// Hàm sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Hàm sắp xếp chọn (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Hàm sắp xếp chèn (Insertion Sort)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Hàm hợp nhất mảng (Merge)
void merge(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge(arr, left, mid);
    merge(arr, mid + 1, right);

    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int left, int right) {
    merge(arr, left, right);
}

// Hàm phân hoạch (Partition) cho Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 0, choice = 0;
    int* arr = nullptr;

    do {
        clearScreen(); 

       cout << "\n================= MENU ==================\n";
        cout << "\n1. Nhap cac phan tu trong mang";
        cout << "\n2. Sap xep Bubble Sort";
        cout << "\n3. Sap xep Selection Sort";
        cout << "\n4. Sap xep Insertion Sort";
        cout << "\n5. Sap xep Merge Sort";
        cout << "\n6. Sap xep Quick Sort";
        cout << "\n7. Thoat";
        cout << "\n=========================================\n";
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
				    cout << "Nhap so luong phan tu trong mang (phai lon hon 0): ";
				    cin >> n;				
				    while (n <= 0) {
				        cout << "So luong phan tu phai lon hon 0. Vui long nhap lai: ";
				        cin >> n;
				    }				
				    arr = new int[n]; 
				    cout << "Nhap cac phan tu trong mang: \n";
				    for (int i = 0; i < n; ++i) {
				        cout << "Nhap phan tu thu " << i + 1 << ": ";
				        cin >> arr[i];
				    }
				    cout << "\nMang da nhap: [ ";
				    for (int i = 0; i < n; ++i) {
				        cout << arr[i] << " ";
				    }
				    cout << "]\n";

  				  break;
				}

            case 2:
                if (arr != nullptr) {
                    bubbleSort(arr, n);
                    cout << "Mang sau khi duoc sap xep voi Bubble Sort: ";
                    printArray(arr, n);
                } else {
                    cout << "Vui long nhap mang truoc.\n";
                }
                break;
            case 3:
                if (arr != nullptr) {
                    selectionSort(arr, n);
                    cout << "Mang sau khi duoc sap xep voi Selection Sort: ";
                    printArray(arr, n);
                } else {
                    cout << "Vui long nhap mang truoc.\n";
                }
                break;
            case 4:
                if (arr != nullptr) {
                    insertionSort(arr, n);
                    cout << "Mang sau khi duoc sap xep voi Insertion Sort: ";
                    printArray(arr, n);
                } else {
                    cout << "Vui long nhap mang truoc.\n";
                }
                break;
            case 5:
                if (arr != nullptr) {
                    mergeSort(arr, 0, n - 1);
                    cout << "Mang sau khi duoc sap xep voi Merge Sort: ";
                    printArray(arr, n);
                } else {
                    cout << "Vui long nhap mang truoc.\n";
                }
                break;
            case 6:
                if (arr != nullptr) {
                    quickSort(arr, 0, n - 1);
                    cout << "Mang sau khi duoc sap xep voi Quick Sort: ";
                    printArray(arr, n);
                } else {
                    cout << "Vui long nhap mang truoc.\n";
                }
                break;
            case 7:
                cout << "Thoat chuong trinh.\n";
                delete[] arr;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
        cout << "\nNhan Enter de tiep tuc...";
        cin.ignore();
        cin.get();
    } while (choice != 7);

    return 0;
}
