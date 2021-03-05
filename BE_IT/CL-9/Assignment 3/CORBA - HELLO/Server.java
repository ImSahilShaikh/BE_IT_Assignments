
import HelloModule.Hello;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;

public class Server {
    public static void main(String[] args) {
        try {

            // create and initialize ORB
            org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init(args,null);

            //Getting reference of ROOTPOA
            POA rootPOA = POAHelper.narrow(orb.resolve_initial_references("RootPOA")); 

            //Activating ROOTPOA
            rootPOA.the_POAManager().activate();
 
            //Create Object of Interface implementation which will act as servant
            HelloImpl helloImpl = new HelloImpl();

            //Registering the servant object reference in the rootPOA
            org.omg.CORBA.Object ref = rootPOA.servant_to_reference(helloImpl);

            //narrowing the ROOTPOA reference object to propertype which in this case is of type Hello
            System.out.println("Step 1");
            Hello h_ref = HelloModule.HelloHelper.narrow(ref);

            //obtaining the ORB object references for initial services
            System.out.println("Step 2");
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");

            //Afain narrowing the ORB object reference to NamingContext type to bin it with server
            System.out.println("Step 3");
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

            //passing path and the servant object to the naming service, binding the servant object to the "Hello" 
            System.out.println("Step 4");
            String name = "Hello";
            NameComponent path[] = ncRef.to_name(name);
            ncRef.rebind(path,h_ref);

            //Enbaling ORB to run on main thread and waiting till invocation comes for ORB. Since it is in main method after invocation it will wait again
            System.out.println("Server Ready....");
            orb.run();

        } catch (Exception e) {
            System.out.println(e);
        }
    }    
}
