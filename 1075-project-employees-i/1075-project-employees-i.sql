# Write your MySQL query statement below

SELECT p.project_id, ROUND(AVG(e.experience_years), 2) as average_years
FROM Project as p
LEFT JOIN Employee as e
ON p.employee_id = e.employee_id
GROUP BY p.project_id;