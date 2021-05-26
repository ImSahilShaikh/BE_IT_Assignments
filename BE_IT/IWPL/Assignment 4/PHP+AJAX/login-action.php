<?php
session_start();

$error = "username/password incorrect";

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

    $mydbcon = mysqli_connect("localhost", "root", "", "epicreview");

    if (!$mydbcon) {
        echo "Connection Failed";
    }

    $sql = "SELECT * FROM users WHERE username='$username' and password='$password'";

    $result = mysqli_query($mydbcon, $sql);

    if (mysqli_num_rows($result) === 1) {
        $row = mysqli_fetch_assoc($result);
        
        if($row['username'] === $username && $row['password'] === $password)
        {            
            $_SESSION['username'] = $row['username'];
            // $_SESSION['id'] = $row['id'];
            echo "success";
            exit();
        }
        else
        {
            $_SESSION["error"] = $error;
            exit();
        }
    } 
    else
    {
        $_SESSION["error"] = $error;
        exit();
    }
    
} else {
    $_SESSION["error"] = $error;
    exit();
}