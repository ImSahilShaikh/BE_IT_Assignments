----------------------------------------------------------------------------
--Statement 2: Write a trigger to check purchase quantity and if purchase quantity < 0 prompt error message 
----------------------------------------------------------------------------
delimiter //
create trigger pur_quantity
before insert on contains
for each row
begin
	if (new.qty < 0) then
		signal sqlstate '02000'
		set message_text = 'ERROR: Quantity Cannot be zero or negative!!!';
	end if;
end //
delimiter ;
----------------------------------OUTPUT------------------------------------
mysql> source pur.sql
Query OK, 0 rows affected (0.06 sec)

mysql> insert into contains values(11,-2,2);
ERROR 1643 (02000): ERROR: Quantity Cannot be zero or negative!!!
----------------------------------------------------------------------------
