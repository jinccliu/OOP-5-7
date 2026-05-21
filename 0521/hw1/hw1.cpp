#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    while(getline(cin, str)){
        if(str[0] == '0')
            break;
        int ct=0;
        for(int i=str.size()-1; i>=0; i--){
            if(str[i]!= ' '){
                ct++;
            }else{
                break;
            }
        }
        cout << "Number of characters in the last word: " << ct << endl;
    }
    return 0;
}