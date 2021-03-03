#include "iostream"
#include "math.h"
using namespace std;
int main() {
    int a, b, c, D;
    double  x1, x2, x;
    cin >> a >> b >> c;
    D = 0;
    x1 = 0;
    x2 = 0;
    x = 0;
    D = b * b - 4 * a * c;
    if (D > 0) {
        x1 = (-b - sqrt(D)) / (2 * a);
        x2 = (-b + sqrt(D)) / (2 * a);
        cout << x1 << x2;
    }
    else if (D == 0) {
        x = -b / (2 * a);
        cout << x;
    }
    else {
        cout << "корней нет";
    }
    return 0;
}