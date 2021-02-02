import java.rmi.*;

//Declare a interface with a method you want to which you want to call remotely

public interface AddSum extends Remote{
    double addNum(double a,double b) throws RemoteException;
}