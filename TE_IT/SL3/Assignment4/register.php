<!DOCTYPE HTML5>
<html>
        <link rel="stylesheet" type="text/css " href="style.css">
    <head>
        <title>
            WELCOME TO MUSIC STREAMINGs
        </title>    
    </head>
    <body onload="init()">
    <?php 
        // define variables and set to empty values
        $nameErr = $emailErr = $genderErr = $websiteErr = "";
        $name = $email = $gender = $comment = $website = "";

        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            if (empty($_POST["name"])) {
                $nameErr = "Name is required";
            } 
            else {
                $name = test_input($_POST["name"]);
                // check if name only contains letters and whitespace
                    if (!preg_match("/^[a-zA-Z ]*$/",$name)) {
                        $nameErr = "\nOnly letters and white space allowed";
                    }
            }


        if (empty($_POST["email"])) {
            //$emailErr = "Email is required";
            } else {
                $email = test_input($_POST["email"]);
                // check if e-mail address is well-formed
                if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                    $emailErr = "Invalid email format";
                }
            }
                
        if (empty($_POST["website"])) {
            $website = "";
              } else {
                $website = test_input($_POST["website"]);
                // check if URL address syntax is valid (this regular expression also allows dashes in the URL)
                if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i",$website)) {
                  $websiteErr = "Invalid URL";
                }
              }
            }
        function test_input($data) {
          $data = trim($data);
          $data = stripslashes($data);
          $data = htmlspecialchars($data);
          return $data;
        }        
    ?>
    <header>
    <div class="header">
        
        <h2 class="logo">Music streaming</h2>
            
             <div class="navbar">
                 <a href="register.html">REGISTER</a>
                <div class="dropdown" style="float: right;">
                    <button class="dropbtn">
                    ABOUT US
                    </button>
	                <div class="dropdown-content">
	                    <a href="Info.html">Info</a>
	                    <a href="Contact.html">Contact</a>


	                </div>
                </div>
                <div class="dropdown" style="float: right;"> 
                    <button class="dropbtn">
                        GENRES
                    </button>
                    <div class="dropdown-content">
                        <a href="pop.html">Pop</a>
                        <a href="romantic.html">Romantic</a>
                        <a href="jazz.html">Jazz</a>
                    </div>
                </div>
                <a href="index.html">HOME</a>
            </div>
            </div>  
            
    </div>
    <style type="text/css">
        .error {color: #FF0000;}
    </style>


    </header>
        <form id="myform" method="post">
            
            <div style="padding-left: 3%">
                <br><h1 style="text-align: float"> Sign Up</h1>
            </div>

            <div style="margin: 10px; padding:20px ; text-align: center">
                <fieldset  style="margin-left: 20%; margin-right: 20%; padding: 5% 5%; ">
                <legend>
                	<h3>Login Infomation</h3>
                </legend>
                       
                    <label style="float: left; width: 35%; margin-right: -50%; text-align: right;"> Name<a class="error">*</a>: </label><input type="text" name="name" value="<?php echo $name;?>"><br><span class="error"> <?php echo $nameErr;?></span>
                    <br><br><br>
                    <label style="float: left; width: 35%; margin-right: -50%; text-align: right;">Email<a class="error">*</a>: </label><input id="email" name="email" placeholder="Ex: abcd@gmail.com" type="text" value="<?php echo $email;?>" autocomplete="off"><br>
                    <span class="error"><?php echo $emailErr;?></span>
                    <br><br><br>
                    <label style="float: left; width: 35%; margin-right: -50%; text-align: right;">Website<a class="error">*</a>: </label><input type="text"  id="website" name="website" autocomplete="off" value="<?php echo $website;?>"><br>
                    <span class="error"><?php echo $websiteErr;?></span>
					<br><br><br>
                   

                    <label style="float: left; width: 35%; margin-right: -50%; text-align: right;">Phone*: </label><input type="text" ><br><span class="error" id="phoneerror"> </span>
                    <br><br><br>
                    <label style="float: left; width: 35%; margin-right: -50%; text-align: right;">Address: </label><textarea rows="2" type="text" id="add" autocomplete="off"></textarea><br><span class="error" id="adderror"> </span>
                    <br><br><br>
                    <label style="float: left; width: 35%; margin-right: -50%; text-align: right;">Pincode*: </label><input type="text" id="pin" onkeyup="pinValid()" onKeyDown="if(this.value.length==6 && event.keyCode!=8) return false;" autocomplete="off"><br>
                    <span class="error" id="pinerror"> </span>                    
                    <br><br><br>



                    <label style="float: left; width: 35%; margin-right: -50%; text-align: right;">Date of Birth<a class="error">*</a>: </label><input type="date"  id="dob" autocomplete="off" >
                    <br><span class="error" id="doberror"> </span>
                    <br><br><br>

                    <label style="float: left; width: 35%; margin-right: -50%; text-align: right;">Gender<a class="error">*</a>: </label>
                    <br>
               		<label style="text-align: right; float:left; margin-left:15% ">Male</label> <input type="radio" name="Gender" id="dob" checked="checked" >
               		<br>
                    <label style="text-align:right; float: left; margin-left: 15%">Female</label> <input type="radio" name="Gender" id="dob" >
                    <br>
                    <label style=" text-align: right; float: left; margin-left: 15%">Other</label> <input type="radio" name="Gender" id="dob" >
                </fieldset>
                <br><br>
                <button class="gbtn" onclick=" return onSub();" style="margin-right:20px" >SUBMIT</button>
                <button class="gbtn" type="Clear" onclick="Clear();">RESET</button>
            
            </div>
        </form>
    </body>
    <footer>&copy All rights reserved</footer>
</html>
