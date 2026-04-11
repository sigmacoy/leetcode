// TOPIC: std::pair In C++

// SYNTAX:
// std::pair<T1, T2> obj;

// NOTES:
// 0. std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
// 1. map, multimap, unorder map, unorder multimap can use pair to insert data into their structures.
    // vector,

#include <iostream>
#include <vector>
using namespace std;

void print(pair<int, int>& obj) { 
    cout << obj.first << " " << obj.second << endl; 
}

int main()
{
  pair<int, int> obj(10, 20);
  print(obj);

  pair<int, int> obj2 = make_pair(10, 20);
  print(obj);

  vector<pair<string, uint>> list;
  list.push_back(make_pair("Rupesh", 30));
  list.push_back(make_pair("Hitesh", 28));
  list.push_back(make_pair(string("Bhupendra"), 22));
  list.push_back(make_pair("Sagar", 18));
  for(auto& elm: list) {
    cout << elm.first << " " << elm.second << endl;
  }

  return 0;
}

// 