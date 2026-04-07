|| - string concatenation operator.
    SELECT 'Hello' || ' ' || 'World';  -- Returns 'Hello World'

LOWER(name) → converts entire string to lowercase

LEFT(..., 1) → extracts first character

UPPER(...) → capitalizes that first character

SUBSTRING(LOWER(name) FROM 2) → extracts from 2nd char onward (lowercase)

EXTRACT(YEAR FROM o.order_date) = 2019 
= returns numeric
= SQL standard

DATE_PART('year', o.order_date) = 2019
= returns float8 (double precision)
= Not specific to PostgreSQL