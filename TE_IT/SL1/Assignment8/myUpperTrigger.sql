--------------------------------------------------------------------------
--Statement 1: Write a trigger which will turn the customer name to upper case
--------------------------------------------------------------------------
delimiter //

create trigger mytrig 
before insert on customer 
for each row
begin
	set NEW.name=upper(NEW.name);
end;
delimiter ;
----------------------------------OUTPUT----------------------------------
mysql>source myUpperTrigger.sql
Query OK, 1 row affected (0.04 sec)

mysql> insert into customer values(6,"Jayesh","jayesh@yahoo.in",8585757565,"NASHIK");
Query OK, 1 row affected (0.04 sec)

mysql> select * from customer;
+------+---------+--------------------+------------+---------+
| c_id | name    | email              | phone      | address |
+------+---------+--------------------+------------+---------+
|    1 | Sahil   | sahil@gmail.com    | 9545727831 | PUNE    |
|    2 | Manish  | manish@yahoo.com   | 9874561230 | PUNE    |
|    3 | Swapnil | swapnil@rediff.com | 9988774455 | NASHIK  |
|    4 | Sanket  | sanket@hotmail.com | 8877994455 | NASHIK  |
|    5 | Rupesh  | rupesh@rediff.com  | 9977664455 | JALGAON |
|    6 | JAYESH  | jayesh@yahoo.in    | 8585757565 | NASHIK  |
+------+---------+--------------------+------------+---------+
6 rows in set (0.00 sec)
