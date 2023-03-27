# SqlServer学习笔记

## SqlServer用户权限

> 设置用户权限的意义

数据库是一个应用程序，运行起来对应一个进程，这个进程中，有很多强大的功能支持，对于开发者或者是数据库管理者，都是充分的来应用这些功能，而为了保证数据库的安全性，必须对于数据库操作者有不同的权限控制

 ## 数据库与表的创建

```sql
create database [数据库名] --数据库的创建
```



```sql
create table Student(
id int primary key identity(1,1),--primary key 主键,identity 后面两个变量分别为起始值和自增量
studentNumber varchar(10) unique not null,
name varchar(50),
age int default 18,
)--表的创建
```

```sqlite
drop table [表名] --表的删除
```

```sqlite
if exists  (select * from sysobjects where name ='[表名]')
drop table [表名]  --条件删除表
```

## CRUD

```sqlite
insert into [表名] ([列名]，[列名]...)values('[数据]'，'[数据]'...) -- 加入一条数据
```

```sqlite
select * from [表名] --  查询表内所有数据
```

```sqlite
update [表名] set [列名]='',... where [条件语句] --更新表数据
```

```sqlite
delete [表名] where [条件语句] --删除数据
```

> 进阶查询

```sqlite
select [列名] as [别名] --查询数据以别名显示
```

```sqlite
select [列名] from [表名]  where [列名] between [小数] and [大数]
```

```sqlite
select [列名] from [表名]  where [列名] is null --判空查询
```

```sqlite
select top [数字]/([数字]) percent * from [表名] -- 查询前几行数据/查询前百分之几的数据
```

```
select * from [表名] order by [列名] asc/desc --升序 降序排列查询
```

```sqlite
select [列名],[列名],[case when 条件 then
when 条件 then
when 条件 then
else
end
]-- case when相当于多查询了一列你想要的分级数据
```

``` 
select * from [表名] where [列名] in ( , , , , , )--in查询
```

```
select * from [表名] where [列名] like '[数据]%' -- 模糊查询注意通配符的使用
```

## 表备份

```
select * into [表1] from [表2]
```

 ```
 insert into [表名] ([列名],...) values [选择语句]
 ```

## 表去重

```
 distinct --一般用于处理单行数据，多行数据的话会判断所有数据是否都完全一致
```

## 表分组

```
group by [列名]
```

## 表分页

```sqlite
select * from [表名]
order by [列名]
offset ((页码-1)*页数) rows
fecth next 页数 rows only --利用偏移量
```

```sqlite
-- 分页查询公式-利用max（主键）
select top @pageSize * 
from 表名 
where 主键>=
(select max(主键) 
	from (
		select top ((@pageIndex-1)*@pageSize+1) 主键
		from 表名  
		order by  主键 asc) temp_max_ids) 
order by 主键;
```

## 合并

```
[查询语句]
union all --合并语句
[查询语句]
--将两条查询语句查询到的结果合并起来 所查表的列数必须相等 并且列的数据类型必须相同 union all会以前面的查询语句作为基础 后面的查询语句其实是一个追加
union会自动去重 union all 是不会自动去重的
```

## 行转列

```
select [列名] from [biao'min]
```

## 左连接查询

```
left join on --以左侧表为维度 根据条件匹配右侧的表 左侧表的数据只多不少 
```

```sqlite
select * from [表1] left join [表2] on [条件]
```

## 内连接 右连接 全链接

```
inner join on --  内连接 取交集 取的就是on后面的条件 取两者共有的
```

```
right join on --  右链接 取以右侧表为基准的 右侧的表的数据只多不少
```

```
full join on  --  全链接
```

## 递归查询

```
with Con(Id,MenuName,ParentId,le) as(
 select Id,MenuName,ParentId,le=1 from [表名] where id =4
 union all
 select a.Id,a.MenuName,a.ParentId,le=le+1 from [表名] a join Con on a.ParentId=con.Id
)
```

## 视图的特点以及核心价值

> 视图核心价值

在数据查询中，可以看到数据表设计过程中，考虑到数据的冗余度低、数据一致性等问题，通常对数据表的设计要满足范式的要求，因此也会造成一个实体的所有信息保存在多个表中。当数据检索时，往往在一个表中不能够得到想要的所有信息，为了解决这种矛盾，在SQL Server中提供了视图

