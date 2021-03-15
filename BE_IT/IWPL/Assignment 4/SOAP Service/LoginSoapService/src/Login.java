import java.sql.*;
public class Login {
	
	public static boolean checkCredentials(String username,String password)
	{
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/epicreview","root","");
			
			String query = "select username,password from authenticate where username='"+username+"' and password ='"+password+"'";
			Statement st = con.createStatement();
			ResultSet resultSet = st.executeQuery(query);
			
			if(resultSet.next()) {
				return true;
			}
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
}
