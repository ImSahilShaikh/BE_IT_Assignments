/* 
Name: Sahil Shaikh
Roll no: 43365
PS: Message passing interface Application to send a array of number to processes and get square of them.
*/

import mpi.*;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;


public class Assignment2 {
    public static void main(String[] args) {
        
        //Initializing the MPI Environment
        MPI.Init(args);

        //size of communicator: total number of processes inside the communicator
        int size = MPI.COMM_WORLD.Size();

        //rank: a unique number for each process
        int rank = MPI.COMM_WORLD.Rank();

        //the rank of root process will always be 0
        int root = 0;

        //creating array which will consist the data to be sent using mpi
        int send[] = new int[size];

        //the root process will consist of full array which we want to send;
        if(rank == root)
        {
            System.out.println("Enter the number to be sent: ");
            send[0] = 1;
            send[1] = 2;
            send[2] = 3;
            send[3] = 4;
            send[4] = 5;
        }

        int receive[] = new int[1];

        //scatter operation shares the data of root to all other processes of communicator
        //Scatter(senddata,start,end,datatype,receivingtargetdata,start,end,datatype,source process)
        
        long starttime = System.nanoTime();
        
        MPI.COMM_WORLD.Scatter(send,0,1,MPI.INT,receive,0,1,MPI.INT,root);

        //printing which process has what data
        System.out.println("Process ["+rank+"] has data: "+receive[0]);
        //squaring the numbers
        
        receive[0] = receive[0] * receive[0];

        //gather operation is inverse of the scatter, takes the data from where they recieved and sends back to root process
        //Gather(receivingtargetdata,start,end,datatype,send,start,end,datatype,source process)
        MPI.COMM_WORLD.Gather(receive,0,1,MPI.INT,send,0,1,MPI.INT,root);

        long elapsedtime = System.nanoTime() - starttime;

        System.out.println("Time required to perform squaring task for process["+rank+"]: "+(elapsedtime/1000000)+"ms");
        
        //displaying the data contained by root process after gather operation
        if(rank == root)
        {
            System.out.println("The root ["+rank+"] process with squared numbers: ");
            for(int i: send)
            {
                System.out.print(i+"\t");
            }
        }

        //Finalize MPI: cleans the mpi environment so that no mpi calls can be made after this
        MPI.Finalize();
    }
}