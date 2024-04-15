# Write your MySQL query statement below

SELECT st.student_id, st.student_name ,su.subject_name , count(Ex.subject_name) as attended_exams
From Students st inner Join Subjects su Left Join Examinations Ex 
on st.student_id = Ex.student_id and su.subject_name = Ex.subject_name
group by st.student_id, st.student_name, su.subject_name
order by student_id

#very nice question