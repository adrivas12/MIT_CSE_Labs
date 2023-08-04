import java.util.Scanner;

class q3
{
	static void Lsearch(int arr[], int n, int ele )
	{
		int i, flag=0; 
		for(i = 0; i<n; i++)
		{
			if(arr[i] == ele)
			{
				//printf("%d", i);
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			System.out.println("Element found at position" +  i);
		else 
			System.out.printf("Element not found");
	}

	public static void main(String[] args)
	{
		int n, i, ele;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements: ");
		n = sc.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter the elements of the array: \n");
		for(i = 0; i<n; i++)
		{
			arr[i] = sc.nextInt();
		}
		System.out.println("Enter the element to be found: ");
		ele = sc.nextInt();
		Lsearch(arr, n, ele);
	}
}