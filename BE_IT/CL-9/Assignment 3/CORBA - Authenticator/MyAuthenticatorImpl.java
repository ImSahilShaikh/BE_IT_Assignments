import MyAuthenticatorModule.MyAuthenticatorPOA;
import java.sql.*;


public class MyAuthenticatorImpl extends MyAuthenticatorPOA{
    MyAuthenticatorImpl()
    {
        super();
        System.out.println("Ready!");
    }

    public String chech_credentials(String username,String password)
    {
        try {
            Class.forName("com.mysql.jdbc.Driver");

            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/epicreview","root","");

            String query = "select password from authenticate where username='"+username+"'";
		    Statement st = con.createStatement();
		    ResultSet resultSet = st.executeQuery(query);

            if(resultSet.next())
            {
                if(password.equals(resultSet.getString("password")))
                {
                    return ("Authenticated");
                }
                else
                    return ("Incorrect Password");
            }
            else
                return("User not Found");

        } catch (Exception e) {
            System.out.println(e);
        }
        return ("Something Went Wrong");
    }
}
