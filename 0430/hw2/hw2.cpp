#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> Vincent;
    vector<string> Leo;
    vector<string> Invitee;
    string name;
    
    cout << "Vincent's friend:" << endl;
    while (cin >> name) {
        if (name == "0") break;
        Vincent.push_back(name);
    }
    
    cout << "Leo's friend:" << endl;
    while (cin >> name) {
        if (name == "0") break;
        Leo.push_back(name);
    }
    
    for (const string& friend_name : Vincent) {
        Invitee.push_back(friend_name);
    }
    
    for (const string& friend_name : Leo) {
        if (find(Invitee.begin(), Invitee.end(), friend_name) == Invitee.end()) {
            Invitee.push_back(friend_name);
        }
    }
    
    cout << "Invitee:" << endl;
    for (const string& friend_name : Invitee) {
        cout << friend_name << endl;
    }
    
    return 0;
}
