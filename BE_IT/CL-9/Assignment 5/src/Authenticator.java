
public class Authenticator {
	public String check(String name,String pass)
	{
		if(name.equals("admin"))
		{
			if(pass.equals("admin@123"))
			{
				return "Authenticated";
			}
			else
			{
				return "Incorrect Password";
			}
		}
		else {
			return "User Not found";
		}
	}
	
}
