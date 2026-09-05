# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from employee e
join department d
on e.departmentId = d.id
where(e.departmentId, e.Salary) in (
    select departmentId, max(salary)
    from employee
    group by departmentId
);