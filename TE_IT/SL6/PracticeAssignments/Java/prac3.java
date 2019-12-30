//Demonstration of Constructor Overloading
public class prac3 {

	prac3()
	{
		System.out.println("\nINFO: This is default constructor!!!");
	}
	prac3(int a)
	{
		System.out.println("INFO: This is constructor with one argument!!");
	}
	prac3(int a, int b)
	{
		System.out.println("INFO: This is constructor with two arguments!");
	}
	@SuppressWarnings("unused")
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a=10,b=120;
		prac3 obj1=new prac3();
		prac3 obj2=new prac3(a);
		prac3 obj3=new prac3(a,b);
	}

}
