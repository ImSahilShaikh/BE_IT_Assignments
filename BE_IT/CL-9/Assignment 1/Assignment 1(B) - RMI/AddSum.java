import java.rmi.*;

//Declare a interface with a method(s) you want to which you want to call remotely

public interface AddSum extends Remote{
    double addNum(double a,double b) throws RemoteException;
    double subNum(double a,double b) throws RemoteException;
    double mulNum(double a,double b) throws RemoteException;
    double divNum(double a,double b) throws RemoteException;
}