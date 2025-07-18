# Write your MySQL query statement below
SELECT LEFT(trans_date, 7) as month, 
country,COUNT(*) as trans_count,
SUM(IF(state = "approved", 1, 0)) as approved_count,
SUM(amount) as trans_total_amount, 
SUM(IF(state = "approved", amount, 0)) as approved_total_amount
FROM Transactions
GROUP BY month, country