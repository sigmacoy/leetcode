

-- Write your PostgreSQL query statement below
SELECT customer_id
FROM Customer 
GROUP BY customer_id 
HAVING COUNT(DISTINCT Customer.product_key) = (SELECT COUNT(*) FROM Product)

/*
checks if a customer has bought all available products.
    left:
    Counts how many unique/different products this customer has purchased
    right:
    Counts the total number of rows (products) that exist in the Product table
    condition:
    must be equal
*/

-- SELECT
--     c.customer_id
-- FROM Customer c
-- GROUP BY c.customer_id
-- HAVING ARRAY_AGG(c.product_key) @>
--     ARRAY(SELECT product_key FROM Product)