import java.util.*;

class IntArr
{
    int arr[];
    int n;

    IntArr(){}
    IntArr(int nn)
    {
        n = nn;
        arr = new int[n];
    }
    void display()
    {
        for(int i = 0; i<n; i++)
        {
            System.out.println(arr[i]+"");
        }
    }
    int search(int arr[], int ele, int n)
    {
        for(int i = 0; i<n; i++)
        {
            if(arr[i] == ele) 
            {
                return i;
            }
        }
        return 0;
    }
    static void compare(IntArr a, IntArr b)
    {
        int flag =0;
        if(a.n != b.n)
        System.out.println("The objects are not equal");
        else
        {
            if(a.arr == b.arr)
            flag =1;
        }
        if(flag == 1)
            System.out.println("The two objects are equal");
        else 
            System.out.println("The two objects are not equal");
    }
}
class p12
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements of the first array: ");
        int m = sc.nextInt();
        IntArr a = new IntArr(m);
        System.out.println("Enter the elements of the first array: ");
        for(int i = 0; i<m; i++)
        {
            a.arr[i] = sc.nextInt();
        }
        System.out.println("\n\nThe elements of the first array");
        a.display();

        System.out.println("Enter the element you want to find");
        int ele = sc.nextInt();
        System.out.println("The element is found at: " + a.search(a.arr, ele, m));
        
        System.out.println("Enter the number of elements for the second array: ");
        int o = sc.nextInt();
        IntArr b = new IntArr(o);
        System.out.println("Enter the elements of the second array: ");
        for(int i = 0; i<o; i++)
        {
            b.arr[i] = sc.nextInt();
        }
        System.out.println("The elements of the second array: ");
        b.display();
        
        System.out.println("\n\nComparison of the two objects: ");
        IntArr.compare(a, b);  
         
    }
}
