-- 1. СОЗДАНИЕ ТАБЛИЦ --
CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    group_number VARCHAR(10) NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name VARCHAR(100) NOT NULL
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id) ON DELETE CASCADE,
    subject_id INT REFERENCES subjects(subject_id) ON DELETE CASCADE,
    grade INT CHECK (grade >= 2 AND grade <= 5)
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id) ON DELETE CASCADE,
    date_attended DATE NOT NULL,
    status VARCHAR(20) NOT NULL
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id) ON DELETE CASCADE,
    note_text TEXT NOT NULL
);
-- 2. НАПОЛНЕНИЕ ДАННЫХ --
INSERT INTO students (full_name, group_number) VALUES
('Сухов Иван Иванович', 'ИУ1-11Б'),
('Петрова Анна Сергеевна', 'ИУ1-11Б '),
('Сидоров Алексей Владимирович', 'ИУ1-11Б '),
('Суанова Мария Дмитриевна', 'ИУ1-11Б '),
('Смирнов Дмитрий Алексеевич', 'ИУ1-11Б '),
('Волкова Екатерина Игоревна', 'ИУ1-11Б ');

INSERT INTO subjects (subject_name) VALUES
('Математический анализ'),
('Аналитическая геометрия'),
('Информатика');

INSERT INTO grades (student_id, subject_id, grade)
VALUES
-- Студент 1
(1, 1, 5), (1, 2, 4), (1, 3, 5),
-- Студент 2
(2, 1, 4), (2, 2, 3), (2, 3, 4),
-- Студент 3
(3, 1, 3), (3, 2, 5), (3, 3, 3),
-- Студент 4
(4, 1, 5), (4, 2, 5), (4, 3, 5),
-- Студент 5
(5, 1, 4), (5, 2, 4), (5, 3, 4),
-- Студент 6
(6, 1, 3), (6, 2, 4), (6, 3, 5);

INSERT INTO attendance (student_id, date_attended, status)
SELECT s.student_id, d.date_attended,
    CASE WHEN random() < 0.8 THEN 'present' ELSE 'absent' END
FROM students s
CROSS JOIN (VALUES 
    ('2024-12-01'::DATE), 
    ('2024-12-02'::DATE)
) AS d(date_attended);

INSERT INTO notes (student_id, note_text) VALUES
(1, 'Любит информатику'),
(2, 'Нужна помощь по информатике'),
(3, 'Редко посещает занятия по информатике'),
(4, 'Отличник по всем предметам'),
(5, 'Хорошо работает в команде'),
(6, 'Прогресс по информатике');
-- 3. ИНДЕКСЫ --
CREATE INDEX idx_students_group_number ON students(group_number);

CREATE INDEX idx_grades_student_id ON grades(student_id);

ALTER TABLE notes ADD COLUMN note_tsvector TSVECTOR;
UPDATE notes SET note_tsvector = to_tsvector('russian', note_text);
CREATE INDEX idx_notes_gin ON notes USING GIN(note_tsvector);
-- 4. ПРЕДСТАВЛЕНИЯ --
CREATE VIEW student_avg_grades AS
SELECT 
    s.student_id,
    s.full_name,
    s.group_number,
    ROUND(AVG(g.grade)::NUMERIC, 2) AS average_grade
FROM students s
LEFT JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name, s.group_number;
-- 5. ТРАНЗАКЦИИ --
BEGIN;
INSERT INTO students (full_name, group_number) 
VALUES ('Новиков Андрей Петрович', 'ИУ5-21')
RETURNING student_id;

DO $$
DECLARE
    new_student_id INT;
BEGIN
    SELECT student_id INTO new_student_id 
    FROM students 
    WHERE full_name = 'Новиков Андрей Петрович';
    
    INSERT INTO grades (student_id, subject_id, grade) VALUES
    (new_student_id, 1, 4), -- Математический анализ
    (new_student_id, 3, 5); -- Информатика
END $$;

COMMIT;
-- 6. ЗАПРОСЫ –
--1.
WITH target AS (
    SELECT student_id, group_number
    FROM students 
    WHERE student_id = 3 
)
SELECT s.*
FROM students s
WHERE s.group_number = (SELECT group_number FROM target)
  AND s.student_id != (SELECT student_id FROM target)
ORDER BY s.student_id
LIMIT 5;

-- 2. 
SELECT * FROM student_avg_grades WHERE student_id = 1;

-- 3. 
SELECT 
    s.subject_name,
    ROUND(AVG(g.grade)::NUMERIC, 2) AS average_grade
FROM grades g
JOIN subjects s ON g.subject_id = s.subject_id
WHERE s.subject_name = 'Информатика'
GROUP BY s.subject_name;

-- 4. 
SELECT 
    n.note_id,
    s.full_name,
    n.note_text
FROM notes n
JOIN students s ON n.student_id = s.student_id
WHERE n.note_tsvector @@ to_tsquery('russian', 'Информатика');

-- 5. 
BEGIN;
UPDATE attendance 
SET status = 'present'
WHERE student_id = 1 
  AND date_attended = '2024-12-01';
COMMIT;

