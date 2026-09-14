# Write your MySQL query statement below
with reaction_counts as (
    select
        user_id,
        reaction,
        count(*) as reaction_count
    from reactions
    group by user_id, reaction
),
user_stats as (
    select
        user_id,
        count(distinct content_id) as content_count,
        count(*) as total_reactions
    from reactions
    group by user_id
)
select
    r.user_id,
    r.reaction as dominant_reaction,
    round(r.reaction_count / u.total_reactions, 2) as reaction_ratio
from reaction_counts r
join user_stats u
    on r.user_id = u.user_id
where u.content_count >= 5
  and r.reaction_count / u.total_reactions >= 0.60
order by reaction_ratio desc, r.user_id asc;