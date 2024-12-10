#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct  userDb{
    string full_name;
    string id;
    string password;
    string verify_password;
    string status;
    void display()const{
        cout<<"Username: "<<full_name<<endl<<"ID:"<<id<<endl<<"Status"<<status<<endl;
    }
};

const string UserProfile="userDb.txt";
vector <userDb> loadUser();
void signUp();
void login();
void EditUserDetails();
void ReadUserDetails();
void saveUser(const vector<userDb> &user);
vector <userDb> userList=loadUser();
void home();

int main()
{

    return 0;
};
void home(){
    cout<<"Not yet implemented..."<<endl;
}
void signUp(){
    userDb Account;
    cout<<"Enter username: "<<endl;
    getline(cin,Account.full_name);
    cout<<"Enter Id: "<<endl;
    getline(cin,Account.id);
//    a mechanism which checks if user id exist in db
    cout<<"Set account password: "<<endl;
    getline(cin,Account.password);
    cout<<"Confirm account password: "<<endl;
    getline(cin,Account.verify_password);
    if (Account.password!=Account.verify_password){
        cout<<"Password don't match... Re-enter your password to confirm."<<endl;

    }else{
        userList.push_back(Account);
        saveUser(userList);
    }
}
void login(){
    userDb Account;
    string ID,password;
    cout<<"Enter your id: "<<endl;
    getline(cin,ID);
    for (const auto &user:userList) {
        if (ID==Account.id){
            cout<<"Enter your password: "<<endl;
            getline(cin,password);
            if (password==Account.password){
                cout<<"User successfully logged in... Redirecting to home page"<<endl;
                home();
            }
            else{
                cout<<"Invalid password... Try again"<<endl;
            }
        }
        else{
            cout<<"User ID not found... Check your ID and try again"<<endl;
        }
    }

}
vector <userDb> loadUser(){
    vector<userDb> users;
    ifstream file(userList);
    if (file.is_open()){
        userDb Account;
        while(getline(cin,Account.id)){
            getline(cin,Account.full_name);
            getline(cin,Account.password);
        }
        file.close();
    }
    return users;
}
void saveUser(const vector<userDb> &user){
    ofstream  file(userList,ios::trunc);
    if (file.is_open()){
        for (const auto &s:user) {
            file<<"Username: "<<s.full_name<<endl
            <<"ID: "<<s.id<<endl
            <<"Password: "<<s.password<<endl;
        }
    }
    else{
        cout<<"failed to open file..... Try again"<<endl;
    }
}
void ReadUserDetails(){
    if (userList.empty()){
        cout<<"No user found... Try to sign up"<<endl;
    }else{
        cout<<"----- User List -------"
        for (const auto &user: userList) {
            user.display();
        }
    }

}



