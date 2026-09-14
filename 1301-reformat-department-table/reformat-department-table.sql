# Write your MySQL query statement below
select
    id,
    sum(case when month = 'jan' then revenue end) as jan_revenue,
    sum(case when month = 'feb' then revenue end) as feb_revenue,
    sum(case when month = 'mar' then revenue end) as mar_revenue,
    sum(case when month = 'apr' then revenue end) as apr_revenue,
    sum(case when month = 'may' then revenue end) as may_revenue,
    sum(case when month = 'jun' then revenue end) as jun_revenue,
    sum(case when month = 'jul' then revenue end) as jul_revenue,
    sum(case when month = 'aug' then revenue end) as aug_revenue,
    sum(case when month = 'sep' then revenue end) as sep_revenue,
    sum(case when month = 'oct' then revenue end) as oct_revenue,
    sum(case when month = 'nov' then revenue end) as nov_revenue,
    sum(case when month = 'dec' then revenue end) as dec_revenue
from department
group by id;