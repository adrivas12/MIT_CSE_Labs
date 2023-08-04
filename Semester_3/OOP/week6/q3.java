import java.util.*;

abstract class Figure
{
	int dim1, dim2, dim3;
	abstract public double area(int dim1, int dim2, int dim3);
}
class Rectangle extends Figure
{
	public double area(int length, int breath, int dim3)
	{
		return (length*breath);
	}
}
class Triangle extends Figure
{
	public double area(int a, int b, int c)
	{
		double s = (a+b+c)/2.00;
		return (Math.pow((s*(s-a)*(s-b)*(s-c)),0.5));
	}
}
class Square extends Figure
{
	public double area(int side, int dim2, int dim3)
	{
		return (side*side);
	}
}

class q3
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Figure r1 = new Rectangle();
		Figure t1 = new Triangle();
		Figure s1 = new Square();
		System.out.println("Enter the length of the reactangle: ");
		int len = sc.nextInt();
		System.out.println("Enter the breath of the rectangle: ");
		int breath = sc.nextInt();
		System.out.println("The area of the rectangle is: " + r1.area(len, breath,0));
		System.out.println("\n\nEnter the sides of the triangle: ");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		System.out.println("The area of the triangle is: " + t1.area(a, b, c));
		System.out.println("\n\nEnter the side of the square: ");
		int side = sc.nextInt();
		System.out.println("The area of the square is: " + s1.area(side, 0, 0));
	}
}