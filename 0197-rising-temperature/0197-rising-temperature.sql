# Write your MySQL query statement below
select w2.id
from Weather w1 join Weather w2 
on w2.recordDate = w1.recordDate + interval 1 day
and w2.temperature > w1.temperature