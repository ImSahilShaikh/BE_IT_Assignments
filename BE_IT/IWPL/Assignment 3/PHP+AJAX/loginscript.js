$(document).ready(function() {
    $("#error").hide();
    $("#login").click(function() {

        var username = $("#username").val();
        var password = $("#password").val();

        if ($.trim(username).length > 0 && $.trim(password).length > 0) {
            $.ajax({

                method: "POST",
                url: "login-action.php",
                data: { username: username, password: password },
                cache: false,
                beforeSend: function() {
                    $('#login').val("Logging in...");
                },
                success: function(response) {
                    if (response) {
                        $("body").load("index.php").hide().fadeIn(1500);
                    } else {
                        $("#error").show();
                    }
                }
            });
        }
    });
});