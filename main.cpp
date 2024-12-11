#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct userDb {
    string full_name;
    string id;
    string password;
    string status;

    void display() const {
        cout << "Username: " << full_name << endl
             << "ID: " << id << endl
             << "Status: " << status << endl;
    }
};

const string UserProfile = "userDb.txt";
//a storage container for user
vector<userDb> userList;

// Function Prototypes
vector<userDb> loadUser();
void signUp();
void login();
void EditUserDetails();
void ReadUserDetails();
void saveUser(const vector<userDb> &users);
void home();

int main() {
    userList = loadUser(); // Initialize user list from file

    int choice;
    do {
        cout << "\n--- User Management System ---" << endl;
        cout << "1. Login to continue" << endl;
        cout << "2. Log In" << endl;
        cout << "3. View All Users" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                home();
                break;
            case 2:
                login();
                break;
            case 3:
                ReadUserDetails();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

void home() {
    cout << "Welcome to the home page!"
            "\n Do you have an account(Yes or No)?" << endl;
    string choice{};
    getline(cin,choice);
    if (choice=="y" || choice=="Y"){
        cout<<"Enter your details below.\n"<<endl;
        login();
    }else{
        cout<<"Create new account:\n"<<endl;
        signUp();
    }
}

void signUp() {
    userDb Account;
    bool idExists;

    cout << "Enter username: ";
    getline(cin, Account.full_name);

    do {
        idExists = false;
        cout << "Enter ID: ";
        getline(cin, Account.id);

        // Check if ID already exists
        for (const auto &user : userList) {
            if (user.id == Account.id) {
                idExists = true;
                cout << "ID already exists. Please try again with a different ID." << endl;
                break;
            }
        }
    } while (idExists);

    cout << "Set account password: ";
    getline(cin, Account.password);

    string verify_password;
    do {
        cout << "Confirm account password: ";
        getline(cin, verify_password);

        if (Account.password != verify_password) {
            cout << "Passwords don't match. Please try again." << endl;
        }
    } while (Account.password != verify_password);
    cout<<"Enter your status(teacher/student)"<<endl;
    getline(cin,Account.status);
    userList.push_back(Account);
    saveUser(userList);
    cout << "Account created successfully!" << endl;
}
void studentPage() {
    cout << "Welcome to the Student Page! (Not yet implemented)" << endl;
}

void teacherPage() {
    cout << "Welcome to the Teacher Page! (Not yet implemented)" << endl;
}


void login() {
    string ID, password;
    bool loggedIn = false;

    do {
        cout << "Enter your ID: ";
        getline(cin, ID);

        bool userFound = false;
        for (const auto &user : userList) {
            if (user.id == ID) {
                userFound = true;

                cout << "Enter your password: ";
                getline(cin, password);

                if (user.password == password) {
                    cout << "Login successful! Redirecting to "<<" "<<user.status<<" "<<"page ...." << endl;
                    if (user.status=="student"){
                        studentPage();
                    }else if (user.status=="teacher"){
                        teacherPage();
                    }
                    loggedIn = true;
                } else {
                    cout << "Invalid password. Try again." << endl;
                }
                break;
            }
        }

        if (!userFound) {
            cout << "User ID not found. Please try again." << endl;
        }
    } while (!loggedIn);
}

vector<userDb> loadUser() {
    vector<userDb> users;
    ifstream file(UserProfile);

    if (file.is_open()) {
        userDb Account;
        while (getline(file, Account.full_name)) {
            getline(file, Account.id);
            getline(file, Account.password);
            getline(file, Account.status);
            users.push_back(Account);
        }
        file.close();
    } else {
        cout << "No existing user database found. Starting fresh." << endl;
    }

    return users;
}

void saveUser(const vector<userDb> &users) {
    ofstream file(UserProfile, ios::in);

    if (file.is_open()) {
        for (const auto &user : users) {
            file << user.full_name << endl
                 << user.id << endl
                 << user.password << endl
                 << user.status << endl;
        }
        file.close();
    } else {
        cout << "Failed to open file for saving. Please try again." << endl;
    }
}

void ReadUserDetails() {
    if (userList.empty()) {
        cout << "No users found. Please sign up to add users." << endl;
    } else {
        cout << "\n----- User List -----" << endl;
        for (const auto &user : userList) {
            user.display();
            cout << "-------------------" << endl;
        }
    }
}
