--USE school;
CREATE VIEW Fail_Stu as
SELECT S.xh as 学号, S.xm as 姓名, S.xb as 性别, S.sjhm as 手机, C.km as 课程, E.zpcj as 成绩
FROM S
JOIN D ON S.yxh = D.yxh
JOIN E ON S.xh = E.xh
JOIN C ON E.kh = C.kh
WHERE D.mc = '计算机学院' AND E.zpcj < 60;