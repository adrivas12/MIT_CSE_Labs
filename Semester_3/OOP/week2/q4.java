import java.util.Scanner;

class q4
{
	public static void main(String args[])
	{
		int r, c, i, j;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the rows of matrices");
		r = in.nextInt();
		System.out.println("Enter the columns of matrices");
		c = in.nextInt();
		int array1[][] = new int[r][c];
		int array2[][] = new int[r][c];
		System.out.println("Enter the integers of matrix 1");
		for(i = 0; i<r; i++)
		{
			for(j = 0; j<c; j++)
			{
				array1[i][j] = in.nextInt();
			}
		}
		System.out.println("Enter the integers of matrix 2");
		for( i = 0; i<r; i++)
		{
			for(j= 0; j<c; j++)
			{
				array2[i][j] = in.nextInt();
			}
		}
		int add[][] = new int[r][c];
		System.out.println("The sum of the two matrices is ");
		for( i = 0; i<r; i++)
		{
			for(j = 0; j<c ; j++)
			{
				add[i][j] = array1[i][j] + array2[i][j];
				
			}
		}
		for( i = 0; i<r; i++)
		{
			for(j = 0; j<c; j++)
			{
				System.out.println(add[i][j]);
			}
		}
	}
}