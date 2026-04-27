SET STATISTICS TIME ON;
use school
SELECT C.kh, C.km, T.xm from S
JOIN D ON S.yxh = D.yxh
JOIN E ON S.xh = E.xh
JOIN C ON E.kh = C.kh
JOIN O ON E.xq = O.xq AND E.kh = O.kh AND E.gh = O.gh
JOIN T ON O.gh = T.gh
WHERE D.mc = '计算机学院' AND S.xb = '男' AND E.zpcj >= 60 AND T.xl = '教授'
ORDER BY T.xm ASC, C.kh DESC