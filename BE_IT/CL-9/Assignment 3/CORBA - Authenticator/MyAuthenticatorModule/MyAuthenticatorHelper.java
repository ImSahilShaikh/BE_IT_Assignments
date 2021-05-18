package MyAuthenticatorModule;


/**
* MyAuthenticatorModule/MyAuthenticatorHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from MyAuthenticatorModule.idl
* Wednesday, 10 March, 2021 1:29:57 PM IST
*/

abstract public class MyAuthenticatorHelper
{
  private static String  _id = "IDL:MyAuthenticatorModule/MyAuthenticator:1.0";

  public static void insert (org.omg.CORBA.Any a, MyAuthenticatorModule.MyAuthenticator that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static MyAuthenticatorModule.MyAuthenticator extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().create_interface_tc (MyAuthenticatorModule.MyAuthenticatorHelper.id (), "MyAuthenticator");
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static MyAuthenticatorModule.MyAuthenticator read (org.omg.CORBA.portable.InputStream istream)
  {
    return narrow (istream.read_Object (_MyAuthenticatorStub.class));
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, MyAuthenticatorModule.MyAuthenticator value)
  {
    ostream.write_Object ((org.omg.CORBA.Object) value);
  }

  public static MyAuthenticatorModule.MyAuthenticator narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof MyAuthenticatorModule.MyAuthenticator)
      return (MyAuthenticatorModule.MyAuthenticator)obj;
    else if (!obj._is_a (id ()))
      throw new org.omg.CORBA.BAD_PARAM ();
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      MyAuthenticatorModule._MyAuthenticatorStub stub = new MyAuthenticatorModule._MyAuthenticatorStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

  public static MyAuthenticatorModule.MyAuthenticator unchecked_narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof MyAuthenticatorModule.MyAuthenticator)
      return (MyAuthenticatorModule.MyAuthenticator)obj;
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      MyAuthenticatorModule._MyAuthenticatorStub stub = new MyAuthenticatorModule._MyAuthenticatorStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

}