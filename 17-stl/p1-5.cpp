#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    string name, prefix;

    map<string, set<string>> mp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name;
        string temp = name;
        while(!temp.empty()) {
            mp[temp].insert(name);
            temp.pop_back();
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> prefix;
        for (auto j : mp[prefix]) {
            cout << j << ' ';
        }
        cout << endl;
    }
}