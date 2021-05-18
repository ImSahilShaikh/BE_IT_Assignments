import java.util.*;

public class Bully{

    boolean processes[];
    int no_process;
    int coordinator;

    public Bully(int no)
    {
        no_process = no;
        processes = new boolean[no];
        coordinator = no;

        System.out.println("Creating processes...");
        for(int i=0;i<no_process;i++)
        {
            System.out.println("Process P["+(i+1)+"] created");
            processes[i] = true; //default value of newly created process is true so that it will be active
        }
        System.out.println("Coordinator Process: "+ this.coordinator);
    }

    //Method to display all active processes
    void showActiveProcesses()
    {
        System.out.println("The active processes are: ");
        {
            for(int i=0;i<processes.length;i++)
            {
                if(processes[i])
                {
                    System.out.print("P["+(i+1)+"]\t");
                }
            }
            System.out.println("");
        }
    }

    //Method to take down a process i.e make that process inactive
    void downProcess(int no){
        //if already down
        if(!processes[no-1])
        {
            System.out.println("Process P["+no+"] is already down");
        }
        //else set process no inactive
        else
        {
            processes[no-1] = false;
            System.out.println("Process P["+no+"] is now down");
        }
    }

    //Method to show the current coordinator process
    void showCurrentCoordinator()
    {
        System.out.println("Process P["+coordinator+"] is the current Coordinator");
    }

    void startElection(int no)
    {
        no = no - 1;
        coordinator = no + 1;
        for(int i=0;i<no_process;i++)
        {
            if(no < i)
            {
                System.out.println("Election message is sent from P["+(no+1)+"] to P["+(i+1)+"]");
                if(processes[i])
                {
                    startElection(i+1);
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Bully b = null;
        int process_number = 0;
        int choice = 0;
        Scanner sc = new Scanner(System.in);

        do{

            System.out.println("MENU");
            System.out.println("1. Create Processes");
            System.out.println("2. Show Active Processes");
            System.out.println("3. Show Current Coordinator");
            System.out.println("4. DOWN a process");   
            System.out.println("5. Send Election Message");         
            System.out.println("6. Exit");
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter number of processes to be created: ");
                    int no_process = sc.nextInt();
                    b = new Bully(no_process);
                    break;
            
                case 2:
                    b.showActiveProcesses();
                    break;

                case 3:
                    b.showCurrentCoordinator();
                    break;

                case 4:
                    System.out.println("Enter number of the process to be taken down: ");
                    process_number = sc.nextInt();
                    b.downProcess(process_number);
                    break;

                case 5:
                    System.out.println("Enter which process will initiate the election: ");
                    process_number = sc.nextInt();
                    b.startElection(process_number);
                    b.showCurrentCoordinator();
                    break;

                case 6:
                    break;

                default:
                    System.out.println("Please select valid option");
                    break;
            }

        }while(choice!= 6);

    }
}