#include "iostream"
using namespace std;
int stepen(int x, int p) {
    int x0 = x;
    for (int i = 1; i < p; i++) {
        x *= x0;
    }
    return x;
}
int main() {
    int x, p;
    cin >> x >> p;
    cout << stepen(x, p);
    return 0;
}