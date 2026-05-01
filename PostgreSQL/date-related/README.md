# postgresql date-related

# 1. Date Arithmetic 
```sql
-- Find yesterday's date
SELECT CURRENT_DATE - INTERVAL '1 day';

-- Find records from exactly 7 days ago
WHERE order_date = CURRENT_DATE - INTERVAL '7 days';

-- Find next day's records
WHERE w1.recordDate = w2.recordDate + INTERVAL '1 day';

-- Add 2 months to a date
SELECT order_date + INTERVAL '2 months' FROM orders;

-- Subtract 3 years
SELECT hire_date - INTERVAL '3 years' FROM employees;
```

2. EXTRACT() - Get date parts as numbers
```sql
-- Get year as number (similar to LOWER() for strings)
EXTRACT(YEAR FROM order_date) = 2019

-- Get month number (1-12)
EXTRACT(MONTH FROM order_date) = 12

-- Get day of month (1-31)
EXTRACT(DAY FROM order_date) = 25

-- Get day of week (0=Sunday to 6=Saturday)
EXTRACT(DOW FROM order_date) = 1  -- Monday

-- Get quarter (1-4)
EXTRACT(QUARTER FROM order_date) = 2

-- Get hour from timestamp
EXTRACT(HOUR FROM order_timestamp) = 14
```

3. DATE_PART() - Similar but returns float
```sql
-- Returns float8 (double precision) instead of numeric
DATE_PART('year', order_date) = 2019.0
DATE_PART('month', order_date) = 6.0
DATE_PART('day', order_date) = 15.0
DATE_PART('dow', order_date) = 3.0  -- Day of week as float
DATE_PART('quarter', order_date) = 2.0

-- Can be used in calculations
SELECT DATE_PART('year', AGE(CURRENT_DATE, birth_date)) AS age_years;
```

4. DATE_TRUNC() - Truncate to specific precision
```sql
-- Like LEFT(string, n) but for dates
DATE_TRUNC('month', order_date)  -- First day of month at 00:00:00
DATE_TRUNC('year', order_date)   -- First day of year
DATE_TRUNC('quarter', order_date) -- First day of quarter
DATE_TRUNC('week', order_date)   -- Monday of that week
DATE_TRUNC('day', order_date)    -- Start of day (00:00:00)
DATE_TRUNC('hour', timestamp)    -- Start of hour

-- Example: Group by month
SELECT DATE_TRUNC('month', order_date) AS month, SUM(amount)
FROM orders GROUP BY month;
```

5. Age calculation
```sql
-- Calculate age between dates (similar to string length)
AGE('2024-12-25', '2024-12-20')  -- Returns '5 days'
AGE('2025-01-10', '2024-12-25')  -- Returns '16 days'
AGE(TIMESTAMP '2025-01-10', TIMESTAMP '2024-12-25') -- '16 days'

-- Calculate full age from birth date
AGE(CURRENT_DATE, birth_date)  -- Returns '32 years 4 months 5 days'

-- Get just the day count
EXTRACT(DAY FROM AGE('2024-12-25', '2024-12-20'))  -- Returns 5

-- Get total days difference (simple subtraction)
SELECT ('2024-12-25'::DATE - '2024-12-20'::DATE);  -- Returns 5
```

6. Date formatting (TO_CHAR) - Like UPPER() for dates
```sql
-- Convert date to specific string format
TO_CHAR(order_date, 'YYYY-MM-DD')  -- '2024-12-25'
TO_CHAR(order_date, 'Month DD, YYYY')  -- 'December 25, 2024'
TO_CHAR(order_date, 'Day')  -- 'Wednesday'
TO_CHAR(order_date, 'Dy')   -- 'Wed'
TO_CHAR(order_date, 'MM/DD/YYYY')  -- '12/25/2024'
TO_CHAR(order_date, 'DDth "of" Month')  -- '25th of December'

-- Format timestamp
TO_CHAR(order_timestamp, 'HH24:MI:SS')  -- '14:30:00'
TO_CHAR(order_timestamp, 'YYYY-MM-DD HH24:MI')  -- '2024-12-25 14:30'
```

7. Comparison with your string analogs
```sql
-- String to date mapping
SELECT 
    -- LIKE LOWER(name) converts string to lowercase
    EXTRACT(YEAR FROM date) AS string_to_number_analog,
    
    -- LIKE LEFT(name, 1) gets first character
    EXTRACT(DAY FROM date) AS get_first_part_analog,
    
    -- LIKE UPPER(name) transforms format
    DATE_TRUNC('month', date) AS transform_format_analog,
    
    -- LIKE SUBSTRING(name FROM 2) removes first char
    date + INTERVAL '1 day' AS remove_first_part_analog,
    
    -- LIKE 'Hello' || ' World' concatenates strings
    (date2 - date1) || ' days' AS concatenate_analog,
    
    -- LIKE POSITION('sub' IN name) finds position
    EXTRACT(DOW FROM date) AS position_analog
FROM sample_table;
```







8. Practical example combining multiple date ops
```sql
-- 1. Find orders placed on first day of any month in 2019
SELECT * FROM orders
WHERE EXTRACT(YEAR FROM order_date) = 2019
  AND DATE_TRUNC('month', order_date) = order_date;

-- 2. Birthdays in next 30 days (SIMPLEST working version)
SELECT name, birth_date
FROM users
WHERE birth_date + (EXTRACT(YEAR FROM AGE(CURRENT_DATE, birth_date)) || ' years')::INTERVAL
    BETWEEN CURRENT_DATE AND CURRENT_DATE + INTERVAL '30 days';

-- 3. Find orders from last complete quarter
SELECT * FROM orders
WHERE DATE_TRUNC('quarter', order_date) = DATE_TRUNC('quarter', CURRENT_DATE - INTERVAL '3 months');

-- 4. Calculate age in years only
SELECT 
    name,
    EXTRACT(YEAR FROM AGE(CURRENT_DATE, birth_date)) AS age_years
FROM users;

-- 5. Format date and calculate days since order
SELECT order_id,
       TO_CHAR(order_date, 'Month DD, YYYY') AS formatted_date,
       CURRENT_DATE - order_date AS days_ago
FROM orders
WHERE order_date > CURRENT_DATE - INTERVAL '30 days';
```