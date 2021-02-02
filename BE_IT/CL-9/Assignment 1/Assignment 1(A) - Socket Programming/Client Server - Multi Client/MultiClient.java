/*
Name: Sahil A. Shaikh
Roll no: 43365
PS: MutliClient Communication 
*/

import java.net.*;
import java.io.*;
import java.util.*;

public class MultiClient {
	
	//Name variable for name of User
	static String name;
	
	//use volatile keyword to be able to change the value of variable using different threads
	static volatile boolean finished = false;

	public static void main(String[] args) throws Exception {
		
		// Use Class D IP Address since they are multicast ip's
		InetAddress group = InetAddress.getByName("225.0.0.0");
		
		// port number
		int port = 5555;

		//Scanner object for console inputs
		Scanner sc = new Scanner(System.in);
		
		//Taking userinput for name
		System.out.print("Enter your name: ");
		name = sc.nextLine();

		//Create a multicast socket binded with specified port number
		MulticastSocket socket = new MulticastSocket(port);

		socket.joinGroup(group);
		Thread t = new Thread(new ReadThread(socket, group, port));

		// Create a thread for reading messages
		t.start();

		// sent to the current group
		System.out.println("Entered in the Chatroom\n");
		while (true) 
		{
			//Writing a message to send on a group
			String message;
			message = sc.nextLine();

			//if message is exit, then leave the group chat
			if (message.equalsIgnoreCase("Exit")) 
			{
				finished = true;
				socket.leaveGroup(group);
				socket.close();
				break;
			}
			//appending name to message for sending on the group
			message = name + ": " + message;

			//to send the message using udp, converting it into byte array
			byte[] buffer = message.getBytes();
			
			//Preparing datagram packet of the typed message
			DatagramPacket datagram = new DatagramPacket(buffer, buffer.length, group, port);
			
			//sending the datagram packet on the multicast socket where group is binded
			socket.send(datagram);
		}
		//closing scanner
		sc.close();
	}
}

//A Thread Class to read the recieved datagram packet at any instant
class ReadThread extends Thread 
{
	// all the required variables
	private MulticastSocket socket;
	private InetAddress group;
	private int port;
	private static final int MAX_LEN = 1000;

	//Initialising all the local variables using constructor
	ReadThread(MulticastSocket socket, InetAddress group, int port) {
		this.socket = socket;
		this.group = group;
		this.port = port;
	}

	public void run() 
	{
		//read only if the user has not exited the group
		while (!MultiClient.finished) 
		{
			byte[] buffer = new byte[ReadThread.MAX_LEN];
			DatagramPacket datagram = new DatagramPacket(buffer, buffer.length, group, port);
			String message;
			try 
			{
				//recieving all the datagram packet sent over the multicast socket
				socket.receive(datagram);

				//converting the datagram packet into readable string format
				message = new String(buffer, 0, datagram.getLength(), "UTF-8");

				//print the recieved packet only if the sender is not the user itself
				if (!message.startsWith(MultiClient.name))
					System.out.println(message);
			}
			catch (IOException e) 
			{
				System.out.println("Socket closed!");
			}
		}
	}
}