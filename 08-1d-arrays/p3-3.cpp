#include <iostream>

using namespace std;

int main() {
    int arr[200];
    int n, inc = 1, cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] <= arr[i]) {
            inc++;
        } else {
            cnt += inc;
            inc = 1;
        }
    }
    
    cout << cnt;
    cout << '\n';
    return 0;
}