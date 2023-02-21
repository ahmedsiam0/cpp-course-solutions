#include <iostream>

using namespace std;

void accumulate_arr(int arr[], int len) {
    if (len != 2) {
        accumulate_arr(arr, len - 1);
    }

    arr[len - 1] += arr[len - 2];
}

int main() {
    int n;
    int arr[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    accumulate_arr(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}