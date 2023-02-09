#include <iostream>

using namespace std;
bool starts_with(const string &input, const string &pattern, int pos) {
    if (pattern.size() > (input.size() - pos))
        return false;
    for (int i = pos, j = 0; j < pattern.size(); i++, j++) {
        if (input[i] != pattern[j])
            return false;
    }

    return true;
}
string replace_str(const string &input, const string &pattern, const string &to) {
    string out = "";

    for (int i = 0; i < input.size(); i++) {
        if (starts_with(input, pattern, i)) {
            out += to;
            i += pattern.size() - 1;
        } else
            out.push_back(input[i]);
    }

    return out;
}

int main() {
    string input, pattern, to, output;

    cin >> input >> pattern >> to;

    output = replace_str(input, pattern, to);

    cout << output << endl;
    return 0;
}