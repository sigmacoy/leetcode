-- Write your PostgreSQL query statement below
SELECT
    DISTINCT product_id,
    10 AS price
FROM Products
GROUP BY product_id
HAVING min(change_date) > '2019-08-16'

UNION

SELECT
    product_id,
    new_price AS price
FROM Products
WHERE (
    product_id,
    change_date
) IN (
    SELECT
        product_id,
        max(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)



/*
1 - 10
1 - 20 8-14
1 - 30 8-15
1 - 35 8-16

2 50
3 10

UNION - combines the results of two or more SELECT statements into a single result set.

UNION: Merges rows and deletes duplicates (slower).
UNION ALL: Merges rows and keeps duplicates (faster).
*/