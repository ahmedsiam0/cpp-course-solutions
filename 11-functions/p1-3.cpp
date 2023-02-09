#include <iostream>

using namespace std;

void read(double &x, double &y) {
    cout << "Input two numbers: ";
    cin >> x >> y;
}
void add() {
    double x, y;
    read(x, y);
    cout << "Result: " << (x + y) << endl;
}
void subtract() {
    double x, y;
    read(x, y);
    cout << "Result: " << (x - y) << endl;
}
void mult() {
    double x, y;
    read(x, y);
    cout << "Result: " << (x * y) << endl;
}
void divide() {
    double x, y;
    read(x, y);
    if (y == 0) {
        cout << "Can't divide by zero!\n";
        return;
    }
    cout << "Result: " << (x / y) << endl;
}
void display() {
    bool out = 1;
    int in;
    double x, y;
    while (out) {
        cout << "\nChoose: \n"
             << "1) add\n"
             << "2) subtract\n"
             << "3) multiply\n"
             << "4) divide\n"
             << "5) exit\n";
        cin >> in;
        switch (in) {
            case 1:
            add();
            break;
            case 2:
            subtract();
            break;
            case 3:
            mult();
            break;
            case 4:
            divide();
            break;
            case 5:
            out = 0;
            break;
            default:
            cout << "Wrong input!\n";
        }
    }
}
int main() {
    display();
}