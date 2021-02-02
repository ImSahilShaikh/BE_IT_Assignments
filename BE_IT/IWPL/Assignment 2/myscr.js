function nameval()
{
    var name=document.getElementById("name").value;    
    var regstr = /^[A-Z][a-z\s]*$/;
    
    if(regstr.test(name) == false)
    {
        document.getElementById('name').style.borderColor = "red";
        return false;
    }
    if(regstr.test(name))
    {
        document.getElementById('name').style.borderColor = "green";
    }
}

function validateLastName() {
    form = document.getElementById('myform');
    lname = document.getElementById('name').value;
    rename = /^[a-zA-Z ]{2,30}$/;

    if (lname.length != 0 && rename.test(lname)) {

        form.lname.style = "border:2px solid green";
        return true;
    } else {

        form.lname.style = "border:2px solid red";
        return false;
    }
}