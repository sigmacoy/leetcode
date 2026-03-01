-- Write your PostgreSQL query statement below
WITH ids as (
    SELECT
        requester_id AS id
    FROM RequestAccepted

    UNION ALL

    SELECT
        accepter_id AS id
    FROM RequestAccepted
)

SELECT
    id,
    COUNT(id) as num
FROM ids
GROUP BY id
ORDER BY num DESC
LIMIT 1

/*
The ids CTE or common table expression or the "inner" query;
     will produce this single-column list:

id
1 (from requester)
1 (from requester)
2 (from requester)
3 (from requester)
2 (from accepter)
3 (from accepter)
3 (from accepter)
4 (from accepter)

Final Result (After a GROUP BY id):

id
1: appears 2 times
2: appears 2 times
3: appears 3 times 
4: appears 1 time

order by id limit 1; return id 3 and num niya
*/