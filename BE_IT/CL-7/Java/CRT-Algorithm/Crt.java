import java.util.*;

class Crt
{
    int findXi(int Ni,int ni)
    {
        int i=1;
        while((Ni*i) % ni != 1)
        {
            i++;
        }
        return i;
    }
    public static void main(String args[]) throws Exception
    {
        Crt c = new Crt();
        ArrayList<Integer> b = new ArrayList<Integer>(Arrays.asList(2,3,1));
        ArrayList<Integer> n = new ArrayList<Integer>(Arrays.asList(3,4,5));

        if(b.size() != n.size())
        {
            throw new Exception("Please enter valid values for b and n");
        }

        int N = 1;

        for(int i=0; i<n.size();i++)
        {
            N *= n.get(i);
        }
        System.out.println("Value of N is: "+N);

        ArrayList<Integer> Ni = new ArrayList<Integer>();
        for(int i=0;i<n.size();i++)
        {
            int temp = N/n.get(i);
            Ni.add(temp);
        }
        System.out.println("The values of Ni are: "+Ni);

        ArrayList<Integer> Xi = new ArrayList<Integer>();
        for(int i=0;i<Ni.size();i++)
        {
            int xi = c.findXi(Ni.get(i),n.get(i));
            Xi.add(xi);
        }
        System.out.println("The values of Xi are: "+Xi);

        ArrayList<Integer> biNiXi = new ArrayList<>();
        for(int i=0;i<Ni.size();i++)
        {
            int temp = b.get(i) * Ni.get(i) * Xi.get(i);
            biNiXi.add(temp);
        }
        System.out.println("The values of biNiXi are: "+biNiXi);

        int bnx=0;
        for(int i=0;i<biNiXi.size();i++)
        {
            bnx += biNiXi.get(i);
        }
        System.out.println("Total of biNiXi is: "+bnx);

        int X = bnx % N;

        System.out.println("X is: "+X);
    }
}
