<!DOCTYPE html>
<html>

<head>
    <title>
        EPIC REVIEW
    </title>
    <link rel="shortcut icon" type="image/x-icon" href="./img/logo.png">
    <link rel="stylesheet" href="./style.css">
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
            <a class="link" href="logout.jsp">LOGOUT</a>
        </ul>
    </nav>
    <div class="container">
        <div class="intro-card">
            <div class="intro-card-body">
                <div class="title">
                    <strong class="title-text">Welcome <% out.print(session.getAttribute("user")); %> to the EPIC REVIEW!</strong>
                    
                </div>
                <p class="content">
                    EPIC REVIEW will provide latest unbiased game reviews for the latest releases. Not every critic is
                    the same. EPIC REVIEW TEAM offers aggregated game reviews from the top critics, and our own EPIC REVIEW
                    pinpoints at a glance how each game works.
                </p>
            </div>
        </div>
    </div>

    <div class="game-container">
        <div class="card">
            <div class="card-image">
                <img src="./img/cyberpunk.jpg">
            </div>
            <div class="card-body">
                <div class="card-title">
                    <strong class="title-text">CyberPunk 2077</strong>
                    <small>Rating: 4.7/5</small>
                </div>
                <div class="more">
                    <button> <a href="./cyberpunk.html"> Read More</button></a>
                </div>
            </div>
        </div>

        <div class="card">
            <div class="card-image">
                <img src="./img/gta5.jpg">
            </div>
            <div class="card-body">
                <div class="card-title">
                    <strong class="title-text">GTA 5</strong>
                    <small>Rating: 4.1/5</small>
                </div>
                <div class="more">
                    <button> <a href="./gta5.html"> Read More</button></a>
                </div>
            </div>
        </div>

        <div class="card">
            <div class="card-image">
                <img src="./img/hitman.jpg">
            </div>
            <div class="card-body">
                <div class="card-title">
                    <strong class="title-text">Hitman : Blood Money</strong>
                    <small>Rating: 4.3/5</small>
                </div>
                <div class="more">
                    <button> <a href="./hitman.html"> Read More</button></a>
                </div>
            </div>
        </div>

    </div>

</body>

</html>