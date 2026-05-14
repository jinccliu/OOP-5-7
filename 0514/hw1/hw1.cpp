#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string tname;
    cin >> tname;

    ifstream inFile("basic.txt");
    ofstream outFile("output.txt");

    if (!inFile) {
        cerr << "Unable to open file basic.txt";
        return 1; 
    }

    string line;
    bool isfound = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        
        ss >> name;

        if(name == tname){
            cout << line << endl;
            outFile << line << endl;
            isfound = true;
            break;
        }
    }

    if (!isfound) {
        cerr << "Name not found." << endl;
    }
    
    inFile.close();
    outFile.close();
    return 0;
}