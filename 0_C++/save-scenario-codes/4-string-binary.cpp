#include <bits/stdc++.h>

int main(){
    // INT to BINARY STRING
    int number = 8;
    string binary = bitset<32>(number).to_string();
    string word = "00143";

    
    // WITHOUT LEADING ZEROES
    int first = binary.find_first_of("1");
    if(first == string::npos) cout << "0" << endl;
    else cout << binary.substr(first) << endl;


    
    // WITHOUT LEADING ZEROES but not Binary
    auto idx = word.find_first_not_of('0');
    if (idx != string::npos) {
        word = word.substr(idx);
    } else word = "0";

    
    

    // BINARY STRING TO INT
    string ans = "1001";
    int ansVal = stoi(ans, nullptr, 2);

    return 0;
}
