USE gyqk
update spj set price=price*1.08  
where sno='S3' and pno='P5'  
and price<(select AVG(price) from spj where pno='P5')