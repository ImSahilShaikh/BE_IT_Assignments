<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <script src="loginscript.js"></script>
    <title>Forgot Password</title>
</head>

<body>
    <div class="about-container">
        <div class="about-card">
            <div class="about-body">
                <div class="about-title">
                    <strong class="title-text">Forgot Password?</strong>
                    <form action="mailer.php" method="POST">
                        <div class="formrow" style="margin-top: 20px;">
                            <input id="email" name="email" type="text" placeholder="Enter your Email">
                        </div>
                        <div class="formrow">
                            <input id="forgot-button" type="submit">
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