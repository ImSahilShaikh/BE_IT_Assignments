import java.rmi.*;
import java.util.*;

public class Client {
    public static void main(String[] args) {
        Scanner s = null;
        try {
            //Server url from where we want to call the method remotely
            String serverurl = "rmi://127.0.0.1/AddServer";

            //lookup method finds the reference of remote object
            AddSum remoteObject = (AddSum)Naming.lookup(serverurl);
            
            s = new Scanner(System.in);
            
            System.out.println("Enter first number: ");
            double num1 = s.nextDouble();

            System.out.println("Enter second number: ");
            double num2 = s.nextDouble();

            //calling the remote method
            System.out.println("The sum is: "+ remoteObject.addNum(num1, num2));
        } 
        catch (Exception e) {
            System.out.println(e);   
        }
        finally{
            s.close();
        }
    }
}
