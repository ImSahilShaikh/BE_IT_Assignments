import java.util.*;

public class Ring{

    ArrayList<Integer> processId;
    boolean processes[];
    int coordinator;
    int no_process;
    int no;

    public Ring(int no_process)
    {
        processId = new ArrayList<Integer>();
        coordinator = no_process;
        processes = new boolean[no_process];
        
        System.out.println("Creating processes...");
        for(int i=0;i<no_process;i++)
        {
            System.out.println("Process P["+(i+1)+"] created");
            processes[i] = true;
        }
        
        this.no_process = no_process;
        System.out.println("Coordinator Process: "+ this.coordinator);
    }

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

    void downProcess(int no){
        if(!processes[no-1])
        {
            System.out.println("Process P["+no+"] is already down");
        }
        else
        {
            processes[no-1] = false;
            System.out.println("Process P["+no+"] is now down");
        }
    }

    void showCurrentCoordinator()
    {
        System.out.println("Process P["+coordinator+"] is the current Coordinator");
    }

    void startElection(int no)
    {
        if(processes[no-1])
        {
            processId.add(no);
            int i = no;

            System.out.print("Process P["+no+"] sending following list: [");

            for(Integer n : processId)
            {
                System.out.print(n + " ");
            }
            System.out.print("]");
            System.out.println("");
            while(i != no-1)
            {
                if(processes[i]){
                    processId.add(i+1);
                    System.out.print("Process P["+no+"] sending following list: [");

                    for(Integer n : processId)
                    {
                        System.out.print(n + " ");
                    }
                    System.out.print("]");
                    System.out.println("");
                }
                else
                    System.out.println("Process P["+(i+1)+"] is down");
                
                i = (i+1) % no_process;
            }
            int new_coordinator = Collections.max(processId);
            System.out.println("Process P["+no+"] declares P["+new_coordinator+"] as new Coordinator");
            coordinator = new_coordinator;
            processId.clear();
        }
        else
            System.out.println("Process P["+no+"] is down, cannot initiate election");
    }
    
    public static void main(String[] args) {
        int choice = 0;
        int process_number = 0;
        Ring r = null;
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
                    r = new Ring(no_process);
                    break;
            
                case 2:
                    r.showActiveProcesses();
                    break;

                case 3:
                    r.showCurrentCoordinator();
                    break;

                case 4:
                    System.out.println("Enter number of the process to be taken down: ");
                    process_number = sc.nextInt();
                    r.downProcess(process_number);
                    break;

                case 5:
                    System.out.println("Enter which process will initiate the election: ");
                    process_number = sc.nextInt();
                    r.startElection(process_number);
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