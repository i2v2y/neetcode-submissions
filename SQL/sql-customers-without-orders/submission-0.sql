-- Write your query below
SELECT name
FROM customers
    LEFT JOIN orders
        ON customers.id = customer_id
WHERE orders.id is NULL