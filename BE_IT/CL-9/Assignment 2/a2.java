/* 
Name: Sahil Shaikh
Roll no: 43365
PS: Basic Illustration of Message passing interface
*/

import mpi.*;

public class a2 {
    public static void main(String ar[]) {
        
        //Initialize the MPI: uses argument given in console (number of processes), which creates a communicator which encloses all the processes
        MPI.Init(ar);
        
        //size of communicator: total number of processes inside the communicator
        int size = MPI.COMM_WORLD.Size();
        //rank: a unique number for each process
        int rank = MPI.COMM_WORLD.Rank();

        System.out.println("Rank of process: "+rank);


        //Finalize MPI: cleans the mpi environment so that no mpi calls can be made after this
        MPI.Finalize();
    }
}
