When using GROUP BY, every column in the SELECT that is not inside an aggregate function (like COUNT, MAX) must appear in the GROUP BY.

-- Write your PostgreSQL query statement below
WITH total_users AS (
    SELECT COUNT(*) AS total
    FROM Users
)

SELECT
    r.contest_id,
    ROUND (
        COUNT(
            DISTINCT r.user_id
        ) * 100.0 / tu.total, 2
    ) AS percentage
FROM Register r
CROSS JOIN total_users tu

GROUP BY r.contest_id, tu.total
ORDER BY percentage DESC, r.contest_id

-- ----------------------------------------------------

r.contest_id → not aggregated → needs GROUP BY
tu.total → not aggregated → needs GROUP BY

aggregated ?
    - gathering multiple rows of data and "squashing" them into a single result.

If a column is in your SELECT but not inside an aggregate function (like SUM or COUNT), it must be in the GROUP BY.

-- ----------------------------------------------------