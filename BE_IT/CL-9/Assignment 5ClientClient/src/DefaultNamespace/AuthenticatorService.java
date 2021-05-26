/**
 * AuthenticatorService.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package DefaultNamespace;

public interface AuthenticatorService extends javax.xml.rpc.Service {
    public java.lang.String getAuthenticatorAddress();

    public DefaultNamespace.Authenticator getAuthenticator() throws javax.xml.rpc.ServiceException;

    public DefaultNamespace.Authenticator getAuthenticator(java.net.URL portAddress) throws javax.xml.rpc.ServiceException;
}
