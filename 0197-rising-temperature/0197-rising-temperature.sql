# Write your MySQL query statement below
select t1.Id from Weather t1 , Weather t2 
where t1.temperature > t2.temperature 
and datediff(t1.recordDate , t2.recordDate) = 1  