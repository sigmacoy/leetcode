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
WHERE ranking <= 1