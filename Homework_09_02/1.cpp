#include <iostream>
using namespace std;
int main(){
    int n, i, sum, p;
    cin >> n;
    int arr[100];
    sum = 0;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (i = 1; i <= n; i++) {
        sum += arr[i];
    }
    cout << sum;
    return 0;
}
