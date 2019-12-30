//Addition of two numbers using scanner
import java.util.*;
public class prac0 {
	public static void main (String args[])
	{
		int a,b;
		@SuppressWarnings("resource")
		Scanner sc=new Scanner(System.in);
		System.out.println("\nINFO: Enter two numbers");
		a=sc.nextInt();
		b=sc.nextInt();
		int c=a+b;
		System.out.println("INFO: 2Addition of entered numbers is: "+c);
	}
}
