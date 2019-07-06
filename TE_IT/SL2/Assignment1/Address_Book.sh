#Assignment No.	:	1
#Statement		:	Write a program to implement an address book with options given below:
					#a) Create address book.
					#b) View address book.
					#c) Insert a record.
					#d) Delete a record.
					#e) Modify a record.
					#f) Exit.
#Author			: 	Sahil Aslam Shaikh
#Class 			: 	TE-11	
#Roll. No.		: 	33364

#!bin/bash

#function to create a database files
createdb()
{
		if [ -e addressbook_database.lst ]
		then
				echo -e "WARNING: DATABASE ALREADY EXISTS!! "	
			else	
				touch addressbook_database.lst
				echo -e "INFO: DATABASE CREATED SUCCESSFULLY!!"
		fi

		if [ -e idcount.dat ] 
		then
				echo -e "WARNING: IDCOUNT FILE ALREADY EXISTS!! "		
			else
				touch idcount.dat
				echo -e "INFO: IDCOUNT FILE CREATED SUCCESSFULLY!!"
		fi
}

#function to insert a record
myid=$(cat idcount.dat)
add_record()
{
	while(true)
	do
		echo -e "Enter the Details : "
		echo -e "\n--------------------------------------------------"
		
		alpha_valid='^[a-zA-Z]+$'
		while(true)
		do
		echo -e "\nName: \c"		
			read name
			if [ -z $name ]
			then
				echo -e "\nWARNING: PLEASE ENTER A VALID NAME!"
			else 
				if ! [[ $name =~ $alpha_valid ]]
				then
					echo -e "\nWARNING: PLEASE ONLY CHARACTERS!"
				else
					break
				fi
			fi
		done
		
		while(true)
		do
		echo -e "\nAddress: \c"
			read address
			if [ -z $address ]
			then
				echo -e "\nWARNING: PLEASE ENTER A VALID ADDRESS!"
			else
				break
			fi
		done
		
		
		while(true)
		do
		echo -e "\nCity: \c"
			read city
			if [ -z $city ]
			then
				echo -e "\nWARNING: PLEASE ENTER A VALID CITY NAME!"
			else
				break
			fi
		done
	
		num_valid='^[0-9]+$' #to check numeric value
		while(true)
		do
		echo -e "\nPincode: \c"
			read pincode
			pinlen=${#pincode}
			#validation for 6 digit input
			if [ $pinlen -ne 6 ]
			then
				echo -e "\nWARNING: PLEASE ENTER A VALID 6 DIGIT PINCODE!"
			else
					if ! [[ $pincode =~ $num_valid ]]
					then
		        		echo -e "WARNING: PLEASE ENTER ONLY NUMERIC VALUES [0-9] "
		        	else
		        		break
		        	fi
			fi
		done
		
		num_valid='^[0-9]+$' #to check numeric value
		while(true)
		echo -e "\nPhone Number: \c"
		do
			read phno
			len=${#phno}
				#validation for 10 digit values
			if [ $len -ne 10 ]
		    then		
		       	echo -e "WARNING: PLEASE ENTER VALID 10 DIGIT VALUE!"
			else
			#validation for numric values
				if ! [[ $phno =~ $num_valid ]]
		        	then
		        		echo -e "WARNING: PLEASE ENTER ONLY NUMERIC VALUES [0-9] "
		       		else
		       			break
		   		fi
			fi
		done
		
		myid=$((myid+1))
	
		echo -e $myid"\t"$name"\t"$address"\t"$city"\t"$pincode"\t"$phno>>addressbook_database.lst
		echo -e "\nINFO: DATA INSERTED INTO DATABASE SUCCESSFULLY!!"
		
		echo -e "\nINFO: DO YOU WANT TO ADD ANOTHER RECORD?(Y/N): \c"
		read input
		
		if [ "$input" = "N" -o "$input" = "n" ];
		then
			break
		else
			continue
		fi
	done
}

#function to display a records 
display()
{
	while(true)
	do
		echo -e "\n--------------------------------------------------------------------"
		echo -e "\nDISPLAY SUB-MENU"
		echo -e "\n--------------------------------------------------------------------"
		echo -e "\n1.Display records by ID\n2.Display records alphabetically\n3.Exit to MAIN-MENU: \c"
		read choice
		case "$choice" in
			#case 1 is used to display the records by id
			1)echo -e "\n--------------------------------------------------------------------"
			echo -e "ID\tNAME\tADDRESS\t\tCITY\tPINCODE\tPHONE NUMBER"
			echo -e "\n--------------------------------------------------------------------"
			cat addressbook_database.lst;;
			#case 2 is used to display the records alphabetically
			2)echo -e "\n--------------------------------------------------------------------"
			echo -e "ID\tNAME\tADDRESS\t\tCITY\tPINCODE\tPHONE NUMBER"
			echo -e "\n--------------------------------------------------------------------"
			sort -k 2 addressbook_database.lst;;
			3)break;;
			*)echo -e "WARNING:PLEASE ENTER A VALID CHOICE!!!"
		esac
	done
}

