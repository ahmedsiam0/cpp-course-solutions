#include <iostream>

using namespace std;

const int spec_num = 21;
const int mx_per_spec = 5;

string p_name[spec_num][mx_per_spec];
bool p_status[spec_num][mx_per_spec];
int last[spec_num] = {0};

void menu() {
    cout << "\nEnter your choice:\n"
         << "1) Add new patient\n"
         << "2) Print all patients\n"
         << "3) Get next patient\n"
         << "4) Exit\n";
}

void add_patient() {
    int spec;
    string name;
    bool status;

    cout << "Enter specialization, name, status: ";
    cin >> spec >> name >> status;
    if (last[spec] >= mx_per_spec) {
        cout << "Sorry we can't add more patients for this specialization\n";
        return;
    }

    if (status == 1) {
        for (int i = mx_per_spec - 2; i >= 0; i--) {
            p_name[spec][i + 1] = p_name[spec][i];
            p_status[spec][i + 1] = p_status[spec][i];
        }
        p_name[spec][0] = name;
        p_status[spec][0] = status;
        last[spec]++;
        return;
    }

    p_name[spec][last[spec]] = name;
    p_status[spec][last[spec]] = status;
    last[spec]++;
}
void print_patients() {
    cout << "*******************************\n";
    for (int i = 1; i < spec_num; i++) {
        if (last[i] == 0)
            continue;
        
        cout << "There are " << last[i]
             << " patients in specialization "
             << i << '\n';
        
        for (int j = 0; j < last[i]; j++) {
            cout << p_name[i][j] << ' ';
            if (p_status[i][j])
                cout << "urgent";
            else
                cout << "regular";
            cout << '\n';
        }
        cout << '\n';
    }
}
void get_next_patient() {
    int spec;
    cout << "Enter specialization: ";
    cin >> spec;

    if (last[spec] == 0) {
        cout << "No patients at the moment. Hava rest, Dr\n";
        return;
    }

    cout << p_name[spec][0] << " please go with Dr\n";

    for (int i = 1; i < last[spec]; i++) {
        p_name[spec][i - 1] = p_name[spec][i];
        p_status[spec][i - 1] = p_status[spec][i];
    }
    last[spec]--;
}

int main() {
    int choice;
    while (1) {
        menu();
        cin >> choice;
        switch (choice) {
            case 1:
            add_patient();
            break;
            case 2:
            print_patients();
            break;
            case 3:
            get_next_patient();
            break;
            case 4:
            return 0;
            default:
            cout << "Wrong Choice!";
        }
    }
}