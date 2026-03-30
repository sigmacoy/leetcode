-- Write your PostgreSQL query statement below

SELECT TO_CHAR(trans_date, 'YYYY-MM') AS month,
        country,
        COUNT(*) AS trans_count, 

        -- "Count the number of rows where the state is 'approved'."
        COUNT(*) FILTER (WHERE state = 'approved') AS approved_count, 
        
        SUM(amount) AS trans_total_amount,

        -- "Sum up the amount for all approved transactions; 
        -- if there are none, show 0 instead of a blank (null) value."
        COALESCE(SUM(amount) FILTER (WHERE state = 'approved'), 0) AS approved_total_amount
FROM Transactions
GROUP BY "month", country;

/*


COUNT(state): Count all entries in the state field.


COALESCE(..., 0): If the sum is empty (NULL), replace it with 0.
COALESCE works for any data type (numbers, dates, strings).
    - returns the first non-null value in its list.

*/