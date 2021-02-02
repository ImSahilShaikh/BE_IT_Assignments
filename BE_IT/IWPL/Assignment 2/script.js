// function init()
// {
//     document.getElementById("name").style.borderColor="red";
//     document.getElementById("email").style.borderColor="red";
//     document.getElementById("p1").style.borderColor="red";
//     document.getElementById("p2").style.borderColor="red";
//     document.getElementById("contact").style.borderColor="red";
// }

// function nameValidation()
// {
//     var name = document.getElementById("name");
    
//     var nameregex = /^[a-zA-Z\s]+$/;

//     if(!nameregex.test(name))
//     {
//         document.getElementById("name").style.borderColor = "rgba(255, 0 , 0, 0.5)";
//         //document.getElementById("name").style.boxShadow = "10px 10px 20px 10px rgba(255, 0 , 0, 0.08)";
//         return false;
//     }
//     if(nameregex.test(name)){
//         document.getElementById("name").style.borderColor = green;//"rgba(102, 255 , 0, 0.5)";
//         //document.getElementById("name").style.boxShadow = "10px 10px 20px 10px rgba(102, 255 , 0, 0.08)";
//     }
// }


function nv()
{
    var name = document.getElementById("name");
    var nameregex = /^[a-zA-Z\s]+$/;

    if(!nameregex.test(name))
    {
        document.getElementById("name").style.borderColor="red";
        return false;
    }
    if(nameregex.test(name))
    {
        document.getElementById("name").style.borderColor="green";
    }
}

function n()
{
    var name = document.getElementById('name');
    var reg = /^[A-Za-z]+$/;

    if(!reg.test(name))
    {
        name.style.borderColor="green";
    }

    if(reg.test(name))
    {
        name.style.borderColor="red";
    }
}