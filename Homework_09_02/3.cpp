#include "iostream"
using namespace std;
int main() {
    int x, p, a;
    cin >> x;
    p = 1;
    a = 2;
    while (a < x) {
        a *= 2;
        p++;
    }
    cout << p;
    return 0;
}