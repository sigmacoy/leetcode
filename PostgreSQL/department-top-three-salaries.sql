-- HARD

-- Write your PostgreSQL query statement below
WITH new_table AS (
    SELECT
        d.name AS Department,
        e.name AS Employee,
        salary AS Salary,
        DENSE_RANK() OVER (
            PARTITION BY d.name  -- gi partition kay mao mana by department
            ORDER BY salary DESC
        ) AS ranking

    FROM Employee e
    LEFT JOIN Department d
        ON e.departmentId = d.id
)

SELECT 
    Department, 
    Employee, 
    Salary
FROM new_table
WHERE ranking <= 3


/*
Assigns a rank to each employee within their department (PARTITION BY d.name) 
based on salary descending.

DENSE_RANK means:
Ties get same rank
No gaps in ranking (1,2,2,3 not 1,2,2,4)

DENSE_RANK → Number each row in sorted order
PARTITION BY → Split into groups (by department)
*/