> 视图的概念

视图是一种数据库对象，是从一个或多个数据表或者视图中导出的虚表，视图的结构和数据是对数据表进行查询的结果

只存放视图的定义，不存放视图中对应的数据

基表中的数据发生变化，从视图中查询出的数据也随之改变

* 单表查询是方便的，但是多表查询是不方便的 视图可以将SQL语句转换为虚表

```
create view [视图名] as( [查询语句 --select  * from 表]  );
```

* 创建视图以后，查询就可以直接访问视图表了

视图中的数据 是不能和表分开单独修改的 ， 要对视图进行增删改查 最好还是直接修改原表

 ## 同义词

> 同义词定义

同义词是用来实现下列用途的数据库对象:

* 为可以存在于本地或者远程服务器上的其他数据库对象 提供备用名称-- 有点像是别名
* 提供抽象层以免对客户端应用程序基对象的名称或者位置进行修改

```
create synonym [SQL架构] synonym_name for
::=
{
 [服务器名].[数据库名].[架构].[基对象名]
}
```

## 数据类型

* 整形   bigint int smallint tinyint 字节数分别为8 4 2 1

* numeric 可以提供高精度的浮点类型 numeric[范围,小数点位数]  //范围指的是小数点左右两侧存储数据的数量
* decimal 与numeric是相似的
* smallmoney 货币类型数据 可以保存-214748.3648 ——214748.3647之间的数据
* money 货币型 这种数据类型能存储从-9220亿到9220 亿之间的数据，精确到货币单位的万分之一 
* float 近似数值型 数据类型是一种近似数值类型，供浮点数使用。说浮点数是近似的，是因为在其范围内不是所有的数都能精确表示。浮点数可以是从-1.79E+308到1.79E+308 之间的任意数 
* real 近似数值型
* Smalldatetime 日期时间型 精确到一分钟
* datetime 日期时间型 精确到三百分之一或3.33毫秒
* nchar   统一编码字符型  nchar 数据类型用来存储定长统一编码字符型数据。统一编码用双字节结构来存储每个字符，而不是用单字节(普通文本中的情况)。它允许大量的扩展字符。此数据类型能存储4000种字符，使用的字节空间上增加了一倍.

* nvarchar  统一编码字符型  
  nvarchar 数据类型用作变长的统一编码字符型数据。此数据类型能存储4000种字符，使用的字节空间增加了一倍.
* char 字符类型 固定长度 
* varchar 可变字符长度
* text 字符型
* ntext 统一编码字符型
* binary 二进制数据类型 binary数据类型用来存储可达8000字节长的定长的二进制数据。当输入表的内容接近相同的长度时，你应该使用这种数据类型
* varbinary 二进制数据类型 varbinary数据类型用来存储可达8000字节长的变长的二进制数据。当输入表的内容大小可变时，你应该使用这种数据类型
* image 二进制数据类型 存图片的

## Tsq编程

```

declare @text varchar(20) ;  //声明变量
select @text //空值
set @text='值'  //赋值语句
select @text //查到了
```

> 分支结构 逻辑判断

* 条件判断

```
declare @a int;
declare @b int;

select @a=4;
select @b=2;

if @a>@b
   begin
       print '@a的值大于@b的值'
   end
else
   begin
       print "@b的值大于@a的值"
   end    
```

* 循环结构

``` 
declare @aa int ;
select @aa = 1; //初始条件


while @aa < 10
 	begin
 		select @aa as 结果;
 		print '结果是：'+ convert(varchar(10),@aa)
 		select @aa=@aa+1;
 	end
```

## 局部变量与全局变量

* 被标志@的为局部变量 他的租用范围仅限只在程序内部，在批处理和脚本变量中有如下用途：
  * 作为计数器计算循环执行的次数或者控制循环执行的次数
  * 保存数据值提供流语句测试
  * 保存由存储过程代码返回的数据值或者函数返回值

* 以@@开头的变量被称作全局变量 ，用户不可以定义全局变量，用户不可以修改全局变量，全局变量以@@开头
  * 一般是系统中存在的变量 如cpu信息 程序工作时间等

## 逻辑运算符

![image-20230321213530545](C:\Users\XiAoRayL\AppData\Roaming\Typora\typora-user-images\image-20230321213530545.png)

