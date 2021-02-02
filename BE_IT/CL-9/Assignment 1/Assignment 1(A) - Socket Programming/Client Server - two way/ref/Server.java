import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Server {

    public static void main(String[] args) {
        try{
            
            ServerSocket sersocket = new ServerSocket(25000);
            System.out.println("Server started and listening to port 25000\n");
            
            Socket socket = sersocket.accept();
            System.out.println("Connection Established between client and server\n");

            //Reading from Client
            DataInputStream clientin = new DataInputStream(socket.getInputStream());
            
            //Writing to Client
            DataInputStream din = new DataInputStream(System.in);

            //Send written message to client
            DataOutputStream clientout = new DataOutputStream(socket.getOutputStream());

            //incoming message from client
            String clientmessage = "";

            //message to be sent from server
            String servermessage = ""; 

            while(!servermessage.equals("bye"))
            {
                clientmessage = clientin.readUTF();
                System.out.println("Client: "+clientmessage);

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
                System.out.print("Server: ");
                servermessage = din.readLine();
                clientout.writeUTF(servermessage);
            }
            sersocket.close();
            socket.close();
            clientin.close();
            clientout.close();
            din.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}