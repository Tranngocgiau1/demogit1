#include <iostream>
using namespace std;
// Ham de quy tinh tong binh phuong tu 1 -> n
int tongBinhPhuong(int n) {
    if (n == 1) {
        return 1;
    } else {
        //Goi de quy tinh tong binh phuong tu 1 den (n-1), sau do cong n^2 vao ket qua 
        return tongBinhPhuong(n - 1) + n * n;
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int result = tongBinhPhuong(n);
    cout << "Tong binh phuong tu 1 den " << n << " la: " << result << std::endl;

    return 0;
}

