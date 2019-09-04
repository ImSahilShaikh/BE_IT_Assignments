
----------------------------------------------------------------------------
Statement 5:Write a trigger which will store updated values as well as previous values of product price.
----------------------------------------------------------------------------

delimiter //
create trigger transaction
before update on product
for each row
begin
	insert into trans values(new.p_id,current_date,user(),old.price,new.price);
end;
//
delimiter ;

----------------------------------OUTPUT------------------------------------	

mysql>source trans.sql
Query OK, 0 rows affected (0.06 sec)

mysql> update product set price=40000 where p_name="Jupiter";
Query OK, 1 row affected (0.104 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from trans;
+------+----------------+----------------+-----------+-----------+
| p_id | date_of_update | user           | old_price | new_price |
+------+----------------+----------------+-----------+-----------+
|   22 | 2019-09-03     | root@localhost |     52177 |     40000 |
+------+----------------+----------------+-----------+-----------+
1 row in set (0.001 sec)
