#assignment for shell 
create_database()
{
	if [ -e mydatabase.dat ]
	then
			echo -e "Database already exists"
		else
			touch mydatabase.dat
			echo -e "INFO: Database created  Successfully!!"
	fi	
}

add_record()
{
	echo -e "\n-------------------Insert records-------------------"
	while(true)
	do
		echo -e "\n Name: "
		read name
			if [ -z $name ] 
			then
				echo -e "Please enter a valid name"
			else
				break
			fi
	done
	echo -e "\n Address"
	read address
	echo -e "\n Pincode"
	read pincode
	
	echo -e $name"\t\t"$address"\t\t"$pincode>>mydatabase.dat
}

delete_database()
{
	if [ -e mydatabase.dat ]
	then
		rm mydatabase.dat
		echo -e "\nINFO: DATABASE DELETED SUCCESSFULLY!!"
	else
		echo -e "No database found"
	fi
}

display()
{
	cat mydatabase.dat
}

search_record()
{
	echo -e "Enter the name you want to search: "
	read name
	grep $name mydatabase.dat
}

modify_record()
{
	echo -e "Enter the name you want to modify: "
	read name
	
	str=$(grep -w -i $name mydatabase.dat)
	status=$?
	
	if [ $status -eq 0 ]
	then
		echo -e "\nName: "
		read name
		echo -e "\nAddress"
		read address
		echo -e "\nPincode"
		read pincode
	
		sed -i "/$str/c\\$name\t\t$address\t\t$pincode" mydatabase.dat
		echo -e "\nNOTE:Record modified"
	else
		echo -e "\nNOTE:Record modification failure"
	fi
}

delete__record()
{
	echo -e "\nEnter the name whose record you want to delete: "
	read name
	if grep -w -q $name mydatabase.dat
	then
		sed -i "/$name/d" mydatabase.dat
		echo -e "\nINFO:Record deleted"
	else
		echo -e "\nRecord not found"
	fi
}



choice = 0 
while (true)
do
	echo -e "---------------------DATABASE---------------------"
	echo -e "\n1.Create database \n2.Add Record \n3.Display Database \n4.Search \n5.Modify \n6.Delete Record \n7.Delete database  \n8.Exit"
	read choice 
	case "$choice" in
		1)create_database;;
		2)add_record;;
		3)display;;
		4)search_record;;
		5)modify_record;;
		6)delete_record;;
		7)delete_database;;
		8)echo -e "INFO: EXITING....."
			exit;;
		*)echo -e "\nWARNING: PLEASE ENTER A VALID CHOICE !!"
	esac
done
