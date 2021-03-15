<?php

if (isset($_POST['fullname']) && isset($_POST['email']) && isset($_POST['question'])) {
    function validate($data)
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }

    $fullname = validate($_POST['fullname']);
    $email = validate($_POST['email']);
    $question = validate($_POST['question']);
    

    $mydbcon = mysqli_connect("localhost", "root", "", "epicreview");

    if (!$mydbcon) {
        echo "Connection Failed";
    }

    $sql1 = "INSERT INTO contactus values('$fullname','$email','$question')";

    if(mysqli_query($mydbcon, $sql1)){
    
    }
    else{
        echo "Error: " . $sql1 . "<br>" . mysqli_error($mydbcon);
    }
} else {
    header("Location: contactus.html");
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
            window.location.href = "contactus.html";
        }, 3000);
    </script>
    <h2>Your query is submitted successfully</h2>
    <p>You will be redirected to contact us page in 3 seconds, please do not reload</p>
</body>

</html>