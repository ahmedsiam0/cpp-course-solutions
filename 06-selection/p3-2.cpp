#include <iostream>
#include<climits>

using namespace std;

int main() {
    int x, s1, e1, s2, e2, s3, e3;
    bool e = false;

    cin >> s1 >> e1
        >> s2 >> e2;

    if (s1 >= s2 && s1 <= e2) {
        e = true;
        s3 = s1;
        if (e1 > e2)
            e3 = e2;
        else
            e3 = e1;
    } else if (s2 >= s1 && s2 <= e1) {
        e = true;
        s3 = s2;
        if (e1 > e2)
            e3 = e2;
        else
            e3 = e1;
    }
    if (e)
        cout << s3 << ' ' << e3 << '\n';
    else
        cout << -1 << '\n';
    return 0;
}