# Write your MySQL query statement below

select name from Employee as e inner join (select managerId, count(managerId) as freq from Employee group by managerId) as s on s.managerId=e.Id where freq>=5;