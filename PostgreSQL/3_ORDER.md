# the Order of Execution

1. FROM - find source table/s

2. JOIN - Combine Data

3. WHERE - Filters the individual rows

4. GROUP BY - Groups rows into buckets

5. HAVING - Filters the groups

    5.5 WINDOW (OVER) - perform calculations across rows while keeping individual rows (unlike GROUP BY which collapses them).

6. SELECT - select columns & expressions
    6.1 Aggregate functions (COUNT, SUM, AVG) execute first
    6.2 Constants/expressions execute last
    
7. DISTINCT - Removes duplicate rows

8. ORDER BY - Sorts the final list or Sort result

9. OFFSET - skip rows

10. LIMIT / FETCH - takes the remaining number of rows requested OR take rows

More:
- JOIN is part of FROM (not a separate phase logically)
- Window functions do NOT replace GROUP BY and run before final SELECT output
- DISTINCT happens after SELECT, before ORDER BY
- OFFSET happens before LIMIT
