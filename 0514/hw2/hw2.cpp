#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main(){
    ifstream inFile("text.txt");
    ofstream outFile("answer.txt");

    if (!inFile) {
        cerr << "Unable to open file text.txt";
        return 1; 
    }

    map<string, int> wordCount;
    string word;

    while(inFile >> word) {
        string cleanedWord;
        for(char c : word) {
            if(isalpha(c)) {
                cleanedWord += c;
            }
        }
        if(!cleanedWord.empty()) {
            ++wordCount[cleanedWord];
        }
    }

    for(const auto& pair : wordCount){
        cout << pair.first << " 有" << pair.second << "個" << endl;
        outFile << pair.first << " 有" << pair.second << "個" << endl;
    }

    inFile.close();
    outFile.close();
    return 0;
}