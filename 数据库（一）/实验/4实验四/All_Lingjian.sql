use gyqk
select jno,jname from J
where not exists(
	select * from P
	where not exists(
		select * from SPJ
		where SPJ.jno = J.jno AND
		SPJ.pno = P.pno
	)
)