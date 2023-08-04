import java.util.Scanner;

class aq1
{
	static int findSum(int n)
	{
		int sum = 0, rem;
		while(n>0){
			rem = n%10;
			sum += rem;
			n = n/10;
		}
		return sum;
	}

	public static void main(String[] args)
	{
		int n, ans; 
		System.out.println("Enter a number: ");
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		ans = findSum(n);
		System.out.println("The sum of digits of the number is: " + ans);
	}
}