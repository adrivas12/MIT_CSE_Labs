import java.util.Scanner;

class q2
{
	public static void main(String[] args)
	{
		double a, b, c, d, x, y;
		System.out.println("Enter a, b and c");
		Scanner sc = new Scanner(System.in);
		a = sc.nextDouble();
		b = sc.nextDouble();
		c = sc.nextDouble();
		d = b*b - 4*a*c;
		int g = -1;
		if(d==0)
			g = 0;
		else if (d>0)
			g = 1;
		else if (d<0)
			g = 2;


		switch(g)
		{
		case 0:
			System.out.println("The root is real and equal");
			x = -b/(2*a);
			System.out.println(x + " is the root");
			break;
		case 1:
			System.out.println("The root is real and distinct");
			x = (-b + Math.sqrt(d))/(2*a);
			y = (-b - Math.sqrt(d))/(2*a);
			System.out.println(x + " is root number 1");
			System.out.println(y + " is root number 2");
			break;
		case 2: 
			System.out.println("The roots are imaginary and complementary");
			break;
		}
	}
}
	
