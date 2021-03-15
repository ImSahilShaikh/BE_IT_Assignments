<?php

if (isset($_POST['name']) && isset($_POST['email']) && isset($_POST['p1']) && isset($_POST['contact'])) {
    function validate($data)
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }

    $name = validate($_POST['name']);
    $email = validate($_POST['email']);
    $password = validate($_POST['p1']);
    $contact = validate($_POST['contact']);

    $mydbcon = mysqli_connect("localhost", "root", "", "epicreview");

    if (!$mydbcon) {
        echo "Connection Failed";
    }

    $sql1 = "INSERT INTO authenticate values('$name','$email','$password','$contact')";

    if(mysqli_query($mydbcon, $sql1)){
        
    }
    else{
        echo "Error: " . $sql1 . "<br>" . mysqli_error($mydbcon);
    }
} else {
    header("Location: login.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <title>EPIC REVIEW</title>
</head>

<body>
    <script>
        setTimeout(function() {
            window.location.href = "index.php";
        }, 3000);
    </script>
    <h2>Congratulations your are now registered with us</h2>
    <p>You will be redirected to home page in 3 seconds, please do not reload</p>
</body>

</html>

