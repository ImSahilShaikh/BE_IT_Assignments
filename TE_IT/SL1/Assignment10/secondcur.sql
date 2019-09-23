--------------------------------------------------------------------------------------
2.Write cursor to calculate grand total for a particular order
--------------------------------------------------------------------------------------
delimiter //
create procedure total(in order_id int)
begin
	declare a int default 0;
	declare total_amt int default 0;
	declare j int default 1;
	declare s cursor for select grandtotal from myorder where o_id=order_id;
	declare continue handler for not found set j=0;
	
	open s;
	fetch s into a;
	
	while j=1 do

		set total_amt=total_amt + a;
		fetch s into a;
		
	end while;

	select order_id,total_amt;

	close s;	
	
end//
delimiter ;
----------------------------------------OUTPUT----------------------------------------
mysql> source secondcur.sql
Query OK, 0 rows affected (0.088 sec)

mysql> call total(1);
+----------+-----------+
| order_id | total_amt |
+----------+-----------+
|        1 |     75400 |
+----------+-----------+
1 row in set (0.002 sec)
--------------------------------------------------------------------------------------
