--------------------------------------------------------------------------------------
3.Find how many orders placed in todays date.
--------------------------------------------------------------------------------------
delimiter //
create procedure order_date(in input_date date)
begin
	select count(*) as order_on_given_date from myorder where o_date=input_date;
end //
delimiter ; 

----------------------------------------OUTPUT----------------------------------------
mysql> source thirdproc.sql;
Query OK, 0 rows affected (0.061 sec)

mysql> call order_date("2019-07-23");
+---------------------+
| order_on_given_date |
+---------------------+
|                   1 |
+---------------------+
1 row in set (0.001 sec)

Query OK, 0 rows affected (0.001 sec)
--------------------------------------------------------------------------------------
