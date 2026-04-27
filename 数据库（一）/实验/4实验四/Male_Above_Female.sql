USE school
SELECT S.xm as 姓名,
    DATEDIFF(YEAR, S.csrq, GETDATE()) as 年龄
FROM S
WHERE S.xb = '男' AND DATEDIFF(YEAR, S.csrq, GETDATE()) > ( SELECT MAX(DATEDIFF(YEAR, csrq, GETDATE())) 
    FROM S WHERE xb = '女'
);