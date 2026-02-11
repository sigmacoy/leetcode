## It does not support the IF() function. You must use CASE.
## Strict to ANSI SQL standards.

PostgreSQL does not have an ELSE IF keyword.
You just use another WHEN.

SQL
CASE
    WHEN condition_1 THEN result_1
    WHEN condition_2 THEN result_2  -- Acts as ELSE IF
    ELSE result_3
END



