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

------------------------------OUTPUT-------------------------------
mysql> insert into contains values(11,-2,2);
ERROR 1643 (02000): ERROR: Quantity Cannot be zero or negative!!!
------------------------------OUTPUT-------------------------------
