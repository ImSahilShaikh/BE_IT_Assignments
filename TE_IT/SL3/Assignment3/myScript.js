//Form validations in javascript
function validation(){
	var name=document.getElementById("name").value;
	var phone=document.getElementById("phno").value;
	var pin=document.getElementById("pin").value;
	var p1=document.getElementById("p1").value;
	var p2=document.getElementById("p2").value;
	var address=document.getElementById("add").value;
	var email=document.getElementById("email").value;
	
	//to check that all fields are filled or not
	if(!name || !phone || !pin || !p1 || !p2 || !address || !email )
	{
		alert("All fields are required!");
		return false;
	}
	var regstr=/^[A-Z][a-z\s]*$/;
	if(regstr.test(name)==false){
		nameerror.innerHTML="Name should consist of string only!";
		return false;
	}	

	var reg = /^([A-Za-z0-9_\-\.])+@([A-Za-z0-9_\-\.])+\.([A-Za-z]{2,4})$/;
	if(reg.test(email)==false){
		emailerror.innerHTML = "Invalid Email"
		return false;
	}


	if(phone.length!=10 || phone.charAt(0)!='9' && phone.charAt(0)!='8' && phone.charAt(0)!='7')
	{
		phoneerror.innerHTML="Invalid length and or start of mobile number";
		return false;
	}

	if(pin.length!=6)
	{
		pinerror.innerHTML="Please enter a valid pincode";
		return false;
	}

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

function resetThis(arg) {
	document.getElementById(arg).value=null;
}
