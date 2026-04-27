USE school
SELECT
    成绩等级,
    COUNT(*) AS 学生人数
FROM (
    SELECT
        CASE
            WHEN E.zpcj >= 90 THEN '优'
            WHEN E.zpcj >= 80 THEN '良'
            WHEN E.zpcj >= 70 THEN '中'
            WHEN E.zpcj >= 60 THEN '及格'
            ELSE '不及格'
        END AS 成绩等级
    FROM E
    WHERE E.zpcj IS NOT NULL 
) AS GradeTable
GROUP BY 成绩等级
ORDER BY 
    CASE 成绩等级
        WHEN '优' THEN 1
        WHEN '良' THEN 2
        WHEN '中' THEN 3
        WHEN '及格' THEN 4
        ELSE 5
    END