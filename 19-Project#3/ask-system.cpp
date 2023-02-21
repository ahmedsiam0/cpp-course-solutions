#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

struct user {
    int id;
    string password;
    string name;
    string email;
    bool allow_anonymous;
    vector<int> questions_to_me_ids;
    vector<int> questions_from_me_ids;
};

struct question {
    int id;
    string text;
    string from;
    string to;
    string answer;
    bool anonymous;
    int parent_question_id {-1};
    vector<int> child_questions_ids;
};

map<string, user> users;
map<int, question> questions;

string current_user {};
int last_user_id = 0;
int last_question_id = 0;

void save_users_data() {

        fstream users_file("users");
        if (users_file.fail()) {
            cout << "ERROR: users file not found!\n";
            exit(1);
        }
        users_file << last_user_id << "\n";

        users_file << users.size() << "\n";
        for (auto i : users) {
            users_file << i.first << " ";
            users_file << i.second.id << " ";
            users_file << i.second.password << " ";
            users_file << i.second.name << " ";
            users_file << i.second.email << " ";
            users_file << i.second.allow_anonymous << "\n";

            users_file << i.second.questions_to_me_ids.size() << "\n";
            for (auto j : i.second.questions_to_me_ids) {
                users_file << j << " ";
            }
            users_file << "\n";

            users_file << i.second.questions_from_me_ids.size() << "\n";
            for (auto j : i.second.questions_from_me_ids) {
                users_file << j << " ";
            }
            users_file << "\n";
        }
        users_file.close();
}
void save_questions_data() {
        fstream questions_file("questions");

        if (questions_file.fail()) {
            cout << "ERROR: questions file not found!\n";
            exit(1);
        }

        questions_file << last_question_id << "\n";
        questions_file << questions.size() << "\n";
        for (auto i : questions) {
            questions_file << i.second.id << " "
                           << i.second.anonymous << " "
                           << i.second.from << " "
                           << i.second.to << " "
                           << i.second.parent_question_id << " "
                           << i.second.child_questions_ids.size() << "\n"
                           << i.second.text << "\n"
                           << i.second.answer << "\n";
            for (auto j : i.second.child_questions_ids) {
                questions_file << j << " ";
            }
            questions_file << "\n";
        }

        questions_file.close();

}
void save_all_data() {
    save_users_data();
    save_questions_data();
}
void read_users_data() {
        users.clear();
        fstream users_file("users");
        if (users_file.fail()) {
            cout << "ERROR: users file not found!\n";
            exit(1);
        }

        int users_size, questions_to_me_ids_size, questions_from_me_ids_size;
        int input;
        users_file >> last_user_id;
        users_file >> users_size;

        string user_name;

        for (int i = 0; i < users_size; i++) {
            user usr;
            users_file >> user_name
                       >> usr.id
                       >> usr.password
                       >> usr.name
                       >> usr.email
                       >> usr.allow_anonymous;
            
            users_file >> questions_to_me_ids_size;
            for (int j = 0; j < questions_to_me_ids_size; j++) {
                users_file >> input;
                usr.questions_to_me_ids.push_back(input);
            }

            users_file >> questions_from_me_ids_size;
            for (int j = 0; j < questions_from_me_ids_size; j++) {
                users_file >> input;
                usr.questions_from_me_ids.push_back(input);
            }
            
            users[user_name] = usr;
        }
        users_file.close();
}

void read_questions_data() {
    questions.clear();
    fstream questions_file("questions");
    if (questions_file.fail()) {
        cout << "ERROR: questions file not found!\n";
        exit(1);
    }

    int questions_size, child_questions_ids_size;
    string txt, ans;
    int input;

    questions_file >> last_question_id;
    questions_file >> questions_size;

    for (int i = 0; i < questions_size; i++) {
        question q;
        questions_file >> q.id
                       >> q.anonymous;
        questions_file >> q.from;
        questions_file >> q.to
                       >> q.parent_question_id
                       >> child_questions_ids_size;
        getline(questions_file, q.text);
        getline(questions_file, q.text);
        getline(questions_file, q.answer);
        for (int j = 0; j < child_questions_ids_size; j++) {
            questions_file >> input;
            q.child_questions_ids.push_back(input);
        }
        questions[q.id] = q;
    }

    questions_file.close();
}

