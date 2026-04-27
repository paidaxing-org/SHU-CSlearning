USE gyqk
select J.jno,J.jname
from J
JOIN SPJ ON J.jno = SPJ.jno
JOIN P ON P.pno = SPJ.pno
GROUP BY J.jno,J.jname
Having count(distinct P.pno) = (select distinct count(*) from P)