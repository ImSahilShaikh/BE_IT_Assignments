//Form validations in javascript
function emailValidation(){
	var name=document.getElementById("name").value;
	var phone=document.getElementById("phno").value;
	var pin=document.getElementById("pin").value;
	var p1=document.getElementById("p1").value;
	var p2=document.getElementById("p2").value;
	var address=document.getElementById("add").value;
	var email=document.getElementById("email").value;
	
	//to check that all fields are filled or not
	/*if(!name || !phone || !pin || !p1 || !p2 || !address || !email )
	{
		alert("All fields are required!");
		return false;
	}*/

	/*
	var regstr=/^[A-Z][a-z\s]*$/;
	if(regstr.test(name)==false){
		nameerror.innerHTML="Name should consist of string only!";
		return false;
	}*/	
	var emailerror = document.getElementById("emailerror");
	emailerror.innerHTML = "";

	var reg = /^([A-Za-z0-9_\-\.])+@([A-Za-z0-9_\-\.])+\.([A-Za-z]{2,3})$/;
	if(!reg.test(email)){
		emailerror.innerHTML = "Invalid Email";
		document.getElementById("email").style.borderColor = "red";
		return false;
	}
	if(reg.test(email)){
		document.getElementById("email").style.borderColor = "green";
	}

/*
	if(phone.length!=10 || phone.charAt(0)!='9' && phone.charAt(0)!='8' && phone.charAt(0)!='7')
	{
		phoneerror.innerHTML="Invalid length and or start of mobile number";
		return false;
	}

	*/
}

function resetThis(arg) {
	document.getElementById(arg).value=null;
}

function onSub()
{
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
}

/*function passValid()
{
	var p1=document.getElementById("p1").value;
	var p2=document.getElementById("p2").value;
	var passerror.getElementById("passerror");
	var rpasserror.getElementById("rpasserror");
	passerror.innerHTML="";

	if(p1.length<8 || p2.length<8)
	{
		if(p1.length<8)
		{
			passerror.innerHTML="Please enter password of atleast 8 characters!";
			//return false;
		}
		else
		{
			document.getElementById("p1").style.borderColor = "green";
		}
		if (p2.length<8) {
			rpasserror.innerHTML="Please enter password of atleast 8 characters!";
			//return false;
		}
		else
		{
			document.getElementById("p2").style.borderColor = "green";	
		}
		return false;
	}
	else if(p1!=p2)
	{
		alert("Password doesn't matches!");
		return false;
	}
	else
	{
		document.getElementById("p1").style.borderColor = "green";
		document.getElementById("p2").style.borderColor = "green";
	}
}*/

function pinValid()
{
	var pin=document.getElementById("pin").value;
	var pinerror=document.getElementById("pinerror");
	pinerror="";
	if (pin.length<6) {
		pinerror.innerHTML="Invalid pin! Pin less than 6 digits";
		document.getElementById(pin).style.borderColor="red";
		return false;
	}
	else
	{
		document.getElementById(pin).style.borderColor="green";
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

function passValid()
{
	var p1=document.getElementById("p1").value;
	var p2=document.getElementById("p2").value;
	if(p1.length<8 || p2.length<8)
	{
		if(p1.length<8)
		{
			passerror.innerHTML="Please enter password of atleast 8 characters!";
			//return false;
		}
		if (p2.length<8) {
			rpasserror.innerHTML="Please enter password of atleast 8 characters!";
			//return false;
		}
		return false;
	}
	else if(p1!=p2)
	{
		alert("Password doesn't matches!");
		return false;
	}
}

function nameValidation()
{
	var name=document.getElementById("name").value;
	var nameerror=document.getElementById("nameerror");
	nameerror.innerHTML="";
	var regstr=/^[A-Z][a-z\s]*$/;
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



function dobValidate() {
	var doberror=document.getElementById("doberror");
	doberror="";

	var today = new Date();
	var nowyear = today.getFullYear();
    var nowmonth = today.getMonth();
    var nowday = today.getDate();
    var b = document.getElementById("dob").value;



    var birth = new Date(b);

    var birthyear = birth.getFullYear();
    var birthmonth = birth.getMonth();
    var birthday = birth.getDate();

    var age = nowyear - birthyear;
    var age_month = nowmonth - birthmonth;
    var age_day = nowday - birthday;

    if (age_month < 0 || (age_month == 0 && age_day < 0)) {
        age = parseInt(age) - 1;
    }
    if ((age < 13 && age_month == 0 && age_day <= 0)) {
    	alert("Age should be more than 13 years!Please enter a valid Date of Birth");
        return false;
	}
}
