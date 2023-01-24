#include <iostream>

using namespace std;

int main() {
    int cnt = 0;
    
    for (int i = 50; i <= 300; i++)
        for (int j = (i < 70)? 70:(i + 1); j <= 400; j++)
            if (i < j && (i + j) % 7 == 0)
                cnt++;
    cout << cnt << '\n';
    return 0;
}