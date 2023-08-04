import java.util.*;

class Person
{
	private String name;
	private String dob;
	public String getname(String name)
	{
		return name;
	}
	public String getdob(String dob)
	{
		return dob;
	}
}
class CollegeGraduate extends Person 
{
	private double gpa;
	private String yog;
	public CollegeGraduate()
	{
		gpa = 0.0;
		yog = null;
	}
	public double getGPA(double gpa)
	{
		return gpa;
	}
	public String getyog(String yog)
	{
		return yog;
	}
}

class q1
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Calendar calendar = Calendar.getInstance();
		System.out.println("Enter name: ");
		String name1= sc.next();
		System.out.println("Enter Birthday(dd/mm/yyyy): ");
		String dob1 = sc.next();
		System.out.println("Enter GPA: ");
		double gpa1 = sc.nextDouble();
		System.out.println("Enter year of graduation: ");
		String yog1 = sc.next();
		CollegeGraduate cg = new CollegeGraduate();
		System.out.println("Name: " + cg.getname(name1) + 
							"\nBirthday: " + cg.getdob(dob1)+
							"\nGPA: "+cg.getGPA(gpa1)+
							"\nYear of Graduation: "+cg.getyog(yog1));
	}
}