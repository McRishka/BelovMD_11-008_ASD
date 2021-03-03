#include "iostream"
using namespace std;
void sort(int * a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (a[j] < a[i]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        cout << a[i] << ' ';
    }
}
int main() {
    int arr[6] = {5,2,8,3,6,1};
    sort(&arr[0], 6);
    return 0;
}