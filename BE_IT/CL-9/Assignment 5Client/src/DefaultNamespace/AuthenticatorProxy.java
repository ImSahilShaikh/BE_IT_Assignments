package DefaultNamespace;

public class AuthenticatorProxy implements DefaultNamespace.Authenticator {
  private String _endpoint = null;
  private DefaultNamespace.Authenticator authenticator = null;
  
  public AuthenticatorProxy() {
    _initAuthenticatorProxy();
  }
  
  public AuthenticatorProxy(String endpoint) {
    _endpoint = endpoint;
    _initAuthenticatorProxy();
  }
  
  private void _initAuthenticatorProxy() {
    try {
      authenticator = (new DefaultNamespace.AuthenticatorServiceLocator()).getAuthenticator();
      if (authenticator != null) {
        if (_endpoint != null)
          ((javax.xml.rpc.Stub)authenticator)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
        else
          _endpoint = (String)((javax.xml.rpc.Stub)authenticator)._getProperty("javax.xml.rpc.service.endpoint.address");
      }
      
    }
    catch (javax.xml.rpc.ServiceException serviceException) {}
  }
  
  public String getEndpoint() {
    return _endpoint;
  }
  
  public void setEndpoint(String endpoint) {
    _endpoint = endpoint;
    if (authenticator != null)
      ((javax.xml.rpc.Stub)authenticator)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
    
  }
  
  public DefaultNamespace.Authenticator getAuthenticator() {
    if (authenticator == null)
      _initAuthenticatorProxy();
    return authenticator;
  }
  
  public java.lang.String check(java.lang.String name, java.lang.String pass) throws java.rmi.RemoteException{
    if (authenticator == null)
      _initAuthenticatorProxy();
    return authenticator.check(name, pass);
  }
  
  
}