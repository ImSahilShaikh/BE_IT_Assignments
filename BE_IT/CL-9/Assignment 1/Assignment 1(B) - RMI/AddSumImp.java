import java.rmi.*;
import java.rmi.server.*;

//Define the method which was declared in interface
//The UnicastRemoteObject Class make objects available from remote machines
public class AddSumImp extends UnicastRemoteObject implements AddSum {

    // A Default Constructor which is defined in order to handle the Remote
    // Exception using throws keyword from its parent class i.e UnicastRemoteObject
    
    public AddSumImp() throws RemoteException {
        //calling the constructor of UnicastRemoteObject
        super();
    }

    public double addNum(double a, double b) throws RemoteException {
        return a + b;
    }

    public double subNum(double a,double b) throws RemoteException{
        return a-b;
    }

    public double mulNum(double a,double b) throws RemoteException{
        return a*b;
    }

    public double divNum(double a,double b) throws RemoteException{
        return a/b; 
    }
}