use gyqk

create table J
(
	jno CHAR(4) NOT NULL,
	jname VARCHAR(10),
	jcity CHAR(4),
	balance NUMERIC(6,2),
	PRIMARY KEY(jno)
)

insert into J values('J1','东方明珠','上海',0.00)
insert into J values('J2','炼油厂','长春',-11.20)
insert into J values('J3','地铁三号','北京',678.00)
insert into J values('J4','炼钢工厂','天津',456.00)
insert into J values('J5','明珠线','上海',123.00)
insert into J values('J6','南浦大桥','上海',234.70)
insert into J values('J7','红星水泥厂','江西',343.00)

create table P
(
	pno CHAR(4) NOT NULL,
	pname VARCHAR(4),
	color CHAR(2),
	weight SMALLINT,
	PRIMARY KEY(pno)
)

insert into P values('P1','钢筋','黑',25)
insert into P values('P2','钢管','白',26)
insert into P values('P3','螺母','红',11)
insert into P values('P4','螺丝','黄',12)
insert into P values('P5','齿轮','红',18)

create table S
(
	sno CHAR(4) NOT NULL,
	sname VARCHAR(20),
	saddr VARCHAR(20),
    PRIMARY KEY(sno)
)

insert into S values('S1','原料工厂','南京北门23号')
insert into S values('S2','红星钢管厂','上海浦东100号')
insert into S values('S3','零件制造公司','南京东晋路55号')
insert into S values('S4','配件公司','江西上饶58号')
insert into S values('S5','原料公司','北京红星路88号')
insert into S values('S8','东方配件厂','天津叶西路100号')

create table SPJ
(
	sno CHAR(4) NOT NULL references S,
	pno CHAR(4) NOT NULL references P,
	jno CHAR(4) NOT NULL references J,
	price NUMERIC(4,2),
	qty SMALLINT,
	PRIMARY KEY(sno,pno,jno)
)

insert into SPJ values('S1','P1','J1',22.60,80)
insert into SPJ values('S1','P1','J4',22.60,60)
insert into SPJ values('S1','P3','J1',22.80,100)
insert into SPJ values('S1','P3','J4',22.80,60)
insert into SPJ values('S1','P3','J6',22.80,6)
insert into SPJ values('S3','P3','J5',22.10,100)
insert into SPJ values('S3','P4','J1',11.90,30)
insert into SPJ values('S3','P4','J4',11.90,60)
insert into SPJ values('S3','P4','J6',11.90,6)
insert into SPJ values('S1','P2','J4',33.80,60)
insert into SPJ values('S4','P2','J6',33.80,8)
insert into SPJ values('S5','P5','J1',22.80,20)
insert into SPJ values('S5','P5','J4',22.80,60)
insert into SPJ values('S5','P5','J6',22.80,8)
insert into SPJ values('S8','P3','J1',13.00,20)