

-- 1st query
SELECT 
    'Low Salary' AS category, -- 4
    COUNT(*) AS accounts_count -- 3
FROM Accounts -- 1
WHERE income < 20000 -- 2

UNION -- the last 

-- 2nd
SELECT 
    'Average Salary' AS category, 
    COUNT(*) AS accounts_count 
FROM Accounts 
WHERE income >= 20000 AND income <= 50000

UNION -- the last 

-- 3rd
SELECT 
    'High Salary' AS category, 
    COUNT(*) AS accounts_count 
FROM Accounts 
WHERE income > 50000 

/*
Input: 
Accounts table:
+------------+--------+
| account_id | income |
+------------+--------+
| 3          | 108939 |
| 2          | 12747  |
| 8          | 87709  |
| 6          | 91796  |
+------------+--------+
Output: 
+----------------+----------------+
| category       | accounts_count |
+----------------+----------------+
| Low Salary     | 1              |
| Average Salary | 0              |
| High Salary    | 3              |
+----------------+----------------+
Explanation: 
Low Salary: Account 2.
Average Salary: No accounts.
High Salary: Accounts 3, 6, and 8.
*/