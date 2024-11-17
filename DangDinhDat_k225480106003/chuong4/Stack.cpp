#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Ngan xep day!" << endl;
            return;
        }
        arr[++top] = value;
        cout << "Da them " << value << " vao ngan xep." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Ngan xep rong!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Ngan xep rong!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Ngan xep rong!" << endl;
            return;
        }
        cout << "Cac phan tu trong ngan xep: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void clearAll() {
        top = -1;
        cout << "Da xoa tat ca phan tu trong ngan xep!" << endl;
    }

    void clearScreen() {
        system("cls");
    }
};

int main() {
    int size;
    cout << "Nhap dung luong ngan xep: ";
    cin >> size;
    Stack sx(size);

    int choice, value;

    do {
        sx.clearScreen();

        cout << "\n================= MENU ==================\n";
        cout << "1. Nhap phan tu vao ngan xep\n";
        cout << "2. Them phan tu vao ngan xep\n";
        cout << "3. Lay phan tu khoi ngan xep\n";
        cout << "4. Xem phan tu o dinh\n";
        cout << "5. Hien thi ngan xep\n";
        cout << "6. Kiem tra ngan xep co rong hay khong\n";
        cout << "7. Kiem tra ngan xep co day hay khong\n";
        cout << "8. Xoa tat ca phan tu trong ngan xep\n";
        cout << "9. Thoat\n";
        cout << "\n=========================================\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap so luong phan tu ban muon them: ";
                int n;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Nhap phan tu thu " << i + 1 << ": ";
                    cin >> value;
                    sx.push(value);
                }
                break;
            case 2:
                cout << "Nhap phan tu muon them vao ngan xep: ";
                cin >> value;
                sx.push(value);
                break;
            case 3:
                cout << "Phan tu lay ra khoi ngan xep: " << sx.pop() << endl;
                break;
            case 4:
                cout << "Phan tu o dinh ngan xep: " << sx.peek() << endl;
                break;
            case 5:
                sx.display();
                break;
            case 6:
                if (sx.isEmpty()) {
                    cout << "Ngan xep rong!" << endl;
                } else {
                    cout << "Ngan xep khong rong!" << endl;
                }
                break;
            case 7:
                if (sx.isFull()) {
                    cout << "Ngan xep day!" << endl;
                } else {
                    cout << "Ngan xep chua day!" << endl;
                }
                break;
            case 8:
                sx.clearAll();
                break;
            case 9:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le! Vui long thu lai.\n";
        }

        cout << "Nhan Enter de quay lai menu..." << endl;
        cin.ignore();
        cin.get();

    } while (choice != 9);

    return 0;
}
