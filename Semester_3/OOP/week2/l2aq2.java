import java.util.Scanner;

class l2aq2
{
    static void trace(int arr[][], int r, int c)
    {
        int i, j;
        double trace = 0.0, sum = 0.0;
        if(r != c)
        {
            System.out.println("There is no trace. ");
        }

        for(i = 0; i<r; i++)
        {
            for(j = 0; j<c; j++)
            {
                if(i == j)
                {
                    trace += arr[i][j];
                }
            }
        }
        System.out.println("The trace of the matrix is: " + trace);
    }
    static void norm(int arr[][], int r, int c)
    {
        int i, j;
        double norm = 0.0, sum = 0.0;
        for(i = 0; i<r; i++)
        {
            for(j = 0; j<c; j++)
            {
                sum += arr[i][j]*arr[i][j];
                norm = Math.sqrt(sum);
            }
        }
        System.out.println("The normal of the matrix is: " + norm);
    }
    public static void main(String[] args)
    {
        int r, c, i, j;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the rows and columns of the matrix : ");
        r = sc.nextInt();
        c = sc.nextInt();
        int arr[][] = new int[r][c];
        System.out.println("Enter the elements of the matrix: ");
        for(i = 0; i<r; i++)
        {
            for(j = 0; j<c; j++)
            {
                arr[i][j] = sc.nextInt();
            }
        }
        norm(arr, r, c);
        trace(arr, r, c);
    }
}
