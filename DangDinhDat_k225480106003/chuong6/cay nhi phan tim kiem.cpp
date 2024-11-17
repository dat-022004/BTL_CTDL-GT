#include <iostream>
using namespace std;

void xoaManHinh() {
    #ifdef _WIN32  
        system("cls");
    #else  
        system("clear");
    #endif
}

// Cấu trúc cây nhị phân
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* themNode(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = themNode(root->left, val);
    } else {
        root->right = themNode(root->right, val);
    }
    return root;
}

// Tìm kiếm phần tử trong cây nhị phân tìm kiếm
Node* timKiem(Node* root, int val) {
    if (root == nullptr || root->data == val) {
        return root;
    }
    if (val < root->data) {
        return timKiem(root->left, val);
    } else {
        return timKiem(root->right, val);
    }
}


Node* timMin(Node* root) {
    while (root && root->left) {
        root = root->left; 
    }
    return root; 
}

// Xóa phần tử trong cây nhị phân tìm kiếm
Node* xoaNode(Node* root, int val) {
    if (root == nullptr) return root;
    if (val < root->data) {
        root->left = xoaNode(root->left, val);
    } else if (val > root->data) {
        root->right = xoaNode(root->right, val);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = timMin(root->right); 
            root->data = temp->data;           
            root->right = xoaNode(root->right, temp->data);  
        }
    }
    return root;
}

// Hàm hiển thị cây nhị phân
void hienThiCay(Node* root, int space = 0, int COUNT = 5) {
    if (root == nullptr) return;

    space += COUNT;

    hienThiCay(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";

    hienThiCay(root->left, space);
}

int main() {
    Node* root = nullptr;
    int choice, value, n;

    do {
        xoaManHinh();  
        cout << "\n===== MENU CAY NHI PHAN TINH KIEM =====";
        cout << "\n1. Nhap so luong phan tu trong cay";
        cout << "\n2. Them phan tu vao cay";
        cout << "\n3. Tim phan tu trong cay";
        cout << "\n4. Xoa phan tu trong cay";
        cout << "\n5. Thoat";
        cout << "\n=========================================";
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Nhap so luong phan tu can them vao cay: ";
                cin >> n;
                cout << "Nhap cac gia tri cho cay (theo thu tu bat ky): \n";
                for (int i = 0; i < n; i++) {
                    cout << "Nhap gia tri " << (i + 1) << ": ";
                    cin >> value;
                    root = themNode(root, value);  
                }
                cout << "Da them " << n << " phan tu vao cay.\n";
                break;
            }

            case 2: {
                cout << "Nhap gia tri can them: ";
                cin >> value;
                root = themNode(root, value);
                cout << "Da them phan tu " << value << " vao cay.\n";
                break;
            }

            case 3: {
                cout << "Nhap gia tri can tim: ";
                cin >> value;
                if (timKiem(root, value)) {
                    cout << "Phan tu " << value << " tim thay trong cay.\n";
                } else {
                    cout << "Phan tu " << value << " khong tim thay.\n";
                }
                break;
            }

            case 4: {
                cout << "Nhap gia tri can xoa: ";
                cin >> value;
                root = xoaNode(root, value);
                cout << "Da xoa phan tu " << value << " trong cay.\n";
                break;
            }

            case 5: {
                cout << "Thoat chuong trinh.\n";
                break;
            }

            default: {
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }
        }

        if (choice != 5) {
            cout << "\nCay nhi phan hien tai:\n";
            hienThiCay(root); 
            cout << endl;
        }

        if (choice != 5) {
            cout << "\nNhan Enter de tiep tuc...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 5);

    return 0;
}
