# Write your MySQL query statement below
select employee_id
from employees e
where salary < 30000
and manager_id is not null
and not exists (
select 1
from employees m
where m.employee_id = e.manager_id
)
order by employee_id;