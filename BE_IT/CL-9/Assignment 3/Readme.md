## Steps to Run:


- Step 1 : Run .idl file using following command 'idlj -fall Hello.idl'
This command will generate 6 helper files in one package with the given module name which are:
1. HelloPOA.java - the server skeleton
2. HelloHolder.java - the instance holder
3. HelloHelper.java - provides functions for casting references to their types
4. _HelloStub.java - the Client stub
5. Hello.java - the signature file that implements the hello contract
6. HelloOperations.java - operations specific to Hello

- Step 2 : Compile all .java files including all the Helper files created using idlj using following command 'javac \*.java HelloModule/\*.java'
- Step 3 : Start orbd using 'orbd -ORBInitialPort 1050&'
- Step 4 : Execute the Server code using the orbd port with 'java Server -ORBInitialPort 1050& -ORBInitialHost localhost&'
- Step 5 : Execute the Client code using the orbd port with 'java Client -ORBInitialPort 1050 -ORBInitialHost localhost'
