#include <iostream>

using namespace std;

int main() {
    int cnt = 0;
    
    for (int a = 1; a <= 200; a++) {
        for (int b = 1; b <= 200; b++) {
            for (int c = 1, d = 1; c <= 200 && d <= 200; c++, d++) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}