--------------------------------------------------------------------------------------
5.Find Sum of first 100 odd and even numbers
--------------------------------------------------------------------------------------
delimiter //
create procedure sum_int(in a int)
begin 

	declare sum_even int;
	declare sum_odd int;
	declare i int;
	
	set sum_even=0;
	set sum_odd=0;
	set i=0;
	
	while i<=a do
		if(i%2=0) then
			set sum_even=sum_even+i;
		else
			set sum_odd=sum_odd+i;
		end if;
		set i=i+1;
	end while;	
	
	select sum_even,sum_odd;
end//
delimiter ;

----------------------------------------OUTPUT----------------------------------------
mysql> call sum_int(100);
+----------+---------+
| sum_even | sum_odd |
+----------+---------+
|     2550 |    2500 |
+----------+---------+
1 row in set (0.003 sec)

Query OK, 0 rows affected (0.003 sec)
--------------------------------------------------------------------------------------

