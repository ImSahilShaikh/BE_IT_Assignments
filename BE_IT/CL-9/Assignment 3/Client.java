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
            org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init(args,null);

            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

            String name = "Hello";

            HelloImpl = HelloHelper.narrow(ncRef.resolve_str(name));

            System.out.println("Enter your name: ");
            Scanner sc = new Scanner(System.in);

            String userName = sc.nextLine();

            String s = HelloImpl.print_hello(userName);
            System.out.println(s);
            
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
