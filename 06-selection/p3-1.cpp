#include <iostream>
#include<climits>

using namespace std;

int main() {
    int x, s1, e1, s2, e2, s3, e3, sum = 0;

    cin >> x
        >> s1 >> e1
        >> s2 >> e2
        >> s3 >> e3;

    sum += (x >= s1 && x <= e1);
    sum += (x >= s2 && x <= e2);
    sum += (x >= s3 && x <= e3);

    cout << sum << '\n';
    
    return 0;
}