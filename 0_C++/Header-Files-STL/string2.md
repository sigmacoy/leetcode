#include <string>

// Element Access
    // .at(size_type pos)
    // .operator[](size_type pos)
    // .front()
    // .back()
    // .data()
    // .c_str()

// Iterators
    // .begin()
    // .end()
    // .rbegin()
    // .rend()
    // .cbegin()
    // .cend()
    // .crbegin()
    // .crend()

// Capacity
    // .empty()
    // .length()
    // .max_size()
    // .capacity()
    // .reserve(size_type new_cap)
    // .shrink_to_fit()

// Modifiers
    // .clear()
    // .push_back(char c)
    // .append(const string& str)
    // .append(const string& str, size_type subpos, size_type sublen)
    // .append(const char* s)
    // .append(const char* s, size_type n)
    // .insert(size_type pos, const string& str)
    // .insert(size_type pos, const string& str, size_type subpos, size_type sublen)
    // .insert(size_type pos, const char* s)
    // .insert(size_type pos, const char* s, size_type n)
    // .insert(size_type pos, size_type n, char c)
    // .erase(size_type pos = 0, size_type len = npos)
    // .replace(size_type pos, size_type len, const string& str)
    // .replace(size_type pos, size_type len, const char* s)
    // .replace(size_type pos, size_type len, size_type n, char c)
    // .swap(string& str)
    // .resize(size_type n)
    // .resize(size_type n, char c)
    // .pop_back()

// String Operations / Searching
    // .c_str()
    // .find(const string& str, size_type pos = 0)
    // .find(const char* s, size_type pos = 0)
    // .find(const char* s, size_type pos, size_type n)
    // .find(char c, size_type pos = 0)
    // .rfind(const string& str, size_type pos = npos)
    // .rfind(const char* s, size_type pos = npos)
    // .rfind(const char* s, size_type pos, size_type n)
    // .rfind(char c, size_type pos = npos)

        // pos = the starting position to begin searching.
    // .find_first_of(const string& str, size_type pos = 0)
    // .find_first_of(const char* s, size_type pos = 0)
    // .find_first_of(const char* s, size_type pos, size_type n)
    // .find_first_of(char c, size_type pos = 0)

    // .find_last_of(const string& str, size_type pos = npos)
    // .find_last_of(const char* s, size_type pos = npos)
    // .find_last_of(const char* s, size_type pos, size_type n)
    // .find_last_of(char c, size_type pos = npos)
    // .find_first_not_of(const string& str, size_type pos = 0)
    // .find_first_not_of(const char* s, size_type pos = 0)
    // .find_first_not_of(const char* s, size_type pos, size_type n)
    // .find_first_not_of(char c, size_type pos = 0)
    // .find_last_not_of(const string& str, size_type pos = npos)
    // .find_last_not_of(const char* s, size_type pos = npos)
    // .find_last_not_of(const char* s, size_type pos, size_type n)
    // .find_last_not_of(char c, size_type pos = npos)

// Comparisons
    // .compare(const string& str) 
    // .compare(size_type pos, size_type len, const string& str)
    // .compare(size_type pos, size_type len, const string& str, size_type subpos, size_type sublen)
    // .compare(const char* s)
    // .compare(size_type pos, size_type len, const char* s)
    
// Substrings
    // .substr(size_type pos = 0, size_type len = npos)

// Character Operations
    // .c_str()
    // .data()
    // .get_allocator()

// Conversions / Misc
    // stoi, stol, stoll, stof, stod, stold (from C++11, not member but related)
    // to_string (from C++11)



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Access & Size ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// .size() / .length() → returns number of characters.
// .empty() → returns true if string has no characters.
// s[i] → access character at index i (0-based).
// .back() → last character.
// .front() → first character.

// Substring & Modification ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// .substr(pos, len) → substring starting at pos, length len (or till end if len omitted).
// .erase(pos, len) → erase len chars from index pos.
// .insert(pos, str) → insert str at index pos.
// .replace(pos, len, str) → replace len chars starting at pos with str.
// .clear() → makes string empty.
// .push_back(c) / .pop_back() → add/remove last character.
// + operator → concatenation (s1 + s2).
// .append(str) → add string to the end.

// Searching ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// .find(str, pos) → index of first occurrence of str starting at pos, or npos if not found.
// .rfind(str) → last occurrence.
// .find_first_of(chars) → first index containing any char from chars.
// .find_last_of(chars) → last index containing any char from chars.
// .find_first_not_of(chars) → first index NOT containing those chars.

// Comparison ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// .compare(str) → returns 0 if equal, <0 if less, >0 if greater (lexicographic).
// Relational operators (==, !=, <, >, <=, >=) → work directly with strings.

// Conversion ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// stoi(str) → string → int.
// stol(str), stoll(str) → string → long / long long.
// stof(str), stod(str) → string → float / double.
// to_string(num) → number → string.

// Other Tricks (Handy in CP) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// reverse(s.begin(), s.end()) → reverse string.
// sort(s.begin(), s.end()) → sort chars.
// count(s.begin(), s.end(), 'a') → count occurrences of a char.
// unique(s.begin(), s.end()) → remove consecutive duplicates.
// s.substr(i) in loop → common for substring problems.
// stringstream ss(s) → split by spaces easily.

// Tip for CP: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Use .substr() and .find() for parsing.
// Use stoi and to_string for conversions.
// Use STL algorithms (reverse, sort, count) with strings whenever possible.