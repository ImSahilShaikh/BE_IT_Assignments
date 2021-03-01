<?php

$error = "Email not found in database";

if (isset($_POST['email'])) {
    function validate($data)
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }


    $to_email = validate($_POST['email']);


    $mydbcon = mysqli_connect("localhost", "root", "", "epicreview");

    if (!$mydbcon) {
        echo "Connection Failed";
    }

    $sql = "SELECT * FROM users WHERE email='$to_email'";

    $result = mysqli_query($mydbcon, $sql);

    if (mysqli_num_rows($result) === 1) {
        $row = mysqli_fetch_assoc($result);

        if ($row['email'] === $to_email) {
            $password = $row['password'];
            $subject = "Simple Email Test via PHP";
            $body = "Hello EpicReview User:'$to_email', Your password is '$password'";
            $headers = "From: 21epicreview@gmail.com";

            if (mail($to_email, $subject, $body, $headers)) {
?>
                <!DOCTYPE html>
                <html lang="en">

                <head>
                    <title>EPIC REVIEW</title>
                </head>

                <body>
                    <script>
                        setTimeout(function() {
                            window.location.href = "login.php";
                        }, 3000);
                    </script>
                    <h2>Password Sent to your Registered Email ID</h2>
                    <p>You will be redirected to home page in 3 seconds, please do not reload</p>
                </body>

                </html>
<?php
            } else {
                $_SESSION["error"] = $error;
            }
            exit();
        } else {
            $_SESSION["error"] = $error;
            exit();
        }
    } else {
        $_SESSION["error"] = $error;
        exit();
    }
} else {
    $_SESSION["error"] = $error;
    exit();
}
?>