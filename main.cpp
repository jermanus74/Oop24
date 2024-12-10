#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct  User{
    string full_name;
    string id;
    string password;
    string verify_password;
    string status;
    void display(){
        cout<<"Username: "<<full_name<<endl<<"ID:"<<id<<endl<<"Status"<<status<<endl;
    }
};

const string UserProfile="userDb.txt";
vector <User> loadUser();
void signUp();
void login();
void EditUserDetails();
void ReadUserDetails();
void saveUser(const vector<User> &user);
vector <User> userList=loadUser();

int main()
{

    return 0;
};

void signUp(){
    User userAccount;
    cout<<"Enter username: "<<endl;
    getline(cin,userAccount.full_name);
    cout<<"Enter Id: "<<endl;
    getline(cin,userAccount.id);
//    a mechanism which checks if user id exist in db
    cout<<"Set account password: "<<endl;
    getline(cin,userAccount.password);
    cout<<"Confirm account password: "<<endl;
    getline(cin,userAccount.verify_password);
    if (userAccount.password!=userAccount.verify_password){
        cout<<"Password don't match... Re-enter your password to confirm."<<endl;

    }else{
        userList.push_back(userAccount);
        saveUser(userList);
    }
}