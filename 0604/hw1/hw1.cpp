#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    while(true){
        string input;
        cout << "請輸入一行文字：";
        getline(cin, input);

        if(input[0] == '0')
            break;

        reverse(input.begin(), input.end());

        cout << "反轉後的文字： " << input << endl;
    }

    return 0;
}