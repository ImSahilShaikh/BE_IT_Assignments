function myResetFunction(){
    document.getElementById("myform").reset();
    alert("Page resetted!");
} 
function resetThis(arg){
  	
    document.getElementById(arg).value=null;
}



function validate(){
	//var pin=document.getElementById("pin").value;
	var phone=document.getElementById("phno").value;
	/*if (pin.length!=6 ){
		{
			alert("Please enter a valid 6 digit numeric pin");
		}
	}*/
	if(phone.charAt(0)=="8"){//(phone.length!=10){//|| phone.charAt(0)!='9' || phone.charAt(0)!='8' || phone.charAt(0)!='7'){
		window.alert("Invalid mobile number");
	return false;
	}
}