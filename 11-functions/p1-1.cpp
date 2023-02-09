#include <iostream>

using namespace std;

int max(int a, int b, int c) {
    int max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    return max;
}

int max(int a, int b, int c, int d) {
    int mx = max(a, b, c);
    if (mx < d)
        mx = d;
    return mx;
}
int max(int a, int b, int c, int d, int e) {
    int mx = max(a, b, c, d);
    if (mx < e)
        mx = e;
    return mx;
}
int max(int a, int b, int c, int d, int e, int f) {
    int mx = max(a, b, c, d, e);
    if (mx < f)
        mx = f;
    return mx;
}
int main() {
    return 0;
}