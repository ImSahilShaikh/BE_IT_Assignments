/* 
Name: Sahil Shaikh
Roll no: 43365
PS: Message passing interface Application to send a array of number using file to processes and get square of them.
*/

import mpi.*;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.concurrent.TimeUnit;

public class Assignment2_file {
    public static void main(String[] args) {

        //Initializing the MPI Environment
        MPI.Init(args);

        //Object of file to get input
        File file;

        //Scanner to read the file
        Scanner sc= null;

        //all the required variables
        int root = 0;
        int data_size = 0;
        int chunk = 0;
        int send_buffer[];

        //size of communicator: total number of processes inside the communicator
        int size = MPI.COMM_WORLD.Size();

        //rank: a unique number for each process
        int rank = MPI.COMM_WORLD.Rank();

        try {

            //reading input.txt
            file = new File("./input.txt");
            sc = new Scanner(file);

            // file consists of data size on first line 
            data_size = sc.nextInt();

        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("File not found");
            System.exit(0);
        }

        //creating a int buffer array of size data_size
        send_buffer = new int[data_size];

        //creating chunk size to scatter on processes
        chunk = data_size / size;

        //the root process will consist of full array which we want to send;
        if (rank == root) {
            try {
                int counter = 0;

                //inserting numbers onto array
                while (sc.hasNextInt() && counter < data_size) {
                    send_buffer[counter++] = sc.nextInt();
                    // System.out.println("sendbuffer["+counter+"]"+send_buffer[counter]);
                }
            } catch (Exception e) {
                // TODO: handle exception
                System.out.println(e);
            }

            //showing sendbuffer
            // System.out.println("Data to be scattered by process " + rank + ": ");
            // for (int i = 0; i < data_size; i++) {
            //     System.out.println(send_buffer[i] + " ");
            // }
            // System.out.println();
        }

        //creating recieving buffer for processes to recieve all the scattered data
        int recieve_buffer[] = new int[chunk];

        //for time calculation using nanoTime method
        long starttime = System.nanoTime();

        //scatter operation shares the data of root to all other processes of communicator
        //Scatter(senddata,start,end,datatype,receivingtargetdata,start,end,datatype,source process)
        MPI.COMM_WORLD.Scatter(send_buffer,0,chunk,MPI.INT,recieve_buffer,0,chunk,MPI.INT,root);

        //printing which process has what data
        for(int i=0;i<chunk;i++)
        {
            //System.out.println("Process "+rank+" squaring "+recieve_buffer[i]);

            //Calculation square of the data
            recieve_buffer[i] = recieve_buffer[i] * recieve_buffer[i] * recieve_buffer[i] * recieve_buffer[i] * recieve_buffer[i] * recieve_buffer[i];
        }
        System.out.println();

        //gather operation is inverse of the scatter, takes the data from where they recieved and sends back to root process
        //Gather(receivingtargetdata,start,end,datatype,send,start,end,datatype,source process)
        MPI.COMM_WORLD.Gather(recieve_buffer,0,chunk,MPI.INT,send_buffer,0,chunk,MPI.INT,root);

        //calling nanoTime method again and substracting starttime from it to get elapsed time
        

        //displaying the data contained by root process after gather operation
        if(rank == root)
        {
            // System.out.println("The root ["+rank+"] process with squared numbers: ");
            // for(int i: send_buffer)
            // {
            //     System.out.print(i+"\t");
            // }
            long elapsedtime = System.nanoTime() - starttime;

        //displaying elapsed time by each process
        System.out.println("Time required to perform squaring task for process["+rank+"]: "+(elapsedtime/1000000)+"ms");
        }

        //Finalize MPI: cleans the mpi environment so that no mpi calls can be made after this
        MPI.Finalize();
    }
}
