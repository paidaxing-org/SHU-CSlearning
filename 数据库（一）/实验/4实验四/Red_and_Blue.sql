USE gyqk
select distinct jno from SPJ,P where SPJ.pno=P.pno and P.color='红'
intersect
select distinct jno from SPJ,P where SPJ.pno=P.pno and P.color='蓝'