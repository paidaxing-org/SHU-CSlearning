create database school
use school

create table D
( yxh varchar(2) not null primary key,
  mc char(10) not null,
  dz char(16) not null,
  lxdh varchar(8) not null
)
insert into D values('01','计算机学院','上大东校区三号楼','65347567')
insert into D values('02','通讯学院','上大东校区二号楼','65341234')
insert into D values('03','材料学院','上大东校区四号楼','65347890')

create table S
( xh varchar(4) not null primary key,
  xm varchar(10) not null,
  xb varchar(2) not null,
  csrq datetime not null,
  jg varchar(6) not null,
  sjhm char(11) not null,
  yxh varchar(2) not null references D(yxh)
 )
insert into S values('1101','李明','男','1993-03-06','上海','13613005466','02')
insert into S values('1102','刘晓明','男','1992-12-08','安徽','18913457890','01')
insert into S values('1103','张颖','女','1993-01-05','江苏','18826490423','01')
insert into S values('1104','刘晶晶','女','1994-11-06','上海','13331934111','01')
insert into S values('1105','刘成刚','男','1991-06-07','上海','18015872567','01')
insert into S values('1106','李二丽','女','1993-05-04','江苏','18107620945','01')
insert into S values('1107','张晓峰','男','1992-08-16','浙江','13912341078','01')
create index idx1 on S(yxh asc,xm desc)

create table T
( gh varchar(5) not null primary key,
  xm varchar(10) not null,
  xb varchar(2) not null check(xb='男' or xb='女'),
  csrq datetime not null check(csrq between '1900-01-01' and '1990-12-31'),
  xl char(6) not null check(xl in('讲师','副教授','教授')),
  jbgz numeric(6,2) not null check(jbgz>0),
  yxh varchar(2) not null references D(yxh)
 )
insert into T values('0101','陈迪茂','男','1973-03-06','副教授','3567.00','01')
insert into T values('0102','马小红','女','1972-12-08','讲师','2845.00','01')
insert into T values('0201','张心颖','女','1960-01-05','教授','4200.00','02')
insert into T values('0103','吴宝钢','男','1980-11-06','讲师','2554.00','01')

create table C
( kh varchar(8) not null primary key,
  km varchar(10) not null,
  xf varchar(1) default '4',
  xs varchar(2) default '40',
  yxh varchar(2) not null references D(yxh)
 )
insert into C values('08305001','离散数学','4','40','01')
insert into C values('08305002','数据库原理','4','50','01')
insert into C values('08305003','数据结构','4','50','01')
insert into C values('08305004','系统结构','6','60','01')
insert into C values('08301001','分子物理学','4','40','03')
insert into C values('08302001','通信学','3','30','02')
create index idx2 on C(km)

create table O
( xq varchar(14) not null,
  kh varchar(8) not null references C(kh),
  gh varchar(5) not null references T(gh),
  sksj varchar(12) not null,
  primary key(xq,kh,gh)
 )
insert into O values('2012-2013 秋季','08305001','0103','星期三 5-6')
insert into O values('2012-2013 冬季','08305002','0101','星期三 1-4')
insert into O values('2012-2013 冬季','08305002','0102','星期三 1-4')
insert into O values('2012-2013 冬季','08305002','0103','星期三 1-4')
insert into O values('2012-2013 冬季','08305003','0102','星期五 5-6')
insert into O values('2013-2014 秋季','08305004','0101','星期二 1-4')
insert into O values('2013-2014 秋季','08305001','0102','星期一 5-6')
insert into O values('2013-2014 冬季','08302001','0201','星期一 5-8')

create table E
( xh varchar(4) not null references S(xh),
  xq varchar(14) not null,
  kh varchar(8) not null,
  gh varchar(5) not null,
  pscj tinyint ,
  kscj tinyint ,
  zpcj tinyint ,
  foreign key(xq,kh,gh) references O(xq,kh,gh),
  primary key(xh,xq,kh,gh))
insert into E values('1101','2012-2013 秋季','08305001','0103',60,60,60)
insert into E values('1102','2012-2013 秋季','08305001','0103',87,87,87)
insert into E values('1102','2012-2013 冬季','08305002','0101',82,82,82)
insert into E values('1102','2013-2014 秋季','08305004','0101',null,null,74)
insert into E values('1103','2012-2013 秋季','08305001','0103',56,56,56)
insert into E values('1103','2012-2013 冬季','08305002','0102',75,75,75)
insert into E values('1103','2012-2013 冬季','08305003','0102',84,84,84)
insert into E values('1103','2013-2014 秋季','08305001','0102',null,null,80)
insert into E values('1103','2013-2014 秋季','08305004','0101',78,null,null)
insert into E values('1104','2012-2013 秋季','08305001','0103',74,74,90)
insert into E values('1104','2013-2014 冬季','08302001','0201',null,null,75)
insert into E values('1106','2012-2013 秋季','08305001','0103',85,85,94)
insert into E values('1106','2012-2013 冬季','08305002','0103',66,66,90)
insert into E values('1107','2012-2013 秋季','08305001','0103',90,90,90)
insert into E values('1107','2012-2013 冬季','08305003','0102',79,79,79)
insert into E values('1107','2013-2014 冬季','08302001','0201',null,null,60)




