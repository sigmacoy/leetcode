// at()	        Returns an indexed character from a string
// size()	    Alias of length(). Returns the length of a string => Same as length()
// max_size()	Returns the maximum length of a string
// empty()	    Checks wheter a string is empty or not
// substr()	    Returns a part of a string from a start index (position) and length
// find()	    Returns the index (position) of the first occurrence of a string or character
// rfind()	    Returns the index (position) of the last occurrence of a string or character
// replace()	Replaces a part of a string with another string
// insert()	    Inserts a string at a specified index (position)
// compare()	Compares two strings

// s.substr(pos, len): Get substring.
    // string str = "Hello, World!";
    
    // string sub1 = str.substr(7);      // "World!" (from index 7 to end)
    // string sub2 = str.substr(0, 5);   // "Hello" (from index 0, 5 chars)
    // sub1 => World!
    // sub2 => Hello

// s.find(substr);
// if(s.find(susbtr) != string::npos);

// s.append(x), s.push_back(c), s.pop_back(): Modify string.

// s.erase(pos, len): Remove part of the string. Removes characters from a string
    // if (!str.empty()) str.erase(0, 1); // Erase 1 character starting at index 0

// s.reverse(s.begin(), s.end()): Reverse string.

// to_string(number) ==> VERY IMPORTANT!!!

// stoi - string to int ==> USE THIS MACOY 
// atoi - argument to int ==> SAFE
// stoll - string to long long

// stringstream
// sscanf 
// strtol 

// string str = "world";
// string newStr = "Hello " + str; // "Hello world"

// string str = "world";
// str.insert(0, 1, 'H'); // Hworld

// string(n, 'L'): Creates a string of length n, consisting of the character 'L'.

// tolower(string)
// toupper(string)

// CHECK if exist in a vector
    // if( find(words.begin(), words.end(), temp2) != words.end() )

// CHECK if substring
    // if(temp2.find(temp1) != string::npos)
    // .find( {the string to search for}, {the starting position to begin searching from} )

// str.insert(idx, {Another String});

// CHECK if prefix str2 is in str1
    // if (str1.rfind(str2, 0) == 0)    if prefix, mo return ni true
                // 0123456
    // string s = "teestee";
    // string s2 = "ee";
    // int index = s.rfind(s2);  // returns 5 (last occurrence)