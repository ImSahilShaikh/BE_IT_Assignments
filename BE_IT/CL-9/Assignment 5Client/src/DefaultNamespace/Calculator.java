/**
 * Calculator.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package DefaultNamespace;

public interface Calculator extends java.rmi.Remote {
    public double add(double a, double b) throws java.rmi.RemoteException;
    public double divide(double a, double b) throws java.rmi.RemoteException;
    public double multiply(double a, double b) throws java.rmi.RemoteException;
    public double subtract(double a, double b) throws java.rmi.RemoteException;
}
