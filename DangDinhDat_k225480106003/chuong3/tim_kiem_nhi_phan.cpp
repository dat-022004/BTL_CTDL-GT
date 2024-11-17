#include <iostream>
using namespace std;

int timKiemNhiPhan(int mang[], int trai, int phai, int giaTriCanTim) {
    if (trai > phai) return -1;
    int giua = trai + (phai - trai) / 2;

    if (mang[giua] == giaTriCanTim) return giua;
    else if (mang[giua] > giaTriCanTim)
        return timKiemNhiPhan(mang, trai, giua - 1, giaTriCanTim);
    else
        return timKiemNhiPhan(mang, giua + 1, phai, giaTriCanTim);
}

int main() {
    int mang[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(mang) / sizeof(mang[0]);
    int giaTriCanTim = 7;
    int ketQua = timKiemNhiPhan(mang, 0, n - 1, giaTriCanTim);

    if (ketQua != -1)
        cout << "Phan tu " << giaTriCanTim << " nam o chi so " << ketQua << endl;
    else
        cout << "Phan tu khong co trong mang" << endl;

    return 0;
}
