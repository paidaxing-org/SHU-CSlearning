USE school
SELECT S.xh as 学号, S.xm as 姓名
FROM S
WHERE NOT EXISTS (
    SELECT * FROM E as E1
    WHERE E1.xh = '1106'
      AND NOT EXISTS (
          SELECT * FROM E as E2
          WHERE E2.xh = S.xh
            AND E2.kh = E1.kh
      )
)
