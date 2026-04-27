USE school
SELECT
    S.xh as 学号, S.xm as 姓名, C.kh as 课程号, C.km as 课程名, E.zpcj as 总评成绩
FROM S
LEFT JOIN E ON S.xh = E.xh
LEFT JOIN C ON E.kh = C.kh
ORDER BY S.xh, C.kh
