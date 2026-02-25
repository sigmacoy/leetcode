-- Write your PostgreSQL query statement below
SELECT person_name
FROM (
    SELECT
        person_name,
        turn,
        SUM(weight) OVER (ORDER BY turn) AS prefix_sum
        FROM Queue
) temp
WHERE prefix_sum <= 1000
ORDER BY turn DESC 
LIMIT 1;
-- LIMIT 1 tells the database to return only the very first row of the final result set and discard everything else.