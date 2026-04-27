USE school
SELECT
    S.xh as 学号, S.xm as 姓名,
    ROUND(AVG(CAST(E.zpcj AS FLOAT)), 2) as 平均总评成绩
FROM S
JOIN E ON S.xh = E.xh
WHERE E.zpcj IS NOT NULL
  AND DATEDIFF(YEAR, S.csrq, GETDATE()) < (
      SELECT AVG(CAST(DATEDIFF(YEAR, S2.csrq, GETDATE()) AS FLOAT)) FROM S as S2
      WHERE S2.yxh = S.yxh
  )
  AND NOT EXISTS (
      SELECT * FROM E as E1
      WHERE E1.xh = S.xh
        AND (
            E1.zpcj IS NULL
            OR E1.zpcj <= (
                SELECT AVG(CAST(E2.zpcj AS FLOAT)) FROM E as E2
                WHERE E2.kh = E1.kh
                  AND E2.zpcj IS NOT NULL
            )
        )
  )
GROUP BY S.xh, S.xm, S.csrq
ORDER BY DATEDIFF(YEAR, S.csrq, GETDATE());
