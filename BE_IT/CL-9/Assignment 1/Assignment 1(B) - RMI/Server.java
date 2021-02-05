import java.rmi.*;
import java.util.*;

public class Server {
    public static void main(String[] args) {
        
        //Scanner Object to take Input from User 
        Scanner s = null;
        try
        {
            //create object to bind with server
            AddSumImp server = new AddSumImp();
            //Bind the remote object name with AddServer
            Naming.rebind("AddServer", server);

            System.out.println("Server Ready for providing RMI services");
            s = new Scanner(System.in);

            //Server execution never stops, so writing the exit condition
            String end = "";
            System.out.println("Enter exit if execution is Complete: ");
            end = s.nextLine();

            
            if(end.equalsIgnoreCase("exit"))
            {
                System.out.println("Server Connection Terminated");
                System.exit(0);
            }
        }
        catch (Exception e){
            System.out.println(e);
        }
        finally{
            s.close();
        }
    }
}
