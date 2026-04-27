USE school
SELECT S.xh as 学号, S.xm as 姓名
FROM S
WHERE NOT EXISTS (
    SELECT * FROM C
    WHERE NOT EXISTS (
        SELECT * FROM E
        WHERE E.xh = S.xh AND E.kh = C.kh
    )
)