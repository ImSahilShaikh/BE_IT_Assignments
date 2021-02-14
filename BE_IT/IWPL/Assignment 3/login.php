<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="error.css">
    <title>EPIC REVIEW</title>
</head>

<body>
    <nav>
        <div class="textandlogo">
            <img src="./img/logo.png" id="logopic">
            <div class="logo">
                <a class="alogo" href="index.html">EPIC REVIEW</a>
            </div>
        </div>
        <ul>
            <a class="link" href="index.html">HOME</a>
            <a class="link" href="about.html">ABOUT</a>
            <a class="link" href="contactus.html">CONTACT US</a>
            <a class="link" href="register.html">REGISTER</a>
        </ul>
    </nav>

    <div class="about-container">
        <div class="about-card">
            <div class="about-body">

                <div class="about-title">
                    <strong class="title-text" style="margin: 20px 0px;"> Login</strong>
                    <form action="login-action.php" method="POST">
                        <div class="formrow">
                            <input type="text" name="username" id="username" placeholder="Username">
                        </div>
                        <div class="formrow">
                            <input type="password" name="password" id="password" placeholder="Password">
                        </div>
                        <div class="formrow" style="margin-bottom: 20px;">
                            <input type="submit" id="login" name="login">
                        </div>
                        <div class="formrow" style="margin-bottom: 20px;">
                            <?php
                            if (isset($_SESSION["error"])) {
                                $error = $_SESSION["error"];
                                echo "<span class='error'>$error</span>";
                            }
                            ?>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>

</body>

</html>

<?php
unset($_SESSION["error"]);
?>