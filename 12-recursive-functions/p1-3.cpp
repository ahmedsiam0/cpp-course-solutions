#include <iostream>

using namespace std;

int arr_max(int arr[], int len) {
    if (len == 1)
        return arr[0];
    
    int max = arr[len - 1];
    int max2 = arr_max(arr, len - 1);

    if (max > max2)
        return max;
    
    return max2;
    
}

int main() {
    int n;
    int arr[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = arr_max(arr, n);
    cout << max << '\n';
}