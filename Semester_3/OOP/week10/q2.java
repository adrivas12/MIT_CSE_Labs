import java.util.*;

class Stack<T>
{
	ArrayList<T> arr;
	int tos;
	int size;
	T x;
	Stack(int size)
	{
		tos=-1;
		this.size=size;
		arr=new ArrayList<T>(size);
	}
	void push(T ele)
	{
		if(tos==size-1)
		{
			System.out.println("Stack overflow");
			return;
		}			
		arr.add(ele);
		tos++;
	}
	T pop()
	{
		if(tos==-1)
		{
			System.out.println("Stack Underflow");
			return x;
		}
		return arr.remove(tos--);
	}
	void display()
	{
		for(int i = 0; i<=tos; i++)
		{
			System.out.println(arr.get(i).toString());
		}
	}
}
class Student
{
	String name;
	int rollnum, grade;
	Student(String name, int rollnum, int grade)
	{
		this.name=name;
		this.rollnum=rollnum;
		this.grade=grade;
	}
	public String toString()
	{
		String t="Name: "+name+"\nRoll number: "+rollnum + "\nGrade: "+grade;
		return t;
	}
}
class Employee
{
	String name; 
	int empid;
	Employee(String name, int empid)
	{
		this.name=name;
		this.empid=empid;
	}
	public String toString()
	{
		String t="Name: "+name+"\nEmployee id: "+empid;
		return t;
	}
}
class q2
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the size of the stack: ");
		int size=sc.nextInt();
		Stack<Student> ob1=new Stack<Student>(size);
		Stack<Employee> ob2=new Stack<Employee>(size);
		Student ss1=new Student("Aditi", 44, 9);
		Student ss2=new Student("Adi", 69, 8);
		Employee ee1=new Employee("ron", 234);
		Employee ee2=new Employee("rob", 679);
		ob1.push(ss1);
		ob1.push(ss2);
		ob2.push(ee1);
		ob2.push(ee2);
		ob1.display();
		ob2.display();
	}
}