#include <iostream>

using namespace std;

string reverse_str(const string & str) {
    string out;
    for (int i = str.size() - 1; i >= 0; i--)
        out.push_back(str[i]);
    return out;
}

int main() {
    // cout << reverse_str("Hello") << '\n';
    return 0;
}