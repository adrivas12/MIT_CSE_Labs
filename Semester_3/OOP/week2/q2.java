import java.util.Scanner;

class q2
{
	
	public static void main(String[] args)
	{
		int i, n, p1, ele;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the length of the array ");
		n = sc.nextInt();
		int[] arr = new int[n+1];
		System.out.println("Enter the elements of the array: ");
		for( i =0; i<n; i++)
		{
			arr[i] = sc.nextInt();
		}
		System.out.println("Enter the element you want to input: ");
		ele = sc.nextInt();
		arr[n] = ele;
		System.out.println("The array after inserting the elements: ");
		for(i = 0; i<n; i++)
		{
			System.out.println(arr[i] + " ");
		}
		System.out.println(arr[n]);

		System.out.println("Enter the position you want to delete: ");
		p1 = sc.nextInt();

		for( i = p1; i<n-1; i++)
		{
			arr[i] = arr[i+1];
		}
		n--;
		System.out.println("The array after deletion: ");
		for(i = 0; i<n; i++)
		{
			System.out.println(arr[i] + " ");
		}
		//--n;
		///System.out.println("The array after deletion: ");
		//for(i = 0; i<n-1; i++)
		//{
		//	System.out.println(arr[i] + " ");
		//}
	}
}