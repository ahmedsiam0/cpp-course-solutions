#include <iostream>

using namespace std;

int main() {
    int choice;
    const unsigned int max = 100;
    unsigned int cmax = 0; // current max;
    string name[max];
    unsigned int age[max];
    unsigned int salary[max];
    char gender[max];
    int start, end;
    string sname; // search name
    int usalary; // updated salary

    while (1) {
        cout << "\nEnter your choice:\n"
             << "1) Add new employee\n"
             << "2) Print all employees\n"
             << "3) Delete by age\n"
             << "4) Update Salary by name\n"
             << "0) Exit\n";
        
        cin >> choice;
        if (choice == 0) {
            cout << "GoodBye!\n";
            return 0;
        } else if (choice == 1) {
            cout << "Enter name: ";
            cin >> name[cmax];
            cout << "Enter age: ";
            cin >> age[cmax];
            cout << "Enter salary: ";
            cin >> salary[cmax];
            cout << "Enter gender (M/F): ";
            cin >> gender[cmax];
            cmax++;
        } else if (choice == 2) {
            cout << "********************\n";
            for (int i = 0; i < cmax; i++) {
                if (name[i] == "")
                    continue;
                cout << name[i] << ' '
                     << age[i] << ' '
                     << salary[i] << ' '
                     << gender[i] << '\n';
            }
        } else if (choice == 3) {
            cout << "Enter start and end age: ";
            cin >> start >> end;
            for (int i = 0; i < cmax; i++) {
                if (age[i] >= start && age[i] <= end) {
                    name[i] = "";
                }
            }
        } else if (choice == 4) {
            cout << "Enter the name and salary: ";
            cin >> sname >> usalary;
            for (int i = 0; i < cmax; i++) {
                if (sname == name[i]) {
                    salary[i] = usalary;
                }
            }
        } else {
            cout << "Wrong Choice!\n";
        }
    }
}