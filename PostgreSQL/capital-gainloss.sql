-- Write your PostgreSQL query statement below
SELECT
    stock_name,
    SUM( -- initial value is 0
        CASE
            WHEN operation = 'Sell' THEN price
            ELSE -price
        END
    ) AS capital_gain_loss
FROM Stocks

GROUP BY stock_name
ORDER BY stock_name;