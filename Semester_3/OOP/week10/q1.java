import java.util.*;

class q1
{

	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		Integer arr[]={1, 2, 3, 4};
		display(arr);
		System.out.println("Enter position 1 and 2 that you want to exchange: ");
		int pos1=sc.nextInt();
		int pos2=sc.nextInt();
		exchange(arr, pos1, pos2);

	}
	static <T> void display(T arr[])
	{
		for(T ele:arr)
			System.out.println( ele);

	}
	static <T> void exchange(T arr[], int pos1, int pos2)
	{
		T temp1;		
		temp1=arr[pos1];
		arr[pos1]=arr[pos2];
		arr[pos2]=temp1;
		System.out.println("Swapped array: ");
		display(arr);
	}
}