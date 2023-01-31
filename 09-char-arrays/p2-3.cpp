#include <iostream>

using namespace std;

int main() {
    string s;
    int remain = 0, temp = 0;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        temp = s[s.size() - i - 1] - '0' + remain;
        if (i < 4)
            temp += 5;
        remain = temp / 10;
        temp = temp % 10;
        s[s.size() - i - 1] = '0' + temp;
    }

    if (remain > 0)
        cout << remain;
    cout << s << '\n';
}