use gyqk
select jno from J
where not exists(
	select * from SPJ as a
	where a.sno = 's1' AND not exists(
		select * from SPJ as b
		where b.jno = J.jno
		AND b.pno = a.pno 
	)
)