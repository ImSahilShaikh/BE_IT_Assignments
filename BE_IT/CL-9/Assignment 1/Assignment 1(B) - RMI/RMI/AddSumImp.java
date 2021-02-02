import java.rmi.*;
import java.rmi.server.*;

//Define the method which was declared in interface
//The UnicastRemoteObject Class make objects available from remote machines
public class AddSumImp extends UnicastRemoteObject implements AddSum {

    // A Default Constructor which is defined in order to handle the Remote
    // Exception using throws keyword from its parent class i.e UnicastRemoteObject
    public AddSumImp() throws RemoteException {
        super();
    }

    public double addNum(double a, double b) throws RemoteException {
        return a + b;
    }
}
