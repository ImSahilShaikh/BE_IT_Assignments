import java.util.*;
public class prac2 {
public void divide(int a,int b)
{
	try
	{
		int c=a/b;
		System.out.print("INFO: Division of the numbers is: "+c);
	}
	catch(Exception e)
	{
		System.out.print("WARNING: Divide by 0 exception!!");
	}
}
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		prac2 obj=new prac2();
		Scanner sc=new Scanner(System.in);
		System.out.println("\nINFO: Enter first number");
		int x=sc.nextInt();
		System.out.println("\nINFO: Enter second number");
		int y=sc.nextInt();
		obj.divide(x, y);
		System.out.println("\nINFO: This statement comes after execution of try-catch");
		System.out.println("\nThis shows that even after exception, the program execution is continued because we have handled the exception properly");
	}

}
