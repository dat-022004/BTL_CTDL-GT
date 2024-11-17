#include <iostream>
using namespace std;

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

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

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
    int n, giaTri;

    cout << "Nhap so luong phan tu trong cay: ";
    cin >> n;

    cout << "Nhap cac gia tri cho cay (theo thu tu bat ky): " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri " << (i+1) << ": ";
        cin >> giaTri;
        root = themNode(root, giaTri);  
    }
    hienThiCay(root);
    cout << "\nDuyet truoc (Pre-order): ";
    preOrder(root);
    cout << endl;

    cout << "Duyet giua (In-order): ";
    inOrder(root);
    cout << endl;

    cout << "Duyet sau (Post-order): ";
    postOrder(root);
    cout << endl;

    return 0;
}
