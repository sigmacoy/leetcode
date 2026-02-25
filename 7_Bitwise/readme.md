XOR (^)

AND (&)

OR (|)

Left Shift (<<)

Right Shift (>>)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Common Bitwise Techniques:

## 1. Check even/odd
if (n & 1) // odd
else // even

## 2. Multiply/Divide by 2
n << 1;  // multiply by 2
n >> 1;  // divide by 2

## 3. Toggle nth bit
n ^= (1 << k);
    Binary:   1 0 0 1
    Position: 3 2 1 0   
                    ^ k=0

## 4. Set nth bit ~> Force to 1
n |= (1 << k);

## 5. Clear nth bit -> Force to 0
n &= ~(1 << k);

## 6. Check if power of two
(n > 0) && ((n & (n - 1)) == 0);

## 7. Count set bits (Brian Kernighan's method)
### Set bits = bits that are 1.
int count = 0;
while (n) {
    count++;
    n &= (n - 1);
}
    OR do use __builtin_popcount
    int n = 19; // binary 10011
    cout << __builtin_popcount(n); // output: 3 (three 1's)

## 8. Get lowest set bit = rightmost 1 position.
n & -n;
10011
     ^ this one (position 0)

## 9. Remove leading zeros:
string s = "0001";
size_t pos = s.find_first_not_of('0');

if (pos == string::npos) {
    s = "0";
} else {
    s = s.substr(pos);
}
### size_t is an unsigned integer type, not an iterator.
### It's used for sizes and indices. find_first_not_of() returns an index position (like array index), which is size_t.