![image-20230321213736041](C:\Users\XiAoRayL\AppData\Roaming\Typora\typora-user-images\image-20230321213736041.png)

* 自定义错误处理( try , catch)

  ```
  begin try
     -- sql
  end try
  begin catch
     --sql
  end catch
  ```

  * 可以在catch中使用以下语句抛出错误

    ```
    throw {error_number | @local_variable},
    {message | @local_varible},
    {state | @local_varible};
    ```

    

## 存储过程

> 存储过程是一组为了完成特定功能的SQL语句集合，经编译后存储在数据库中，用户通过指定的存储过程的名称并给出参数来执行

* 存储过程优点

  * 通过把处理封装在简单易用的单元中，简化复杂的操作存储过程创建后可以在程序中被多次调用执行，而不必重新编写该存储过程的SQL语句
  * 提高性能，使用存储过程比使用单独的SQL语句要快 如果某一操作包含大量的SQL语句代码，分别被多次执行，那么存储过程要比批处理的执行速度快得多
  * 安全，调用者只需要知道如何调用指定的存储过程即可，而不用关心存储过程的内容，防止sql注入

  

![image-20230322142705755](C:\Users\XiAoRayL\AppData\Roaming\Typora\typora-user-images\image-20230322142705755.png)

* 存储过程缺点

1. SQL本身是一种结构化查询语言，但不是面向对象的的，本质上还是过程化的语言，面对复杂的业务逻辑，过程化的处理会很吃力。同时SQL擅长的是数据查询而非业务逻辑的处理，如果如果把业务逻辑全放在存储过程里面，违背了这一原则。
2. 如果需要对输入过程的参数进行更改，或者要更改由其返回的数据，则仍然需要更新程序集中的代码以添加参数，更新调用等
3. 开发调试复杂
4. 没办法应用缓存 虽然有全局临时表之类的方法可以做缓存 但是同样加重了数据库的负担，如果缓存并发严重，经常要枷锁 效率堪忧
5. 不支持集群 水平方向无法扩展，数据库切割以后，存储过程并不清楚数据存在哪个数据库中

## 函数

说到函数，首先感觉和存储过程是很相像的，两者有一个共同点都是预编译优化后存储在磁盘中，所以效率要比T-Sql高一些 值得注意的是，存储过程可以创建或者访问临时表，而函数是不可以的，同时函数不可以修改表中的数据。或调用产生副作用的函数，但是函数可以作为select 或from、where子句的一部分，而存储过程不可以

* 常用函数

  ```
  datalength([字符串]) --返回字符串包含字符数，包含后面的空格
  sysdatetime() --系统时间
  getdate() --当前时间
  charindex([想要查的字符串],[用于被查找的字符串])
  orginal_login --返回连接到Sql_Server实例的登录名，你可以在具有众多显式或隐式上下文切换的会话中使用该函数返回原始登录的标识
  cast(expression As  data_type) --数据类型转换 experssion可以是任意的sql语句
  isnull([参数1],[参数2]) --判断参数1是否为null 如果是，返回参数2，如果不是，返回参数1.
  convert([转换后的数据类型],[要转换的日期],[规定日期/时间的输出格式])
  Coalesce([数据])  --返回所有数据的第一个非空数据
  avg() --返回数据的平均值
  count() --返回数据的总数量
  ```
  
  

* 自定义函数

  * Sql Server 中根据函数返回值形式的不同将用户自定义函数分为三种类型

    * 标量函数

    * 内联表值函数

    * 多语句表值函数

      SqlServer自定义函数必须具有返回值

* 三种自定义函数的异同点

  * 创建定义相同

    ```
    create function [函数名](传入参数的名称 传入参数的类型,.....)
    return 返回值类型
    as
    ```

  * 不同点：

    * 标量值函数返回的是一个数据类型值，内联表值函数返回的是一个table，而多语句表值函数返回的是一个类型为table的变量
    * 语法的结构，标量值函数和多语句表值函数都是要有begin........end，而内联表值函数就没有
    * 调用:标量函数要写成dbo.function_name

## 触发器

