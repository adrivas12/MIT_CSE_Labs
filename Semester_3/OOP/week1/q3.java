import java.util.Scanner;

class q3
{
	static int fact(int n)
	{
		int i;
		int f = 1;
		for(i = 1; i<n-1; i++)
		{
			f*=i;
		}
		return f;
	}
	public static void main(String[] args)
	{
		int n, r;
		System.out.println("Enter n and r");
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		r = sc.nextInt();
		System.out.println(fact(n) +" is the factorial");
		int ncr = fact(n)/(fact(r)*fact(n-r));
		System.out.println(ncr + " is ncr");
	}
}