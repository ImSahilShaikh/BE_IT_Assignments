$(document).ready(function() {
    $('#name').keyup(function() {
        let name = $('#name').val();
        let regex = new RegExp('^[A-Z][a-z\s]*$');

        if (name.length != 0 && regex.test(name)) {
            $('#name').css('border', '2px solid rgba(77, 255, 77)');
        } else {
            $('#name').css('border', '2px solid red');
        }
    });

    $('#email').keyup(function() {
        let email = $('#email').val();

        let regex1 = /^([A-Za-z0-9_\-\.])+@([A-Za-z0-9_\-])+\.([A-Za-z]{3})$/;
        let regex2 = /^([A-Za-z0-9_\-\.])+@([A-Za-z0-9_\-])+\.([A-Za-z]{2})+\.([A-Za-z]{2})$/;

        if (email.length != 0 && regex1.test(email)) {
            $('#email').css('border', '2px solid rgba(77, 255, 77)');
        } else if (email.length != 0 && regex2.test(email)) {
            $('#email').css('border', '2px solid rgba(77, 255, 77)');
        } else {
            $('#email').css('border', '2px solid red');
        }
    });

    $('#p1').keyup(function() {
        let pass = $('#p1').val();

        let regex = /^(?=.*[0-9])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{8,}$/;

        if (pass.length != 0 && regex.test(pass)) {
            $('#p1').css('border', '2px solid rgba(77, 255, 77)');
        } else
            $('#p1').css('border', '2px solid red');
    });

    $('#p2').keyup(function() {
        let pass = $('#p1').val();
        let confirmpass = $('#p2').val();

        if (pass == confirmpass)
            $('#p2').css('border', '2px solid rgba(77, 255, 77)');
        else
            $('#p2').css('border', '2px solid red');
    });

    $('#contact').keyup(function() {
        let contact = $('#contact').val();
        let regex = new RegExp('^[789]{1}[0-9]{9}$');

        if (contact.length != 0 && regex.test(contact)) {
            $('#contact').css('border', '2px solid rgba(77, 255, 77)');
        } else
            $('#contact').css('border', '2px solid red');
    });
});