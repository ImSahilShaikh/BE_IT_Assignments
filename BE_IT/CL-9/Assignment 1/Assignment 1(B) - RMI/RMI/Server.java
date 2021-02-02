import java.rmi.*;
import java.util.*;

public class Server {
    public static void main(String[] args) {
        
        //Scanner Object to take Input from User 
        Scanner s = null;
        try
        {
            AddSumImp server = new AddSumImp();
            //Bind the remote object name with AddServer
            Naming.rebind("AddServer", server);
            s = new Scanner(System.in);

            //Server execution never stops, so writing the exit condition
            String end = "";
            end = s.nextLine();

            System.out.println("Enter exit if execution is Complete: ");
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
