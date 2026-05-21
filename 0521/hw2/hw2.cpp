#include <iostream>
#include <fstream>   
#include <string>
#include <sstream>   
#include <vector>    
#include <algorithm> 
#include <cctype>    

using namespace std;

int main() {
    ifstream inFile("text 2.txt");
    ofstream outFile("output.txt");

    if (!inFile) {
        cout << "無法開啟 text.txt 檔案！\n";
        return 1;
    }

    string line;
    vector<int> numbers;

    while (getline(inFile, line)) {
        
        for (char &c : line) {
            if (!isdigit(c)) {
                c = ' '; 
            }
        }

        stringstream ss(line);
        int num;
        while (ss >> num) {
            numbers.push_back(num); 
        }
    }
    
    inFile.close(); 

    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i];
        outFile << numbers[i];
        
        if (i != numbers.size() - 1) {
            cout << " ";
            outFile << " ";
        }
    }
    
    cout << "\n";
    outFile << "\n";
    
    outFile.close(); 

    return 0;
}