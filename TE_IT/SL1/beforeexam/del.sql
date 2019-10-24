delimiter //
create procedure del(in s int)
begin
	delete from sailor where sid=s;
end //
delimiter ;
