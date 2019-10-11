//Form validations in javascript
function emailValidation(){

	var email=document.getElementById("email").value;
	var emailerror = document.getElementById("emailerror");
	emailerror.innerHTML = "";

	var reg1 = /^([A-Za-z0-9_\-\.])+@([A-Za-z0-9_\-])+\.([A-Za-z]{3})$/;
	var reg2 = /^([A-Za-z0-9_\-\.])+@([A-Za-z0-9_\-])+\.([A-Za-z]{2})+\.([A-Za-z]{2})$/;
	if(reg1.test(email)==true)
	{
		document.getElementById("email").style.borderColor = "green";//return false;
	}
	else if(reg2.test(email)==true)
	{	
		document.getElementById("email").style.borderColor = "green";//return false;
	}
	else
	{
		emailerror.innerHTML = "Invalid Email";
		document.getElementById("email").style.borderColor = "red";
		return false;
	}

}

function resetThis(arg) {
	document.getElementById(arg).value=null;
}

function pinValid()
{
	var pin=document.getElementById("pin").value;
	var pinerror=document.getElementById("pinerror");
	pinerror.innerHTML="";
	if (pin.length<6) {
		pinerror.innerHTML="Invalid pin! Pin less than 6 digits";
		document.getElementById("pin").style.borderColor="red";
		return false;
	}
	else
	{
		document.getElementById("pin").style.borderColor="green";
	}
}

function phoneValid()
{
	var phone=document.getElementById("phno").value;
	var phoneerror=document.getElementById("phoneerror");
	phoneerror.innerHTML="";
	if(phone.length!=10 || phone.charAt(0)!='9' && phone.charAt(0)!='8' && phone.charAt(0)!='7')
	{
		phoneerror.innerHTML="Invalid length and or start of mobile number";
		document.getElementById("phno").style.borderColor = "red"
		return false;
	}
	else
	{
		document.getElementById("phno").style.borderColor = "green";
	}
}

function nameValidation()
{
	var name=document.getElementById("name").value;
	var nameerror=document.getElementById("nameerror");
	nameerror.innerHTML="";
	var regstr = /^[A-Z][a-z\s]*$/;
	if(!regstr.test(name))
	{
		nameerror.innerHTML="Name should consist of string only With first letter capital!";
		document.getElementById("name").style.borderColor = "red";
		return false;
	}
	if(regstr.test(name))
	{		document.getElementById("name").style.borderColor = "green";
	}

}

function init()
{
	document.getElementById("name").style.borderColor = "red";
	document.getElementById("email").style.borderColor = "red";
	document.getElementById("p1").style.borderColor = "red";
	document.getElementById("p2").style.borderColor = "red";
	document.getElementById("phno").style.borderColor = "red";
	document.getElementById("add").style.borderColor = "red";
	document.getElementById("pin").style.borderColor = "red";
	document.getElementById("dob").style.borderColor = "red";
}



function onSub() {

	var name=document.getElementById("name").value;
	var phone=document.getElementById("phno").value;
	var pin=document.getElementById("pin").value;
	var p1=document.getElementById("p1").value;
	var p2=document.getElementById("p2").value;
	var address=document.getElementById("add").value;
	var email=document.getElementById("email").value;

	if(!name || !phone || !pin || !p1 || !p2 || !address || !email )
	{
		alert("All fields are required!");
		return false;
	}	
	
	var p1=document.getElementById("p1").value;
	var p2=document.getElementById("p2").value;
	
	if(p1.length<8 || p2.length<8)
	{
		if(p1.length<8)
		{
			document.getElementById("p1").focus();
			passerror.innerHTML="Please enter password of atleast 8 characters!";
			return false;
		}
		if (p2.length<8)
		{
			document.getElementById("p2").focus();
			rpasserror.innerHTML="Please enter password of atleast 8 characters!";
			return false;
		}
		return false;
	}
	else if(p1!=p2)
	{
		document.getElementById("p1").focus();
		alert("Password doesn't matches!");
		return false;
	}

	
	
	var doberror=document.getElementById("dob").value;

	var d1 = new Date(doberror);	//MAKE DATE OBJECT FROM USER INPUT
	var d2 = new Date();	//MAKE DATE OBJECT FOR CURRENT DATE
	
	var diff =(d2.getTime() - d1.getTime()) / 1000;
   	diff /= (60 * 60 * 24);
  	var age = Math.abs(Math.round(diff/365.25));
	console.log(age);
	
  	if(age<13)
  	{
  		alert("At least 13 years of age is required to continue.");
  		document.getElementById("dob").style.border = "1px solid red";
		document.getElementById("dob").focus();
  		return false;
  	}	
}