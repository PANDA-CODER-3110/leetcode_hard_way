# Write your MySQL query statement below
SELECT  DISTINCT author_id as id 
FROM  Views
Where author_id = viewer_id
Order by author_id ; 