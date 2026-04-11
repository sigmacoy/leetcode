// move() - avoid a deep copy of the vector.
//        - transfer ownership of the data within the vector from the local variable new_digits to the variable digits. Performance optimization.
// swap() 

#include <utility>
#include <iostream>
using namespace std;

pair<int, string> student = make_pair(1, "Alice");

#include <map>
int main() {
    map<int, string> students;

    // Insert using make_pair
    students.insert(make_pair(1, "Alice"));
    students.insert(make_pair(2, "Bob"));

    for (auto &p : students) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}