USE school
SELECT
    E.kh as 课程号, C.km as 课程名, E.xh as 学号, S.xm as 姓名, E.zpcj as 总评成绩
FROM E
JOIN S ON E.xh = S.xh
JOIN C ON E.kh = C.kh
WHERE E.zpcj IS NOT NULL
  AND E.zpcj = (
      SELECT MAX(E2.zpcj) FROM E as E2
      WHERE E2.kh = E.kh
  )
ORDER BY E.kh, E.xh
