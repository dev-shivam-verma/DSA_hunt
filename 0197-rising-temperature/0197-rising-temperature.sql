# Write your MySQL query statement below
SELECT a.id 
FROM Weather as a
JOIN Weather as b
ON a.temperature > b.temperature AND DATEDIFF(a.recordDate , b.recordDate) = 1;
