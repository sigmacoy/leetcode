L <= R → searches entire range, 
    inclusive. 
    Loop exits when L > R. 
    Use when R = size-1.

L < R → narrower, 
    stops when L == R. 
    Use for "find first/last" variants. 
    May miss single element.

