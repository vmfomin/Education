/******* Домашнее задание к уроку 3:*******/

/* 1. Написать запрос для выбора студентов в порядке их регистрации на сервисе.*/

select * from Students
order by registration_date asc;

/* 2. Написать запрос для выбора 5 самых дорогих курсов, на которых более 4 
      студентов, и которые длятся более 10 часов.*/

 -- select * from courses
 -- where students_count > 4 and duration > 10
 -- order by price desc limit 5;
 
/* 3. Написать один (!) запрос, который выведет одновременно список из имен трёх 
   самых молодых студентов, имен трёх самых старых учителей и названий трёх 
   самых продолжительных курсов.*/
   
/*
(select name, age from students
order by age limit 3)
union all
(select name as teacher, age from teachers
order by age desc limit 3)
union all
(select name, duration from courses
order by duration desc limit 3);
*/

/******* Домашнее задание к уроку 4:*******/

/* 1. Написать запрос для выбора среднего возраста всех учителей с зарплатой более 10 000.*/

-- select avg(salary) as average_teachers_salary from teachers
-- where salary > 10000;

/* 2. Написать запрос для расчета суммы, сколько будет стоить купить все курсы по дизайну.*/

-- select sum(price) as sum_design from courses
-- where type = "DESIGN";

/* 3. Написать запрос для расчёта, сколько минут (!) длятся все курсы по программированию.*/

-- select sum(duration * 60) as duration_minutes_PROGRAMMING from courses
-- where type = "PROGRAMMING";

/*******Домашнее задание к уроку 6:*******/

/* 1. Напишите запрос, который выводит сумму, сколько часов должен в итоге проучиться 
   каждый студент (сумма длительности всех курсов на которые он подписан).
   В результате запрос возвращает две колонки: Имя Студента — Количество часов.*/

-- не писал inner, т.к. по умлочанию join идет как inner
/* select students.name, sum(courses.duration) as full_duration_courses from students 
join subscriptions on students.id = subscriptions.student_id
join courses on courses.id = subscriptions.course_id
group by students.name; */

/* 2. Напишите запрос, который посчитает для каждого учителя средний возраст его учеников.
      В результате запрос возвращает две колонки: Имя Учителя — Средний Возраст Учеников.*/

/* select teachers.name as name, avg(students.age) as average_students_age from teachers
join courses on courses.teacher_id = teachers.id
join students on students.id = courses.id
group by name; */

/* 3. Напишите запрос, который выводит среднюю зарплату учителей для каждого типа курса 
(Дизайн/Программирование/Маркетинг и т.д.).В результате запрос возвращает две колонки: 
Тип Курса — Средняя зарплата.*/

/* select type, avg(salary) as average_salary from teachers as t
join courses c on c.teacher_id = t.id
group by type; */