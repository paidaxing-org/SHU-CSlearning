USE gyqk
insert into SPJ(sno,pno,jno,qty)
select sno,pno,'J7',60 from SPJ where jno = 'J1'