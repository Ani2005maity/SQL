# Write your MySQL query statement below
select Department, Employee, Salary from
(select d.name as department, e.name as employee, e.salary as salary,
dense_rank() over(partition by d.name order by e.salary desc) as ranks
from employee e
left join department d
on e.departmentId = d.id) temp
where ranks <= 3;
