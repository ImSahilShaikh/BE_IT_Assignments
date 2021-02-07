function passwordValidation()
{
    var password = document.getElementById("p1").value;
    var pass_reg = /^(?=.*[0-9])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{8,}$/;


    if(!pass_reg.test(password))
    {
        document.getElementById("p1").style.borderColor = "red";
        return false;
    }
    if(pass_reg.test(password))
    {
        document.getElementById("p1").style.borderColor = "rgba(77, 255, 77)";
    }
}

function confirmPassword()
{
    var password = document.getElementById("p1").value;
    var confirmPassword = document.getElementById("p2").value;

    if(password == confirmPassword)
    {
        document.getElementById("p2").style.borderColor ="rgba(77, 255, 77)";
    }
    if(password != confirmPassword)
    {
        document.getElementById("p2").style.borderColor = "red";
    }
}



function emailValidation()
{
    var email = document.getElementById("email").value;

    const regemail1 = /^([A-Za-z0-9_\-\.])+@([A-Za-z0-9_\-])+\.([A-Za-z]{3})$/;
    const regemail2 = /^([A-Za-z0-9_\-\.])+@([A-Za-z0-9_\-])+\.([A-Za-z]{2})+\.([A-Za-z]{2})$/;

    if(regemail1.test(email) == true)
    {
        document.getElementById("email").style.borderColor = "rgba(77, 255, 77)";
    }
    else if(regemail2.test(email) == true)
    {
        document.getElementById("email").style.borderColor = "rgba(77, 255, 77)";
    }
    else
    {
        document.getElementById("email").style.borderColor = "red";
        return false;
    }   
}

function contactValidation()
{
    var contactno = document.getElementById("contact").value;
    if(contactno.length!=10 || contactno.charAt(0)!='9' && contactno.charAt(0)!='8' && contactno.charAt(0)!='7')
    {
        document.getElementById("contact").style.borderColor = "red";
        return false;
    }
    else
    {  
        document.getElementById("contact").style.borderColor = "rgba(77, 255, 77)";
    }
}

function nameValidation()
{
	var name=document.getElementById("name").value;
	const regstr = /^[A-Z][a-z\s]*$/;
	if(!regstr.test(name))
	{
		document.getElementById("name").style.borderColor = "red";
		return false;
	}
	if(regstr.test(name))
	{		
		document.getElementById("name").style.borderColor = "rgba(77, 255, 77)";
	}
}



function init()
{
	document.getElementById("name").style.borderColor = "red";
    document.getElementById("email").style.borderColor = "red";
    document.getElementById("p1").style.borderColor ="red";
    document.getElementById("p2").style.borderColor ="red";
    document.getElementById("contact").style.borderColor ="red";
}