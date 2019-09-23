--------------------------------------------------------------------------------------
4.Find how many orders placed between a range of date
--------------------------------------------------------------------------------------
delimiter //
create procedure range_date(in start_date date,in end_date date)
begin
	select count(*) as orders_from_given_date_range from myorder where o_date>=start_date and o_date<=end_date;
end //
delimiter ;

----------------------------------------OUTPUT----------------------------------------
mysql> source fourthproc.sql;
Query OK, 0 rows affected (0.059 sec)

mysql> call range_date("2018-08-20","2019-07-30");
+------------------------------+
| orders_from_given_date_range |
+------------------------------+
|                            3 |
+------------------------------+
1 row in set (0.001 sec)

Query OK, 0 rows affected (0.001 sec)

--------------------------------------------------------------------------------------
