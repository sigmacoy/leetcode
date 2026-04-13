## Return if first letter of employee does not start 'M'

```
SELECT
    employee_id
FROM Employees
WHERE name NOT LIKE 'M%'
```

```
M% is a pattern used with LIKE in SQL.

M → the text must start with the letter M
% → wildcard meaning “any number of characters after this”
```



## BUT

Employees table:
+-------------+---------+--------+
| employee_id | name    | salary |
+-------------+---------+--------+
| 2           | Meir    | 3000   |
| 3           | Michael | 3800   |
| 7           | Addilyn | 7400   |
| 8           | Juan    | 6100   |
| 9           | Kannon  | 7700   |
+-------------+---------+--------+
Output: 
+-------------+-------+
| employee_id | bonus |
+-------------+-------+
| 2           | 0     |
| 3           | 0     |
| 7           | 7400  |
| 8           | 0     |
| 9           | 7700  |
+-------------+-------+


SELECT
    employee_id,
    CASE 
        WHEN employee_id % 2 = 1
            AND name NOT LIKE 'M%'
            THEN salary
            ELSE 0
    END AS bonus
FROM Employees
ORDER BY employee_id