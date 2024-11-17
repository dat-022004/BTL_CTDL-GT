#include <iostream>
#include <cstdlib> 
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, size;
    int capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Hang doi day! Khong the them phan tu " << value << endl;
            return;
        }

        if (front == -1) {
            front = 0; 
        }

        rear = (rear + 1) % capacity; 
        arr[rear] = value;
        size++;
        cout << "Them phan tu " << value << " vao hang doi." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Hang doi rong! Khong the xoa." << endl;
            return -1;
        }

        int dequeuedValue = arr[front];
        front = (front + 1) % capacity;  
        size--;
        cout << "Xoa phan tu " << dequeuedValue << " khoi hang doi." << endl;
        return dequeuedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return;
        }

        cout << "Cac phan tu trong hang doi: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }

    void clearQueue() {
        front = rear = -1;
        size = 0;
        cout << "Hang doi da duoc xoa." << endl;
    }

    void displayReverse() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return;
        }

        cout << "Cac phan tu trong hang doi (tu cuoi toi dau): ";
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    void insertAtPosition(int value, int position) {
        if (position < 0 || position >= capacity || size == capacity) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        if (position == 0) {
            enqueue(value); 
            return;
        }

        int *newArr = new int[capacity];
        int newSize = 0;

        for (int i = 0; i < position; i++) {
            newArr[i] = arr[(front + i) % capacity];
            newSize++;
        }

        newArr[position] = value;  
        for (int i = position; i < size; i++) {
            newArr[i + 1] = arr[(front + i) % capacity];
            newSize++;
        }
        delete[] arr;
        arr = newArr;
        size++;
        front = 0;
        rear = size - 1;

        cout << "Them phan tu " << value << " vao vi tri " << position << " trong hang doi." << endl;
    }
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    int capacity = 5;
    Queue q(capacity);
    int choice, value, position;

    do {
        clearScreen();
        cout << "\n================= MENU ==================\n";
        cout << "1. Nhap phan tu vao hang doi\n";
        cout << "2. Xoa phan tu khoi hang doi\n";
        cout << "3. Xem phan tu dau hang doi\n";
        cout << "4. Tinh kich thuoc hang doi\n";
        cout << "5. Xoa tat ca phan tu trong hang doi\n";
        cout << "6. Hien thi hang doi tu cuoi toi dau\n";
        cout << "7. Them phan tu vao vi tri bat ky\n";
        cout << "8. Thoat\n";
        cout << "=========================================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Nhap so luong phan tu can them: ";
                int n;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Nhap phan tu thu " << i + 1 << ": ";
                    cin >> value;
                    q.enqueue(value);
                    q.display();  
                }
                break;  
            }

            case 2: {
                q.dequeue();
                q.display();  
                break;
            }

            case 3: {
                cout << "Phan tu dau hang doi: " << q.peek() << endl;
                break;
            }

            case 4: {
                cout << "Kich thuoc hang doi hien tai: " << q.getSize() << endl;
                break;
            }

            case 5: {
                q.clearQueue();
                q.display();  
                break;
            }

            case 6: {
                q.displayReverse();
                break;
            }

            case 7: {
                cout << "Nhap phan tu can them: ";
                cin >> value;
                cout << "Nhap vi tri can them: ";
                cin >> position;
                q.insertAtPosition(value, position);
                q.display(); 
                break;
            }

            case 8: {
                cout << "Thoat chuong trinh." << endl;
                break;
            }

            default: {
                cout << "Lua chon khong hop le, vui long chon lai!" << endl;
                break;
            }
        }
        cout << "Nhan Enter de quay lai menu..." << endl;
        cin.ignore();
        cin.get();

    } while (choice != 8);

    return 0;
}
