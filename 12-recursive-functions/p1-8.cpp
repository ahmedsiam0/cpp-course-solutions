#include <iostream>

using namespace std;

void left_max(int arr[], int len) {
    if (len != 2) {
        left_max(arr, len - 1);
    }
    if (arr[len - 2] > arr[len - 1])
        arr[len - 1] = arr[len - 2];
}

int main() {
    int n;
    int arr[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    left_max(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}