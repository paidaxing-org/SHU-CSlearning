use school
select distinct kh
from C
where kh not in(
	select distinct E.kh  
	from S,E
	where S.xm='刘晓明' and S.xh=E.xh
	)