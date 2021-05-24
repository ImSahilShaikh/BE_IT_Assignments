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
        <div class="container" id="contactus-container">
            <div class="contact">
                <div class="contact-body">
                    <div class="title">
                        <strong class="title-text">CONTACT US</strong>
                    </div>
                    <form class="contactus-form" id="contactus-form" autocomplete="off" action="contactUsSubmit.jsp" method="POST">
                        <p class="content">
                            <input id="fullname" name="fullname" placeholder="FULLNAME">
                            <input id="email" name="email" placeholder="EMAIL">
                            <textarea name="question" id="question" placeholder="Write your query here" rows="10"></textarea>
                            <input type="submit" class="button">
                        </p>
                    </form>
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