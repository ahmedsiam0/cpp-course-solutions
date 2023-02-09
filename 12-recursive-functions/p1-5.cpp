#include <iostream>

using namespace std;

double average(int arr[], int len) {
    if (len == 1)
        return arr[0];
    double r = average(arr, len - 1);
    r *= (len - 1);
    return (r + arr[len - 1]) / len;
}

int main() {
    int n;
    int arr[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int avg = average(arr, n);
    cout << avg << '\n';
}