
class Complex
{
    int r;
    int img;

    void setvalues(int real , int imgaginary )
    {
        r = real;
        img = imgaginary;
    }
    Complex sum(Complex n1, Complex n2)
    {
        Complex temp = new Complex();
        temp.r = n1.r + n2.r;
        temp.img = n1.img + n2.img;
        return temp;
    }
    Complex diff(Complex n1, Complex n2)
    {
        Complex temp = new Complex();
        temp.r = n1.r -  n2.r;
        temp.img = n1.img - n2.img;
        return temp;
    }
    void print()
    {
        System.out.println("Complex number: " + r + " + " + img + "i");
    }
}

class q1
{
    public static void main(String[] args)
    {
        Complex n1 = new Complex();
        n1.setvalues(5, 4);
        n1.print();
        Complex n2 = new Complex();
        n2.setvalues(7, 3);
        n2.print();
        Complex n3 = new Complex();
        n3 = n3.sum(n1, n2);

        System.out.println("Sum of ");
        n3.print();

        n3 = n3.diff(n1, n2);

        System.out.println("Difference of ");
        n3.print();
    }
}
