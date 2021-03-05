import MyAuthenticatorModule.MyAuthenticatorPOA;

public class MyAuthenticatorImpl extends MyAuthenticatorPOA{
    MyAuthenticatorImpl()
    {
        super();
        System.out.println("Ready!");
    }

    public String chech_credentials(String username,String password)
    {
        if(username.equals("Sahil"))
        {
            if(password.equals("123"))
                return ("Authenticated");
        }
        return ("Check Credentials");
    }
}
