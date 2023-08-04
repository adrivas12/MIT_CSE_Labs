import java.util.*;

class List<T>
{
	LinkedList<T> list;
	List()
	{
		list = new LinkedList<T>();
	}
	void insertlast(T ele)
	{
		list.addLast(ele);
	}
	void insertfront(T ele)
	{
		list.addFirst(ele);
	}
	T deletelast()
	{
		return list.removeLast();
	}
	T deletefront()
	{
		return list.removeFirst();
	}
	void display()
	{
		for(T ele:list)
		{
			System.out.println(ele);
		}
		System.out.println();
	}
}
class q3
{
	public static void main(String[] args)
	{
		List<Integer> ob1=new List<Integer>();
		List<Double> ob2= new List<Double>();
		ob1.insertlast(1);
		ob1.insertlast(2);
		ob1.insertfront(4);
		ob1.display();
		ob2.insertlast(2.5);
		ob2.insertfront(3.4);
		ob2.insertlast(3.5);
		ob2.display();
		System.out.println("Deleted last element: ");
		System.out.println("L1: "+ob1.deletelast()+"\nL2: "+ob2.deletelast()+"\n\n");
		ob1.display();
		ob2.display();
	}
}