select max(num) as num 
From (select num from MyNumbers as num group by num having count(num) =1) as num;