
-- Playground Link
-- https://www.w3schools.com/sql/trysql.asp?filename=trysql_editor

# CLAUSES

SELECT – Choose column/s
FROM – Specify table

WHERE – Filter rows
    - for filtering results.
    - Filters rows BEFORE grouping.

GROUP BY – Group rows for aggregates
    - only one distinct ?

HAVING – Filter groups AFTER grouping.

ORDER BY – Sort results
    - ORDER BY salary DESC <-------------- ADD KEYWORD "DESC" para DECREASING SORT

LIMIT - Restrict number of rows
    - LIMIT 10

OFFSET - Skip rows
    - OFFSET 5

JOIN - Combine tables
    - (INNER, LEFT, RIGHT, FULL, CROSS)
    - JOIN departments ON employees.dept_id = departments.id
    
    - JOIN (short for Inner Join) only returns rows where there is a match in both tables.

    LEFT JOIN {table_name} ON
        - A LEFT JOIN returns all rows from the left table and the matching rows from the right table.
        - If there is no match, the result from the right side will be NULL.

UNION - Combine result sets
    - UNION / UNION ALL
    - SELECT a FROM t1 UNION SELECT b FROM t2

WITH - Common Table Expression (CTE)
    - WITH temp AS (SELECT * FROM users) SELECT * FROM temp;

WINDOW (for window functions)
    - Define window for functions
    - WINDOW w AS (PARTITION BY dept ORDER BY salary)

DISTINCT - Remove duplicates
    - SELECT DISTINCT city


ON (for JOIN conditions)
    - ON users.id = orders.user_id
    - for relationship matching

USING (for JOIN shorthand)
    - JOIN departments USING (dept_id)

FILTER – Conditional aggregate (PostgreSQL)
    - SUM(sales) FILTER (WHERE year = 2023)

CROSS JOIN – Every row with every row (Cartesian product)
    - SELECT * FROM a CROSS JOIN b

PARTITION BY – Divides rows into groups for window functions
    - ROW_NUMBER() OVER (PARTITION BY dept ORDER BY salary)

Aggregate – Functions that combine multiple rows (SUM, COUNT, AVG)
    - SUM(sales)

WITH – Common Table Expression (CTE)
    - WITH temp AS (SELECT * FROM users) SELECT * FROM temp

ROW – Single record in a table / Row constructor
    - ROW(1, 'John')

Table – Collection of rows and columns
    - CREATE TABLE employees (id INT, name TEXT)

# MORE
1. 
WHERE: Filters rows before grouping first. (before GROUP BY)
HAVING: Filters groups after grouping.

2. 