import java.io.*;
import java.net.*;
import java.util.*;


public class Client {

    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("127.0.0.1", 1555);

        BufferedReader recieve = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        PrintWriter pr = new PrintWriter(socket.getOutputStream(), true);

        Scanner sc = new Scanner(System.in);
        String clientMessage = "";
        String username;

        System.out.print("Enter Your name: ");
        username = sc.nextLine();

        ServerHandler serverHandler = new ServerHandler(socket, username);
        serverHandler.start();

        while (true) {
            clientMessage = sc.nextLine();
            if (!clientMessage.equalsIgnoreCase("exit"))
            {
                pr.println(username + ": " + clientMessage);
            }
        }
    }
}

class ServerHandler extends Thread {
    Socket socket;
    String username;

    ServerHandler(Socket socket, String username) {
        this.socket = socket;
        this.username = username;
    }

    public void run() {
        try {
            while (true) {
                BufferedReader recieve = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                String message = recieve.readLine();

                if (!message.startsWith(username))
                    ;
                {
                    System.out.println(message);
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
