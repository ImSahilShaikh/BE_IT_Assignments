--------------------------------------------------------------------------------------
1.Display customer name and address if id is input.
--------------------------------------------------------------------------------------

delimiter //
create procedure customer_details(in input_id int)
begin
	select c.name, c.address from customer as c where c.c_id = input_id;
end //
delimiter ;

----------------------------------------OUTPUT----------------------------------------
mysql> source firstproc.sql
mysql> call customer_details(5);

+--------+---------+
| name   | address |
+--------+---------+
| Rupesh | JALGAON |
+--------+---------+
1 row in set (0.000 sec)

Query OK, 0 rows affected (0.001 sec)

--------------------------------------------------------------------------------------
