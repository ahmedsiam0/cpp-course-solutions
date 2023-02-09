#include <iostream>

using namespace std;

void array_increment(int arr[], int len) {
    if (len == 1)
        return;
    
    arr[len - 1] += (len - 1);
    array_increment(arr, len - 1);
}

int main() {
    int n;
    int arr[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    array_increment(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}