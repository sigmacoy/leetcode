-- Write your PostgreSQL query statement below
SELECT
    s1.score,
    (SELECT 
        COUNT(DISTINCT s2.score)
    FROM Scores s2
    WHERE s2.score >= s1.score
    ) AS rank
FROM Scores s1
ORDER BY s1.score DESC;

-- the correlated subquery
-- Think of it like a nested for-loop
-- s1.score mag run as many times sa subquery

-- SELECT 
--    s1.score,   
--    COUNT(DISTINCT s2.score) + 1 AS "rank" 
-- FROM Scores s1 
-- LEFT JOIN Scores s2 ON s1.score < s2.score. 
-- GROUP BY s1.id, s1.score  
-- ORDER BY s1.score DESC;