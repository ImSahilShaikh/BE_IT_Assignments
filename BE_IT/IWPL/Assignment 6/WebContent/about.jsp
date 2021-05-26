<%

if(!((String)session.getAttribute("user")).equals("NoUser"))
{  
%>
    <!DOCTYPE html>
    <html>

    <head>
        <title>
            EPIC REVIEW
        </title>
        <link rel="shortcut icon" type="image/x-icon" href="./img/logo.png">
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
        <link rel="stylesheet" href="./style.css">
    </head>

    <body style="overflow: hidden;">
        <nav>
            <div class="textandlogo">
                <img src="./img/logo.png" id="logopic">
                <div class="logo">
                    <a class="alogo" href="index.html">EPIC REVIEW</a>
                </div>
            </div>
            <ul>
                <a class="link" href="index.jsp">HOME</a>
                <a class="link" href="about.jsp">ABOUT</a>
                <a class="link" href="contactus.jsp">CONTACT US</a>
                <a class="link" href="logout.jsp">LOGOUT</a>
            </ul>
        </nav>
        <div class="about-container">
            <h1>
                About the developer
            </h1>
            <div class="about-card">
                <div class="about-image">
                    <img src="./img/myphoto.jpg">
                </div>
                <div class="about-body">
                    <div class="about-title">
                        <strong class="title-text"> Sahil Shaikh</strong>
                        <small>B.E Information Technology</small>
                        <a href="https://twitter.com/imsahilshaikh98" class="fa fa-twitter"></a>
                        <a href="https://www.linkedin.com/in/sahilshaikh21/" class="fa fa-linkedin"></a>
                    </div>
                </div>
            </div>
        </div>
    </body>

    </html>

    <%
}

else
	response.sendRedirect("Login.jsp");
%>