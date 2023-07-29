# Write your MySQL query statement below
select product_name,year,price 
from Sales left join Product 
On Sales.product_id = Product.product_id