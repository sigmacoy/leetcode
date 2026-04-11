#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string s = "i love you so much";
    stringstream ss(s);
    string x;
    while (ss >> x) { // string word space word space
        cout << x << " "; // i love you so much
    }
    
    return 0;
}

// User Input ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // string temp = "";
    // cout << "Enter expression: ";
    // getline(cin, temp);
    // stringstream ss(temp);
    // string token;
    
    // while(ss >> token){
    //      some code...
    // }

// custom delimiter ~~~~~~~~~~~~~~~~~~~~
vector<string> split(string s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;
    
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            result.push_back(item);
        }
    }
    return result;
}