#include "iostream"
using namespace std;
int main() {
    int * a = new int[5];
    int * b = new int[5];
    int * c = new int[10];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    for (int i = 0; i < 5; i++) {
        b[i] = i + 6;
    }
    for (int i = 0; i < 5; i++) {
        c[i] = a[i];
        c[i + 5] = b[i];
    }
    delete[] a;
    delete[] b;
    for (int i = 0; i < 10; i ++) {
        cout << c[i] << ' ';
    }
    return 0;
}