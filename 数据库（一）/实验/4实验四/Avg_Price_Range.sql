USE gyqk
select '0-30' as qujian,AVG(price) as avg_price from SPJ where price between 0 and 30
union
select '31-60' as qujian,AVG(price) as avg_price from SPJ where price between 31 and 60
union
select '61-80' as qujian,AVG(price) as avg_price from SPJ where price between 61 and 80
union
select '81-100' as qujian,AVG(price) as avg_price from SPJ where price between 81 and 100
