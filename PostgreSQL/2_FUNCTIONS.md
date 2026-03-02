
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