import java.util.Scanner;

class q1
{
	static void asc(int arr1[], int n)
	{
		int i, j; 
		for(i =0; i<n; i++)
		{
			for(j =0; j<n-i-1; j++)
			{
				if(arr1[j]>arr1[j+1])
				{
					arr1[j] = arr1[j] + arr1[j+1];
					arr1[j+1] = arr1[j] - arr1[j+1];
					arr1[j] = arr1[j] - arr1[j+1];
				}
			}
		}
		System.out.println("The array in ascending order is : \n");
		for(i = 0; i<arr1.length; i++)
		{
			System.out.println(" " + arr1[i]);
		}
	}

	static void dsc(int arr1[], int n)
	{
		int j, i; 
		for(i = 0; i<n; i++)
		{
			for(j = 0; j<n-i-1; j++)
			{
				if (arr1[j]<arr1[j+1])
				{
					arr1[j] = arr1[j] + arr1[j+1];
					arr1[j+1] = arr1[j] - arr1[j+1];
					arr1[j] = arr1[j] - arr1[j+1];
				}
			}
		}
		System.out.println("The array in descending order is: \n");
		for(i = 0; i<arr1.length; i++)
		{
			System.out.println(" " + arr1[i]);
		}
	}
	public static void main(String[] args)
	{
		int n,i;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements");
		n = sc.nextInt();
		int[] arr1 = new int[n];
		System.out.println("Enter " + n + " numbers");
		for(i =0; i<n; i++)
		{
			arr1[i] = sc.nextInt();
		}
		asc(arr1, n);
		dsc(arr1, n);
	}
} 