void read_all_data() {
    read_users_data();
    read_questions_data();
}
struct ask_system {
    void print_login_menu() {
        cout << "\nLogin menu:\n"
             << "\t1: Login\n"
             << "\t2: Signup\n"
             << "\t3: Exit\n";
    }

    void print_tasks_menu() {
        cout << "\nTasks menu:\n"
             << "\t1: Print Questions To Me\n"
             << "\t2: Print Questions From Me\n"
             << "\t3: Answer Question\n"
             << "\t4: Delete Question\n"
             << "\t5: Ask Question\n"
             << "\t6: List System Users\n"
             << "\t7: Feed\n"
             << "\t8: Logout\n";
    }
    
    void print_questions_to_me() {
        for(auto i : users[current_user].questions_to_me_ids) {
            if (questions[i].parent_question_id != -1) {
                cout << "\tThread: ";
            }
            cout << "Question Id ("
                 << questions[i].id
                 << ") ";

            if (!questions[i].anonymous) {
                cout << "from user "
                     << questions[i].from;
            }

            cout << "\t Question: "
                 << questions[i].text
                 << "\t Answer: "
                 << questions[i].answer
                 << "\n\n";
        }
    }
    void print_questions_from_me() {
        for(auto i : users[current_user].questions_from_me_ids) {
            if (questions[i].parent_question_id != -1) {
                cout << "\tThread: ";
            }
            cout << "Question Id ("
                << questions[i].id
                << ") to user "
                << questions[i].to;
            if (!questions[i].anonymous) {
                cout << " !AQ ";
            }

            cout << "\t Question: "
                << questions[i].text
                << "\t Answer: "
                << questions[i].answer
                << "\n\n";
        }
    }
    void answer_question() {
        int id;
        string answer;
        cout << "Enter Question id or -1 to cancel: ";
        cin >> id;

        if (id == -1) {
            return;
        }

        if (!questions.count(id)) {
            cout << "Question doesn't exist!\n";
            return;
        }
        if (questions[id].to != current_user) {
            cout << "You are not allowed to answer this question!\n";
            return;
        }
        cout << "Question Id ("
             << id
             << ") ";
        if (!questions[id].anonymous) {
            cout << "from user id("
                 << questions[id].from;
        }
        cout << "\t Question: "
             << questions[id].text
             << "\n";
        if (questions[id].answer != "") {
            cout << "Answer: "
                 << questions[id].answer
                 << "\n\n"
                 << "Warning: Already answered. Answer will be updated\n";
        }
        cout << "Enter answer: ";
        getline(cin, answer);
        getline(cin, answer);
        questions[id].answer  = answer;
        save_all_data();
    }
    void delete_question(int id) {
        int parent_id = questions[id].parent_question_id; // TODO erase existence of the question and its child questions
        string from = questions[id].from;
        string to = questions[id].to;

        if (parent_id != -1) {
            auto index = find(questions[parent_id].child_questions_ids.begin(), questions[parent_id].child_questions_ids.end(), id);
            questions[parent_id].child_questions_ids.erase(index);
        }
        
        auto index_from = find(users[from].questions_from_me_ids.begin(), users[from].questions_from_me_ids.end(), id);
        users[from].questions_from_me_ids.erase(index_from);

        auto index_to = find(users[to].questions_to_me_ids.begin(), users[to].questions_to_me_ids.end(), id);
        users[to].questions_to_me_ids.erase(index_to);

        while (questions[id].child_questions_ids.size() != 0) {
            delete_question(questions[id].child_questions_ids[0]);
        }
        questions.erase(questions.find(id));
    }
    void delete_question_interface() {
        int id;
        cout << "Enter Question id or -1 to cancel: ";
        cin >> id;

        if (id == -1) {
            return;
        }

        if (!questions.count(id)) {
            cout << "Question doesn't exist!\n";
            return;
        }

        if (questions[id].from != current_user && questions[id].to != current_user) {
            cout << "You are not allowed to delete this question!\n";
            return;
        }
        delete_question(id);
        save_all_data();
    }
    void ask_question() {
        question ques;
        ques.from = current_user;
        string to_user;
        
        cout << "Enter user name or -1 to cancel: ";
        cin >> to_user;

        if (to_user == "-1") {
            return;
        }
        if (!users.count(to_user)) {
            cout << "ERROR: invalid user name!";
            return;
        }
        ques.to = to_user;
        if (users[to_user].allow_anonymous) {
            cout << "Do you need it to be anonymous? (0 or 1): ";
            cin >> ques.anonymous;
        } else {
            cout << "Note: Anonymous questions are not allowed for this user\n";
        }
        cout << "For thread question: Enter Question id or -1 for new question: ";
        cin >> ques.parent_question_id;

        if (ques.parent_question_id != -1) {
            if (questions[ques.parent_question_id].parent_question_id != -1) {
                cout << "ERROR: This question is part of a question thread!";
                return;
            }
        }

        cout << "Enter question text: ";
        getline(cin, ques.text);
        getline(cin, ques.text);

        ques.id = last_question_id;
        last_question_id++;
        questions[ques.id] = ques;
        users[current_user].questions_from_me_ids.push_back(ques.id);
        users[to_user].questions_to_me_ids.push_back(ques.id);

        if (ques.parent_question_id != -1) {
            questions[ques.parent_question_id].child_questions_ids.push_back(ques.id);
        }
        save_all_data();
    }
    void list_system_users() {
        for (auto i : users) {
            cout << "Username: "
                 << i.first
                 << "\tname: "
                 << i.second.name
                 << "\tid: "
                 << i.second.id
                 << "\n";
        }
    }
    void feed() {
        for (auto i : questions) {
            if (i.second.answer != "") {
            if (i.second.parent_question_id != -1) {
                cout << "\tThread: ";
            }
            cout << "Question Id ("
                 << i.second.id
                 << ") ";
            
            if (!i.second.anonymous) {
                cout << "from user "
                     << i.second.from
                     << " ";
            }
            cout << "to user "
                 << i.second.to;


            cout << "\t Question: "
                 << i.second.text
                 << "\t Answer: "
                 << i.second.answer
                 << "\n\n";
            }
        }
    }
    void start_tasks() {
        int choice;

        print_tasks_menu();

        while (true) {
            read_all_data();
            cout << "Enter number in range 1 - 8: ";
            cin >> choice;

            switch (choice) {
            case 1:
                print_questions_to_me();
                break;
            case 2:
                print_questions_from_me();
                break;
            case 3:
                answer_question();
                break;
            case 4:
                delete_question_interface();
                break;
            case 5:
                ask_question();
                break;
            case 6:
                list_system_users();
                break;
            case 7:
                feed();
                break;
            case 8:
                return;
                break;
            
            default:
                cout << "ERROR: invalid number...Try again\n";
                break;
            }
            cout << endl;
        }
    }
    void login() {
        string usr_name, pass;

        cout << "Enter user name & password: ";
        cin >> usr_name >> pass;
        cout << endl;

        if (!users.count(usr_name)) {
            cout << "This user name doesn't exist!\n";
            return;
        }
        if (users[usr_name].password != pass) {
            cout << "Wrong password!\n";
            return;
        }

        current_user = usr_name;

        start_tasks();
    }
    void sign_up() {
        string usr_name;
        user usr;

        cout << "Enter user name (No spaces): ";
        cin >> usr_name;
        cout << "Enter password: ";
        cin >> usr.password;
        cout << "Enter name: ";
        cin >> usr.name;
        cout << "Enter email: ";
        cin >> usr.email;
        cout << "Allow anonymous questions?: (0 or 1) ";
        cin >> usr.allow_anonymous;
        cout << endl;

        usr.id = last_user_id;
        last_user_id++;

        users[usr_name] = usr;

        current_user = usr_name;

        save_all_data();
        start_tasks();
    }
    void start_login() {
        int choice;
        cout << "Welcome in the Ask System\n";
        
        while (true) {
            read_all_data();
            print_login_menu();
            
            cout << "Enter number in range 1 - 3: ";
            cin >> choice;

            switch (choice) {
            case 1:
                login();
                break;
            case 2:
                sign_up();
                break;
            case 3:
                return;
                break;
            
            default:
                cout << "Wrong choice!\n";
                break;
            }
        }
        cout << endl;
    }
};

int main() {
    ask_system().start_login();
}