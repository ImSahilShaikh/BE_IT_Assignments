--------------------------------------------------------------------------------------
1.Write cursor to find the customer id, name and address from customer table
--------------------------------------------------------------------------------------
delimiter //
create procedure GetAllCustomers()
begin 
	declare is_done integer default 0;
	declare id integer default 0;
	declare c_name integer(255) default "";
	declare c_add integer(255) default "";
	
	declare cust_info CURSOR for select c_id,name,address from customer;
	declare continue HANDLER for not found set is_done = 1;
				
	OPEN cust_info;
	get_list: LOOP 
				
	fetch cust_info into id,c_name,c_add;
	if is_done  = 1 then LEAVE get_list;
	end if; 
				
	select id as ID,c_name as name ,c_add as address; 

	end loop get_list;
	close cust_info;
end//
delimiter ;
----------------------------------------OUTPUT----------------------------------------
mysql> source mycur.sql
Query OK, 0 rows affected (0.036 sec)

mysql> call GetAllCustomers;
+------+-------+---------+
| ID   | name  | address |
+------+-------+---------+
|    1 | Sahil | PUNE    |
+------+-------+---------+
1 row in set (0.001 sec)

+------+--------+---------+
| ID   | name   | address |
+------+--------+---------+
|    2 | Manish | PUNE    |
+------+--------+---------+
1 row in set (0.002 sec)

+------+---------+---------+
| ID   | name    | address |
+------+---------+---------+
|    3 | Swapnil | NASHIK  |
+------+---------+---------+
1 row in set (0.002 sec)

+------+--------+---------+
| ID   | name   | address |
+------+--------+---------+
|    4 | Sanket | NASHIK  |
+------+--------+---------+
1 row in set (0.002 sec)

+------+--------+---------+
| ID   | name   | address |
+------+--------+---------+
|    5 | Rupesh | JALGAON |
+------+--------+---------+
1 row in set (0.002 sec)

Query OK, 0 rows affected (0.002 sec)
--------------------------------------------------------------------------------------