#function to search a record
search()
{
	while(true)
	do
		echo -e "\n--------------------------------------------------------------------"
		echo -e "\nSEARCH SUB-MENU"
		echo -e "\n--------------------------------------------------------------------"
		echo -e "\n1.Search records by ID\n2.Search by name\n3.Exit to MAIN-MENU: \c"
		read choice
		case "$choice" in	
			#case 1 is used to search a record by particular id
			1)	echo -e "\nEnter the ID you want to search: \c"
				read idd
				if grep -w -q $idd addressbook_database.lst
				then 
					echo -e "\nINFO: RECORD FOUND!"
					echo -e "\n--------------------------------------------------------------------"
					echo -e "ID\tNAME\tADDRESS\t\tCITY\tPINCODE\tPHONE NUMBER"
					echo -e "\n--------------------------------------------------------------------"
					grep -w $idd addressbook_database.lst
				else
					echo -e "\nINFO: NOT DATA FOUND!!"
				fi
				;;
			#case 2 is used to search a record by name
			2)	read -p "Enter the name, city, pincode or phone number  you want to search: " search_param
				echo -e "\n--------------------------------------------------------------------"
				echo -e "ID\tNAME\tADDRESS\t\tCITY\tPINCODE\tPHONE NUMBER"
				echo -e "\n--------------------------------------------------------------------"
				grep -i -w $search_param addressbook_database.lst 
				;;
			3)break;;
			*)echo -e "WARNING: PLEASE ENTER A VALID CHOICE!!!"
		esac
	done	
}

#function to delete a record
delete()
{
	echo -e "Enter the ID you want to Delete: \c"
	read idd
	if grep -w -q $idd addressbook_database.lst
	then
 		sed -i "/$idd/d" addressbook_database.lst
		echo -e "NOTE: RECORD DELETED SUCCESSFULLY!!"
	else
		echo -e "NOTE: RECORD NOT FOUND!"
	fi 
}

#function to modify a record
modify()
{
	echo -e "ENTER THE ID YOU WANT TO MODIFY: \c"
	read idd
	
	str=$( grep -w -i $idd addressbook_database.lst )
	status=$?
	
	if [ $status -eq 0 ]
	then
		alpha_valid='^[a-zA-Z]+$'
		while(true)
		do
		echo -e "\nName: \c"		
			read nname
			if [ -z $nname ]
			then
				echo -e "\nWARNING: PLEASE ENTER A VALID NAME!"
			else 
				if ! [[ $nname =~ $alpha_valid ]]
				then
					echo -e "\nWARNING: PLEASE ONLY CHARACTERS!"
				else
					break
				fi
			fi
		done
		
		while(true)
		do
		echo -e "\nAddress: \c"
			read naddress
			if [ -z $naddress ]
			then
				echo -e "\nWARNING: PLEASE ENTER A VALID ADDRESS!"
			else
				break
			fi
		done
		
		while(true)
		do
		echo -e "\nCity: \c"
			read ncity
			if [ -z $ncity ]
			then
				echo -e "\nWARNING: PLEASE ENTER A VALID CITY NAME!"
			else
				break
			fi
		done
		
		num_valid='^[0-9]+$' #to check numeric value
		while(true)
		do
		echo -e "\nPincode: \c"
			read npincode
			pinlen=${#pincode}
			#validation for 6 digit input
			if [ $pinlen -ne 6 ]
			then
				echo -e "\nWARNING: PLEASE ENTER A VALID 6 DIGIT PINCODE!"
			else
					if ! [[ $npincode =~ $num_valid ]]
					then
		        		echo -e "WARNING: PLEASE ENTER ONLY NUMERIC VALUES [0-9] "
		        	else
		        		break
		        	fi
			fi
		done
		
		while(true)
		echo -e "\nPhone Number: \c"
		do
			read nphno
			len=${#nphno}
		        if [ $len -ne 10 ]
		        then		
		        	echo -e "WARNING: PLEASE ENTER VALID 10 digit value!"
			else
					if ! [[ $nphno =~ $num_valid ]]
		        		then
		        			echo -e "WARNING: PLEASE ENTER ONLY NUMERIC VALUES [0-9] "
		        		else
		        			break
		        		fi
			fi
		done
		
		sed -i "/$str/c\\$idd\t$nname\t$naddress\t$ncity\t$npincode\t$nphno" addressbook_database.lst
		echo -e "NOTE: RECORD MODIFIED SUCCESSFULLY!!"
	else
		echo -e "NOTE: RECORD NOT FOUND!"
	fi
}

#dropping a database
drop_database()
{
	rm addressbook_database.lst
	rm idcount.dat
	touch addressbook_database.lst
	touch idcount.dat
	echo "INFO: Database dropped Successfully!!!"
}

#main code starts here
choice=0
while(true)
do
	echo -e "\n------------------ADDRESS BOOK------------------"
	echo -e "\n1.Create Database\n2.Insert a record\n3.Display Database\n4.Search a record\n5.Delete a record\n6.Modify a record\n7.Drop Database\n8.Exit to SHELL "
	echo -e "\nEnter your choice: \c"
	echo -e "\n--------------------------------------------------------------------"
	read choice
	case "$choice" in
		1)createdb;;
		2)add_record;;
		3)display;;
		4)search;;
		5)delete;;
		6)modify;;
		7)drop_database;;
		8)echo -e "EXITING...... "
			echo -e $myid>idcount.dat #saving the idcount
			exit;;
		*) echo -e "\nWARNING: PLEASE ENTER A VALID CHOICE!!"
	esac
done