是SQL Server提供给程序员和数据分析员来保证数据完整性的一种方法，它是与表事件相关的特殊存储过程，他的执行不是由程序调用，也不是手工启动，二十通过事件来触发，比如对一个表进行操作时就会激活它执行，触发器经常用于加强数据的完整性约束和业务规划等

* 触发器分类
  * DML触发器
  * DDL触发器
  * 登录触发器

* DML触发器

  是一些附加在特定表或者视图上的操作代码，当数据服务器中发生数据操作语言事件时执行这些操作，SqlServer中的DML触发器有三种：

  * Insert触发器

    在向目标表中插入数据以后，会触发该表的insert触发器，系统自动在内存中创建inserted表，如果不满足判断的数据会进行回滚，那么插入数据这一操作就会失败

    

  * Delete触发器

  * Update触发器

* DDL触发器

  DDL触发器时当服务器或者数据库中发生数据定义语言（create drop alter开头的语句）时被激活使用，使用DDL触发器可以防止对数据架构进行的某些更改或记录数据中的更改或者事件操作。

* 登录触发器

  登陆触发器是相应login事件而激发存储过程，与Sql Server实例建立用户会话时将引发这个事件，登陆触发器将在登录的身份验证阶段完成之后且用户会话实际建立之前触发，因此，来自触发器内部且通常将到达用户的所有消息（例如报错信息或者是print语句的消息） 会传送到SQL Server错误日志，如果身份验证失败，将不激发登陆触发器

  

### 使用触发器的优劣势

* 遇到下列情形，应当考虑使用触发器
  * 通过数据库中的相关表实现级联更改
  * 防止恶意或者错误的insert、update、delete操作，并强制执行check约束定义的限制更为复杂的其他限制
  * 评估数据修改表前后的状态，并根据差异采取措施

* 触发器的劣势
  * 可移植性不好
  * 占用服务器资源，给服务器造成压力
  * 执行速度主要取决于数据库服务器的性能与触发器代码的复杂程度
  * 嵌套调用一旦出现问题，排错困难，而且数据容易造成不一致，后期维护不方便

## 用户自定义数据类型

通俗定义：用户自己设计并实现的数据库类型就成为用户自定义数据类型，即使这些数据类型基于系统数据类型，也可以理解为基础类型的一个延申。

用户定义数据类型三要素：

* 数据类型的名称
* 所基于的系统数据类型
* 数据类型的可空性

 [自定义数据名] [规定好的其数据类型] 后续就可以直接调用了

## 用户自定义表类型

 ```sqlite
 create type [类型名]  as table (
 [表数据定义]
 )
 
 Go
 
 declare @pageParame [类型名]
 insert into @pageParame values([数值])
 select * from @pageParame
 ```

## 序列

> 类似于自增主键

序列是由用户定义的绑定到架构的对象，序列依据定义的间隔按照升序或降序生成 并可配置为用尽时重新循环，序列不与特定表相关联，序列与表之间的关系由应用程序进行控制

```sqlite
CREATE SEQUENCE [schema_name . ] sequence_name
[ AS [ built_in_integer_type | user-defined_integer_type ] ]
[ START WITH <constant> ]
[ INCREMENT BY <constant> ]
[ { MINVALUE [ <constant> ] } | { NO MINVALUE } ]
[ { MAXVALUE [ <constant> ] } | { NO MAXVALUE } ]
[ CYCLE | { NO CYCLE } ]
[ { CACHE [ <constant> ] } | { NO CACHE } ]
[ ; ]
```

cycle就是指如果用尽 自动循环。

## 约束价值 主键约束

数据库由若干张数据表组成（理解为一个类库） 数据表由行和列组成一个二维数组 约束是数据库中保证数据完整性的方法

* 主键约束 PRIMARY KEY

  确定表中的标识列 主键字段不能为空 必须唯一  是确定一个对象的唯一表现   

  ```
  alter table [数据表名]
  add constraint [约束名]
  primary key(字段名)
  ```

  

* 外键约束 FOREIGN KEY 

  确定表与表之间的联系 一般情况下通过主表的标识进行确定主表

  ```
  alter table [从表名称]
  add constraint [约束名]
  foreign key() references [主表名](id)
  ```

  

* UNIQUE

  确定这个字段必须是唯一的

* NOT NULL 确定这个字段的数据必须不为空

* CHECK 设置这个字段的数据特性

* DEFAULT 默认值

  
