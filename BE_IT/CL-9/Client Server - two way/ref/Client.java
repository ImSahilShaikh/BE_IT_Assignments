import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Client {
    public static void main(String args[]) {
        try{

            //Create socket to establish connection with server
            Socket s = new Socket("127.0.0.1",25000);

            //Writing to server
            DataInputStream din = new DataInputStream(System.in);

            //Send written message to Client 
            DataOutputStream serverout = new DataOutputStream(s.getOutputStream());
            
            DataInputStream serverin = new DataInputStream(s.getInputStream());

            //Message to be sent to server
            String clientmessage = "";
            
            //Message recieved from Server
            String servermessage = "";

            while(!servermessage.equals("bye"))
            {
                System.out.print("Client: ");
                clientmessage = din.readLine();
                serverout.writeUTF(clientmessage);
                
                String ans ="";

                if(clientmessage.equals("bye"))
                {
                    System.out.println("Do you wish to end the conversation?(Y/N)");
                    Scanner sc = new Scanner(System.in);
                    ans = sc.next();
                    if(ans=="y" || ans=="Y")
                    {
                        break;
                    }
                }

                servermessage = serverin.readUTF();
                System.out.println("Server: "+servermessage);
            }

            s.close();
            serverout.close();
            serverin.close();
            din.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}