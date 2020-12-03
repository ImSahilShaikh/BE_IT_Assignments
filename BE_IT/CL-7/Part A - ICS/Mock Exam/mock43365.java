import java.util.*;
class mock43365
{
    static int findXi(int Ni,int ni)
    {
        int i = 1;
        while((Ni*i) % ni != 1){
            i++;
        }
        return i;
    }
    public static void main(String ar[]) throws Exception
    {
        System.out.println("Chinese remainder equation:\n----------------\nx=bi mod ni\n----------------\n");
        Scanner s = new Scanner(System.in);

        ArrayList<Integer> b = new ArrayList<>();
        System.out.println("Enter 3 Numbers of b");
        for(int i=0;i<3;i++)
        {
            int x = s.nextInt();
            b.add(x);
        }

        ArrayList<Integer> n = new ArrayList<>();
        System.out.println("Enter 3 Numbers of b");
        for(int i=0;i<3;i++)
        {
            int x = s.nextInt();
            n.add(x);
        }
        
        int N = 1;
        for(int temp : n)
        {
            N *= temp;
        }
        System.out.println("\n--------\nN = n1 * n2 * n3\n--------");
        System.out.println("Value of N is:"+N);

        ArrayList<Integer> Ni = new ArrayList<>();
        System.out.println("\n--------\nNi= N/ni\n--------");
        for(int temp : n)
        {
            Ni.add(N/temp);
        }
        System.out.println("\nThe values of Ni are: "+Ni);

        ArrayList<Integer> Xi = new ArrayList<>();
        for(int i=0;i<Ni.size();i++)
        {
            int xi = findXi(Ni.get(i), n.get(i));
            Xi.add(xi);
        }
        System.out.println("The values of Xi are: "+Xi);

        ArrayList<Integer> biNiXi = new ArrayList<>();
        for(int i=0;i<Ni.size();i++)
        {
            int temp = b.get(i) * Ni.get(i) * Xi.get(i);
            biNiXi.add(temp);
        }
        System.out.println("\nThe values of biNiXi are: "+biNiXi);

        int bnx=0;
        for(int i=0;i<biNiXi.size();i++)
        {
            bnx += biNiXi.get(i);
        }
        System.out.println("\nTotal of biNiXi is: "+bnx);
        int X = bnx % N;

        System.out.println("\nX is: "+X);
        s.close();
    }
}