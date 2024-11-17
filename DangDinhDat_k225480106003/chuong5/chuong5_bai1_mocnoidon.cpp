#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void themPhanTu(int giaTri) {
        Node* newNode = new Node();
        newNode->data = giaTri;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void xoaPhanTu(int giaTri) {
        if (head == nullptr) {
            cout << "Danh sach rong! Khong the xoa." << endl;
            return;
        }

        if (head->data == giaTri) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Phan tu " << giaTri << " da duoc xoa." << endl;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != giaTri) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Khong tim thay phan tu " << giaTri << " de xoa." << endl;
            return;
        }

        previous->next = current->next;
        delete current;
        cout << "Phan tu " << giaTri << " da duoc xoa." << endl;
    }

    void timKiem(int giaTri) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == giaTri) {
                cout << "Phan tu " << giaTri << " duoc tim thay trong danh sach." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Khong tim thay phan tu " << giaTri << " trong danh sach." << endl;
    }

    void inDanhSach() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Danh sach rong." << endl;
            return;
        }
        cout << "Danh sach: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> "; 
            temp = temp->next;
        }
        cout << endl;
    }

    void daoNguocDanhSach() {
        if (head == nullptr || head->next == nullptr) {
            return; 
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
        cout << "Danh sach da duoc dao nguoc." << endl;
    }

    int tinhTong() {
        int tong = 0;
        Node* temp = head;
        while (temp != nullptr) {
            tong += temp->data;
            temp = temp->next;
        }
        return tong;
    }

    void xoaPhanTuCuoi() {
        if (head == nullptr) {
            cout << "Danh sach rong. Khong the xoa." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Phan tu cuoi da duoc xoa." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Phan tu cuoi da duoc xoa." << endl;
    }

    void hopNhatDanhSach(LinkedList& otherList) {
        if (otherList.head == nullptr) {
            cout << "Danh sach thu hai rong." << endl;
            return;
        }

        if (head == nullptr) {
            head = otherList.head;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = otherList.head;
        }
        otherList.head = nullptr; 
        cout << "Danh sach da duoc hop nhat." << endl;
    }

    ~LinkedList() {
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
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

int main() {
    int n;
    LinkedList danhSach;
    LinkedList danhSachKhac;
    int luaChon, giaTri;

    do {
        xoaManHinh();  
        cout << "\n=============================" << endl;
        cout << "      MENU CHUONG TRINH      " << endl;
        cout << "=============================" << endl;
        cout << "1. Nhap danh sach" << endl;
        cout << "2. Them phan tu" << endl;
        cout << "3. Xoa phan tu" << endl;
        cout << "4. Tim phan tu" << endl;
        cout << "5. Dao nguoc danh sach" << endl;
        cout << "6. Tinh tong cac phan tu" << endl;
        cout << "7. Hop nhat hai danh sach" << endl;
        cout << "8. Xoa phan tu cuoi" << endl;
        cout << "0. Thoat" << endl;
        cout << "=============================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                cout << "Nhap so luong phan tu trong danh sach: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Nhap phan tu " << (i + 1) << ": ";
                    cin >> giaTri;
                    danhSach.themPhanTu(giaTri);
                }
                danhSach.inDanhSach();
                break;
            }

            case 2: {
                cout << "Nhap phan tu can them: ";
                cin >> giaTri;
                danhSach.themPhanTu(giaTri);
                danhSach.inDanhSach();
                break;
            }

            case 3: {
                cout << "Nhap phan tu can xoa: ";
                cin >> giaTri;
                danhSach.xoaPhanTu(giaTri);
                danhSach.inDanhSach();
                break;
            }

            case 4: {
                cout << "Nhap phan tu can tim: ";
                cin >> giaTri;
                danhSach.timKiem(giaTri);
                break;
            }

            case 5: {
                danhSach.daoNguocDanhSach();
                danhSach.inDanhSach();
                break;
            }

            case 6: {
                cout << "Tong cac phan tu trong danh sach: " << danhSach.tinhTong() << endl;
                break;
            }

            case 7: {
                cout << "Nhap danh sach thu hai: " << endl;
                cout << "Nhap so luong phan tu trong danh sach: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Nhap phan tu " << (i + 1) << ": ";
                    cin >> giaTri;
                    danhSachKhac.themPhanTu(giaTri);
                }
                danhSach.hopNhatDanhSach(danhSachKhac);
                danhSach.inDanhSach();
                break;
            }

            case 8: {
                danhSach.xoaPhanTuCuoi();
                danhSach.inDanhSach();
                break;
            }

            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;

            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
         cout << "Nhan Enter de quay lai menu..." << endl;
        cin.ignore();
        cin.get();

    } while (luaChon != 0);

    return 0;
}
