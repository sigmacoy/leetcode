
-- Playground Link
-- https://www.w3schools.com/sql/trysql.asp?filename=trysql_editor


# String Functions
1. STRING_AGG
SELECT STRING_AGG(product_name, ',') AS output
FROM products;

Key Things to Know
Grouping: Usually, you use this with a GROUP_BY. For example, to see all products bought per user:

Postgres: STRING_AGG(product_name, ',' ORDER BY product_name)
MySQL: GROUP_CONCAT(product_name ORDER BY product_name)

2. COALESCE
If a user has no confirmation rows, AVG = NULL
COALESCE converts that to 0

COALESCE(SUM(amount) FILTER (WHERE state = 'approved'), 0) AS approved_total_amount
The Problem: If zero rows match the filter, SUM() returns NULL.
The Fix: COALESCE(SUM(...), 0) catches that NULL and turns it into a 0.

3. TO_CHAR
TO_CHAR(value, 'format')

Dates: TO_CHAR(now(), 'YYYY') → "2026"
Numbers: TO_CHAR(1234.5, '9,999.99') → "1,234.50" (Adds commas and decimals)
Months: TO_CHAR(now(), 'Month') → "March "