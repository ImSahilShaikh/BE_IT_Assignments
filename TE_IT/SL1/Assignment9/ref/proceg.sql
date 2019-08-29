delimiter //
create procedure get_cust_details()	
begin
	select * from customer where name="Sahil";
end//
delimiter ;
