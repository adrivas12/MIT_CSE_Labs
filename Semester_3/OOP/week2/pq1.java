import java.util.Scanner;

class pq1
{
	public static void main(String args[])
	{
		int n, c;
		Scanner sc = new Scanner(System.in);
		System.out.println("Input number of integers");
		n = sc.nextInt();
		int array[]= new int[n];
		System.out.println("Enter " + n + " integers");
		for(c = 0; c<n; c++)
			{
				array[c]=sc.nextInt();
			}
		System.out.println("The array is: ");
		for(c = 0; c<n; c++)
			System.out.println(array[c]);

	}	
}