import java.rmi.*;
import java.util.*;

public class Client {
    public static void main(String[] args) {
        Scanner s = null;
        try {
            // Server url from where we want to call the method remotely
            String serverurl = "rmi://127.0.0.1/AddServer";

            // lookup method finds the reference of remote object
            AddSum remoteObject = (AddSum)Naming.lookup(serverurl);

            s = new Scanner(System.in);

            System.out.println("Enter first number: ");
            double num1 = s.nextDouble();

            System.out.println("Enter second number: ");
            double num2 = s.nextDouble();

            // calling the remote method
            while (true) {
                System.out.println("-------Enter the operation you want to perform-------");
                System.out.println("1.Add \t2.Substract\t3.Multiply\t4.Divide\t5.Exit");
                int ch = s.nextInt();

                switch (ch) {
                    case 1:
                        System.out.println("The Sum is: " + remoteObject.addNum(num1, num2));
                        break;
                    case 2:
                        System.out.println("The Difference is: " + remoteObject.subNum(num1, num2));
                        break;
                    case 3:
                        System.out.println("The Multiply is: " + remoteObject.mulNum(num1, num2));
                        break;
                    case 4:
                        System.out.println("The Division is: " + remoteObject.divNum(num1, num2));
                        break;
                    case 5:
                        System.exit(0);
                        break;
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            s.close();
        }
    }
}