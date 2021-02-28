<?php
session_start();
if (!isset($_SESSION["username"])) {
?>

    <!DOCTYPE html>
    <html lang="en">

    <head>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

        <link rel="stylesheet" href="style.css">
        <link rel="stylesheet" href="register-style.css">
        <script src="loginscript.js">
            
        </script>

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
                <a class="link" href="register.html">REGISTER</a>
            </ul>
        </nav>

        <div class="about-container">
            <div class="about-card">
                <div class="about-body">

                    <div class="about-title">
                        <strong class="title-text" style="margin: 20px 0px;"> Login</strong>
                        <form class="loginform">
                            <div class="formrow">
                                <input type="text" name="username" id="username" placeholder="Username">
                            </div>
                            <div class="formrow">
                                <input type="password" name="password" id="password" placeholder="Password">
                            </div>
                            <div id="login-button" class="formrow" style="margin-bottom: 20px;">
                                <button id="login" type="button" name="login">Submit</button>
                            </div>
                            <div class="formrow" style="margin-bottom: 20px;">
                                <!-- <?php
                                if (isset($_SESSION["error"])) {
                                    $error = $_SESSION["error"];
                                    echo "<span class='error'>$error</span>";
                                }
                                ?> -->
                                <span id="error" class='error'>incorrect Username or password</span>
                            </div>
                        </form>
                    </div>
                    <!-- <div class="signup">
                        <a href="" id="show_signup">Dont have account?</a>
                    </div> -->
                </div>
            </div>
        </div>

    </html>

<?php
} else {
    header("Location: ./index.php");
}
//unset($_SESSION["error"]);
?>