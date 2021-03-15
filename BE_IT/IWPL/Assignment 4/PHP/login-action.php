<?php
require_once('C:\\xampp\\nusoap\\lib\\nusoap.php');
session_start();
unset($_SESSION['error']);

$error = "username/password incorrect";

//Web Services Description Language
// XML format for describing network services as a set of endpoints operating on messages containing either document-oriented or procedure-oriented information. The operations and messages are described abstractly, and then bound to a concrete network protocol and message format to define an endpoint.
$wsdl="http://localhost:9080/LoginSoapService/services/Login?wsdl";

if (isset($_POST['username']) && isset($_POST['password'])) {
    function validate($data)
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }

    $username = validate($_POST['username']);
    $password = validate($_POST['password']);

    if(empty($username)){
        $_SESSION["error"] = $error;
        header("Location: login.php");
        exit();
    }

    if(empty($password)){
        $_SESSION["error"] = $error;
        header("Location: login.php");
        exit();
    }    

    $param = array('username'=>$username,'password'=>$password);

    //instantiating client with server info
    $client = new nusoap_client($wsdl,'wsdl');

    //calling check credentials method
    $result = $client->call('checkCredentials',$param);

    // if the result is true send to main page else print error
    if(implode($result) == 'true'){
        $_SESSION['username'] = $username;
        header('location: index.php');
    }else{
        $_SESSION['error'] = "Wrong Username or Password";
        header('location: login.php');
    }


} else {
    $_SESSION["error"] = $error;
    header("Location: login.php");
    exit();
}
