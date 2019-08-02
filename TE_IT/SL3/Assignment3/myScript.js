function validation(){
	var name=document.getElementById("name").value;
	var phone=document.getElementById("phno").value;
	var pin=document.getElementById("pin").value;
	
	
	if(!name)
	{
		alert("Please enter a valid name");
		return false;
	}
	if(phone.length!=10 || phone.charAt(0)!='9' && phone.charAt(0)!='8' && phone.charAt(0)!='7')
	{
		alert("Invalid length and or start of mobile number");
		return false;
	}
	if(pin.length!=6)
	{
		alert("Please enter a valid pincode");
		return false;
	}
}
function resetThis(arg) {
	document.getElementById(arg).value=null;
}