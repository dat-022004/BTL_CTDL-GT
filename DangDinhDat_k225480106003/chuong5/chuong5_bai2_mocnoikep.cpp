#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void nhapDanhSach() {
        int soLuong, giaTri;
        cout << "\nNhap so luong phan tu trong danh sach: ";
        cin >> soLuong;

        cout << "\nNhap cac phan tu:\n";
        for (int i = 0; i < soLuong; i++) {
            cout << "Gia tri " << (i + 1) << ": ";
            cin >> giaTri;
            themVaoCuoi(giaTri);
        }
        hienThi();
    }

    void themVaoCuoi(int giaTri) {
        Node* newNode = new Node{giaTri, nullptr, tail};
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void xoaDau() {
        if (head == nullptr) {
            cout << "\n=> Danh sach rong.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        hienThi();
    }

    void xoaCuoi() {
        if (tail == nullptr) {
            cout << "\n=> Danh sach rong.\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        hienThi();
    }

    void xoaGiaTri(int giaTri) {
        Node* current = head;
        while (current != nullptr && current->data != giaTri) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "\n=> Khong tim thay gia tri " << giaTri << " trong danh sach.\n";
            return;
        }
        if (current == head) {
            xoaDau();
        } else if (current == tail) {
            xoaCuoi();
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            cout << "\n=> Da xoa gia tri " << giaTri << " trong danh sach.\n";
            hienThi();
        }
    }

    void timKiem(int giaTri) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == giaTri) {
                cout << "\n=> Gia tri " << giaTri << " duoc tim thay o vi tri " << index << ".\n";
                return;
            }
            current = current->next;
            index++;
        }
        cout << "\n=> Gia tri " << giaTri << " khong co trong danh sach.\n";
    }

    void hienThi() {
        Node* current = head;
        cout << "\nDanh sach hien tai: ";
        if (current == nullptr) {
            cout << "Danh sach rong.";
        } else {
            while (current != nullptr) {
                cout << current->data << (current->next ? " -> " : "");
                current = current->next;
            }
        }
        cout << "\n";
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Hàm xóa màn hình
void xoaManHinh() {
    #ifdef _WIN32
        system("cls"); // Dành cho Windows
    #else
        system("clear"); // Dành cho Linux/Mac
    #endif
}

int main() {
    DoublyLinkedList list;
    int luaChon, giaTri;

    do {
        xoaManHinh();  // Xóa màn hình mỗi lần hiển thị lại menu
        cout << "\n===========================================";
        cout << "\n  MENU - DANH SACH LIEN KET KEP";
        cout << "\n===========================================";
        cout << "\n 1. Nhap danh sach";
        cout << "\n 2. Them phan tu vao cuoi danh sach";
        cout << "\n 3. Xoa phan tu o dau danh sach";
        cout << "\n 4. Xoa phan tu o cuoi danh sach";
        cout << "\n 5. Xoa phan tu theo gia tri";
        cout << "\n 6. Tim kiem phan tu";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n===========================================";
        cout << "\nNhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                list.nhapDanhSach();
                break;
            case 2:
                cout << "\nNhap gia tri can them vao cuoi: ";
                cin >> giaTri;
                list.themVaoCuoi(giaTri);
                list.hienThi();
                break;
            case 3:
                list.xoaDau();
                break;
            case 4:
                list.xoaCuoi();
                break;
            case 5:
                cout << "\nNhap gia tri can xoa: ";
                cin >> giaTri;
                list.xoaGiaTri(giaTri);
                break;
            case 6:
                cout << "\nNhap gia tri can tim: ";
                cin >> giaTri;
                list.timKiem(giaTri);
                break;
            case 0:
                cout << "\n=> Thoat chuong trinh.\n";
                break;
            default:
                cout << "\n=> Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
        cout << "\nNhan Enter de quay lai menu...";
        cin.ignore();
        cin.get();

    } while (luaChon != 0);

    return 0;
}
