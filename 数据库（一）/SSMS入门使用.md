# 数据库原理**<u>实践部分</u>**一些笔记&小心得



## 操作前准备~

首先便是SQL server与SSMS(SQL Server Management System)的下载与安装，这边就不给出教程了，放两篇教程的链接吧~

[SQL Server 2025下载和安装教程（附安装包，非常详细） - 莫之烟~ - 博客园](https://www.cnblogs.com/mozhiyan/articles/19303339)

[ 如何在 Windows 上安装SSMS，保姆级教程来了！ - 知乎](https://zhuanlan.zhihu.com/p/694623537)

SQL server是一个数据库软件，SSMS是一个数据库管理系统，可以把SQL server理解为是一个在<u>后台默默工作的工人</u>，SSMS是一个<u>管理工人进行操作的“项目经理”</u>（但是没有主观能动性，是个提线木偶）。而用户就是操控这个项目经理安排工人干活、把成果收到一起的“无形之手”。





------------------------------------



## 创建SQL模式

(其实大部分情况下不需要进行这个操作，==**因为在创建完一个数据库后，会生成默认的模式dbo**==)

(但是如果有分模块管理的需求，那么就需要进行创建了)

代码格式为：

```sql
CREATE SCHEMA 要创建的模式名(AUTHORIZATION <用户名>)
```

但是在我操作的过程中，发现了如下报错：

![image-20260302221107978](C:\Users\fdfx_\AppData\Roaming\Typora\typora-user-images\image-20260302221107978.png)

![image-20260302221115704](C:\Users\fdfx_\AppData\Roaming\Typora\typora-user-images\image-20260302221115704.png)

说明CREATE SCHEMA **<u>创建SQL模式语句必须独立执行 不能和其他语句一起并发批处理执行</u>**。

---------------

## 创建数据库、使用数据库、删除数据库

在完成上面的一些步骤后，想要存储数据，先得有数据库才行，我们可以使用以下的指令来创建：

```sql
CREATE DATABASE 数据库名称
```

注意这边不可以用AUTHORIZATION 来规定数据库归属于哪个模式，因为SCHEMA是位于DATABASE的下一级的。AUTHORIZATION和DATABASE不是同一级，不能加。

在创建了某一个数据库后，输入以下指令便可以选中这个数据库，进行进一步的操作（见下面的操作....）

(可能需要刷新一下才可以在左侧的目录结构中看到刚创建完的 )

```sql
USE 数据库名称
```

如果想要删除呢？也是用DROP的，指令如下：

```sql
DROP DATABASE 数据库名称
```



### 数据库显示在使用中 无法删除？

先尝试：

```sql
use master
drop database X
```

如果还是不行，再用（强制切换为单用户模式并断开其他链接）：

```sql
ALTER DATABASE X SET SINGLE_USER WITH ROLLBACK IMMEDIATE;
DROP DATABASE X
```



----------------

## 查数据库中的表格

大体分为两种方法

一是通过图形化界面展示，此以SSMS为例：

![image-20260316100609062](C:\Users\fdfx_\AppData\Roaming\Typora\typora-user-images\image-20260316100609062.png)

直接点击数据库左侧的“+”即可。



第二种是通过sql语句

如下所示：

```sql
USE gyqk(数据库的名称)
go
select name from sys.tables
%上方代码在SSMS中可行 mySQL中未测试
------------------ 
show tables from gyqk
%这个代码在mySQL中可行

```

这个sys.tables就可以理解为是记录数据库中所有“用户表”的一张表



----------------



## 查数据

那么如何进行表格中数据的查询呢？使用select语句即可。

select语句的格式如下：

```sql
select [distinct] 列名(可以多个)
from 表格名称
[where 满足条件的表达式]
[group by 列名序列 
 [having] 组条件表达式 ]
[order by] 列名]
```

举个例子，例如对于一个表格D

输入指令 

```sql
select distinct kh,km,xf,xs,yxh
from C
```

(**<u>如果要查询表格中所有的列也可以用*代替上面的kh,km,xf,xs,yxh</u>**)

![image-20260309101356197](C:\Users\fdfx_\AppData\Roaming\Typora\typora-user-images\image-20260309101356197.png)

### where的测试：

```sql
select distinct *
from C
where xf=4 and xs=40
```

![image-20260309102047464](C:\Users\fdfx_\AppData\Roaming\Typora\typora-user-images\image-20260309102047464.png)

### group by 测试

```sql
select xs,COUNT(*)
from C
group by xs
```

![image-20260309102916848](C:\Users\fdfx_\AppData\Roaming\Typora\typora-user-images\image-20260309102916848.png)

显示每个xs对应的行的个数





