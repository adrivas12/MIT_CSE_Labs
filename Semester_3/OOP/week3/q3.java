import java.util.Scanner;

class Mixer 
{
    int arr[];
    int n;
    Scanner sc = new Scanner(System.in);

    Mixer(int nn)
    {
        n = nn;
        arr = new int[n];
    }

    void accept()
    {
        System.out.println("Enter " + n + " elements in ascending order");
        for(int i = 0; i<n; i++)
        {
            arr[i] = sc.nextInt();
        }
    }

    Mixer mix(Mixer A)
    {
        Mixer B = new Mixer(n+A.n);
        int x = 0;
        for(int i = 0; i<n; i++)
        {
            B.arr[x++] = arr[i];
        }
        for(int j = 0; j< A.n; j++)
        {
            B.arr[x++] = A.arr[j];
        }
        return B;
    }
    void display()
    {
        for(int i = 0; i<n; i++)
        {
        System.out.println( arr[i] + " ");
        }
    }
}
class q3{
    public static void main(String[] args)
    {
        Scanner sc1 = new Scanner(System.in);
        System.out.println("Enter the size of the first array: ");
        int n1 = sc1.nextInt();
        Mixer P = new Mixer(n1);
        P.accept();
        System.out.println("Enter the size of the second array: ");
        int n2 = sc1.nextInt();
        Mixer Q = new Mixer(n2);
        Q.accept();

        Mixer R = P.mix(Q);
        R.display();
    }
}

