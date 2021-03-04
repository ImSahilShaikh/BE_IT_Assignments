
import HelloModule.Hello;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;

public class Server {
    public static void main(String[] args) {
        try {

            org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init(args,null);

            POA rootPOA = POAHelper.narrow(orb.resolve_initial_references("RootPOA")); 
            rootPOA.the_POAManager().activate();

            HelloImpl helloImpl = new HelloImpl();

            org.omg.CORBA.Object ref = rootPOA.servant_to_reference(helloImpl);

            System.out.println("Step 1");
            Hello h_ref = HelloModule.HelloHelper.narrow(ref);

            System.out.println("Step 2");

            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");

            System.out.println("Step 3");
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

            System.out.println("Step 4");

            String name = "Hello";

            NameComponent path[] = ncRef.to_name(name);
            ncRef.rebind(path,h_ref);

            System.out.println("Server Ready....");
            orb.run();

        } catch (Exception e) {
            System.out.println(e);
        }
    }    
}
