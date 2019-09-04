----------------------------------------------------------------------------
--Statement 4: Write a trigger to Calculate total amount of particular purchase
----------------------------------------------------------------------------
delimiter //
create trigger total_amount
before insert on myorder
for each row
begin 
	set new.tax=new.amount/3;
	set new.grandtotal=new.tax+new.amount;
end;
//
delimiter ;
----------------------------------OUTPUT------------------------------------	
mysql>source calculate.sql
Query OK, 0 rows affected (0.06 sec)

mysql> insert into myorder values(6,4,"2019-8-5",NULL,58000,NULL);
Query OK, 1 row affected (0.038 sec)

mysql> select * from myorder;
+------+------+------------+-------+--------+------------+
| o_id | c_id | o_date     | tax   | amount | grandtotal |
+------+------+------------+-------+--------+------------+
|    1 |    3 | 2019-07-23 | 19333 |  58000 |      75400 |
|    3 |    3 | 2019-07-21 | 36118 | 108354 |     112688 |
|    4 |    2 | 2019-08-04 | 41392 | 124177 |     124179 |
|    5 |    5 | 2019-08-04 | 17392 |  52177 |       NULL |
|    6 |    4 | 2019-08-05 | 19333 |  58000 |      77333 |
|   12 |    1 | 2019-07-18 | 65000 | 195000 |     202800 |
+------+------+------------+-------+--------+------------+
6 rows in set (0.000 sec)
----------------------------------------------------------------------------
