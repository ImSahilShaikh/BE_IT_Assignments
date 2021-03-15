import HelloModule.*;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;
import org.omg.CORBA.ORB.*;
import java.util.Scanner;


public class Client {
    public static void main(String[] args) {
        Hello HelloImpl = null;
        try {

            // create and initialize ORB
            org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init(args,null);

            //obtaining the ORB object references for initial services
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");

            //Naming ContextExt contains set of name bindings of Interoperable Naming services
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

            //We have binded the name Hello from server so using same name for lookup
            String name = "Hello";

            //Getting reference of server name hello and then we are narrowing it down to Hello type
            HelloImpl = HelloHelper.narrow(ncRef.resolve_str(name));

            //Taking user Input
            System.out.println("Enter your name: ");
            Scanner sc = new Scanner(System.in);
            String userName = sc.nextLine();

            //Invoking the print_hello
            System.out.println(HelloImpl.print_hello(userName));
            
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}