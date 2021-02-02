import java.io.*;
import java.net.*;
import java.util.*;


public class Server {
    public static void main(String[] args) throws Exception {

        ServerSocket serverSocket = new ServerSocket(1555);
        System.out.println("Waiting for Client to Connect..");

        Socket socket = null;
        while (true) {
            socket = serverSocket.accept();
            System.out.println("New Member added to groupchat");

            ArrayList<ClientHandler> activeClients = new ArrayList<>();

            ClientHandler clientHandler = new ClientHandler(socket, activeClients);
            activeClients.add(clientHandler);
            clientHandler.start();
        }

    }
}

class ClientHandler extends Thread {
    ArrayList<ClientHandler> activeClients;
    Socket socket;
    PrintWriter message;

    public ClientHandler(Socket socket, ArrayList<ClientHandler> activeClients) {
        this.socket = socket;
        this.activeClients = activeClients;
    }

    public void run() {
        try {
            System.out.println("New thread created");

            BufferedReader receive = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            message = new PrintWriter(socket.getOutputStream(), true);

            while (true) {
                String readMessage = receive.readLine();

                if (readMessage.equalsIgnoreCase("exit")) {
                    break;
                }

                for (ClientHandler i : activeClients) {
                    i.message.println(readMessage);
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
