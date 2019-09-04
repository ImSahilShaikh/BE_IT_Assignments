----------------------------------------------------------------------------
--Statement 3: Write a trigger to check purchase quantity with available stock , if not available prompt error message 
----------------------------------------------------------------------------

delimiter //

create trigger stock_trig
before insert on contains
for each row
begin
	if(new.qty>(select stock from product where new.p_id=p_id)) then
		signal sqlstate '02000'
		set message_text='ERROR: NOT ENOUGH STOCK';
	end if;
end//
delimiter ;

----------------------------------OUTPUT------------------------------------

mysql> source stocktrig.sql
Query OK, 0 rows affected (0.06 sec)

mysql> insert into contains values(7,3,15);
ERROR 1643 (02000): ERROR: NOT ENOUGH STOCK
----------------------------------------------------------------------------
