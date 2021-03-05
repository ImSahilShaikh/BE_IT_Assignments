import HelloModule.HelloPOA;

class HelloImpl extends HelloPOA{
    HelloImpl()
    {
        super();
        System.out.println("Ready");
    }

    public String print_hello(String s)
    {
        return("Hello "+s);
    }
}