//Method overloading
import java.util.*;
public class prac1 extends a{
	public void print(int a)
	{
		System.out.println("\nINFO: This is class prac1 with argument passed: "+a);
	}
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x;
		System.out.println("\nINFO: Enter argument to be passed in print method with one argument");
		Scanner sc=new Scanner(System.in);
		x=sc.nextInt();
		prac1 p=new prac1();
		a p1=new a();
		p.print(x);
		p1.print();
		p.print();
	}

}
class a
{
	public void print()
	{
	System.out.println("\nINFO: This is class a with no argument");
	}
}
