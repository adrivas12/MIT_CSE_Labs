import java.util.*;

class ISBN
{
    int inputISBN()
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        return a;
    }

    void checkISBN(int a)
    {
        int count =0;
        while (a!=0){
            a/=10;
            ++count;
        }
        if(count != 10)
        {
            System.out.println("ISBN should be a 10 digit number");
        }
        if(count == 10)
        {
            int sum=0;
            String str = Integer.toString(a);
            for(int i = 0; i<str.length(); i++)
            {
                sum+=i*str.charAt(i);
            }
            if(sum%11==0)
                System.out.println("Legal ISBN");
            else 
                System.out.println("Illegal ISBN");
        }
    }
}

class aq1
{
    public static void main(String[] args)
    {
        ISBN isbn = new ISBN();
        System.out.println("Enter the ISBN code: ");
        int b = isbn.inputISBN();
        isbn.checkISBN(b);
    }
}
