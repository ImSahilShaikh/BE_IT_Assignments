delimiter //

create trigger mytrig 
before insert on customer 
for each row
begin
	set NEW.name=upper(NEW.name);
end;
