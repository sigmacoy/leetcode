SELECT
    s.user_id,
    ROUND(AVG(
            CASE
                WHEN c.action = 'confirmed' THEN 1
                    ELSE 0
            END
        ), 2
    ) AS confirmation_rate

FROM Signups s
LEFT JOIN Confirmations c
    ON s.user_id = c.user_id
GROUP BY s.user_id



/*
SELECT
    s.user_id,
    COALESCE (
        ROUND(AVG(
                CASE
                    WHEN c.action = 'confirmed' THEN 1
                        ELSE 0
                END
            ), 2
        ), 0
    ) AS confirmation_rate

FROM Signups s
LEFT JOIN Confirmations c
    ON s.user_id = c.user_id
GROUP BY s.user_id

FOR Postgres USERS ✅
use to type casting : : numeric before you apply ROUND function.

PostgreSQL string comparison is case-sensitive.
Confirmed is not equal to confirmed

*/

