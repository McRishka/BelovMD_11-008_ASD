#include "iostream"
using namespace std;
int sum(int * a, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *a + i;
    }
    return sum;
}
int main() {
    int arr[4] = {1,2,3,4};
    cout << sum(&arr[0], 4);
    return 0;
}