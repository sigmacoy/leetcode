-- Write your PostgreSQL query statement below
-- SELECT t.id,
--     CASE
--         WHEN t.p_id IS NULL THEN 'Root'
--         WHEN (
--             SELECT COUNT(*)
--             FROM Tree c
--             WHERE c.p_id = t.id
--         ) = 0 THEN 'Leaf'
--         ELSE 'Inner'
--     END AS type

-- FROM Tree t;
-- O(n^2)

SELECT id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN ( -- 3
            SELECT p_id
            FROM Tree
            WHERE p_id IS NOT NULL 
        ) THEN 'Inner'
        ELSE 'Leaf' -- 3 is not in p_id mao LEAF sha
    END AS type

FROM Tree;
-- O(n) since 20 testcases ra